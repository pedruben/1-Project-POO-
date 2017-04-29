#ifndef INCLUDED_CLASS
#define INCLUDED_CLASS

#include <string>

using namespace std;

class Node{
    public:
        string word;
        int count;

    public:
        Node* left;
        Node* right;
        Node();
        Node(string argWord);
        ~Node();
        void leftInsert(string word);    //Inserts a word as a new node to the left
        void rightInsert(string word);    //Inserts a word as a new node to the right
        void increment();
        void print(ofstream& file);
        void printDesc(ofstream& file);
        void lexInsert(string argWord);
};






class BinTree{
    public:
        Node* root;
        BinTree();
        ~BinTree();
        void lexInsert(string word);    //Inserts a word lexicographically ordered
        void print(ofstream& file);
};

#endif
