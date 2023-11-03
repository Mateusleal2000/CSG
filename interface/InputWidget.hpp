#ifndef INPUT_WIDGET_H
#define INPUT_WIDGET_H

#include <QWidget>
#include <QLayoutItem>
#include <QGridLayout>
#include <QFormLayout>
#include "../CSGTree.hpp"

class InputWidget : public QWidget
{
    Q_OBJECT
private:
    QFormLayout *layout;
    std::vector<CSGTree> *trees;

public:
    InputWidget(QWidget *parent = 0);
    ~InputWidget();
    void cleanLayout();
    void setTrees(std::vector<CSGTree> *_trees);

public slots:
    void mainScreen();
    void addSolidScreen();
    void transformSolidScreen();
    void operationScreen();
    void changeCameraScreen();
    // void confirmSolidSelection(QString solidType, QString tree);
    // void confirmSolidTransform(QString solidName);
    void confirmSolidUnion(QString solidName1, QString solidName2);
    void setNewInputs(QString solidType);
signals:
    void addSolid();
};

#endif // INPUT_WIDGET_H
