#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mypocess = new QProcess(this);
    mypocess->setProgram("cmd");
    connect(mypocess, SIGNAL(readyReadStandardOutput()), this, SLOT(sltOnReadOutput()));
    connect(mypocess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onFinished(int, QProcess::ExitStatus)));

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_startCutVideo_clicked()
{
  // " D:\myProgrames\EuroData_Creator\include\ffmpeg\bin\ffmpeg -i 1.avi -r 24 ./test/0_%05d.jpg"

    ffmpegComd=ui->ffmpegPath->text()+"/ffmpeg -i "+ui->videoIputPath->text()+" -r "+ui->cuteFPS->text()+" "
            +ui->vidoe2imgoutputPath->text()+"/0_%05d.jpg"+"\n";

    qDebug()<<ffmpegComd;

    mypocess->start("cmd");
    mypocess->waitForStarted();        //等待启动完成

    QString  str;
    char*  ch;
    QByteArray ba = ffmpegComd.toLatin1(); // must
    ch=ba.data();
    mypocess->write(ch);

}

void MainWindow::sltOnReadOutput()
{
    QString s = mypocess->readAllStandardOutput();
    if(s=="\r\nD:\\myProgrames\\EuroData_Creator>")
    {
        mypocess->kill();
    };
}
 void MainWindow::onFinished(int myint, QProcess::ExitStatus mystayus)
 {
    qDebug()<<"finished@!!!!!!!!";

 };

void MainWindow::on_startChange_clicked()
{

}

void MainWindow::on_videoIputPath_pushButton_clicked()
{
    QString  srcDirPath = QFileDialog::getOpenFileName( this, "选择视频", "/");
    if (srcDirPath.isEmpty())
    {
        QMessageBox mesbox;
        mesbox.setText("文件不存在！");
        mesbox.exec();
        return;
    }
    else
    {
        ui->videoIputPath->setText(srcDirPath);
    }
}
void MainWindow::on_vidoe2imgoutputPath_pushButton_clicked()
{
    QString  srcDirPath = QFileDialog::getExistingDirectory( this, "请选择标输出图片存储路径", "/");
    if (srcDirPath.isEmpty())
    {
        QMessageBox mesbox;
        mesbox.setText("路径为空！");
        mesbox.exec();
        return;
    }
    else
    {
       ui->vidoe2imgoutputPath->setText(srcDirPath);
    }
}
void MainWindow::on_imgIputPath_pushButton_clicked()
{
    QString  srcDirPath = QFileDialog::getExistingDirectory( this, "请选择标输入图片存储路径", "/");
    if (srcDirPath.isEmpty())
    {
        QMessageBox mesbox;
        mesbox.setText("路径为空！");
        mesbox.exec();
        return;
    }
    else
    {
       ui->imgIputPath->setText(srcDirPath);
    }
}
void MainWindow::on_imgOutputPath_pushButton_clicked()
{
    QString  srcDirPath = QFileDialog::getExistingDirectory( this, "请选择标输出图片存储路径", "/");
    if (srcDirPath.isEmpty())
    {
        QMessageBox mesbox;
        mesbox.setText("路径为空！");
        mesbox.exec();
        return;
    }
    else
    {
       ui->imgOutputPath->setText(srcDirPath);
    }
}

void MainWindow::on_ffmpegPath_pushButton_clicked()
{
    QString  srcDirPath = QFileDialog::getExistingDirectory( this, "选择ffmpeg路径", "/");
    if (srcDirPath.isEmpty())
    {
        QMessageBox mesbox;
        mesbox.setText("文件不存在！");
        mesbox.exec();
        return;
    }
    else
    {
        ui->ffmpegPath->setText(srcDirPath);
    }
}

