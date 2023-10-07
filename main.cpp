#include "interface/MainWidget.hpp"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWidget *mw = new MainWidget();

    app.exec();

    return 0;
}
