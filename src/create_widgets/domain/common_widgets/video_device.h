#ifndef VIDEO_DEVICE_H
#define VIDEO_DEVICE_H

#include "create_widgets/domain/_qwidget.h"
#include "device_address.h"

class VideoDevice : public _QWidget
{
    Q_OBJECT
public:
    explicit VideoDevice(QWidget *parent = NULL);

private:
    QLabel          *modelLabel;
    QLabel          *vramLabel;
    QSpinBox        *vram;
    QCheckBox       *accel2d;
    QCheckBox       *accel3d;
    QComboBox       *model;
    DeviceAddress   *addr;
    QGridLayout     *commonLayout;

public slots:
    QDomDocument getDataDocument() const;
};

#endif // VIDEO_DEVICE_H
