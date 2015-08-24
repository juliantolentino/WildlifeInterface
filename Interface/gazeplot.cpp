// the CPP file of the gaze plot
#include "gazeplot.h"
#include "ui_gazeplot.h"
#include <math.h>
#include <iostream>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QApplication>
#include <QProcess>
#include <QMessageBox>
#include <QFileInfo>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <qgraphicseffect.h>
#include <iomanip>
#include <QGraphicsVideoItem>
#include <QDoubleValidator>

using namespace std;

QString dataname_gaze;
extern double xvalue, starting_point, ending_point;
double cnt_gaze,cnt_gaze2,cnt_gaze3,cnt_gaze4,cnt_gaze5,cnt_gaze6,cnt_gaze7,cnt_gaze8,cnt_gaze9,cnt_gaze10,
    timestamp_matcher,timestamp_matcher2,timestamp_matcher3,timestamp_matcher4,timestamp_matcher5,timestamp_matcher6,timestamp_matcher7,timestamp_matcher8,timestamp_matcher9,timestamp_matcher10,
    iTemp,iTemp2,iTemp3,iTemp4,iTemp5,iTemp6,iTemp7,iTemp8,iTemp9,iTemp10;
int gaze_plots_count;
QVector<double> timestamp_gaze,timestamp_gaze2,timestamp_gaze3,timestamp_gaze4,timestamp_gaze5,timestamp_gaze6,timestamp_gaze7,timestamp_gaze8,timestamp_gaze9,timestamp_gaze10;
QVector<double> x_gaze,y_gaze,x_gaze2,y_gaze2,x_gaze3,y_gaze3,x_gaze4,y_gaze4,x_gaze5,y_gaze5,x_gaze6,y_gaze6,x_gaze7,y_gaze7,x_gaze8,y_gaze8,x_gaze9,y_gaze9,x_gaze10,y_gaze10;
QVector<double> pupil_gaze;
QVector<double> curr_gaze_point_x, curr_gaze_point_y,curr_gaze_point_x2,curr_gaze_point_y2,curr_gaze_point_x3,curr_gaze_point_y3,curr_gaze_point_x4,curr_gaze_point_y4,curr_gaze_point_x5,curr_gaze_point_y5,curr_gaze_point_x6,curr_gaze_point_y6,curr_gaze_point_x7,curr_gaze_point_y7,curr_gaze_point_x8,curr_gaze_point_y8,curr_gaze_point_x9,curr_gaze_point_y9,curr_gaze_point_x10,curr_gaze_point_y10;
QString gp_legend_qstring;

GazePlot::GazePlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GazePlot)
{
    ui->setupUi(this);

    // customizes gaze plot
    ui->customPlot_gaze->setStyleSheet("background:hsva(255,255,255,0%);");
    ui->customPlot_gaze->setBackground(QBrush(Qt::NoBrush));
    ui->customPlot_gaze->xAxis->setRangeLower(0);
    ui->customPlot_gaze->yAxis->setRangeLower(0);
    ui->customPlot_gaze->xAxis->setRangeLower(1680);
    ui->customPlot_gaze->yAxis->setRangeLower(1050);
    ui->customPlot_gaze->axisRect()->setAutoMargins(QCP::msNone);
    ui->customPlot_gaze->axisRect()->setMargins(QMargins(1,1,1,1));

    //initializes timer for gaze plot
    timer_gaze = new QTimer(this);

    //declares QSpinBoxes for gaze plot delay times
    ui->delay->setRange(-5,5);
    ui->delay2->setRange(-5,5);
    ui->delay3->setRange(-5,5);
    ui->delay4->setRange(-5,5);
}

GazePlot::~GazePlot()
{
    delete ui;
}

