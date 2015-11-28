#include "videoeditmainwindow.h"
#include "ui_videoeditmainwindow.h"

VideoEditMainWindow::VideoEditMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VideoEditMainWindow)
{
    ui->setupUi(this);

    ui->labelVideoPreview->setAcceptDrops(false);
    setAcceptDrops(true);

    connect(this, SIGNAL(didCloseBrowsingDialog(QString)), this, SLOT(readFile(QString)));

}

VideoEditMainWindow::~VideoEditMainWindow()
{
    delete ui;
}

void VideoEditMainWindow::on_radioBtnWipe_clicked(bool checked)
{
    if(checked) {
        currectDetectionType = DetectionTypeWipe;
    }
}

void VideoEditMainWindow::on_radioBtnDissolve_clicked(bool checked)
{
    if(checked) {
        currectDetectionType = DetectionTypeDissolve;
    }
}

void VideoEditMainWindow::on_btnBrowse_clicked()
{
    QString filter = "MPEG Video(*.mpg);;m4v Video(*.m4v);;MP4 Video(*.mp4);;QuickTime Video(*.mov);;All files(*.*)";

    QString sourceFileName = QFileDialog::getOpenFileName(this, "Select a source file", "/", filter);
    emit didCloseBrowsingDialog(sourceFileName);

    openedFileName = sourceFileName;
    qDebug() << openedFileName;
}

void VideoEditMainWindow::on_btnDetect_clicked()
{
    //TransitionDetect detector(openedFileName.toStdString());
    qDebug() << openedFileName;
    cout << openedFileName.toStdString() << " at new";
    detector = new TransitionDetect(openedFileName.toStdString());
    //cout << openedFileName.toStdString() << " at new";
    detector->AddCols();
}

void VideoEditMainWindow::dragEnterEvent(QDragEnterEvent *event) {
    /*if(event->mimeData()->hasFormat("video/mp4")) {
        event->acceptProposedAction();
    }*/
    event->acceptProposedAction();
    qDebug() << "1";
}

void VideoEditMainWindow::dropEvent(QDropEvent *event) {
    QList<QUrl> urlList = event->mimeData()->urls();
    QString fileName = urlList.first().toLocalFile();

    emit didCloseBrowsingDialog(fileName);

    openedFileName = fileName;
    qDebug() << fileName;
}

void VideoEditMainWindow::readFile(QString fileName) {
    qDebug() << fileName << "at readFile()";

    VideoCapture thumbnailVideo(fileName.toStdString());
    Mat thumbnailFrame, thumbnailFrameRGB;
    thumbnailVideo >> thumbnailFrame;
    cvtColor(thumbnailFrame, thumbnailFrameRGB, CV_BGR2RGB);
    QImage image = QImage((uchar*)(thumbnailFrameRGB.data),thumbnailFrameRGB.cols, thumbnailFrameRGB.rows, thumbnailFrameRGB.step,QImage::Format_RGB888);
    QImage scaledImage = image.scaled(240, 160, Qt::KeepAspectRatio);
    ui->labelVideoPreview->setPixmap(QPixmap::fromImage(scaledImage));
    ui->labelVideoPreview->show();
}
