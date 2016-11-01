#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebView>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("http://www.google.com"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addressbar_returnPressed()
{
    on_goButton_clicked();
}

void MainWindow::on_backButton_clicked()
{
    ui->webView->back();
}

void MainWindow::on_goButton_clicked()
{
    //Formaterar user input till en valid URL
     ui->webView->load(QUrl::fromUserInput(ui->addressbar->text()));
}

void MainWindow::on_forwardButton_clicked()
{
    ui->webView->forward();
}

void MainWindow::on_webView_urlChanged(const QUrl &arg1)
{
    //Uppdaterar Address Bar:n då användaren surfar
    ui->addressbar->setText(arg1.toString());
}
