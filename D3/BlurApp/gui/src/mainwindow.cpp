#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "desc.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QSlider>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    connect(ui_->openButton, &QPushButton::clicked,
            this, &MainWindow::OnOpenImage);

    connect(ui_->blurSlider, &QSlider::valueChanged,
            this, &MainWindow::OnSliderValueChanged);
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::OnOpenImage()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Выберите изображение",
        QString(),
        "Images (*.jpg *.jpeg *.png *.bmp)"
    );

    if (fileName.isEmpty())
    {
        return;
    }

    if (!sourceImage_.load(fileName))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    UpdateImage();
}

void MainWindow::OnSliderValueChanged(int /*value*/)
{
    UpdateImage();
}

void MainWindow::UpdateImage()
{
    if (sourceImage_.isNull())
    {
        return;
    }

    QImage blurred = blurImage(sourceImage_, ui_->blurSlider->value());

    ui_->imageLabel->setPixmap(QPixmap::fromImage(
        blurred.scaled(
            ui_->imageLabel->width(),
            ui_->imageLabel->height(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    ));
}
