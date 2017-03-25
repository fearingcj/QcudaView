#-------------------------------------------------
#
# Project created by QtCreator 2017-03-24T15:14:26
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QcudaView
TEMPLATE = app


SOURCES += src/main.cpp\
           src/mainwindow.cpp \
           src/cqtopencvviewergl.cpp

HEADERS  += src/mainwindow.h \
            src/cqtopencvviewergl.h

FORMS    += src/mainwindow.ui


INCLUDEPATH += /usr/local/cuda-8.0/include
LIBS += -L/usr/local/cuda-8.0/lib64
LIBS += -L/usr/local/lib

LIBS += -lcudart
LIBS += -lboost_filesystem -lboost_system
LIBS += -lopencv_core -lopencv_imgcodecs -lopencv_imgproc
LIBS += -lGL -lGLU
