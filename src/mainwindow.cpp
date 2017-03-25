#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_glWidget(nullptr),
    m_timer()
{

    ui->setupUi(this);
    m_glWidget = new CQtOpenCVViewerGl(this);

    ui->layout->addWidget(m_glWidget);


    m_timer.setInterval(33);
    m_timer.start();

    QObject::connect(&m_timer, &QTimer::timeout,
                     this,     &MainWindow::getImage);

    QObject::connect(this,       &MainWindow::showImage,
                     m_glWidget, &CQtOpenCVViewerGl::showImage);


}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::getImage()
{
    m_image = cv::imread("/home/chris/Pictures/cinnamon-bay-st-john.jpg");
    emit showImage(m_image);
}
