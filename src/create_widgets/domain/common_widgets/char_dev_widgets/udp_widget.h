#ifndef UDP_WIDGET_H
#define UDP_WIDGET_H

#include "create_widgets/domain/_qwidget.h"

class UdpWidget : public _QWidget
{
    Q_OBJECT
public:
    explicit UdpWidget(QWidget *parent = 0, QString _tag = "");

signals:

private:
    QLabel          *hostLabel;
    QLineEdit       *host;
    QLabel          *port1Label;
    QSpinBox        *port1;
    QLabel          *bindHostLabel;
    QLineEdit       *bindHost;
    QLabel          *port2Label;
    QSpinBox        *port2;
    QGridLayout     *udpLayout;
    QString          tag;

public slots:
    QDomDocument getDevDocument() const;
    void         setDeviceData(QString&);
};

#endif // UDP_WIDGET_H
