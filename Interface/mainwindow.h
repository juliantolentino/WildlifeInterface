// the header of the mainwindow.cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QtGui>
#include <QtCore>
#include "qcustomplot.h"
#include "gazeplot.h"
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class QCPGraph;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setupDemo(QCustomPlot *customPlot);

private slots:
    void on_interact_clicked();
    void on_play_clicked();
    void onMousePress(QMouseEvent *event);
    void onMousePressStart(QMouseEvent *event);
    void onMousePressEnd(QMouseEvent *event);
    void ending_timer();
    void on_actionOpen_triggered();
    void on_open_clicked();
    void on_starting_clicked();
    void on_ending_clicked();
    void no_video_opened();
    void no_data_selected();
    void on_load_clicked();
    void on_top_n_clicked();
    void on_gaze_clicked();
    void on_actionLoad_Data_triggered();
    void on_actionLoad_Gaze_Data_triggered();
    void playGazeClickedSlot();
    void splash_screen_show();
    void on_actionHelp_triggered();

    void on_rescale_x_axis_clicked();

    void on_rescale_y_axis_clicked();

private:
    Ui::MainWindow *ui;

    QCPGraph *top;
    QCPGraph *top2;
    QCPGraph *top3;
    QCPGraph *top4;
    QCPGraph *top5;
    QCPGraph *top6;
    QCPGraph *top7;
    QCPGraph *top8;
    QCPGraph *top9;
    QCPGraph *top10;
    QCPGraph *points;
    QCPGraph *points_starting;
    QCPGraph *points_ending;
    QCPGraph *points_plotter;
    QMediaPlayer *mMediaPlayer;
    QMediaPlayer *mMediaPlayer2;
    QVideoWidget *mVideoWidget;
    QVideoWidget *mVideoWidget2;
    QTimer *timer;
    GazePlot *gazeplot;
};

#endif // MAINWINDOW_H