// "Play Gaze" button. Plays the gaze plot and parses information into QVectors
void GazePlot::on_play_gaze_clicked()
{
    if(dataname_gaze.isEmpty()){
        return;
    }
    else if(!timer_gaze->isActive()){
        if(starting_point == 0){
            if(xvalue != 0){
                // uses delay values to synchronize gaze plots with video.
                if(gaze_plots_count > 0){
                    timestamp_matcher = xvalue * 1000000 - (ui->delay->value()*1000000);
                    cnt_gaze = timestamp_gaze[timestamp_gaze.size()-1] - timestamp_matcher;
                    iTemp = 0;
                }
                if(gaze_plots_count > 1){
                    timestamp_matcher2 = xvalue * 1000000 - (ui->delay2->value()*1000000);
                    cnt_gaze2 = timestamp_gaze2[timestamp_gaze2.size()-1] - timestamp_matcher2;
                    iTemp2 = 0;
                }
                if(gaze_plots_count > 2){
                    timestamp_matcher3 = xvalue * 1000000 - (ui->delay3->value()*1000000);
                    cnt_gaze3 = timestamp_gaze3[timestamp_gaze3.size()-1] - timestamp_matcher3;
                    iTemp3 = 0;
                }
                if(gaze_plots_count > 3){
                    timestamp_matcher4 = xvalue * 1000000 - (ui->delay4->value()*1000000);
                    cnt_gaze4 = timestamp_gaze4[timestamp_gaze4.size()-1] - timestamp_matcher4;
                    iTemp4 = 0;
                }
                if(gaze_plots_count > 4){
                    timestamp_matcher5 = xvalue * 1000000 - (ui->delay5->value()*1000000);
                    cnt_gaze5 = timestamp_gaze5[timestamp_gaze5.size()-1] - timestamp_matcher5;
                    iTemp5 = 0;
                }
                if(gaze_plots_count > 5){
                    timestamp_matcher6 = xvalue * 1000000 - (ui->delay6->value()*1000000);
                    cnt_gaze6 = timestamp_gaze6[timestamp_gaze6.size()-1] - timestamp_matcher6;
                    iTemp6 = 0;
                }
                if(gaze_plots_count > 6){
                    timestamp_matcher7 = xvalue * 1000000 - (ui->delay7->value()*1000000);
                    cnt_gaze7 = timestamp_gaze7[timestamp_gaze7.size()-1] - timestamp_matcher7;
                    iTemp7 = 0;
                }
                if(gaze_plots_count > 7){
                    timestamp_matcher8 = xvalue * 1000000 - (ui->delay8->value()*1000000);
                    cnt_gaze8 = timestamp_gaze8[timestamp_gaze8.size()-1] - timestamp_matcher8;
                    iTemp8 = 0;
                }
                if(gaze_plots_count > 8){
                    timestamp_matcher9 = xvalue * 1000000 - (ui->delay9->value()*1000000);
                    cnt_gaze9 = timestamp_gaze9[timestamp_gaze9.size()-1] - timestamp_matcher9;
                    iTemp9 = 0;
                }
                if(gaze_plots_count > 9){
                    timestamp_matcher10 = xvalue * 1000000 - (ui->delay10->value()*1000000);
                    cnt_gaze10 = timestamp_gaze10[timestamp_gaze10.size()-1] - timestamp_matcher10;
                    iTemp10 = 0;
                }
            }
            //updated every 10 milliseconds.
            timer_gaze->setInterval(10);
            timer_gaze->disconnect();
            connect(timer_gaze,SIGNAL(timeout()),this,SLOT(timer_gaze_function()));
            timer_gaze->start();
            emit(playGazeClicked());
        }
        else{
            // uses delay and starting point values to synchronize gaze plots with video.
            if(gaze_plots_count > 0){
                timestamp_matcher = starting_point * 1000000 - (ui->delay->value()*1000000);
                cnt_gaze = timestamp_gaze[timestamp_gaze.size()-1] - timestamp_matcher;
                iTemp = 0;
            }
            if(gaze_plots_count > 1){
                timestamp_matcher2 = starting_point * 1000000 - (ui->delay2->value()*1000000);
                cnt_gaze2 = timestamp_gaze2[timestamp_gaze2.size()-1] - timestamp_matcher2;
                iTemp2 = 0;
            }
            if(gaze_plots_count > 2){
                timestamp_matcher3 = starting_point * 1000000 - (ui->delay3->value()*1000000);
                cnt_gaze3 = timestamp_gaze3[timestamp_gaze3.size()-1] - timestamp_matcher3;
                iTemp3 = 0;
            }
            if(gaze_plots_count > 3){
                timestamp_matcher4 = starting_point * 1000000 - (ui->delay4->value()*1000000);
                cnt_gaze4 = timestamp_gaze4[timestamp_gaze4.size()-1] - timestamp_matcher4;
                iTemp4 = 0;
            }
            if(gaze_plots_count > 4){
                timestamp_matcher5 = starting_point * 1000000 - (ui->delay5->value()*1000000);
                cnt_gaze5 = timestamp_gaze5[timestamp_gaze5.size()-1] - timestamp_matcher5;
                iTemp5 = 0;
            }
            if(gaze_plots_count > 5){
                timestamp_matcher6 = starting_point * 1000000 - (ui->delay6->value()*1000000);
                cnt_gaze6 = timestamp_gaze6[timestamp_gaze6.size()-1] - timestamp_matcher6;
                iTemp6 = 0;
            }
            if(gaze_plots_count > 6){
                timestamp_matcher7 = starting_point * 1000000 - (ui->delay7->value()*1000000);
                cnt_gaze7 = timestamp_gaze7[timestamp_gaze7.size()-1] - timestamp_matcher7;
                iTemp7 = 0;
            }
            if(gaze_plots_count > 7){
                timestamp_matcher8 = starting_point * 1000000 - (ui->delay8->value()*1000000);
                cnt_gaze8 = timestamp_gaze8[timestamp_gaze8.size()-1] - timestamp_matcher8;
                iTemp8 = 0;
            }
            if(gaze_plots_count > 8){
                timestamp_matcher9 = starting_point * 1000000 - (ui->delay9->value()*1000000);
                cnt_gaze9 = timestamp_gaze9[timestamp_gaze9.size()-1] - timestamp_matcher9;
                iTemp9 = 0;
            }
            if(gaze_plots_count > 9){
                timestamp_matcher10 = starting_point * 1000000 - (ui->delay10->value()*1000000);
                cnt_gaze10 = timestamp_gaze10[timestamp_gaze10.size()-1] - timestamp_matcher10;
                iTemp10 = 0;
            }

            //updated every 10 milliseconds.
            timer_gaze->setInterval(10);
            timer_gaze->disconnect();
            connect(timer_gaze,SIGNAL(timeout()),this,SLOT(timer_gaze_function()));
            timer_gaze->start();
            emit(playGazeClicked());
        }
    }
    else{
        timer_gaze->stop();
        emit(playGazeClicked());
    }
}

