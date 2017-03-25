#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <QMainWindow>
#include <QtWidgets>

#include "cqtopencvviewergl.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void getImage();

signals:
    void showImage(cv::Mat);

private:
    Ui::MainWindow *ui;

    cv::Mat m_image;

    CQtOpenCVViewerGl* m_glWidget;
    QTimer             m_timer;
};

#endif // MAINWINDOW_H
