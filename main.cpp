#include "mainwindow.h"
#include <QApplication>
#include "header.h"
using namespace std;

// void displayMenu()
// {
//     cout << "\nMenu:\n";
//     cout << "1. Display AVL Tree (Words and Meanings)\n";
//     cout << "2. Add Word to AVL Tree and File\n";
//     cout << "3. Search for a Word\n";
//     cout << "4. Update Word Meaning\n";
//     cout << "5. Delete Word\n";
//     cout << "6. Display Suggestions\n";
//     cout << "7. Exit\n";
// }

extern AVLTree avlTree;
int main(int argc, char *argv[])
{
    // Load data from file and insert into AVL tree
    avlTree.loadFromFile("Dictionary.txt");

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Dictionary");
    w.show();
    return a.exec();
}
