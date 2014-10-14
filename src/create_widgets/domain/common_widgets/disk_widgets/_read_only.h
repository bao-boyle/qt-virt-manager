#ifndef _READ_ONLY_H
#define _READ_ONLY_H

#include <QWidget>
#include <QCheckBox>
#include <QHBoxLayout>

class _ReadOnly : public QWidget
{
    Q_OBJECT
public:
    explicit _ReadOnly(QWidget *parent = NULL);

private:
    QCheckBox       *readOnly;
    QHBoxLayout     *commonLayout;

public slots:
    bool state() const;
};

#endif // _READ_ONLY_H
