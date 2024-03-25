#ifndef PARAM_H
#define PARAM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Param;
}
QT_END_NAMESPACE

class Param : public QWidget
{
    Q_OBJECT

public:
    Param(QWidget *parent = nullptr);
    ~Param();

private:
    Ui::Param *ui;
};

#endif // PARAM_H
