#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//all the Qt libs that well we need
#include <QMainWindow>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkReply>
#include<QtDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include<QFile>
#include<QLineEdit>
#include <QSplashScreen>
#include <QThread>
#include<QMessageBox>
// the end of the Qt libs

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_re_btn_clicked();
    void useData(QNetworkReply*);

    void on_reportbtn_clicked();

    void on_closebtn_clicked();

private:
    QString myUrl = "http://127.0.0.1:5000/api/v1/newInfo"; // the url var witch well save the url string

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
