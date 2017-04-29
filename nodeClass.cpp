#include "class.hpp"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Node::Node(){
    word="";
    count=0;
    left=NULL;
    right=NULL;
}

Node::Node(string argWord){    //Creates a Node with a given word attribute.
    word=argWord;
    count=1;
    left=NULL;
    right=NULL;
}

Node::~Node(){    //Calling delete calls the destructors and only after does it delete.
    delete left;
    delete right;
}

void Node::increment(){        // use ++ ?
    count++;
}

void Node::leftInsert(string argWord){
    delete left;
    left = new Node(argWord);
}

void Node::rightInsert(string argWord){ // DOESNT SEEM TO BEWORKING WELL......
    delete right;
    right = new Node(argWord);
}

void Node::print(ofstream& file){
    file << word.c_str() << " - " << count << '\n';
}

void Node::printDesc(ofstream& file){    // printDescendant
    if( left != NULL ){
        left->printDesc(file);
    }
    print(file);
    if( right != NULL ){
        right->printDesc(file);
    }
}

/*
void Node::print(str &argString){
    strcat( argString, word);
    strcat( argString; " - ");
    strcat( argString, count);
    strcat( argString; "\n");
}


void Node::printDesc(string &argString){    // printDescendant
    if( left != NULL ){
        left->concDesc();
    }
    conc();
    if( right != NULL ){
        right->concDesc();
    }
}*/
///
/////////////////7
void Node::lexInsert(string argWord){
    int comp = word.compare(argWord);
    if (comp == 0){
        increment();
        return;
    }
    else if (comp > 0){
        if(left == NULL){
            leftInsert(argWord);
        }
        else{
            left->lexInsert(argWord);    //INNEFICIENT
        }
    }
    else if (comp < 1){
        if(right == NULL){
            rightInsert(argWord);
        }
        else{
            right->lexInsert(argWord);    //INNEFICIENT
        }
    }
       
}
   

//~ Node::Node(string argWord, Node* argLeft=NULL, Node* argRight=NULL){    //Creates a Node with a given word, left and right attribute.
    //~ word=argWord;
    //~ count=1;
    //~ left=argLeft;
    //~ right=argRight;
//~ }
//~ Node *Node::find(string argWord){        //Poisslby a private method that takes a word and outputs the pointer to where the Node should be put. It's pretty useful for eg lexInsert. If it's null we create a new node. If it's not null we take that node and we increment it. Something like that.
    //~ int comp = word.compare(argWord);
//~ }
