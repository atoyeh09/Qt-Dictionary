#include "header.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QString>
#include <QInputDialog>

extern AVLTree avlTree;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SearchButtom_clicked()
{
    // Search for a word
    string storeResult;

    cout << "\nEnter the word to search: \n";
    QString testFromInputBox = ui->TypeHereInput->text();

    AVLNode* result = avlTree.searchWord(testFromInputBox.toStdString());
    if (result != NULL)
    {
        cout << "Word found:\n> " << result->key << " :  " << result->meaning << ".\n";
        storeResult = "Word found:\n> " + result->key + " :  " + result->meaning;
    }
    else
    {
        cout << "Word Not Found!\n";
        storeResult = "Word Not Found!\n";
    }
    ui->OutputBox->setText(QString::fromStdString(storeResult));
}

void MainWindow::on_SuggestButton_clicked()
{
    // Display suggestions
    cout << "\nEnter prefix to get suggestions: ";
    QString testFromInputBox = ui->TypeHereInput->text();

    avlTree.displaySuggestions(testFromInputBox.toStdString(), ui);
}

void MainWindow::on_DeleteButton_clicked()
{
    // Delete word
    string deleteWord;

    cout << "\nEnter word to delete:\n";
    QString testFromInputBox = ui->TypeHereInput->text();
    //deleteWord = testFromInputBox.toStdString();

    avlTree.deleteWord(testFromInputBox.toStdString(), "Dictionary.txt");
    ui->OutputBox->setText("Deleted!");
}

void MainWindow::on_AddWordButton_clicked()
{
    cout << "\nEnter the new word: ";
    QString testFromInputBox = ui->TypeHereInput->text();
    cout << "Enter the meaning of the word: ";
    bool ok;
    QString newMeaning = QInputDialog::getText(this, "Enter Meaning", "Meaning for " + testFromInputBox + ":", QLineEdit::Normal, "", &ok);

    // Update meaning in AVL tree
    if (ok)
    {
        avlTree.addWordToFile("Dictionary.txt", testFromInputBox.toStdString(), newMeaning.toStdString());
        cout << "\nWord Added Successfully!\n";
        ui->OutputBox->setText("Word Added Successfully!");
    }
    else
    {
        ui->OutputBox->setText("Operation canceled by the user.");
    }
}

void MainWindow::on_UpdateMeaningButton_clicked()
{
    // Get the word to update
    QString wordToUpdate = ui->TypeHereInput->text();

    AVLNode* node = avlTree.searchWord(wordToUpdate.toStdString());

    if (node != NULL)
    {
        bool ok;
        // Get new meanning from user
        QString newMeaning = QInputDialog::getText(this, "Update Meaning", "Enter the new meaning:", QLineEdit::Normal, QString::fromStdString(node->meaning), &ok);

        // Update meaning in AVL tree
        if (ok)
        {
            avlTree.updateWordMeaning(wordToUpdate.toStdString(), newMeaning.toStdString());
            QString outputMessage = "Meaning updated successfully!";
            ui->OutputBox->setText(outputMessage);
        }
        else
        {
            QString outputMessage = "Operation canceled by the user.";
            ui->OutputBox->setText(outputMessage);
        }
    }
    else {
        // If word not found
        QString outputMessage = "Word Not Found.";
        ui->OutputBox->setText(outputMessage);
    }
}

