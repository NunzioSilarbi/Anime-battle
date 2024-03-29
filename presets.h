#ifndef PRESETS_H
#define PRESETS_H

#include <QWidget>
#include <QVector>
#include <QTextStream>
#include "ui_presets.h" // Assurez-vous d'inclure le fichier d'en-tête généré par Qt pour votre interface utilisateur

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
    void goBack();

};

#endif // PRESETS_H
