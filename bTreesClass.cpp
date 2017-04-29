#include "class.hpp"

#include <iostream>

using namespace std;

BinTree::BinTree(){
    root=NULL;
}

BinTree::~BinTree(){    //Calls the destructor of the nodes recursively
    delete root;
}

void BinTree::lexInsert(string argWord){    //use >> ?
    Node* curPt = root;
    bool done = false;
    int comp;
    
    if(curPt == NULL)
    {
		root = new Node(argWord);
		return;
	}
    
    while (!done){
        comp = curPt->word.compare(argWord);    // ie: (word > argWord)
        
        if (comp == 0){
            curPt->increment();
            done = true;
        }
        else if (comp > 0) {
            if (curPt->left == NULL){
                curPt->leftInsert(argWord);
                done = true;
            }
            else {
                curPt = curPt->left;
            }
        }
        else if (comp < 0) {
            if (curPt->right == NULL){
                curPt->rightInsert(argWord);
                done = true;
            }
            else {
                curPt = curPt->right;
            }
        }
    }
}

void BinTree::print(ofstream& file){        // use << ?
    if( root != NULL ){
        root->printDesc(file);
    }
}   

/*
void BinTree::lexInsert(string argWord){
    Node* curPt=root;
    Bool done=False;
    int comp;
    while(not done){
        comp=strcmp(curPt->word,argWord);
        if(comp==0){
            (curPt->count)++
            done=True;
        }
        elif(comp>0){    //Then word > argWord, which means argWord must go to the left of word.
            curPt=curPt->left
            if(curPt == NULL){
                curPt new Node(argWord);
                done=True;
            }
            //Else keep going.
        }
        elif(comp<0){
            curPt=curPt->right
            if(curPt == NULL){
                curPt new Node(argWord);
                done=True;
        }   
    }
}
*/
