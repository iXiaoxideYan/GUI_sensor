#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// #include "countdownhandler.h"
#include "datasmoother.h"
#include "serialportreader.h"

// #include "graphhandler.h"
#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void setConfigFilePath(const QString &filePath);

    void setSerialPortReader(SerialPortReader *reader);

    void readSerialData();

private slots:

    void handleDataReceived(const QByteArray &data);

    void updateGraph(double &value, double &timestamp);

    void handleDisplayRealTimeData(const QByteArray &data);

    void updateDurationInfo(const QString &info);

    void on_start_clicked();

    void on_show_clicked();

    void on_exit_clicked();

    void timeout();

    void updateCountdown();

private:
    Ui::MainWindow *ui;
    QString m_configFilePath;
    SerialPortReader *m_reader;
    QByteArray m_receivedData;
    QDateTime m_lastDataReceivedTime;
    qint64 m_timeout;
    QString m_savePath;
    QTimer *m_timer;
    qint64 m_expectedDataSize;
    QString m_unvalidData;
    QDateTime m_validDataStartTime;
    double m_displayDuration = 20.0;
    DataSmoother dataSmoother;
    // GraphHandler graphHandler;
    // CountdownHandler countdownHandler;
    QTimer *m_countdownTimer;
    int m_countdownValue;

    void setupUI();
    void configureGraph();
    void startCountdown(int seconds);
};
#endif // MAINWINDOW_H
