/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <glwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *layout_fileInformation;
    QLabel *label_fileInfo;
    QHBoxLayout *filePath_layout;
    QLabel *label_filepath;
    QLabel *label_filepathInfo;
    QHBoxLayout *verticesNumber_layout;
    QLabel *label_vertices_num;
    QLabel *label_verticesInfo;
    QHBoxLayout *edgesNumber_layout;
    QLabel *label_edges;
    QLabel *label_edgesNumber;
    QPushButton *open_file;
    QVBoxLayout *layout_rotateModel;
    QLabel *label_transformModel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *axisX_rotate_label;
    QDoubleSpinBox *rotateXInput;
    QSlider *rotationX_slider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *axisY_rotate_label;
    QDoubleSpinBox *rotateYInput;
    QSlider *rotationY_slider;
    QHBoxLayout *horizontalLayout_7;
    QLabel *axisZ_rotate_label;
    QDoubleSpinBox *rotateZInput;
    QSlider *rotationZ_slider;
    QVBoxLayout *layout_movingModel;
    QLabel *label_transformModel_2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *axisX_rotate_label_2;
    QDoubleSpinBox *moveXInput;
    QHBoxLayout *horizontalLayout_3;
    QLabel *axisX_rotate_label_3;
    QDoubleSpinBox *moveYInput;
    QHBoxLayout *horizontalLayout_4;
    QLabel *axisX_rotate_label_4;
    QDoubleSpinBox *moveZInput;
    QVBoxLayout *layout_scalingModel;
    QLabel *label_scaleModel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelScaleInput;
    QSpinBox *scaleSpinBox;
    QLabel *label;
    QSlider *scaleSlider;
    QPushButton *scaleToDefault;
    QVBoxLayout *layout_projectionType;
    QLabel *label_projectionType;
    QHBoxLayout *horizontalLayout_10;
    QRadioButton *radioButton_orthogonal;
    QRadioButton *radioButton_perspective;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *layout_edgesWidth;
    QLabel *label_settingsEdge;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelEdge_width;
    QSpinBox *edgeWidth_spinbox;
    QSlider *edgeWidth_slider;
    QHBoxLayout *layout_edgesType;
    QLabel *labelEdge_type;
    QRadioButton *radioButton_dotted;
    QRadioButton *radioButton_constant;
    QHBoxLayout *layout_edgesColor;
    QLabel *labelEdge_color;
    QLabel *label_colorEdges;
    QPushButton *pushButton_colorEdge;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *layout_verticesSettings;
    QLabel *label_settingsVerticle;
    QHBoxLayout *horizontalLayout_17;
    QLabel *labelVerticle_type;
    QRadioButton *radioButton_noneVertice;
    QRadioButton *radioButton_circleVertice;
    QRadioButton *radioButton_squareVertice;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_18;
    QLabel *labelVertice_size;
    QDoubleSpinBox *verticeSize_spinbox;
    QSlider *verticeSize_slider;
    QHBoxLayout *horizontalLayout_19;
    QLabel *labelVertice_color;
    QLabel *label_colorVertice;
    QPushButton *pushButton_colorVertice;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *layout_BackgroundColor;
    QLabel *label_backColor;
    QHBoxLayout *horizontalLayout_20;
    QLabel *labelBackg_color;
    QLabel *label_colorBackg;
    QPushButton *pushButton_colorBackg;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *layout_downloadImage;
    QLabel *label_downloadImage;
    QHBoxLayout *horizontalLayout_21;
    QLabel *labelImage;
    QRadioButton *radioButton_jpgFormat;
    QRadioButton *radioButton_bmpFormat;
    QPushButton *pushButton_downloadImage;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *layout_recordingGif;
    QLabel *label_recordGif;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Gif_mode_1;
    QPushButton *pushButton_Gif_mode_2;
    GLWidget *viewport;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1560, 1011);
        MainWindow->setWindowOpacity(1.000000000000000);
        MainWindow->setToolTipDuration(0);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setToolTipDuration(0);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(-1, 0, 0, 0);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMinimumSize(QSize(431, 0));
        scrollArea->setMaximumSize(QSize(430, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 429, 1009));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setObjectName("verticalLayout");
        layout_fileInformation = new QVBoxLayout();
        layout_fileInformation->setObjectName("layout_fileInformation");
        label_fileInfo = new QLabel(scrollAreaWidgetContents_2);
        label_fileInfo->setObjectName("label_fileInfo");
        label_fileInfo->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setBold(true);
        label_fileInfo->setFont(font);

        layout_fileInformation->addWidget(label_fileInfo);

        filePath_layout = new QHBoxLayout();
        filePath_layout->setSpacing(0);
        filePath_layout->setObjectName("filePath_layout");
        label_filepath = new QLabel(scrollAreaWidgetContents_2);
        label_filepath->setObjectName("label_filepath");
        label_filepath->setMinimumSize(QSize(0, 15));
        label_filepath->setMaximumSize(QSize(70, 16777215));
        QFont font1;
        font1.setItalic(true);
        label_filepath->setFont(font1);

        filePath_layout->addWidget(label_filepath);

        label_filepathInfo = new QLabel(scrollAreaWidgetContents_2);
        label_filepathInfo->setObjectName("label_filepathInfo");

        filePath_layout->addWidget(label_filepathInfo);


        layout_fileInformation->addLayout(filePath_layout);

        verticesNumber_layout = new QHBoxLayout();
        verticesNumber_layout->setSpacing(0);
        verticesNumber_layout->setObjectName("verticesNumber_layout");
        label_vertices_num = new QLabel(scrollAreaWidgetContents_2);
        label_vertices_num->setObjectName("label_vertices_num");
        label_vertices_num->setMinimumSize(QSize(15, 15));
        label_vertices_num->setMaximumSize(QSize(110, 16777215));
        label_vertices_num->setFont(font1);

        verticesNumber_layout->addWidget(label_vertices_num);

        label_verticesInfo = new QLabel(scrollAreaWidgetContents_2);
        label_verticesInfo->setObjectName("label_verticesInfo");

        verticesNumber_layout->addWidget(label_verticesInfo);


        layout_fileInformation->addLayout(verticesNumber_layout);

        edgesNumber_layout = new QHBoxLayout();
        edgesNumber_layout->setSpacing(0);
        edgesNumber_layout->setObjectName("edgesNumber_layout");
        label_edges = new QLabel(scrollAreaWidgetContents_2);
        label_edges->setObjectName("label_edges");
        label_edges->setMinimumSize(QSize(0, 15));
        label_edges->setMaximumSize(QSize(95, 16777215));
        label_edges->setFont(font1);

        edgesNumber_layout->addWidget(label_edges);

        label_edgesNumber = new QLabel(scrollAreaWidgetContents_2);
        label_edgesNumber->setObjectName("label_edgesNumber");

        edgesNumber_layout->addWidget(label_edgesNumber);


        layout_fileInformation->addLayout(edgesNumber_layout);

        open_file = new QPushButton(scrollAreaWidgetContents_2);
        open_file->setObjectName("open_file");
        open_file->setMaximumSize(QSize(120, 16777215));

        layout_fileInformation->addWidget(open_file);


        verticalLayout->addLayout(layout_fileInformation);

        layout_rotateModel = new QVBoxLayout();
        layout_rotateModel->setObjectName("layout_rotateModel");
        label_transformModel = new QLabel(scrollAreaWidgetContents_2);
        label_transformModel->setObjectName("label_transformModel");
        label_transformModel->setFont(font);

        layout_rotateModel->addWidget(label_transformModel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        axisX_rotate_label = new QLabel(scrollAreaWidgetContents_2);
        axisX_rotate_label->setObjectName("axisX_rotate_label");
        axisX_rotate_label->setMaximumSize(QSize(50, 16777215));
        axisX_rotate_label->setFont(font1);
        axisX_rotate_label->setIndent(0);

        horizontalLayout_5->addWidget(axisX_rotate_label);

        rotateXInput = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        rotateXInput->setObjectName("rotateXInput");
        rotateXInput->setMinimumSize(QSize(20, 0));
        rotateXInput->setMaximumSize(QSize(60, 16777215));
        rotateXInput->setMinimum(-360.000000000000000);
        rotateXInput->setMaximum(360.000000000000000);
        rotateXInput->setSingleStep(1.000000000000000);

        horizontalLayout_5->addWidget(rotateXInput);

        rotationX_slider = new QSlider(scrollAreaWidgetContents_2);
        rotationX_slider->setObjectName("rotationX_slider");
        rotationX_slider->setMinimum(-180);
        rotationX_slider->setMaximum(180);
        rotationX_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(rotationX_slider);


        layout_rotateModel->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        axisY_rotate_label = new QLabel(scrollAreaWidgetContents_2);
        axisY_rotate_label->setObjectName("axisY_rotate_label");
        axisY_rotate_label->setMaximumSize(QSize(50, 16777215));
        axisY_rotate_label->setFont(font1);
        axisY_rotate_label->setIndent(0);

        horizontalLayout_6->addWidget(axisY_rotate_label);

        rotateYInput = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        rotateYInput->setObjectName("rotateYInput");
        rotateYInput->setMinimumSize(QSize(20, 0));
        rotateYInput->setMaximumSize(QSize(60, 16777215));
        rotateYInput->setMinimum(-360.000000000000000);
        rotateYInput->setMaximum(360.000000000000000);
        rotateYInput->setSingleStep(1.000000000000000);

        horizontalLayout_6->addWidget(rotateYInput);

        rotationY_slider = new QSlider(scrollAreaWidgetContents_2);
        rotationY_slider->setObjectName("rotationY_slider");
        rotationY_slider->setMinimum(-180);
        rotationY_slider->setMaximum(180);
        rotationY_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(rotationY_slider);


        layout_rotateModel->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        axisZ_rotate_label = new QLabel(scrollAreaWidgetContents_2);
        axisZ_rotate_label->setObjectName("axisZ_rotate_label");
        axisZ_rotate_label->setMaximumSize(QSize(50, 16777215));
        axisZ_rotate_label->setFont(font1);
        axisZ_rotate_label->setIndent(0);

        horizontalLayout_7->addWidget(axisZ_rotate_label);

        rotateZInput = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        rotateZInput->setObjectName("rotateZInput");
        rotateZInput->setMinimumSize(QSize(20, 0));
        rotateZInput->setMaximumSize(QSize(60, 16777215));
        rotateZInput->setMinimum(-360.000000000000000);
        rotateZInput->setMaximum(360.000000000000000);
        rotateZInput->setSingleStep(1.000000000000000);

        horizontalLayout_7->addWidget(rotateZInput);

        rotationZ_slider = new QSlider(scrollAreaWidgetContents_2);
        rotationZ_slider->setObjectName("rotationZ_slider");
        rotationZ_slider->setMinimum(-180);
        rotationZ_slider->setMaximum(180);
        rotationZ_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(rotationZ_slider);


        layout_rotateModel->addLayout(horizontalLayout_7);


        verticalLayout->addLayout(layout_rotateModel);

        layout_movingModel = new QVBoxLayout();
        layout_movingModel->setObjectName("layout_movingModel");
        label_transformModel_2 = new QLabel(scrollAreaWidgetContents_2);
        label_transformModel_2->setObjectName("label_transformModel_2");
        label_transformModel_2->setFont(font);

        layout_movingModel->addWidget(label_transformModel_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        axisX_rotate_label_2 = new QLabel(scrollAreaWidgetContents_2);
        axisX_rotate_label_2->setObjectName("axisX_rotate_label_2");
        axisX_rotate_label_2->setMaximumSize(QSize(50, 16777215));
        axisX_rotate_label_2->setFont(font1);
        axisX_rotate_label_2->setIndent(0);

        horizontalLayout_2->addWidget(axisX_rotate_label_2);

        moveXInput = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        moveXInput->setObjectName("moveXInput");
        moveXInput->setMaximumSize(QSize(60, 16777215));
        moveXInput->setMinimum(-9999.989999999999782);
        moveXInput->setMaximum(9999.989999999999782);

        horizontalLayout_2->addWidget(moveXInput);


        horizontalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        axisX_rotate_label_3 = new QLabel(scrollAreaWidgetContents_2);
        axisX_rotate_label_3->setObjectName("axisX_rotate_label_3");
        axisX_rotate_label_3->setMaximumSize(QSize(50, 16777215));
        axisX_rotate_label_3->setFont(font1);
        axisX_rotate_label_3->setIndent(0);

        horizontalLayout_3->addWidget(axisX_rotate_label_3);

        moveYInput = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        moveYInput->setObjectName("moveYInput");
        moveYInput->setMaximumSize(QSize(60, 16777215));
        moveYInput->setMinimum(-9999.989999999999782);
        moveYInput->setMaximum(9999.989999999999782);

        horizontalLayout_3->addWidget(moveYInput);


        horizontalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        axisX_rotate_label_4 = new QLabel(scrollAreaWidgetContents_2);
        axisX_rotate_label_4->setObjectName("axisX_rotate_label_4");
        axisX_rotate_label_4->setMaximumSize(QSize(50, 16777215));
        axisX_rotate_label_4->setFont(font1);
        axisX_rotate_label_4->setIndent(0);

        horizontalLayout_4->addWidget(axisX_rotate_label_4);

        moveZInput = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        moveZInput->setObjectName("moveZInput");
        moveZInput->setMaximumSize(QSize(60, 16777215));
        moveZInput->setMinimum(-9999.989999999999782);
        moveZInput->setMaximum(9999.989999999999782);

        horizontalLayout_4->addWidget(moveZInput);


        horizontalLayout_8->addLayout(horizontalLayout_4);


        layout_movingModel->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(layout_movingModel);

        layout_scalingModel = new QVBoxLayout();
        layout_scalingModel->setObjectName("layout_scalingModel");
        label_scaleModel = new QLabel(scrollAreaWidgetContents_2);
        label_scaleModel->setObjectName("label_scaleModel");
        label_scaleModel->setFont(font);

        layout_scalingModel->addWidget(label_scaleModel);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        labelScaleInput = new QLabel(scrollAreaWidgetContents_2);
        labelScaleInput->setObjectName("labelScaleInput");
        labelScaleInput->setMinimumSize(QSize(50, 0));
        labelScaleInput->setMaximumSize(QSize(50, 16777215));
        labelScaleInput->setFont(font1);

        horizontalLayout_9->addWidget(labelScaleInput);

        scaleSpinBox = new QSpinBox(scrollAreaWidgetContents_2);
        scaleSpinBox->setObjectName("scaleSpinBox");
        scaleSpinBox->setMinimumSize(QSize(60, 0));
        scaleSpinBox->setMaximumSize(QSize(60, 16777215));
        scaleSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        scaleSpinBox->setMinimum(1);
        scaleSpinBox->setMaximum(1000);
        scaleSpinBox->setValue(100);

        horizontalLayout_9->addWidget(scaleSpinBox);

        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName("label");

        horizontalLayout_9->addWidget(label);

        scaleSlider = new QSlider(scrollAreaWidgetContents_2);
        scaleSlider->setObjectName("scaleSlider");
        scaleSlider->setMinimumSize(QSize(20, 0));
        scaleSlider->setMinimum(1);
        scaleSlider->setMaximum(1000);
        scaleSlider->setSliderPosition(100);
        scaleSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(scaleSlider);

        scaleToDefault = new QPushButton(scrollAreaWidgetContents_2);
        scaleToDefault->setObjectName("scaleToDefault");

        horizontalLayout_9->addWidget(scaleToDefault);


        layout_scalingModel->addLayout(horizontalLayout_9);


        verticalLayout->addLayout(layout_scalingModel);

        layout_projectionType = new QVBoxLayout();
        layout_projectionType->setObjectName("layout_projectionType");
        label_projectionType = new QLabel(scrollAreaWidgetContents_2);
        label_projectionType->setObjectName("label_projectionType");
        label_projectionType->setFont(font);

        layout_projectionType->addWidget(label_projectionType);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        radioButton_orthogonal = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_orthogonal->setObjectName("radioButton_orthogonal");

        horizontalLayout_10->addWidget(radioButton_orthogonal);

        radioButton_perspective = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_perspective->setObjectName("radioButton_perspective");

        horizontalLayout_10->addWidget(radioButton_perspective);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);


        layout_projectionType->addLayout(horizontalLayout_10);


        verticalLayout->addLayout(layout_projectionType);

        layout_edgesWidth = new QVBoxLayout();
        layout_edgesWidth->setObjectName("layout_edgesWidth");
        label_settingsEdge = new QLabel(scrollAreaWidgetContents_2);
        label_settingsEdge->setObjectName("label_settingsEdge");
        label_settingsEdge->setFont(font);

        layout_edgesWidth->addWidget(label_settingsEdge);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        labelEdge_width = new QLabel(scrollAreaWidgetContents_2);
        labelEdge_width->setObjectName("labelEdge_width");
        labelEdge_width->setMinimumSize(QSize(50, 0));
        labelEdge_width->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_14->addWidget(labelEdge_width);

        edgeWidth_spinbox = new QSpinBox(scrollAreaWidgetContents_2);
        edgeWidth_spinbox->setObjectName("edgeWidth_spinbox");
        edgeWidth_spinbox->setMinimumSize(QSize(60, 0));
        edgeWidth_spinbox->setMaximumSize(QSize(60, 16777215));
        edgeWidth_spinbox->setMinimum(1);
        edgeWidth_spinbox->setMaximum(21);

        horizontalLayout_14->addWidget(edgeWidth_spinbox);

        edgeWidth_slider = new QSlider(scrollAreaWidgetContents_2);
        edgeWidth_slider->setObjectName("edgeWidth_slider");
        edgeWidth_slider->setMinimumSize(QSize(200, 0));
        edgeWidth_slider->setMinimum(1);
        edgeWidth_slider->setMaximum(21);
        edgeWidth_slider->setPageStep(1);
        edgeWidth_slider->setValue(1);
        edgeWidth_slider->setSliderPosition(1);
        edgeWidth_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_14->addWidget(edgeWidth_slider);


        layout_edgesWidth->addLayout(horizontalLayout_14);


        verticalLayout->addLayout(layout_edgesWidth);

        layout_edgesType = new QHBoxLayout();
        layout_edgesType->setObjectName("layout_edgesType");
        labelEdge_type = new QLabel(scrollAreaWidgetContents_2);
        labelEdge_type->setObjectName("labelEdge_type");
        labelEdge_type->setMinimumSize(QSize(50, 0));
        labelEdge_type->setMaximumSize(QSize(50, 16777215));
        labelEdge_type->setFont(font1);

        layout_edgesType->addWidget(labelEdge_type);

        radioButton_dotted = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_dotted->setObjectName("radioButton_dotted");
        radioButton_dotted->setMaximumSize(QSize(65, 16777215));

        layout_edgesType->addWidget(radioButton_dotted);

        radioButton_constant = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_constant->setObjectName("radioButton_constant");

        layout_edgesType->addWidget(radioButton_constant);


        verticalLayout->addLayout(layout_edgesType);

        layout_edgesColor = new QHBoxLayout();
        layout_edgesColor->setObjectName("layout_edgesColor");
        labelEdge_color = new QLabel(scrollAreaWidgetContents_2);
        labelEdge_color->setObjectName("labelEdge_color");
        labelEdge_color->setFont(font1);

        layout_edgesColor->addWidget(labelEdge_color);

        label_colorEdges = new QLabel(scrollAreaWidgetContents_2);
        label_colorEdges->setObjectName("label_colorEdges");

        layout_edgesColor->addWidget(label_colorEdges);

        pushButton_colorEdge = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_colorEdge->setObjectName("pushButton_colorEdge");

        layout_edgesColor->addWidget(pushButton_colorEdge);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_edgesColor->addItem(horizontalSpacer);


        verticalLayout->addLayout(layout_edgesColor);

        layout_verticesSettings = new QVBoxLayout();
        layout_verticesSettings->setObjectName("layout_verticesSettings");
        label_settingsVerticle = new QLabel(scrollAreaWidgetContents_2);
        label_settingsVerticle->setObjectName("label_settingsVerticle");
        label_settingsVerticle->setFont(font);

        layout_verticesSettings->addWidget(label_settingsVerticle);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        labelVerticle_type = new QLabel(scrollAreaWidgetContents_2);
        labelVerticle_type->setObjectName("labelVerticle_type");
        labelVerticle_type->setMinimumSize(QSize(50, 0));
        labelVerticle_type->setMaximumSize(QSize(50, 16777215));
        labelVerticle_type->setFont(font1);

        horizontalLayout_17->addWidget(labelVerticle_type);

        radioButton_noneVertice = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_noneVertice->setObjectName("radioButton_noneVertice");

        horizontalLayout_17->addWidget(radioButton_noneVertice);

        radioButton_circleVertice = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_circleVertice->setObjectName("radioButton_circleVertice");

        horizontalLayout_17->addWidget(radioButton_circleVertice);

        radioButton_squareVertice = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_squareVertice->setObjectName("radioButton_squareVertice");

        horizontalLayout_17->addWidget(radioButton_squareVertice);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_5);


        layout_verticesSettings->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        labelVertice_size = new QLabel(scrollAreaWidgetContents_2);
        labelVertice_size->setObjectName("labelVertice_size");
        labelVertice_size->setMinimumSize(QSize(50, 0));
        labelVertice_size->setMaximumSize(QSize(50, 16777215));
        labelVertice_size->setFont(font1);
        labelVertice_size->setIndent(0);

        horizontalLayout_18->addWidget(labelVertice_size);

        verticeSize_spinbox = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        verticeSize_spinbox->setObjectName("verticeSize_spinbox");
        verticeSize_spinbox->setMaximumSize(QSize(60, 16777215));
        verticeSize_spinbox->setDecimals(1);
        verticeSize_spinbox->setMinimum(0.100000000000000);
        verticeSize_spinbox->setMaximum(21.000000000000000);
        verticeSize_spinbox->setSingleStep(0.100000000000000);
        verticeSize_spinbox->setValue(1.000000000000000);

        horizontalLayout_18->addWidget(verticeSize_spinbox);

        verticeSize_slider = new QSlider(scrollAreaWidgetContents_2);
        verticeSize_slider->setObjectName("verticeSize_slider");
        verticeSize_slider->setMinimum(10);
        verticeSize_slider->setMaximum(2100);
        verticeSize_slider->setValue(100);
        verticeSize_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_18->addWidget(verticeSize_slider);


        layout_verticesSettings->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        labelVertice_color = new QLabel(scrollAreaWidgetContents_2);
        labelVertice_color->setObjectName("labelVertice_color");
        labelVertice_color->setFont(font1);

        horizontalLayout_19->addWidget(labelVertice_color);

        label_colorVertice = new QLabel(scrollAreaWidgetContents_2);
        label_colorVertice->setObjectName("label_colorVertice");

        horizontalLayout_19->addWidget(label_colorVertice);

        pushButton_colorVertice = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_colorVertice->setObjectName("pushButton_colorVertice");

        horizontalLayout_19->addWidget(pushButton_colorVertice);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_2);


        layout_verticesSettings->addLayout(horizontalLayout_19);


        verticalLayout->addLayout(layout_verticesSettings);

        layout_BackgroundColor = new QVBoxLayout();
        layout_BackgroundColor->setObjectName("layout_BackgroundColor");
        label_backColor = new QLabel(scrollAreaWidgetContents_2);
        label_backColor->setObjectName("label_backColor");
        label_backColor->setFont(font);

        layout_BackgroundColor->addWidget(label_backColor);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        labelBackg_color = new QLabel(scrollAreaWidgetContents_2);
        labelBackg_color->setObjectName("labelBackg_color");
        labelBackg_color->setFont(font1);

        horizontalLayout_20->addWidget(labelBackg_color);

        label_colorBackg = new QLabel(scrollAreaWidgetContents_2);
        label_colorBackg->setObjectName("label_colorBackg");

        horizontalLayout_20->addWidget(label_colorBackg);

        pushButton_colorBackg = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_colorBackg->setObjectName("pushButton_colorBackg");

        horizontalLayout_20->addWidget(pushButton_colorBackg);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_3);


        layout_BackgroundColor->addLayout(horizontalLayout_20);


        verticalLayout->addLayout(layout_BackgroundColor);

        layout_downloadImage = new QVBoxLayout();
        layout_downloadImage->setObjectName("layout_downloadImage");
        label_downloadImage = new QLabel(scrollAreaWidgetContents_2);
        label_downloadImage->setObjectName("label_downloadImage");
        label_downloadImage->setFont(font);

        layout_downloadImage->addWidget(label_downloadImage);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        labelImage = new QLabel(scrollAreaWidgetContents_2);
        labelImage->setObjectName("labelImage");
        labelImage->setMinimumSize(QSize(50, 0));
        labelImage->setMaximumSize(QSize(50, 16777215));
        labelImage->setFont(font1);

        horizontalLayout_21->addWidget(labelImage);

        radioButton_jpgFormat = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_jpgFormat->setObjectName("radioButton_jpgFormat");
        radioButton_jpgFormat->setMaximumSize(QSize(75, 16777215));
        radioButton_jpgFormat->setChecked(true);

        horizontalLayout_21->addWidget(radioButton_jpgFormat);

        radioButton_bmpFormat = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_bmpFormat->setObjectName("radioButton_bmpFormat");
        radioButton_bmpFormat->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_21->addWidget(radioButton_bmpFormat);

        pushButton_downloadImage = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_downloadImage->setObjectName("pushButton_downloadImage");
        pushButton_downloadImage->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_21->addWidget(pushButton_downloadImage);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_4);


        layout_downloadImage->addLayout(horizontalLayout_21);


        verticalLayout->addLayout(layout_downloadImage);

        layout_recordingGif = new QVBoxLayout();
        layout_recordingGif->setObjectName("layout_recordingGif");
        label_recordGif = new QLabel(scrollAreaWidgetContents_2);
        label_recordGif->setObjectName("label_recordGif");
        label_recordGif->setFont(font);
        label_recordGif->setToolTipDuration(0);

        layout_recordingGif->addWidget(label_recordGif);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_Gif_mode_1 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_Gif_mode_1->setObjectName("pushButton_Gif_mode_1");

        horizontalLayout->addWidget(pushButton_Gif_mode_1);

        pushButton_Gif_mode_2 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_Gif_mode_2->setObjectName("pushButton_Gif_mode_2");

        horizontalLayout->addWidget(pushButton_Gif_mode_2);


        layout_recordingGif->addLayout(horizontalLayout);


        verticalLayout->addLayout(layout_recordingGif);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout_2->addWidget(scrollArea, 0, 1, 1, 1);

        viewport = new GLWidget(centralwidget);
        viewport->setObjectName("viewport");
        viewport->setMinimumSize(QSize(640, 480));
        viewport->setMaximumSize(QSize(16777215, 16777215));
        viewport->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_2->addWidget(viewport, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3d_viewer", nullptr));
        label_fileInfo->setText(QCoreApplication::translate("MainWindow", "File information", nullptr));
        label_filepath->setText(QCoreApplication::translate("MainWindow", "file name:", nullptr));
        label_filepathInfo->setText(QString());
        label_vertices_num->setText(QCoreApplication::translate("MainWindow", "vertices number:", nullptr));
        label_verticesInfo->setText(QString());
        label_edges->setText(QCoreApplication::translate("MainWindow", "edges number:", nullptr));
        label_edgesNumber->setText(QString());
        open_file->setText(QCoreApplication::translate("MainWindow", "upload new model", nullptr));
        label_transformModel->setText(QCoreApplication::translate("MainWindow", "Rotate model", nullptr));
        axisX_rotate_label->setText(QCoreApplication::translate("MainWindow", "axis: X", nullptr));
        axisY_rotate_label->setText(QCoreApplication::translate("MainWindow", "axis: Y", nullptr));
        axisZ_rotate_label->setText(QCoreApplication::translate("MainWindow", "axis: Z", nullptr));
        label_transformModel_2->setText(QCoreApplication::translate("MainWindow", "Move model", nullptr));
        axisX_rotate_label_2->setText(QCoreApplication::translate("MainWindow", "axis: X", nullptr));
        axisX_rotate_label_3->setText(QCoreApplication::translate("MainWindow", "axis: Y", nullptr));
        axisX_rotate_label_4->setText(QCoreApplication::translate("MainWindow", "axis: Z", nullptr));
        label_scaleModel->setText(QCoreApplication::translate("MainWindow", "Scale model", nullptr));
        labelScaleInput->setText(QCoreApplication::translate("MainWindow", "scale", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        scaleToDefault->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_projectionType->setText(QCoreApplication::translate("MainWindow", "Proection type", nullptr));
        radioButton_orthogonal->setText(QCoreApplication::translate("MainWindow", "Orthogonal", nullptr));
        radioButton_perspective->setText(QCoreApplication::translate("MainWindow", "Perspective", nullptr));
        label_settingsEdge->setText(QCoreApplication::translate("MainWindow", "Edges:", nullptr));
        labelEdge_width->setText(QCoreApplication::translate("MainWindow", "width", nullptr));
        labelEdge_type->setText(QCoreApplication::translate("MainWindow", "type", nullptr));
        radioButton_dotted->setText(QCoreApplication::translate("MainWindow", "Dotted", nullptr));
        radioButton_constant->setText(QCoreApplication::translate("MainWindow", "Constant", nullptr));
        labelEdge_color->setText(QCoreApplication::translate("MainWindow", "Color:", nullptr));
        label_colorEdges->setText(QString());
        pushButton_colorEdge->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        label_settingsVerticle->setText(QCoreApplication::translate("MainWindow", "Vertices:", nullptr));
        labelVerticle_type->setText(QCoreApplication::translate("MainWindow", "type", nullptr));
        radioButton_noneVertice->setText(QCoreApplication::translate("MainWindow", "none", nullptr));
        radioButton_circleVertice->setText(QCoreApplication::translate("MainWindow", "circle", nullptr));
        radioButton_squareVertice->setText(QCoreApplication::translate("MainWindow", "square", nullptr));
        labelVertice_size->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        labelVertice_color->setText(QCoreApplication::translate("MainWindow", "Color:", nullptr));
        label_colorVertice->setText(QString());
        pushButton_colorVertice->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        label_backColor->setText(QCoreApplication::translate("MainWindow", "Background:", nullptr));
        labelBackg_color->setText(QCoreApplication::translate("MainWindow", "Color:", nullptr));
        label_colorBackg->setText(QString());
        pushButton_colorBackg->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        label_downloadImage->setText(QCoreApplication::translate("MainWindow", "Dowload image", nullptr));
        labelImage->setText(QCoreApplication::translate("MainWindow", "format", nullptr));
        radioButton_jpgFormat->setText(QCoreApplication::translate("MainWindow", ".jpg", nullptr));
        radioButton_bmpFormat->setText(QCoreApplication::translate("MainWindow", ".bmp", nullptr));
        pushButton_downloadImage->setText(QCoreApplication::translate("MainWindow", "download", nullptr));
        label_recordGif->setText(QCoreApplication::translate("MainWindow", "Record gif", nullptr));
        pushButton_Gif_mode_1->setText(QCoreApplication::translate("MainWindow", "Task", nullptr));
        pushButton_Gif_mode_2->setText(QCoreApplication::translate("MainWindow", "Cooler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
