#include "interface/MainWidget.hpp"
#include <QApplication>
#include "CSGTree.hpp"

int main(int argc, char **argv)
{
    Operation *op = new Union();
    OpNode *root = new OpNode(op);
    CSGTree *csg = new CSGTree();
    csg->_initTest();
    csg->_print();

    QApplication app(argc, argv);
    MainWidget *mw = new MainWidget();

    app.exec();

    return 0;
}
