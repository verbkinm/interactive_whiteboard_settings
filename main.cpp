#include "main_widget/main_widget.h"

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    app.setOverrideCursor(Qt::BlankCursor);
    Main_Widget w;

    w.showFullScreen();
    w.show();

    return app.exec();
}
