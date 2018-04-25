#include "pasc.tab.h"
#include "SemanticAnalysis.h"
#include "CodeGenerate.h"
#include <string>
#include <iostream>
using namespace std;

extern Programstruct* ROOT;

int main(int argc, char* argv[]){
    if (1 == Lexical_Syntax())
        exit(1);
    cout << endl << "PART 1 OK!" << endl << endl;

    if (!semantic_Error_Detect(ROOT))
        exit(2);
    cout << endl << "PART 2 OK!" << endl << endl;
    
    Code_Generate(ROOT, "output");
    cout << endl << "PART 3 OK!" << endl << endl;

    return 0;
}