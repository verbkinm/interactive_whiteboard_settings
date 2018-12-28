#include "main_widget/main_widget.h"

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QString translatorFileName = QLatin1String("qt_");
//    translatorFileName += QLocale::system().name();
//    QTranslator *translator = new QTranslator(&app);
//    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
//        app.installTranslator(translator);

//    a.setOverrideCursor(Qt::BlankCursor);
    Main_Widget w;

//    w.setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);
//    w.showMaximized();
//    w.showFullScreen();
    w.show();

    return app.exec();
}
