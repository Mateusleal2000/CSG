#include "interface/MainWidget.hpp"
#include <QApplication>
#include <QSurfaceFormat>
#include "CSGTree.hpp"

int main(int argc, char **argv)
{

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3, 3);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

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
