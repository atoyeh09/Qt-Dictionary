#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT    

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_SearchButtom_clicked();

    void on_SuggestButton_clicked();

    void on_DeleteButton_clicked();

    void on_AddWordButton_clicked();

    void on_UpdateMeaningButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
