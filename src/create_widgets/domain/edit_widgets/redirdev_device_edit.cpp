#include "redirdev_device_edit.h"

RedirDevDevice_Edit::RedirDevDevice_Edit(
        QWidget *parent, virConnectPtr conn) :
    RedirDevDevice(parent, conn)
{
    connect(type, SIGNAL(currentIndexChanged(int)),
            this, SIGNAL(dataChanged()));
    connect(host, SIGNAL(textEdited(QString)),
            this, SIGNAL(dataChanged()));
    connect(port, SIGNAL(valueChanged(int)),
            this, SIGNAL(dataChanged()));
    connect(address, SIGNAL(dataChanged()),
            this, SIGNAL(dataChanged()));
    connect(filter, SIGNAL(dataChanged()),
            this, SIGNAL(dataChanged()));
}

/* public slots */
void RedirDevDevice_Edit::setDataDescription(QString &xmlDesc)
{
    //qDebug()<<xmlDesc;
    QDomDocument doc;
    doc.setContent(xmlDesc);
    QDomElement _device, _source, _addr, _filter;
    _device = doc.firstChildElement("device")
            .firstChildElement("redirdev");
    QString _type = _device.attribute("type", "tcp");
    int idx = type->findData(
                _type,
                Qt::UserRole,
                Qt::MatchContains);
    type->setCurrentIndex( (idx<0)? 0:idx );
    if ( _type=="tcp" ) {
        _source = _device.firstChildElement("source");
        if ( !_source.isNull() ) {
            host->setText(_source.attribute("host"));
            port->setValue(_source.attribute("service").toInt());
        };
    };
    _addr = _device.firstChildElement("address");
    address->use->setChecked(!_addr.isNull());
    if ( !_addr.isNull() ) {
        USBAddr *wdg = static_cast<USBAddr*>( address->getCurrentAddrWidget() );
        wdg->bus->setText( _addr.attribute("bus") );
        wdg->port->setText( _addr.attribute("port") );
    };
    _filter = doc.firstChildElement("device")
            .firstChildElement("redirfilter");
    filter->filtered->setChecked(!_filter.isNull());
    filter->filter->clear();
    if ( !_filter.isNull() ) {
        QDomNodeList _list = _filter.childNodes();
        uint j = 0;
        uint count = _list.length();
        for (uint i=0; i<count; i++) {
            if (!_list.item(j).isNull()) {
                //qDebug()<<_list.item(j).toElement().tagName();
                if ( _list.item(j).toElement().tagName()=="usbdev" ) {
                    QDomElement _el = _list.item(j).toElement();
                    QString _class, _vendor, _product, _version, _allow, _split;
                    _class = _el.attribute("class", "");
                    _vendor = _el.attribute("vendor", "");
                    _product = _el.attribute("product", "");
                    _version = _el.attribute("version", "");
                    _allow = _el.attribute("allow", "");
                    _split.append(_class);
                    _split.append(":");
                    _split.append(_vendor);
                    _split.append(":");
                    _split.append(_product);
                    _split.append(":");
                    _split.append(_version);
                    filter->setFiltersList(_split, (_allow=="yes") );
                };
            } else
                ++j;
        };
    };
}
