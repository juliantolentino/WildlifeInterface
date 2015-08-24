/********************************************************************************
** Form generated from reading UI file 'gazeplot.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAZEPLOT_H
#define UI_GAZEPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_GazePlot
{
public:
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout;
    QCustomPlot *customPlot_gaze;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *play_gaze;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label;
    QDoubleSpinBox *delay;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QDoubleSpinBox *delay2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QDoubleSpinBox *delay3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QDoubleSpinBox *delay4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QDoubleSpinBox *delay5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *delay6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QDoubleSpinBox *delay7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QDoubleSpinBox *delay8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QDoubleSpinBox *delay9;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QDoubleSpinBox *delay10;
    QLabel *gp_legend;

    void setupUi(QWidget *GazePlot)
    {
        if (GazePlot->objectName().isEmpty())
            GazePlot->setObjectName(QStringLiteral("GazePlot"));
        GazePlot->setWindowModality(Qt::NonModal);
        GazePlot->resize(703, 328);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GazePlot->sizePolicy().hasHeightForWidth());
        GazePlot->setSizePolicy(sizePolicy);
        GazePlot->setWindowOpacity(0.6);
        horizontalLayout_12 = new QHBoxLayout(GazePlot);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        customPlot_gaze = new QCustomPlot(GazePlot);
        customPlot_gaze->setObjectName(QStringLiteral("customPlot_gaze"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(customPlot_gaze->sizePolicy().hasHeightForWidth());
        customPlot_gaze->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(customPlot_gaze);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(GazePlot);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setIconSize(QSize(16, 5));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(13, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        play_gaze = new QPushButton(GazePlot);
        play_gaze->setObjectName(QStringLiteral("play_gaze"));
        play_gaze->setIconSize(QSize(16, 5));

        horizontalLayout->addWidget(play_gaze);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_12->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_11 = new QLabel(GazePlot);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_11);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label = new QLabel(GazePlot);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_11->addWidget(label);

        delay = new QDoubleSpinBox(GazePlot);
        delay->setObjectName(QStringLiteral("delay"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(delay->sizePolicy().hasHeightForWidth());
        delay->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(8);
        delay->setFont(font);
        delay->setWrapping(false);
        delay->setFrame(false);
        delay->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay->setDecimals(3);

        horizontalLayout_11->addWidget(delay);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_2 = new QLabel(GazePlot);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(label_2);

        delay2 = new QDoubleSpinBox(GazePlot);
        delay2->setObjectName(QStringLiteral("delay2"));
        delay2->setFrame(false);
        delay2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay2->setDecimals(3);

        horizontalLayout_10->addWidget(delay2);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_3 = new QLabel(GazePlot);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(label_3);

        delay3 = new QDoubleSpinBox(GazePlot);
        delay3->setObjectName(QStringLiteral("delay3"));
        delay3->setFrame(false);
        delay3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay3->setDecimals(3);

        horizontalLayout_9->addWidget(delay3);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_4 = new QLabel(GazePlot);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(label_4);

        delay4 = new QDoubleSpinBox(GazePlot);
        delay4->setObjectName(QStringLiteral("delay4"));
        delay4->setFrame(false);
        delay4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay4->setDecimals(3);

        horizontalLayout_8->addWidget(delay4);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(GazePlot);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(label_5);

        delay5 = new QDoubleSpinBox(GazePlot);
        delay5->setObjectName(QStringLiteral("delay5"));
        delay5->setFrame(false);
        delay5->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay5->setDecimals(3);

        horizontalLayout_7->addWidget(delay5);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(GazePlot);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_6);

        delay6 = new QDoubleSpinBox(GazePlot);
        delay6->setObjectName(QStringLiteral("delay6"));
        delay6->setFrame(false);
        delay6->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay6->setDecimals(3);

        horizontalLayout_6->addWidget(delay6);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(GazePlot);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_7);

        delay7 = new QDoubleSpinBox(GazePlot);
        delay7->setObjectName(QStringLiteral("delay7"));
        delay7->setFrame(false);
        delay7->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay7->setDecimals(3);

        horizontalLayout_5->addWidget(delay7);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(GazePlot);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_8);

        delay8 = new QDoubleSpinBox(GazePlot);
        delay8->setObjectName(QStringLiteral("delay8"));
        delay8->setFrame(false);
        delay8->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay8->setDecimals(3);

        horizontalLayout_4->addWidget(delay8);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(GazePlot);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_9);

        delay9 = new QDoubleSpinBox(GazePlot);
        delay9->setObjectName(QStringLiteral("delay9"));
        delay9->setFrame(false);
        delay9->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay9->setDecimals(3);

        horizontalLayout_3->addWidget(delay9);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_10 = new QLabel(GazePlot);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_10);

        delay10 = new QDoubleSpinBox(GazePlot);
        delay10->setObjectName(QStringLiteral("delay10"));
        delay10->setFrame(false);
        delay10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        delay10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delay10->setDecimals(3);

        horizontalLayout_2->addWidget(delay10);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_12->addLayout(verticalLayout_2);

        gp_legend = new QLabel(GazePlot);
        gp_legend->setObjectName(QStringLiteral("gp_legend"));
        QFont font1;
        font1.setPointSize(7);
        gp_legend->setFont(font1);
        gp_legend->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_12->addWidget(gp_legend);


        retranslateUi(GazePlot);

        QMetaObject::connectSlotsByName(GazePlot);
    } // setupUi

    void retranslateUi(QWidget *GazePlot)
    {
        GazePlot->setWindowTitle(QApplication::translate("GazePlot", "Gaze", 0));
        pushButton->setText(QApplication::translate("GazePlot", "Load Gaze", 0));
        play_gaze->setText(QApplication::translate("GazePlot", "Play/Pause Gaze and Video", 0));
        label_11->setText(QApplication::translate("GazePlot", "Add Delay", 0));
        label->setText(QApplication::translate("GazePlot", "1", 0));
        label_2->setText(QApplication::translate("GazePlot", "2", 0));
        label_3->setText(QApplication::translate("GazePlot", "3", 0));
        label_4->setText(QApplication::translate("GazePlot", "4", 0));
        label_5->setText(QApplication::translate("GazePlot", "5", 0));
        label_6->setText(QApplication::translate("GazePlot", "6", 0));
        label_7->setText(QApplication::translate("GazePlot", "7", 0));
        label_8->setText(QApplication::translate("GazePlot", "8", 0));
        label_9->setText(QApplication::translate("GazePlot", "9", 0));
        label_10->setText(QApplication::translate("GazePlot", "10", 0));
        gp_legend->setText(QApplication::translate("GazePlot", "Legend                                                    ", 0));
    } // retranslateUi

};

namespace Ui {
    class GazePlot: public Ui_GazePlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAZEPLOT_H
