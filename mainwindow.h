#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "texteditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();

    void on_undoButton_clicked();

    void on_redoButton_clicked();

private:
    Ui::MainWindow* ui;
    TextEditor m_textEditor;
};
#endif // MAINWINDOW_H
