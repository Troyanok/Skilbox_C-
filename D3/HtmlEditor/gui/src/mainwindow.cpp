#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPlainTextEdit>
#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    connect(ui_->plainTextEdit, &QPlainTextEdit::textChanged,
            this, &MainWindow::OnTextChanged);

    ui_->plainTextEdit->setPlainText(
        "<h1>Привет!</h1>"
        "<p>Редактируй HTML слева — результат появится справа.</p>"
    );
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::OnTextChanged()
{
    ui_->webEngineView->setHtml(ui_->plainTextEdit->toPlainText());
}