//"Load Gaze" button. Opens gaze data.
void GazePlot::on_pushButton_clicked()
{
    //opens gaze data .txt file.
    dataname_gaze = QFileDialog::getOpenFileName(this,"Open a Gaze Coordinates Text File","","*.txt");
    if(dataname_gaze.isEmpty()){
        QMessageBox::information(this, "File Status", "No gaze coordinates data was loaded.");
        return;
    }
    QFile textFile(dataname_gaze);
    QVector<QString> v;
    QFile dg(dataname_gaze);
    QFileInfo dgInfo(dg.fileName());
    QString dataname_gaze_display(dgInfo.fileName());
    if(textFile.open(QIODevice::ReadOnly))
    {
        // parses gaze data text file and inputs into QVectors
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
        if(gaze_plots_count == 0){
            timestamp_gaze.resize(v.size()-1);
            x_gaze.resize(v.size()-1), y_gaze.resize(v.size()-1);
        }
        if(gaze_plots_count == 1){
            timestamp_gaze2.resize(v.size()-1);
            x_gaze2.resize(v.size()-1), y_gaze2.resize(v.size()-1);
        }
        if(gaze_plots_count == 2){
            timestamp_gaze3.resize(v.size()-1);
            x_gaze3.resize(v.size()-1), y_gaze3.resize(v.size()-1);
        }
        if(gaze_plots_count == 3){
            timestamp_gaze4.resize(v.size()-1);
            x_gaze4.resize(v.size()-1), y_gaze4.resize(v.size()-1);
        }
        if(gaze_plots_count == 4){
            timestamp_gaze5.resize(v.size()-1);
            x_gaze5.resize(v.size()-1), y_gaze5.resize(v.size()-1);
        }
        if(gaze_plots_count == 5){
            timestamp_gaze6.resize(v.size()-1);
            x_gaze6.resize(v.size()-1), y_gaze6.resize(v.size()-1);
        }
        if(gaze_plots_count == 6){
            timestamp_gaze7.resize(v.size()-1);
            x_gaze7.resize(v.size()-1), y_gaze7.resize(v.size()-1);
        }
        if(gaze_plots_count == 7){
            timestamp_gaze8.resize(v.size()-1);
            x_gaze8.resize(v.size()-1), y_gaze8.resize(v.size()-1);
        }
        if(gaze_plots_count == 8){
            timestamp_gaze9.resize(v.size()-1);
            x_gaze9.resize(v.size()-1), y_gaze9.resize(v.size()-1);
        }
        if(gaze_plots_count == 9){
            timestamp_gaze10.resize(v.size()-1);
            x_gaze10.resize(v.size()-1), y_gaze10.resize(v.size()-1);
        }
         pupil_gaze.resize(v.size()-1);
        for(int i=1; i<v.size(); ++i){
            string v_i_as_string = v[i].toUtf8().constData();
            int comma_pos = v_i_as_string.find(",");
            int comma_pos2 = v_i_as_string.find(",",comma_pos+1,1);
            int comma_pos3 = v_i_as_string.find(",",comma_pos2+1,1);
            double timestamp_double = stod(v_i_as_string.substr(0,comma_pos));
            double x_double = stod(v_i_as_string.substr(comma_pos+1,comma_pos2));
            double y_double = stod(v_i_as_string.substr(comma_pos2+1,comma_pos3));
            double pupil_double = stod(v_i_as_string.substr(comma_pos3+1,v_i_as_string.length()));
            if(gaze_plots_count == 0){
                timestamp_gaze[i-1] = timestamp_double;
                x_gaze[i-1] = x_double;
                y_gaze[i-1] = 1050-y_double;
            }
            if(gaze_plots_count == 1){
                timestamp_gaze2[i-1] = timestamp_double;
                x_gaze2[i-1] = x_double;
                y_gaze2[i-1] = 1050-y_double;
            }
            if(gaze_plots_count == 2){
                timestamp_gaze3[i-1] = timestamp_double;
                x_gaze3[i-1] = x_double;
                y_gaze3[i-1] = 1050-y_double;
            }
            if(gaze_plots_count == 3){
                timestamp_gaze4[i-1] = timestamp_double;
                x_gaze4[i-1] = x_double;
                y_gaze4[i-1] = 1050-y_double;
            }
            if(gaze_plots_count == 4){
                timestamp_gaze5[i-1] = timestamp_double;
                x_gaze5[i-1] = x_double;
                y_gaze5[i-1] = 1050-y_double;
            }
            if(gaze_plots_count == 5){
                timestamp_gaze6[i-1] = timestamp_double;
                x_gaze6[i-1] = x_double;
                y_gaze6[i-1] = 1050-y_double;
            }
            if(gaze_plots_count == 6){
                timestamp_gaze7[i-1] = timestamp_double;
                x_gaze7[i-1] = x_double;
                y_gaze7[i-1] = 1050-y_double;
            }
            if(gaze_plots_count == 7){
                timestamp_gaze8[i-1] = timestamp_double;
                x_gaze8[i-1] = x_double;
                y_gaze8[i-1] = 1050-y_double;
            }
            if(gaze_plots_count == 8){
                timestamp_gaze9[i-1] = timestamp_double;
                x_gaze9[i-1] = x_double;
                y_gaze9[i-1] = 1050-y_double;
            }
            if(gaze_plots_count == 9){
                timestamp_gaze10[i-1] = timestamp_double;
                x_gaze10[i-1] = x_double;
                y_gaze10[i-1] = 1050-y_double;
            }
            pupil_gaze[i-1] = pupil_double;
        }
        if(gaze_plots_count == 0){
            timestamp_matcher = -1 - (ui->delay->value()*1000000);
            cnt_gaze = (timestamp_gaze[timestamp_gaze.size()-1])-timestamp_matcher;
            ending_point = (timestamp_gaze[timestamp_gaze.size()-1])/1000000;
            iTemp = 0;
            gp_legend_qstring += "Legend\nRed: " + dataname_gaze_display;
        }
        if(gaze_plots_count == 1){
            timestamp_matcher2 = -1 - (ui->delay2->value()*1000000);
            cnt_gaze2 = (timestamp_gaze2[timestamp_gaze2.size()-1])-timestamp_matcher2;
            iTemp2 = 0;
            gp_legend_qstring += "\nDark Green: " + dataname_gaze_display;
        }
        if(gaze_plots_count == 2){
            timestamp_matcher3 = -1 - (ui->delay3->value()*1000000);
            cnt_gaze3 = (timestamp_gaze3[timestamp_gaze3.size()-1])-timestamp_matcher3;
            iTemp3 = 0;
            gp_legend_qstring += "\nBlue: " + dataname_gaze_display;
        }
        if(gaze_plots_count == 3){
            timestamp_matcher4 = -1 - (ui->delay4->value()*1000000);
            cnt_gaze4 = (timestamp_gaze4[timestamp_gaze4.size()-1])-timestamp_matcher4;
            iTemp4 = 0;
            gp_legend_qstring += "\nBlack: " + dataname_gaze_display;
        }
        if(gaze_plots_count == 4){
            timestamp_matcher5 = -1 - (ui->delay5->value()*1000000);
            cnt_gaze5 = (timestamp_gaze5[timestamp_gaze5.size()-1])-timestamp_matcher5;
            iTemp5 = 0;
            gp_legend_qstring += "\nDark Cyan: " + dataname_gaze_display;
        }
        if(gaze_plots_count == 5){
            timestamp_matcher6 = -1 - (ui->delay6->value()*1000000);
            cnt_gaze6 = (timestamp_gaze6[timestamp_gaze6.size()-1])-timestamp_matcher6;
            iTemp6 = 0;
            gp_legend_qstring += "\nDark Magenta: " + dataname_gaze_display;
        }
        if(gaze_plots_count == 6){
            timestamp_matcher7 = -1 - (ui->delay7->value()*1000000);
            cnt_gaze7 = (timestamp_gaze7[timestamp_gaze7.size()-1])-timestamp_matcher7;
            iTemp7 = 0;
            gp_legend_qstring += "\nDark Yellow: " + dataname_gaze_display;
        }
        if(gaze_plots_count == 7){
            timestamp_matcher8 = -1 - (ui->delay8->value()*1000000);
            cnt_gaze8 = (timestamp_gaze8[timestamp_gaze8.size()-1])-timestamp_matcher8;
            iTemp8 = 0;
            gp_legend_qstring += "\nDark Red: " + dataname_gaze_display;
        }
        if(gaze_plots_count == 8){
            timestamp_matcher9 = -1 - (ui->delay9->value()*1000000);
            cnt_gaze9 = (timestamp_gaze9[timestamp_gaze9.size()-1])-timestamp_matcher9;
            iTemp9 = 0;
            gp_legend_qstring += "\nDark Gray: " + dataname_gaze_display;
        }
        if(gaze_plots_count == 9){
            timestamp_matcher10 = -1 - (ui->delay10->value()*1000000);
            cnt_gaze10 = (timestamp_gaze10[timestamp_gaze10.size()-1])-timestamp_matcher10;
            iTemp10 = 0;
            gp_legend_qstring += "\nDark Blue: " + dataname_gaze_display;
        }
        ui->gp_legend->setText(gp_legend_qstring);
        ++gaze_plots_count;

        //Message showing user gaze coordinates data has been loaded.
        QMessageBox::information(this, "File Status", dataname_gaze_display + " has been loaded.");
    }
}

