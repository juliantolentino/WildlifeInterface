/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"
#include "qvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionLoad_Data;
    QAction *actionLoad_Gaze_Data;
    QAction *actionHelp;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *open;
    QPushButton *load;
    QPushButton *gaze;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpinBox *graph_selector;
    QLineEdit *lineEdit;
    QPushButton *top_n;
    QPushButton *starting;
    QPushButton *ending;
    QPushButton *interact;
    QPushButton *play;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QSlider *progress;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *low_x_axis_line_edit;
    QLineEdit *high_x_axis_line_edit;
    QPushButton *rescale_x_axis;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *low_y_axis_line_edit;
    QLineEdit *high_y_axis_line_edit;
    QPushButton *rescale_y_axis;
    QHBoxLayout *horizontalLayout_5;
    QCustomPlot *customPlot;
    QLabel *hr_legend;
    QHBoxLayout *horizontalLayout_2;
    QVideoWidget *mVideoWidget;
    QVideoWidget *mVideoWidget2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1250, 690);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(400, 300));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDocumentMode(true);
        MainWindow->setTabShape(QTabWidget::Triangular);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/open_file_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionLoad_Data = new QAction(MainWindow);
        actionLoad_Data->setObjectName(QStringLiteral("actionLoad_Data"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/load_data_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Data->setIcon(icon1);
        actionLoad_Gaze_Data = new QAction(MainWindow);
        actionLoad_Gaze_Data->setObjectName(QStringLiteral("actionLoad_Gaze_Data"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/load_gaze_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Gaze_Data->setIcon(icon2);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        open = new QPushButton(centralWidget);
        open->setObjectName(QStringLiteral("open"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(open->sizePolicy().hasHeightForWidth());
        open->setSizePolicy(sizePolicy1);
        open->setMinimumSize(QSize(0, 0));
        open->setMaximumSize(QSize(30, 30));
        open->setLayoutDirection(Qt::LeftToRight);
        open->setIconSize(QSize(20, 20));
        open->setFlat(true);

        horizontalLayout->addWidget(open);

        load = new QPushButton(centralWidget);
        load->setObjectName(QStringLiteral("load"));
        sizePolicy1.setHeightForWidth(load->sizePolicy().hasHeightForWidth());
        load->setSizePolicy(sizePolicy1);
        load->setMaximumSize(QSize(30, 30));
        load->setIconSize(QSize(20, 20));
        load->setFlat(true);

        horizontalLayout->addWidget(load);

        gaze = new QPushButton(centralWidget);
        gaze->setObjectName(QStringLiteral("gaze"));
        sizePolicy1.setHeightForWidth(gaze->sizePolicy().hasHeightForWidth());
        gaze->setSizePolicy(sizePolicy1);
        gaze->setMaximumSize(QSize(30, 30));
        gaze->setIconSize(QSize(20, 20));
        gaze->setFlat(true);

        horizontalLayout->addWidget(gaze);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        graph_selector = new QSpinBox(centralWidget);
        graph_selector->setObjectName(QStringLiteral("graph_selector"));

        horizontalLayout->addWidget(graph_selector);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(lineEdit);

        top_n = new QPushButton(centralWidget);
        top_n->setObjectName(QStringLiteral("top_n"));
        sizePolicy2.setHeightForWidth(top_n->sizePolicy().hasHeightForWidth());
        top_n->setSizePolicy(sizePolicy2);
        top_n->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(8);
        top_n->setFont(font);

        horizontalLayout->addWidget(top_n);

        starting = new QPushButton(centralWidget);
        starting->setObjectName(QStringLiteral("starting"));
        sizePolicy2.setHeightForWidth(starting->sizePolicy().hasHeightForWidth());
        starting->setSizePolicy(sizePolicy2);
        starting->setMinimumSize(QSize(0, 0));
        starting->setFont(font);

        horizontalLayout->addWidget(starting);

        ending = new QPushButton(centralWidget);
        ending->setObjectName(QStringLiteral("ending"));
        sizePolicy2.setHeightForWidth(ending->sizePolicy().hasHeightForWidth());
        ending->setSizePolicy(sizePolicy2);
        ending->setMinimumSize(QSize(0, 0));
        ending->setFont(font);

        horizontalLayout->addWidget(ending);

        interact = new QPushButton(centralWidget);
        interact->setObjectName(QStringLiteral("interact"));
        sizePolicy2.setHeightForWidth(interact->sizePolicy().hasHeightForWidth());
        interact->setSizePolicy(sizePolicy2);
        interact->setMinimumSize(QSize(0, 0));
        interact->setFont(font);
        interact->setFlat(false);

        horizontalLayout->addWidget(interact);

        play = new QPushButton(centralWidget);
        play->setObjectName(QStringLiteral("play"));
        sizePolicy2.setHeightForWidth(play->sizePolicy().hasHeightForWidth());
        play->setSizePolicy(sizePolicy2);
        play->setMinimumSize(QSize(0, 0));
        play->setFont(font);

        horizontalLayout->addWidget(play);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(65, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        progress = new QSlider(centralWidget);
        progress->setObjectName(QStringLiteral("progress"));
        progress->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(progress);

        horizontalSpacer_4 = new QSpacerItem(15, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        low_x_axis_line_edit = new QLineEdit(centralWidget);
        low_x_axis_line_edit->setObjectName(QStringLiteral("low_x_axis_line_edit"));
        sizePolicy2.setHeightForWidth(low_x_axis_line_edit->sizePolicy().hasHeightForWidth());
        low_x_axis_line_edit->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(low_x_axis_line_edit);

        high_x_axis_line_edit = new QLineEdit(centralWidget);
        high_x_axis_line_edit->setObjectName(QStringLiteral("high_x_axis_line_edit"));
        sizePolicy2.setHeightForWidth(high_x_axis_line_edit->sizePolicy().hasHeightForWidth());
        high_x_axis_line_edit->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(high_x_axis_line_edit);

        rescale_x_axis = new QPushButton(centralWidget);
        rescale_x_axis->setObjectName(QStringLiteral("rescale_x_axis"));

        horizontalLayout_3->addWidget(rescale_x_axis);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        low_y_axis_line_edit = new QLineEdit(centralWidget);
        low_y_axis_line_edit->setObjectName(QStringLiteral("low_y_axis_line_edit"));
        sizePolicy2.setHeightForWidth(low_y_axis_line_edit->sizePolicy().hasHeightForWidth());
        low_y_axis_line_edit->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(low_y_axis_line_edit);

        high_y_axis_line_edit = new QLineEdit(centralWidget);
        high_y_axis_line_edit->setObjectName(QStringLiteral("high_y_axis_line_edit"));
        sizePolicy2.setHeightForWidth(high_y_axis_line_edit->sizePolicy().hasHeightForWidth());
        high_y_axis_line_edit->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(high_y_axis_line_edit);

        rescale_y_axis = new QPushButton(centralWidget);
        rescale_y_axis->setObjectName(QStringLiteral("rescale_y_axis"));

        horizontalLayout_3->addWidget(rescale_y_axis);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy3);
        customPlot->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(customPlot);

        hr_legend = new QLabel(centralWidget);
        hr_legend->setObjectName(QStringLiteral("hr_legend"));
        QFont font1;
        font1.setPointSize(7);
        hr_legend->setFont(font1);
        hr_legend->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_5->addWidget(hr_legend);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mVideoWidget = new QVideoWidget(centralWidget);
        mVideoWidget->setObjectName(QStringLiteral("mVideoWidget"));
        mVideoWidget->setAutoFillBackground(false);
        mVideoWidget->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 255));"));

        horizontalLayout_2->addWidget(mVideoWidget);

        mVideoWidget2 = new QVideoWidget(centralWidget);
        mVideoWidget2->setObjectName(QStringLiteral("mVideoWidget2"));
        mVideoWidget2->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 255));"));

        horizontalLayout_2->addWidget(mVideoWidget2);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 1250, 21));
        menuBar->setToolTipDuration(-1);
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(interact, play);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionLoad_Data);
        menuFile->addAction(actionLoad_Gaze_Data);
        menuHelp->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        actionOpen->setText(QApplication::translate("MainWindow", "Open Video", 0));
        actionLoad_Data->setText(QApplication::translate("MainWindow", "Load Heart-Rate Data", 0));
        actionLoad_Gaze_Data->setText(QApplication::translate("MainWindow", "Load Gaze Data", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Interface Help", 0));
        open->setText(QString());
        load->setText(QString());
        gaze->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Subject", 0));
        top_n->setText(QApplication::translate("MainWindow", "Top N Values", 0));
        starting->setText(QApplication::translate("MainWindow", "Select Start", 0));
        ending->setText(QApplication::translate("MainWindow", "Select End", 0));
        interact->setText(QApplication::translate("MainWindow", "Interact with Graph", 0));
        play->setText(QApplication::translate("MainWindow", "Play/Pause", 0));
        rescale_x_axis->setText(QApplication::translate("MainWindow", "Rescale x-axis", 0));
        rescale_y_axis->setText(QApplication::translate("MainWindow", "Rescale y-axis", 0));
        hr_legend->setText(QApplication::translate("MainWindow", "Legend                                 ", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
