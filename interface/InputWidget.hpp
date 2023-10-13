#ifndef INPUT_WIDGET_H
#define INPUT_WIDGET_H

#include <QWidget>
#include <QLayoutItem>
#include <QGridLayout>
#include <QFormLayout>

class InputWidget : public QWidget
{
    Q_OBJECT
private:
    QFormLayout *layout;

public:
    InputWidget(QWidget *parent = 0);
    ~InputWidget();
    void cleanLayout();

public slots:
    void mainScreen();
    void addSolidScreen();
    void transformSolidScreen();
    void confirmSolidSelection(QString solidType);
    void confirmSolidTransform(QString solidName);
    void setNewInputs(QString solidType);
signals:
    void addSolid();
};

#endif // INPUT_WIDGET_H
