//~ using namespace std;
#include <stddef.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
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
    //~ Node n=Node("banana");
   

    string entrada, saida, file;
    cout << "Diga qual o titlo do ficheiro:/n>>";
    cin >> entrada;
   
    ifstream Pfile("text");
    ofstream Ufile;
    file= "Ordenado"+entrada;
    if(Pfile.is_open())
    {   
        Ufile.open(file);
       
       
         
       
        Pfile.close();
        Ufile.close();
    }
   
    else cout << "O ficheiro nao existe.";

   
   
    return 0;
}
