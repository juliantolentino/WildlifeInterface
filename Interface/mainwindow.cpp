// the CPP file of the main window
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QApplication>
#include <QProcess>
#include <QMessageBox>
#include <QFileInfo>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <qgraphicseffect.h>
#include <iomanip>
#include <QGraphicsVideoItem>
#include <QSlider>
#include <QInputDialog>

using namespace std;

double xvalue;
double starting_point;
double ending_point;
double cnt;
QString filename;
QString dataname = "";
QVector<double> a,b,a2,b2,a3,b3,a4,b4,a5,b5,a6,b6,a7,b7,a8,b8,a9,b9,a10,b10;
int number_of_n;
vector<double>x_coord, y_coord;
int heart_rate_plots_count;
QString hr_legend_qstring;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // shows splash screen (a.k.a. help message)
    splash_screen_show();

    // sets the menu icons
    ui->open->setIcon(QIcon(":/Images/open_file_icon.png"));
    ui->load->setIcon(QIcon(":/Images/load_data_icon.png"));
    ui->gaze->setIcon(QIcon(":/Images/load_gaze_icon.png"));

    // declares the plottable points for the heart-rate plot
    points_starting = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    points_ending = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    points = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    top = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    top2 = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    top3 = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    top4 = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    top5 = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    top6 = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    top7 = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    top8 = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    top9 = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    top10 = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);

    // customizes the heart-rate plot background and axis
    ui->customPlot->setStyleSheet("background:hsva(255,255,255,0%);");
    ui->customPlot->setBackground(QBrush(Qt::NoBrush));
    ui->customPlot->xAxis->setLabel("Time (seconds)");
    ui->customPlot->yAxis->setLabel("Heart Rate (BPM)");
    ui->customPlot->xAxis->setRange(0, 60);
    ui->customPlot->yAxis->setRange(70, 120);

    // sets the range for the top n values
    ui->lineEdit->setValidator( new QIntValidator(-1000, 1000, this) );

    // sets the range for the axis rescaling
    ui->low_x_axis_line_edit->setValidator( new QDoubleValidator(this));
    ui->high_x_axis_line_edit->setValidator( new QDoubleValidator(this));
    ui->low_y_axis_line_edit->setValidator( new QDoubleValidator(this));
    ui->high_y_axis_line_edit->setValidator( new QDoubleValidator(this));

    // QMediaPlayer(s) set to QVideoWidget(s)
    mMediaPlayer = new QMediaPlayer(this);
    mMediaPlayer->setVideoOutput(ui->mVideoWidget);
    mMediaPlayer2 = new QMediaPlayer(this);
    mMediaPlayer2->setVideoOutput(ui->mVideoWidget2);

    // timer declared
    // timer is for if starting and ending points are used when playing the video
    timer = new QTimer(this);

    // declares QSpinbBox ui->graph_selector for heart-rate subject selector
    ui->graph_selector->setRange(1,10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// shows help information
void MainWindow::splash_screen_show(){
    QMessageBox::information(this, "Help", "Load video first, followed by the heart-rate and gaze "
                                           "coordinates text files. Upon loading the video, the previews "
                                           "will disappear, but the file status pop-up will confirm the video "
                                           "was loaded correctly."
                                           "\n\nEach subject's data is organized in a folder "
                                           "named according to the date the data was collected and "
                                           "their subject number, e.g. \"21-Jul-2015-s005\". "
                                           "\n\nInside a subject's folder, the heart-rate data text file "
                                           "is named according to the subject, the video's number and title, "
                                           "with the suffix _HRwTS, e.g. \"s005_001_WonderfulWorld_HRwTS\". "
                                           "\n\nThe gaze coordinates data text file is named according to the subject, "
                                           "the video's number and title, with the suffix _gazeTS, "
                                           "e.g. \"s005_001_WonderfulWorld_gazeTS.\"");
}

// Help button
void MainWindow::on_actionHelp_triggered()
{
    splash_screen_show();
}

// graph icon button loads heart-rate data
void MainWindow::on_load_clicked()
{
    if(filename.isEmpty()){
        no_video_opened();
    }
    else{
        setupDemo(ui->customPlot);
    }
}

// plots heart-rate data
void MainWindow::setupDemo(QCustomPlot *customPlot)
{
    // opens heart-rate data and checks if something selected
    dataname = QFileDialog::getOpenFileName(this,"Open a Heart-Rate Data Text File","","*.txt");
    if(dataname.isEmpty()){
        QMessageBox::information(this, "File Status", "No heart-rate data was loaded.");
        return;
    }

    // parses heart-rate data text file and plots it into ui->customPlot (for heart rate)
    QVector<QString> v;
    QFile textFile(dataname);
    QFile d(dataname);
    QFileInfo dInfo(d.fileName());
    QString dataname_display(dInfo.fileName());
    if(textFile.open(QIODevice::ReadOnly))
    {
        QString all;
        QTextStream textStream(&textFile);
        while (!textStream.atEnd()) {
            textStream >> all;
            if(textStream.status() == QTextStream::Ok){
                v.append(all);
            }
            else
                break;
        }

        if (heart_rate_plots_count == 0){
            a.resize(v.size()-1), b.resize(v.size()-1);
        }
        if (heart_rate_plots_count == 1){
            a2.resize(v.size()-1), b2.resize(v.size()-1);
        }
        if (heart_rate_plots_count == 2){
            a3.resize(v.size()-1), b3.resize(v.size()-1);
        }
        if (heart_rate_plots_count == 3){
            a4.resize(v.size()-1), b4.resize(v.size()-1);
        }
        if (heart_rate_plots_count == 4){
            a5.resize(v.size()-1), b5.resize(v.size()-1);
        }
        if (heart_rate_plots_count == 5){
            a6.resize(v.size()-1), b6.resize(v.size()-1);
        }
        if (heart_rate_plots_count == 6){
            a7.resize(v.size()-1), b7.resize(v.size()-1);
        }
        if (heart_rate_plots_count == 7){
            a8.resize(v.size()-1), b8.resize(v.size()-1);
        }
        if (heart_rate_plots_count == 8){
            a9.resize(v.size()-1), b9.resize(v.size()-1);
        }
        if (heart_rate_plots_count == 9){
            a10.resize(v.size()-1), b10.resize(v.size()-1);
        }

        for(int i=1; i<v.size(); ++i)
        {
            string v_i_as_string = v[i].toUtf8().constData();
            int comma_pos = v_i_as_string.find(",");
            double x_double = stod(v_i_as_string.substr(0,comma_pos));
            double y_double = stod(v_i_as_string.substr(comma_pos+1,v_i_as_string.length()));
            if (heart_rate_plots_count == 0){
                a[i-1] = x_double;
                b[i-1] = y_double;
            }
            if (heart_rate_plots_count == 1){
                a2[i-1] = x_double;
                b2[i-1] = y_double;
            }
            if (heart_rate_plots_count == 2){
                a3[i-1] = x_double;
                b3[i-1] = y_double;
            }
            if (heart_rate_plots_count == 3){
                a4[i-1] = x_double;
                b4[i-1] = y_double;
            }
            if (heart_rate_plots_count == 4){
                a5[i-1] = x_double;
                b5[i-1] = y_double;
            }
            if (heart_rate_plots_count == 5){
                a6[i-1] = x_double;
                b6[i-1] = y_double;
            }
            if (heart_rate_plots_count == 6){
                a7[i-1] = x_double;
                b7[i-1] = y_double;
            }
            if (heart_rate_plots_count == 7){
                a8[i-1] = x_double;
                b8[i-1] = y_double;
            }
            if (heart_rate_plots_count == 8){
                a9[i-1] = x_double;
                b9[i-1] = y_double;
            }
            if (heart_rate_plots_count == 9){
                a10[i-1] = x_double;
                b10[i-1] = y_double;
            }
        }

        //sets ending point to the duration of video
        ending_point = (mMediaPlayer->duration())/1000;

        // add and color the graphs
        customPlot->addGraph();
        QPen graphPen;
        if (heart_rate_plots_count == 0){
            customPlot->graph()->setData(a, b);
            graphPen.setColor(Qt::red);
            hr_legend_qstring += "Legend\nRed: " + dataname_display;
        }
        if (heart_rate_plots_count == 1){
            customPlot->graph()->setData(a2, b2);
            graphPen.setColor(Qt::darkGreen);
            hr_legend_qstring += "\nDark Green: " + dataname_display;
        }
        if (heart_rate_plots_count == 2){
            customPlot->graph()->setData(a3, b3);
            graphPen.setColor(Qt::blue);
            hr_legend_qstring += "\nBlue: " + dataname_display;
        }
        if (heart_rate_plots_count == 3){
            customPlot->graph()->setData(a4, b4);
            graphPen.setColor(Qt::black);
            hr_legend_qstring += "\nBlack: " + dataname_display;
        }
        if (heart_rate_plots_count == 4){
            customPlot->graph()->setData(a5, b5);
            graphPen.setColor(Qt::darkCyan);
            hr_legend_qstring += "\nDark Cyan: " + dataname_display;
        }
        if (heart_rate_plots_count == 5){
            customPlot->graph()->setData(a6, b6);
            graphPen.setColor(Qt::darkMagenta);
            hr_legend_qstring += "\nDark Magenta: " + dataname_display;
        }
        if (heart_rate_plots_count == 6){
            customPlot->graph()->setData(a7, b7);
            graphPen.setColor(Qt::darkYellow);
            hr_legend_qstring += "\nDark Yellow: " + dataname_display;
        }
        if (heart_rate_plots_count == 7){
            customPlot->graph()->setData(a8, b8);
            graphPen.setColor(Qt::darkRed);
            hr_legend_qstring += "\nDark Red: " + dataname_display;
        }
        if (heart_rate_plots_count == 8){
            customPlot->graph()->setData(a9, b9);
            graphPen.setColor(Qt::darkGray);
            hr_legend_qstring += "\nDark Gray: " + dataname_display;
        }
        if (heart_rate_plots_count == 9){
            customPlot->graph()->setData(a10, b10);
            graphPen.setColor(Qt::darkBlue);
            hr_legend_qstring += "\nDark Blue: " + dataname_display;
        }
        ui->hr_legend->setText(hr_legend_qstring);
        heart_rate_plots_count++;
        graphPen.setWidthF(1);
        customPlot->graph()->setPen(graphPen);

        // rescales time axis to match video length
        customPlot->graph()->rescaleAxes();
        customPlot->xAxis->setRangeLower(0);
        customPlot->xAxis->setRangeUpper((mMediaPlayer->duration())/1000);

        // makes ui->customPlot (heart rate) zoomable and draggable
        customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        customPlot->replot();

        //Message showing user heart-rate data has been loaded.
        QMessageBox::information(this, "File Status", dataname_display + " has been loaded.");
    }
}

/* "interact with graph" button method. Upon clicking, the user can plot X's on the heart-rate plot. The
 * video and the gaze plot will update to the corresponding time.
*/
void MainWindow::on_interact_clicked()
{
    // checks if video frame directory and heart-rate data exists.
    if(filename.isEmpty()){
        no_video_opened();
    }
    else if(dataname.isEmpty()){
        no_data_selected();
    }
    else{
        // disconnects other mouse press signals and slots
        disconnect(ui->customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(onMousePressStart(QMouseEvent*)));
        disconnect(ui->customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(onMousePressEnd(QMouseEvent*)));

        // adds plottable points to ui->customPlot (heart rate)
        ui->customPlot->addPlottable(points);
        points->setAdaptiveSampling(false);
        points->removeFromLegend();
        points->setLineStyle(QCPGraph::lsNone);
        points->setScatterStyle(QCPScatterStyle::ssCross);
        points->setPen(QPen(QBrush(Qt::red),3));
        ui->customPlot->replot();

        // connects mouse press for "interact with graph" to ui->customPlot (heart rate)
        connect(ui->customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(onMousePress(QMouseEvent*)));
    }
}

/* The "select start" button method. Upon clicking, the user can set the starting point of the video
 * and the gaze data will correspond. The video frames and the gaze plot will update to the corresponding time.
 * */
void MainWindow::on_starting_clicked()
{
    // checks if video and heart-rate data exist.
    if(filename.isEmpty()){
        no_video_opened();
    }
    else if(dataname.isEmpty()){
        no_data_selected();
    }
    else{
        // disconnects other mouse press signals and slots
        disconnect(ui->customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(onMousePress(QMouseEvent*)));
        disconnect(ui->customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(onMousePressEnd(QMouseEvent*)));

        // stops video players
        mMediaPlayer->stop();
        mMediaPlayer2->stop();

        // adds plottable points to ui->customPlot (heart rate)
        points_starting->clearData();
        ui->customPlot->addPlottable(points_starting);
        points_starting->setAdaptiveSampling(false);
        points_starting->removeFromLegend();
        points_starting->setLineStyle(QCPGraph::lsNone);
        points_starting->setScatterStyle(QCPScatterStyle::ssTriangle);
        points_starting->setPen(QPen(QBrush(Qt::black),3));
        ui->customPlot->replot();

        // connects mouse press for starting point to ui->customPlot (heart rate)
        connect(ui->customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(onMousePressStart(QMouseEvent*)));
    }
}

/* The "select end" button method. Upon clicking, the user can set the ending point of the video
 * and the gaze data will correspond. The video frames and the gaze plot will update to the corresponding time.
 * */
void MainWindow::on_ending_clicked()
{
    // checks if video and heart-rate data exist.
    if(filename.isEmpty()){
        no_video_opened();
    }
    else if(dataname.isEmpty()){
        no_data_selected();
    }
    else{
        // disconnects other mouse press signals and slots
        disconnect(ui->customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(onMousePress(QMouseEvent*)));
        disconnect(ui->customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(onMousePressStart(QMouseEvent*)));

        // stops video players
        mMediaPlayer->stop();
        mMediaPlayer2->stop();

        // adds plottable points to ui->customPlot (heart rate)
        points_ending->clearData();
        ui->customPlot->addPlottable(points_ending);
        points_ending->setAdaptiveSampling(false);
        points_ending->removeFromLegend();
        points_ending->setLineStyle(QCPGraph::lsNone);
        points_ending->setScatterStyle(QCPScatterStyle::ssTriangleInverted);
        points_ending->setPen(QPen(QBrush(Qt::black),3));
        ui->customPlot->replot();

        // connects mouse press for ending point to ui->customPlot (heart rate)
        connect(ui->customPlot,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(onMousePressEnd(QMouseEvent*)));
    }
}

/* "play" button method. The QMediaPlayers for the video frames and the gaze plots are updated.
 * The progress is updated on the cursor.
 */
void MainWindow::on_play_clicked()
{
    // error message
    if(filename.isEmpty()){
        no_video_opened();
    }
    else{
        // plays the QMediaPlayers
        if(mMediaPlayer->state() != 1){
            if (starting_point == 0){
                mMediaPlayer->play();
                mMediaPlayer2->play();
            }
            else{
                // sets the position of the video players
                mMediaPlayer->setPosition(starting_point*(mMediaPlayer->duration())/((mMediaPlayer->duration())/1000));
                mMediaPlayer2->setPosition(starting_point*(mMediaPlayer->duration())/((mMediaPlayer->duration())/1000));
                mMediaPlayer->play();
                mMediaPlayer2->play();

                //timer for video if start and end points are used.
                cnt = (ending_point - starting_point)*((mMediaPlayer->duration())/((mMediaPlayer->duration())/1000));
                timer->setInterval(10);
                timer->disconnect();
                connect(timer,SIGNAL(timeout()),this,SLOT(ending_timer()));
                timer->start();
            }
        }
        // pauses the QMediaPlayers and disconnects timer
        else{
            mMediaPlayer->pause();
            mMediaPlayer2->pause();
            timer->disconnect();
        }
    }
}

// controls ending point
void MainWindow::ending_timer()
{
    if(cnt > 0)
    {
        cnt -= 10.046942149;
    }
    else
    {
        mMediaPlayer->pause();
        mMediaPlayer2->pause();
        timer->stop();
        timer->disconnect();
    }
}

//takes the mouse press event and plots the corresponding point on ui->customPlot (heart rate grapher)
void MainWindow::onMousePress(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(ui->customPlot->axisRect()->rect().contains(event->pos()))
        {
            xvalue = ui->customPlot->xAxis->pixelToCoord(event->x());
            double yvalue = ui->customPlot->yAxis->pixelToCoord(event->y());
            points->addData(xvalue,yvalue);
            ui->customPlot->replot();
            mMediaPlayer->setPosition(xvalue*(mMediaPlayer->duration())/((mMediaPlayer->duration())/1000));
            mMediaPlayer2->setPosition(xvalue*(mMediaPlayer->duration())/((mMediaPlayer->duration())/1000));
        }
    }
}

