#ifndef PRESETS_H
#define PRESETS_H

#include <QWidget>

namespace Ui {
class Presets;
}

class Presets : public QWidget
{
    Q_OBJECT

public:
    explicit Presets(QWidget *parent = nullptr);
    ~Presets();

private slots:
    void goBack();

private:
    Ui::Presets *ui;
};

#endif // PRESETS_H
