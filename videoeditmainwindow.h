#ifndef VIDEOEDITMAINWINDOW_H
#define VIDEOEDITMAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDebug>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include "corewipedetector.h"

using namespace std;
using namespace cv;

enum DetectionType {
    DetectionTypeWipe,
    DetectionTypeDissolve
};

namespace Ui {
class VideoEditMainWindow;
}

class VideoEditMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoEditMainWindow(QWidget *parent = 0);
    ~VideoEditMainWindow();
    TransitionDetect *detector;

private slots:

    void on_radioBtnWipe_clicked(bool checked);

    void on_radioBtnDissolve_clicked(bool checked);

    void on_btnBrowse_clicked();

    void on_btnDetect_clicked();

    void readFile(QString fileName);

private:
    Ui::VideoEditMainWindow *ui;

    DetectionType currectDetectionType;

    QString openedFileName;



    VideoCapture importedVideo;

signals:

    void didCloseBrowsingDialog(QString sourceFileName);

protected:

    void dragEnterEvent(QDragEnterEvent *event);

    void dropEvent(QDropEvent *event);
};

#endif // VIDEOEDITMAINWINDOW_H