//takes the mouse press event and plots the corresponding point on ui->customPlot (heart rate grapher) for starting point
void MainWindow::onMousePressStart(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(ui->customPlot->axisRect()->rect().contains(event->pos()))
        {
            mMediaPlayer->pause();
            mMediaPlayer2->pause();
            points_starting->clearData();
            xvalue = ui->customPlot->xAxis->pixelToCoord(event->x());
            double yvalue = ui->customPlot->yAxis->pixelToCoord(event->y());
            points_starting->addData(xvalue,yvalue);
            ui->customPlot->replot();
            starting_point = xvalue;
            mMediaPlayer->setPosition(xvalue*(mMediaPlayer->duration())/((mMediaPlayer->duration())/1000));
            mMediaPlayer2->setPosition(xvalue*(mMediaPlayer->duration())/((mMediaPlayer->duration())/1000));
        }
    }
}

//takes the mouse press event and plots the corresponding point on ui->customPlot (heart rate grapher) for ending point
void MainWindow::onMousePressEnd(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(ui->customPlot->axisRect()->rect().contains(event->pos()))
        {
            mMediaPlayer->pause();
            mMediaPlayer2->pause();
            points_ending->clearData();
            xvalue = ui->customPlot->xAxis->pixelToCoord(event->x());
            double yvalue = ui->customPlot->yAxis->pixelToCoord(event->y());
            points_ending->addData(xvalue,yvalue);
            ui->customPlot->replot();
            ending_point = xvalue;
            mMediaPlayer->setPosition(xvalue*(mMediaPlayer->duration())/((mMediaPlayer->duration())/1000));
            mMediaPlayer2->setPosition(xvalue*(mMediaPlayer->duration())/((mMediaPlayer->duration())/1000));
        }
    }
}

