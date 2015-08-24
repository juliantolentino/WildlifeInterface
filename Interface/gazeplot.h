// the header file of gazeplot.cpp
#ifndef GAZEPLOT_H
#define GAZEPLOT_H

#include <QWidget>

#include <QTimer>
#include "qcustomplot.h"
#include <QDialog>


namespace Ui {
class GazePlot;
}

class GazePlot : public QDialog
{
    Q_OBJECT

public:
    explicit GazePlot(QWidget *parent = 0);
    ~GazePlot();

private slots:
    void timer_gaze_function();
    void on_play_gaze_clicked();
    void on_pushButton_clicked();

private:
    Ui::GazePlot *ui;

    QTimer *timer_gaze;

signals:
    void playGazeClicked();
};

#endif // GAZEPLOT_H
