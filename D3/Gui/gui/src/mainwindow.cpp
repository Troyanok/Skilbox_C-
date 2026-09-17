#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , player_(new QMediaPlayer(this))
{
    ui_->setupUi(this);

    player_->setMedia(QUrl("qrc:/click.mp3"));

    connect(ui_->pushButton, &QPushButton::pressed,
            this, &MainWindow::OnButtonPressed);
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::OnButtonPressed()
{
    player_->play();
}