// open a video file through "File > Open"
void MainWindow::on_actionOpen_triggered()
{
    // opens video file
    filename = QFileDialog::getOpenFileName(this,"Open a Video File","", "*.mp4 *.mov");
    if(filename.isEmpty()){
        QMessageBox::information(this, "File Status", "No video has been loaded.");
        return;
    }
    else{
        // set window title as the video file name
        QFile f(filename);
        QFileInfo fileInfo(f.fileName());
        QString filename_display(fileInfo.fileName());
        this->setWindowTitle(filename_display);

        mMediaPlayer->stop();
        mMediaPlayer2->stop();

        // sets 1st Video Output
        mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
        mMediaPlayer->play();
        mMediaPlayer->pause();

        // sets 2nd Video Output
        mMediaPlayer2->setMedia(QUrl::fromLocalFile(filename));
        mMediaPlayer2->play();
        mMediaPlayer2->pause();
        mMediaPlayer2->setVolume(0);

        // connects video players and slider to view and change video progress
        connect(mMediaPlayer, &QMediaPlayer::positionChanged, [&](qint64 pos){
            ui->progress->setValue(pos);
        });
        connect(mMediaPlayer, &QMediaPlayer::durationChanged, [&](qint64 dur){
            ui->progress->setMaximum(dur);
        });
        connect(mMediaPlayer2, &QMediaPlayer::positionChanged, [&](qint64 pos){
            ui->progress->setValue(pos);
        });
        connect(mMediaPlayer2, &QMediaPlayer::durationChanged, [&](qint64 dur){
            ui->progress->setMaximum(dur);
        });
        connect(ui->progress, &QSlider::sliderMoved, [&](qint64 pos){
            mMediaPlayer->setPosition(pos);
        });
        connect(ui->progress, &QSlider::sliderMoved, [&](qint64 pos){
            mMediaPlayer2->setPosition(pos);
        });

        //Message showing user movie has been loaded.
        QMessageBox::information(this, "File Status", filename_display + " has been loaded.");
    }
}

