#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_textEdit_textChanged() {
    m_textEditor.replace(ui->textEdit->toPlainText().toStdString(), 0, m_textEditor.text().length());
}

void MainWindow::on_undoButton_clicked() {
    m_textEditor.undo();
    ui->textEdit->blockSignals(true);
    ui->textEdit->setPlainText(m_textEditor.text().c_str());
    ui->textEdit->blockSignals(false);
}

void MainWindow::on_redoButton_clicked() {
    m_textEditor.redo();
    ui->textEdit->blockSignals(true);
    ui->textEdit->setPlainText(m_textEditor.text().c_str());
    ui->textEdit->blockSignals(false);
}
