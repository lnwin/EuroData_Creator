#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
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
    void on_videoIputPath_pushButton_clicked();

    void on_vidoe2imgoutputPath_pushButton_clicked();

    void on_startCutVideo_clicked();

    void on_imgIputPath_pushButton_clicked();

    void on_imgOutputPath_pushButton_clicked();

    void on_startChange_clicked();

    void on_ffmpegPath_pushButton_clicked();

    void sltOnReadOutput();

    void  onFinished(int, QProcess::ExitStatus);


private:
    Ui::MainWindow *ui;
    QProcess *mypocess;
    QString ffmpegComd;

};
#endif // MAINWINDOW_H