// open a video file through folder icon
void MainWindow::on_open_clicked()
{
    on_actionOpen_triggered();
}

// open a heart-rate txt file through "File" > "Load Heart-Rate Data"
void MainWindow::on_actionLoad_Data_triggered()
{
    on_load_clicked();
}

// open a gaze data text file through "File" > "Load Gaze Data"
void MainWindow::on_actionLoad_Gaze_Data_triggered()
{
    on_gaze_clicked();
}

// Error message for if video has not been opened.
void MainWindow::no_video_opened(){
    QMessageBox::information(this, "Error", "Please open video.");
    return;
}

//Error message for if heart-rate text file has not been opened.
void MainWindow::no_data_selected(){
    QMessageBox::information(this, "Error", "Please open data text file.");
    return;
}

/*"Top N Values" button method. Sorts the coordinate pairs of time (in seconds) and heart rate (in BPM) from heart-rate data text file
 * and allows the user to input most extreme N number values. Negative N integers look for the lowest BPMs and positive N integers look
 * for the greatest BPMs.
 */
void MainWindow::on_top_n_clicked()
{
    if(dataname.isEmpty()){
        no_data_selected();
    }
    else{
        if(ui->lineEdit->text() == ""){
            QMessageBox::information(this, "Error", "Please enter an integer.");
            return;
        }
        else{
            QMessageBox::information(this,"Top N Values","Searching for top " + ui->lineEdit->text() + " values.");
            number_of_n = (ui->lineEdit->text()).toInt();
            x_coord.resize(0);
            y_coord.resize(0);

            vector<pair<double,double>> a_and_b_pair;
            a_and_b_pair.resize(0);

            if(ui->graph_selector->value() == 1){
                for( int q = 0; q < a.size(); q++){
                    a_and_b_pair.push_back(make_pair(a[q], b[q]));
                }
            }
            else if(ui->graph_selector->value() == 2){
                for( int q = 0; q < a2.size(); q++){
                    a_and_b_pair.push_back(make_pair(a2[q], b2[q]));
                }
            }
            else if(ui->graph_selector->value() == 3){
                for( int q = 0; q < a3.size(); q++){
                    a_and_b_pair.push_back(make_pair(a3[q], b3[q]));
                }
            }
            else if(ui->graph_selector->value() == 4){
                for( int q = 0; q < a4.size(); q++){
                    a_and_b_pair.push_back(make_pair(a4[q], b4[q]));
                }
            }
            else if(ui->graph_selector->value() == 5){
                for( int q = 0; q < a5.size(); q++){
                    a_and_b_pair.push_back(make_pair(a5[q], b5[q]));
                }
            }
            else if(ui->graph_selector->value() == 6){
                for( int q = 0; q < a6.size(); q++){
                    a_and_b_pair.push_back(make_pair(a6[q], b6[q]));
                }
            }
            else if(ui->graph_selector->value() == 7){
                for( int q = 0; q < a7.size(); q++){
                    a_and_b_pair.push_back(make_pair(a7[q], b7[q]));
                }
            }
            else if(ui->graph_selector->value() == 8){
                for( int q = 0; q < a8.size(); q++){
                    a_and_b_pair.push_back(make_pair(a8[q], b8[q]));
                }
            }
            else if(ui->graph_selector->value() == 9){
                for( int q = 0; q < a9.size(); q++){
                    a_and_b_pair.push_back(make_pair(a9[q], b9[q]));
                }
            }
            else {
                for( int q = 0; q < a10.size(); q++){
                    a_and_b_pair.push_back(make_pair(a10[q], b10[q]));
                }
            }


            std::sort(a_and_b_pair.begin(), a_and_b_pair.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
                return left.second < right.second;
            });

            if(number_of_n <= 0){
                for(unsigned long i = 0; i < a_and_b_pair.size(); i++)
                {
                     x_coord.push_back(a_and_b_pair[i].first);
                     y_coord.push_back(a_and_b_pair[i].second);
                }
                x_coord.resize(number_of_n * -1);
                y_coord.resize(number_of_n * -1);
            }
            else{
                for(int i = a_and_b_pair.size() - 1; i > -1; i--)
                {
                     x_coord.push_back(a_and_b_pair[i].first);
                     y_coord.push_back(a_and_b_pair[i].second);
                }
                x_coord.resize(number_of_n);
                y_coord.resize(number_of_n);
            }
            bool valid_peak_number = true;
            for( unsigned long i = 0; i < x_coord.size(); ++i){
                if (x_coord[i] == 0 && y_coord[i] ==0){
                     valid_peak_number = false;
                }
            }

            if (valid_peak_number){
                ui->customPlot->replot();
                for( unsigned long i = 0; i < x_coord.size(); ++i){
                    double x_coord_as_double = x_coord[i];
                    double y_coord_as_double = y_coord[i];

                    if(ui->graph_selector->value() == 1){
                        ui->customPlot->addPlottable(top);
                        top->setAdaptiveSampling(false);
                        top->removeFromLegend();
                        top->setLineStyle(QCPGraph::lsNone);
                        top->setScatterStyle(QCPScatterStyle::ssDisc);
                        top->setPen(QPen(QBrush(Qt::red),3));
                        top->addData(x_coord_as_double,y_coord_as_double);
                    }
                    else if(ui->graph_selector->value() == 2){
                        ui->customPlot->addPlottable(top2);
                        top2->setAdaptiveSampling(false);
                        top2->removeFromLegend();
                        top2->setLineStyle(QCPGraph::lsNone);
                        top2->setScatterStyle(QCPScatterStyle::ssDisc);
                        top2->setPen(QPen(QBrush(Qt::darkGreen),3));
                        top2->addData(x_coord_as_double,y_coord_as_double);
                    }
                    else if(ui->graph_selector->value() == 3){
                        ui->customPlot->addPlottable(top3);
                        top3->setAdaptiveSampling(false);
                        top3->removeFromLegend();
                        top3->setLineStyle(QCPGraph::lsNone);
                        top3->setScatterStyle(QCPScatterStyle::ssDisc);
                        top3->setPen(QPen(QBrush(Qt::blue),3));
                        top3->addData(x_coord_as_double,y_coord_as_double);
                    }
                    else if(ui->graph_selector->value() == 4){
                        ui->customPlot->addPlottable(top4);
                        top4->setAdaptiveSampling(false);
                        top4->removeFromLegend();
                        top4->setLineStyle(QCPGraph::lsNone);
                        top4->setScatterStyle(QCPScatterStyle::ssDisc);
                        top4->setPen(QPen(QBrush(Qt::black),3));
                        top4->addData(x_coord_as_double,y_coord_as_double);
                    }
                    else if(ui->graph_selector->value() == 5){
                        ui->customPlot->addPlottable(top5);
                        top5->setAdaptiveSampling(false);
                        top5->removeFromLegend();
                        top5->setLineStyle(QCPGraph::lsNone);
                        top5->setScatterStyle(QCPScatterStyle::ssDisc);
                        top5->setPen(QPen(QBrush(Qt::darkCyan),3));
                        top5->addData(x_coord_as_double,y_coord_as_double);
                    }
                    else if(ui->graph_selector->value() == 6){
                        ui->customPlot->addPlottable(top6);
                        top6->setAdaptiveSampling(false);
                        top6->removeFromLegend();
                        top6->setLineStyle(QCPGraph::lsNone);
                        top6->setScatterStyle(QCPScatterStyle::ssDisc);
                        top6->setPen(QPen(QBrush(Qt::darkMagenta),3));
                        top6->addData(x_coord_as_double,y_coord_as_double);
                    }
                    else if(ui->graph_selector->value() == 7){
                        ui->customPlot->addPlottable(top7);
                        top7->setAdaptiveSampling(false);
                        top7->removeFromLegend();
                        top7->setLineStyle(QCPGraph::lsNone);
                        top7->setScatterStyle(QCPScatterStyle::ssDisc);
                        top7->setPen(QPen(QBrush(Qt::darkYellow),3));
                        top7->addData(x_coord_as_double,y_coord_as_double);
                    }
                    else if(ui->graph_selector->value() == 8){
                        ui->customPlot->addPlottable(top8);
                        top8->setAdaptiveSampling(false);
                        top8->removeFromLegend();
                        top8->setLineStyle(QCPGraph::lsNone);
                        top8->setScatterStyle(QCPScatterStyle::ssDisc);
                        top8->setPen(QPen(QBrush(Qt::darkRed),3));
                        top8->addData(x_coord_as_double,y_coord_as_double);
                    }
                    else if(ui->graph_selector->value() == 9){
                        ui->customPlot->addPlottable(top9);
                        top9->setAdaptiveSampling(false);
                        top9->removeFromLegend();
                        top9->setLineStyle(QCPGraph::lsNone);
                        top9->setScatterStyle(QCPScatterStyle::ssDisc);
                        top9->setPen(QPen(QBrush(Qt::darkGray),3));
                        top9->addData(x_coord_as_double,y_coord_as_double);
                    }
                    else {
                        ui->customPlot->addPlottable(top10);
                        top10->setAdaptiveSampling(false);
                        top10->removeFromLegend();
                        top10->setLineStyle(QCPGraph::lsNone);
                        top10->setScatterStyle(QCPScatterStyle::ssDisc);
                        top10->setPen(QPen(QBrush(Qt::darkBlue),3));
                        top10->addData(x_coord_as_double,y_coord_as_double);
                    }
                    ui->customPlot->replot();

                    QString x_coord_as_qstring = QString::number(x_coord_as_double);
                    QString y_coord_as_qstring = QString::number(y_coord_as_double);
                    QString nth_peak_as_qstring = QString::number(i + 1);
                    QMessageBox::information(this,"Top N Values", nth_peak_as_qstring + " : (" + x_coord_as_qstring + " seconds, " + y_coord_as_qstring + " BPM)");
                }
            }
            else{
                QMessageBox::information(this,"Title","Invalid Top N Value.");
            }
        }
    }
}