/*Method connected to timer_gaze. Updates the gaze plot (ui->customPlot_gaze).
 * Matches the timestamp of the gaze data txt file.
 */
void GazePlot::timer_gaze_function()
{
    if(cnt_gaze > 0 && ((timestamp_matcher/1000000) < ending_point))
    {
         if(gaze_plots_count > 0){
             double timestamp_max = timestamp_matcher;
             for(int i = iTemp; i < x_gaze.size(); ++i){
                 if((timestamp_gaze[i] >= timestamp_max) && (x_gaze[i] != -99 || y_gaze[i] != -99)){
                     ui->customPlot_gaze->clearGraphs();
                     ui->customPlot_gaze->addGraph();
                         curr_gaze_point_x.resize(0), curr_gaze_point_y.resize(0);
                         curr_gaze_point_x.push_back(x_gaze[i]);
                         curr_gaze_point_y.push_back(y_gaze[i]);
                         ui->customPlot_gaze->graph(0)->setData(curr_gaze_point_x,curr_gaze_point_y);
                         ui->customPlot_gaze->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::red, 7));
                         ui->customPlot_gaze->graph(0)->setLineStyle(QCPGraph::lsNone);
                         ui->customPlot_gaze->replot();
                     iTemp = i;
                     i = x_gaze.size();
                 }
             }
             cnt_gaze -= 10000;
             timestamp_matcher += 10000;
        }
         if(gaze_plots_count >1){
             double timestamp_max2=timestamp_matcher2;
             for(int i = iTemp2; i < x_gaze2.size(); ++i){
                 if((timestamp_gaze2[i] >= timestamp_max2) && (x_gaze2[i] != -99 || y_gaze2[i] != -99)){
                     curr_gaze_point_x2.resize(0), curr_gaze_point_y2.resize(0);
                     curr_gaze_point_x2.push_back(x_gaze2[i]);
                     curr_gaze_point_y2.push_back(y_gaze2[i]);
                     ui->customPlot_gaze->addGraph();
                     ui->customPlot_gaze->graph(1)->setData(curr_gaze_point_x2,curr_gaze_point_y2);
                     ui->customPlot_gaze->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::darkGreen, 7));
                     ui->customPlot_gaze->graph(1)->setLineStyle(QCPGraph::lsNone);
                     ui->customPlot_gaze->replot();
                     iTemp2 = i;
                     i = x_gaze2.size();
                 }
             }
             cnt_gaze2 -= 10000;
             timestamp_matcher2 += 10000;

         }
         if(gaze_plots_count >2){
             double timestamp_max3=timestamp_matcher3;
             for(int i = iTemp3; i < x_gaze3.size(); ++i){
                 if((timestamp_gaze3[i] >= timestamp_max3) && (x_gaze3[i] != -99 || y_gaze3[i] != -99)){
                     curr_gaze_point_x3.resize(0), curr_gaze_point_y3.resize(0);
                     curr_gaze_point_x3.push_back(x_gaze3[i]);
                     curr_gaze_point_y3.push_back(y_gaze3[i]);
                     ui->customPlot_gaze->addGraph();
                     ui->customPlot_gaze->graph(2)->setData(curr_gaze_point_x3,curr_gaze_point_y3);
                     ui->customPlot_gaze->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::blue, 7));
                     ui->customPlot_gaze->graph(2)->setLineStyle(QCPGraph::lsNone);
                     ui->customPlot_gaze->replot();
                     iTemp3 = i;
                     i = x_gaze3.size();
                 }
             }
             cnt_gaze3 -= 10000;
             timestamp_matcher3 += 10000;

         }
         if(gaze_plots_count >3){
             double timestamp_max4=timestamp_matcher4;
             for(int i = iTemp4; i < x_gaze4.size(); ++i){
                 if((timestamp_gaze4[i] >= timestamp_max4) && (x_gaze4[i] != -99 || y_gaze4[i] != -99)){
                     curr_gaze_point_x4.resize(0), curr_gaze_point_y4.resize(0);
                     curr_gaze_point_x4.push_back(x_gaze4[i]);
                     curr_gaze_point_y4.push_back(y_gaze4[i]);
                     ui->customPlot_gaze->addGraph();
                     ui->customPlot_gaze->graph(3)->setData(curr_gaze_point_x4,curr_gaze_point_y4);
                     ui->customPlot_gaze->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::black, 7));
                     ui->customPlot_gaze->graph(3)->setLineStyle(QCPGraph::lsNone);
                     ui->customPlot_gaze->replot();
                     iTemp4 = i;
                     i = x_gaze4.size();
                 }
             }
             cnt_gaze4 -= 10000;
             timestamp_matcher4 += 10000;

         }
         if(gaze_plots_count >4){
             double timestamp_max5=timestamp_matcher5;
             for(int i = iTemp5; i < x_gaze5.size(); ++i){
                 if((timestamp_gaze5[i] >= timestamp_max5) && (x_gaze5[i] != -99 || y_gaze5[i] != -99)){
                     curr_gaze_point_x5.resize(0), curr_gaze_point_y5.resize(0);
                     curr_gaze_point_x5.push_back(x_gaze5[i]);
                     curr_gaze_point_y5.push_back(y_gaze5[i]);
                     ui->customPlot_gaze->addGraph();
                     ui->customPlot_gaze->graph(4)->setData(curr_gaze_point_x5,curr_gaze_point_y5);
                     ui->customPlot_gaze->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::darkCyan, 7));
                     ui->customPlot_gaze->graph(4)->setLineStyle(QCPGraph::lsNone);
                     ui->customPlot_gaze->replot();
                     iTemp5 = i;
                     i = x_gaze5.size();
                 }
             }
             cnt_gaze5 -= 10000;
             timestamp_matcher5 += 10000;
         }
         if(gaze_plots_count >5){
             double timestamp_max6=timestamp_matcher6;
             for(int i = iTemp6; i < x_gaze6.size(); ++i){
                 if((timestamp_gaze6[i] >= timestamp_max6) && (x_gaze6[i] != -99 || y_gaze6[i] != -99)){
                     curr_gaze_point_x6.resize(0), curr_gaze_point_y6.resize(0);
                     curr_gaze_point_x6.push_back(x_gaze6[i]);
                     curr_gaze_point_y6.push_back(y_gaze6[i]);
                     ui->customPlot_gaze->addGraph();
                     ui->customPlot_gaze->graph(5)->setData(curr_gaze_point_x6,curr_gaze_point_y6);
                     ui->customPlot_gaze->graph(5)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::darkMagenta, 7));
                     ui->customPlot_gaze->graph(5)->setLineStyle(QCPGraph::lsNone);
                     ui->customPlot_gaze->replot();
                     iTemp6 = i;
                     i = x_gaze6.size();
                 }
             }
             cnt_gaze6 -= 10000;
             timestamp_matcher6 += 10000;
         }
         if(gaze_plots_count >6){
             double timestamp_max7=timestamp_matcher7;
             for(int i = iTemp7; i < x_gaze7.size(); ++i){
                 if((timestamp_gaze7[i] >= timestamp_max7) && (x_gaze7[i] != -99 || y_gaze7[i] != -99)){
                     curr_gaze_point_x7.resize(0), curr_gaze_point_y7.resize(0);
                     curr_gaze_point_x7.push_back(x_gaze7[i]);
                     curr_gaze_point_y7.push_back(y_gaze7[i]);
                     ui->customPlot_gaze->addGraph();
                     ui->customPlot_gaze->graph(6)->setData(curr_gaze_point_x7,curr_gaze_point_y7);
                     ui->customPlot_gaze->graph(6)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::darkYellow, 7));
                     ui->customPlot_gaze->graph(6)->setLineStyle(QCPGraph::lsNone);
                     ui->customPlot_gaze->replot();
                     iTemp7 = i;
                     i = x_gaze7.size();
                 }
             }
             cnt_gaze7 -= 10000;
             timestamp_matcher7 += 10000;
         }
         if(gaze_plots_count >7){
             double timestamp_max8=timestamp_matcher8;
             for(int i = iTemp8; i < x_gaze8.size(); ++i){
                 if((timestamp_gaze8[i] >= timestamp_max8) && (x_gaze8[i] != -99 || y_gaze8[i] != -99)){
                     curr_gaze_point_x8.resize(0), curr_gaze_point_y8.resize(0);
                     curr_gaze_point_x8.push_back(x_gaze8[i]);
                     curr_gaze_point_y8.push_back(y_gaze8[i]);
                     ui->customPlot_gaze->addGraph();
                     ui->customPlot_gaze->graph(7)->setData(curr_gaze_point_x8,curr_gaze_point_y8);
                     ui->customPlot_gaze->graph(7)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::darkRed, 7));
                     ui->customPlot_gaze->graph(7)->setLineStyle(QCPGraph::lsNone);
                     ui->customPlot_gaze->replot();
                     iTemp8 = i;
                     i = x_gaze8.size();
                 }
             }
             cnt_gaze8 -= 10000;
             timestamp_matcher8 += 10000;
         }
         if(gaze_plots_count >8){
             double timestamp_max9=timestamp_matcher9;
             for(int i = iTemp9; i < x_gaze9.size(); ++i){
                 if((timestamp_gaze9[i] >= timestamp_max9) && (x_gaze9[i] != -99 || y_gaze9[i] != -99)){
                     curr_gaze_point_x9.resize(0), curr_gaze_point_y9.resize(0);
                     curr_gaze_point_x9.push_back(x_gaze9[i]);
                     curr_gaze_point_y9.push_back(y_gaze9[i]);
                     ui->customPlot_gaze->addGraph();
                     ui->customPlot_gaze->graph(8)->setData(curr_gaze_point_x9,curr_gaze_point_y9);
                     ui->customPlot_gaze->graph(8)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::darkGray, 7));
                     ui->customPlot_gaze->graph(8)->setLineStyle(QCPGraph::lsNone);
                     ui->customPlot_gaze->replot();
                     iTemp9 = i;
                     i = x_gaze9.size();
                 }
             }
             cnt_gaze9 -= 10000;
             timestamp_matcher9 += 10000;
         }
         if(gaze_plots_count >9){
             double timestamp_max10=timestamp_matcher10;
             for(int i = iTemp10; i < x_gaze10.size(); ++i){
                 if((timestamp_gaze10[i] >= timestamp_max10) && (x_gaze10[i] != -99 || y_gaze10[i] != -99)){
                     curr_gaze_point_x10.resize(0), curr_gaze_point_y10.resize(0);
                     curr_gaze_point_x10.push_back(x_gaze10[i]);
                     curr_gaze_point_y10.push_back(y_gaze10[i]);
                     ui->customPlot_gaze->addGraph();
                     ui->customPlot_gaze->graph(9)->setData(curr_gaze_point_x10,curr_gaze_point_y10);
                     ui->customPlot_gaze->graph(9)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, Qt::darkBlue, 7));
                     ui->customPlot_gaze->graph(9)->setLineStyle(QCPGraph::lsNone);
                     ui->customPlot_gaze->replot();
                     iTemp10 = i;
                     i = x_gaze10.size();
                 }
             }
             cnt_gaze10 -= 10000;
             timestamp_matcher10 += 10000;
         }
    }
    else
    {
        timer_gaze->stop();
        timer_gaze->disconnect();
    }
}
