#include "hv_features.h"

HV_Features::HV_Features(QWidget *parent) :
    _Changed(parent)
{
    // workaround
    features = new QTextEdit(this);
    //
    commonLayout = new QVBoxLayout(this);
    commonLayout->addWidget(features);
    commonLayout->addStretch(-1);
    setLayout(commonLayout);
    // dataChanged connections
    connect(features, SIGNAL(textChanged()),
            this, SLOT(stateChanged()));
}

/* public slots */
void HV_Features::setFeatures(QDomDocument &_doc)
{
    features->setPlainText(_doc.toByteArray(4).data());
}