//Gaze (eye icon) button method.
void MainWindow::on_gaze_clicked()
{
    if(filename.isEmpty())
    {
        no_video_opened();
    }
    else{
        int n = QInputDialog::getInt(this,"Gaze Plot", "Enter Password");
        if(n == 123){
            gazeplot = new GazePlot(this);
            gazeplot->setGeometry( 64, 421, 793, 328 );
            connect(gazeplot,SIGNAL(playGazeClicked()),this,SLOT(playGazeClickedSlot()));
            gazeplot->show();
        }
        else{
            QMessageBox::information(this, "Error", "Incorrect Password.");
        }
    }
}

// Signal connected to "Play Gaze" button in gazeplot.ui and gazeplot.cpp
void MainWindow::playGazeClickedSlot(){
    on_play_clicked();
}

//Rescale x-axis of heart-rate plot
void MainWindow::on_rescale_x_axis_clicked()
{
    if(dataname.isEmpty()){
        no_data_selected();
    }
    else{
        if(ui->low_x_axis_line_edit->text() == "" || ui->high_x_axis_line_edit->text() == ""){
            QMessageBox::information(this, "Error", "Please enter lower and higher x-axis values.");
            return;
        }
        else{
            ui->customPlot->xAxis->setRangeLower(ui->low_x_axis_line_edit->text().toDouble());
            ui->customPlot->xAxis->setRangeUpper(ui->high_x_axis_line_edit->text().toDouble());
            ui->customPlot->replot();
        }
    }
}

//Rescale y-axis of heart-rate plot
void MainWindow::on_rescale_y_axis_clicked()
{
    if(dataname.isEmpty()){
        no_data_selected();
    }
    else{
        if(ui->low_y_axis_line_edit->text() == "" || ui->high_y_axis_line_edit->text() == ""){
            QMessageBox::information(this, "Error", "Please enter lower and higher y-axis values.");
            return;
        }
        else{
            ui->customPlot->yAxis->setRangeLower(ui->low_y_axis_line_edit->text().toDouble());
            ui->customPlot->yAxis->setRangeUpper(ui->high_y_axis_line_edit->text().toDouble());
            ui->customPlot->replot();
        }
    }
}
