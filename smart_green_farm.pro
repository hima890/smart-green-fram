QT       += core gui
QT += network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    smrart_green_farmReports/newReport.txt \
    source/Screen Shot 2021-03-08 at 12.01.03.png \
    source/iconfinder_weather-01_1530392.png \
    source/iconfinder_weather-02_1530391.png \
    source/iconfinder_weather-21_1530373.png \
    source/iconfinder_weather_12_2682839.png \
    source/iconfinder_weather_44_2682807.png \
    source/img1.svg \
    source/loding.jpg \
    source/sound.mp3 \
    source/test.txt \
    source/undraw_Weather_re_qsmd (1).svg \
    source/undraw_Weather_re_qsmd.svg \
    source/undraw_data_report_bi6l.svg \
    source/undraw_data_reports_706v.svg \
    source/undraw_investment_data_yfvt.svg \
    source/uv-index (1).png \
    source/uv-index (3).png \
    source/uv-index (5).png \
    source/uv-index.png \
    source/vecteezy_collection-of-linear-style-weather-signs-and-symbols-in-minimal-white-outline-design-on-dark-background_155855/48.eps \
    source/vecteezy_collection-of-linear-style-weather-signs-and-symbols-in-minimal-white-outline-design-on-dark-background_155855/48.svg \
    source/vecteezy_collection-of-linear-style-weather-signs-and-symbols-in-minimal-white-outline-design-on-dark-background_155855/Vecteezy-License-Information.pdf \
    source/vecteezy_collection-of-linear-style-weather-signs-and-symbols-in-minimal-white-outline-design-on-dark-background_155855/free-linear-weather-symbols-vector.jpg

RESOURCES += \
    source/resorcue.qrc


