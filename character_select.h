#ifndef CHARACTER_SELECT_H
#define CHARACTER_SELECT_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class Character_select;
}

class Character_select : public QWidget
{
    Q_OBJECT

public:
    explicit Character_select(QWidget *parent = nullptr);
    ~Character_select(); // Assurez-vous que le destructeur est déclaré ici
    void setPresetValues(const QVector<int> &presetValues);


private slots:
    void goBack();
    void goPresetsWindow();
    void updateCharacterIds(int characterId);
    void updateFrameImages();
    void goFight();


private:
    Ui::Character_select *ui;
    int characterIds[3];
    int enemyCharacterIds[3];
    bool characterIdsFilled;
};

#endif // CHARACTER_SELECT_H
