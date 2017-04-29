//~ using namespace std;
#include <stddef.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm> 

using namespace std;
using std::string;
using std::cout;
// str1.compare( str2) is similar to (str1 > str2). ie: ("z">"a") returns 1.
#include "class.hpp"
#include "nodeClass.cpp"
#include "bTreesClass.cpp"
#include <fstream>

int main(int argc,const char* argv[])
{
    /*Node n=Node("banana"); */
    BinTree tree;
    
	string entrada, saida, file;
    cout << "Diga qual o titlo do ficheiro:\n>>";
    
    cin >> entrada;
    
    ifstream Pfile(entrada.c_str());
    
    while (Pfile.good())
    {
		string palavra;
		Pfile >> palavra;
		palavra.erase(remove(palavra.begin(), palavra.end(), '.'), palavra.end());
		palavra.erase(remove(palavra.begin(), palavra.end(), ','), palavra.end());
		palavra.erase(remove(palavra.begin(), palavra.end(), '!'), palavra.end());
		palavra.erase(remove(palavra.begin(), palavra.end(), '?'), palavra.end());
		palavra.erase(remove(palavra.begin(), palavra.end(), '('), palavra.end());
		palavra.erase(remove(palavra.begin(), palavra.end(), ')'), palavra.end());
		transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
		tree.lexInsert(palavra);
	}
    
   
    
    ofstream Ufile;
    file= "Ordenado"+entrada;
    
    if(Pfile.is_open())
    {   
        Ufile.open(file.c_str());
        
        tree.print(Ufile);
       
        Pfile.close();
        Ufile.close();
        
        cout << "\n\n\nO ficheiro " << file; 
        cout << " foi criado e o processo um sucesso.";
        cout << "\nPresse qualquer letra para terminar.";
		cin.get();
		cin.get();
    }
    else 
    {
		cout << "O ficheiro nao existe."; 
    }
   
    return 0;
}
