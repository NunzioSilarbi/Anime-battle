#ifndef PRESETS_H
#define PRESETS_H

#include <QWidget>
#include <QVector>
#include <QTextStream>
#include "ui_presets.h"
#include "character_select.h"

namespace Ui {
class Presets;
}

class Presets : public QWidget {
    Q_OBJECT

public:
    explicit Presets(QWidget *parent = nullptr);
    ~Presets();
    QVector<int> readPresetFile(const QString &filename);

private:
    Ui::Presets *ui;

private slots:
    void loadPreset1();
    void loadPreset2();
    void loadPreset3();
    void loadPreset4();
    void loadPreset5();
    void loadPreset6();
    void openCharacterSelectWithPreset(const QVector<int> &presetValues);
    void goBack();

};

#endif // PRESETS_H
