//include the lib. here so we can use it function in our code
#include "mainwindow.h"
#include <QApplication>
//include part fenish

//here is main function of our project
//and we pass some vars witch Qt nedded
int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //here we make an un instend of QT calling it a

    // QPixmap to show the loding screen
    QPixmap pixmap("E:/project_GUI/smart_green_farm/source/loding.jpg"); //here we use QPixmap witch is function to show something before the main window show up
    QSplashScreen *splash = new QSplashScreen(pixmap); // here we setup the function
    splash->show(); // and here we show it in our screen using Qt
    QCoreApplication::processEvents(); // a function Qt need to track every event while runing
    a.thread()->sleep(3); //a timer  wait for just 3 second and then show main window
    // QPixmap part finesh

    // setup the main window
    a.processEvents();
    MainWindow w;
    w.show(); // show the main window
    // end od setup

    splash->finish(&w); // close the lodng screen
    return a.exec(); // run the whole project
}
