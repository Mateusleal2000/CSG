#ifndef INPUT_WIDGET_H
#define INPUT_WIDGET_H

#include <QWidget>
#include <QLayoutItem>
#include <QGridLayout>

class InputWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *layout;

public:
    InputWidget(QWidget *parent = 0);
    ~InputWidget();
    void cleanLayout();

public slots:
    void mainScreen();
    void addSolidScreen();
    void confirmSolidSelection(QString solidType);
    void setNewInputs(QString solidType);
    // void setSolidSelection();
signals:
    void addSolid();
};

#endif // INPUT_WIDGET_H
