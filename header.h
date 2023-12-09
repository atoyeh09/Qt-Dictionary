#ifndef HEADER_H
#define HEADER_H

#include "mainwindow.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

// TrieNode structure is for suggestions
class TrieNode
{
public:
    char data;
    bool isEnd;
    TrieNode** children;

    TrieNode(char c);
    ~TrieNode();
};

// Trie class for suggestions
class Trie
{
private:
    TrieNode* root;
    void insertWord(TrieNode* node, const string& word);
    TrieNode* findNode(TrieNode* node, const string& prefix);
    void getSuggestions(TrieNode* node, const string& prefix, Ui::MainWindow *ui);

public:
    Trie();
    ~Trie();
    void insert(const string& word);
    void getSuggestions(const string& prefix, Ui::MainWindow *ui);
};

// AVLNode structure is for suggestions
class AVLNode
{
public:
    string key;
    string meaning;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(string word, string wordMeaning);
};

// AVLTree class
class AVLTree
{
private:
    AVLNode* root;
    Trie suggestionsTrie; // Trie for storing suggestions
    int getHeight(AVLNode* node);
    int getBalanceFactor(AVLNode* node);
    AVLNode* rotateRight(AVLNode* root);
    AVLNode* rotateLeft(AVLNode* root);
    AVLNode* insert(AVLNode* node, string key, string meaning);
    AVLNode* search(AVLNode* node, const string& key);
    AVLNode* findMinNode(AVLNode* node);
    AVLNode* deleteNode(AVLNode* root, string key);
    void inOrderTraversalHelper(AVLNode* node, ostream& output);
    void inOrderTraversal(AVLNode* node, ofstream& outputFile);
    void updateSuggestionsTrie(AVLNode* node);

public:
    AVLTree();
    void insert(string key, string meaning);
    void loadFromFile(const string& filename);
    void addWordToFile(const string& filename, string key, string meaning);
    AVLNode* searchWord(const string& key);
    void updateWordMeaning(const string& key, const string& newMeaning);
    void deleteWord(const string& key, const string& filename);
    void displayInOrder(ostream& output = cout);
    void displaySuggestions(const string& prefix, Ui::MainWindow *ui);
};

#endif // HEADER_H
