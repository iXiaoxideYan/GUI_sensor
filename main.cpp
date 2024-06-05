#include "file.h"
#include "mainwindow.h"

#include <QApplication>
#include <QDir>
#include <QLocale>
#include <QTranslator>
#include <serialportreader.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString filePath = "conf.json"; // Default JSON file path

    // If a JSON file path is provided in the command-line arguments, use that path
    if (argc > 1) {
        filePath = QString(argv[1]);
    }

    if (!checkFile(filePath)) {
        return -1; // Exit the program with an error code
    }

    SerialPortReader serialPortReader;
    if (serialPortReader.readConfigFromFile(filePath)) {
        if (serialPortReader.openSerialPort()) {
            qDebug() << "Serial port opened successfully!";
        } else {
            qWarning() << "Failed to open serial port!";
        }
    } else {
        qWarning() << "Failed to read configuration from JSON file!";
    }

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "gui_test_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.setConfigFilePath(filePath);
    w.setSerialPortReader(&serialPortReader);
    w.show();
    return a.exec();
}
