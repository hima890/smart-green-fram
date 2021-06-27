//the include part
#include "mainwindow.h"
#include "ui_mainwindow.h"
//end of include part

//here we defiend our vars
QString timeKnow;
QString datetime;
QString initialInTemp;
QString initialOutTemp;
QString initialSunShineIn;
QString initialSunShineOut;
QString initialCo2In;
QString initialCo2Out;
QString nextWaterTime;
//end of the defiend

//the use data function
void MainWindow::useData(QNetworkReply *reply){ // the function get the reply from the server
    QFile file("E:/project_GUI/smart_green_farm/source/test.txt"); // we  use the Qt file system to open a file
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) // the if statement check if the file in the dec. and its open in writeOnly mode
          {
              // We're going to streaming text to the file
              QTextStream stream(&file); // here we declure the Qt stream function
              stream << reply->readAll(); // we use the stream function to write the server reply to the file
              file.close(); // here we close the file after we write the server reply
              qDebug() << "Writing finished"; // a message to know every thing is ok
              // end of stream to the file




              // here we use the data witch in the file
              file.open(QIODevice::ReadOnly | QIODevice::Text); // we open the file agine in readOnly mode
              QString stor = file.readAll(); // here we read the data witch its a Json data type and save it in a var
              file.close(); // and we close the file
              QJsonDocument d = QJsonDocument::fromJson(stor.toUtf8()); // here we use the Qt Json lib. to procces the json data to (Utf-8) coded data
              QJsonObject s = d.object(); // here we make the data callebel
              // end of useing data

              // here we change the data type from a json type to QtString type by useing the toString() function
              timeKnow = s["timeKnow"].toString();
              datetime = s["datetime"].toString();
              initialInTemp = s["initialInTemp"].toString();
              initialOutTemp = s["initialOutTemp"].toString();
              initialSunShineOut = s["initialSunShineOut"].toString();
              initialSunShineIn = s["initialSunShineIn"].toString();
              initialCo2In = s["initialCo2In"].toString();
              initialCo2Out = s["initialCo2Out"].toString();
              nextWaterTime = s["nextWaterTime"].toString();
              // end of the change type

              // in this part we update our (GUI) with the new data using Qt ui function
              ui->lnd1->setText(initialInTemp); // here we set the inTemp value
              ui->lnd2->setText(initialOutTemp); //  here we set the outTemp value
              ui->lnd3->setText(initialCo2In); //  here we set the inHumded value
              ui->lnd4->setText(initialCo2Out); //  here we set the outHumded value
              ui->lnd5->setText(initialSunShineIn); //  here we set the inUV value
              ui->lnd6->setText(initialSunShineOut); //  here we set the outUV value
              // end of this part

    }else{ // if the file not found un error message well show in the consol
        qDebug() << "Error finding file!!" << endl; // we use the Qt debug function to show the message
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//the refresh function
void MainWindow::on_re_btn_clicked() // when the button clicked this function well start
{
    QNetworkAccessManager *man = new QNetworkAccessManager(this); // here we use the QtNetwork assess manger and we stored in a var named man
    connect(man, &QNetworkAccessManager::finished, this, &MainWindow::useData); // here we connect the QtNetwork assess manger with the condion of finished requst and then call the use data function
    const QUrl url = QUrl(myUrl); // here we used the Qurl lib to save and use the url (server address)
    QNetworkRequest request(url); // the QNetworkRequest function make requst to the url
    man->get(request); // the reply pass to the QNetworkAccessManager so we can used it leter
}
// the end report function


// the report function
void MainWindow::on_reportbtn_clicked() // the function call when the report button pressed
{
            QFile file("E:/project_GUI/smart_green_farm/smrart_green_farmReports/newReport.txt"); // we  use the Qt file system to open a file
            if(file.open(QIODevice::WriteOnly | QIODevice::Text)) // the if statement check if the file in the dec. and its open in writeOnly mode
                  {
                      // We're going to streaming text to the file
                      QTextStream stream(&file); // here we declure the Qt stream function

                      // here we declure a var of the report in string content the data from the server
                      QString report = "\t \t \tSmart Green-Farm report \t \t \t \t \t \t \n \t \t \t \t  D12354 \t \t \t \t \t \t \n Date : " +
                              datetime +  "\t \t \n Time:  " + timeKnow +
                              "\t \t \n initialInTemp:  " + initialInTemp +
                              "\t \t \n initialOutTemp:  " + initialOutTemp +
                              "\t \t \n initialSunShineOut:  " + initialSunShineOut +
                                "\t \t \n initialSunShineIn:  " + initialSunShineIn +
                              "\t \t \n initialCo2In:  " + initialCo2In + "\t \t \n initialCo2Out:  " +
                              initialCo2Out + "\t \t \n \t \t \t \t Next weater time:  " + nextWaterTime +
                              "\t\t \t" + "\n \t \t \t     Recommendation: Increase the humidity while reducing UV rays";
                      // the end of the report string

                      stream << report; // write the report string to the report file
                      file.close(); // close after the stream to the function end

                      QMessageBox msgBox; // here we dec. a Qt QMessageBox to used it to show a message to user
                      msgBox.setText("The Report has been saved."); // the message that well show
                      msgBox.exec(); // show the messsge in the Gui
                      qDebug() << "Writing finished"; // use the qdebug to show a message in consol


            }else{ // if the file not found un error message well show in the consol
                qDebug() << "Error finding file!!" << endl; // we use the Qt debug function to show the message
            }
}

// the close function called when the close button pressed
void MainWindow::on_closebtn_clicked()
{
    close(); // call a function to close the whole programe
}
