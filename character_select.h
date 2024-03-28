#ifndef CHARACTER_SELECT_H
#define CHARACTER_SELECT_H

#include <QWidget>

namespace Ui {
class Character_select;
}

class Character_select : public QWidget
{
    Q_OBJECT

public:
    explicit Character_select(QWidget *parent = nullptr);
    ~Character_select();

private:
    Ui::Character_select *ui;
};

#endif // CHARACTER_SELECT_H
