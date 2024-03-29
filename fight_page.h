#ifndef FIGHT_PAGE_H
#define FIGHT_PAGE_H

#include <QWidget>

namespace Ui {
class Fight_page;
}

class Fight_page : public QWidget
{
    Q_OBJECT

public:
    explicit Fight_page(const QString &backgroundImagePath, QWidget *parent = nullptr);
    ~Fight_page();

private:
    Ui::Fight_page *ui;
};

#endif // FIGHT_PAGE_H
