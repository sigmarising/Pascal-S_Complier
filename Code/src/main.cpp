#include "../include/pasc.tab.h"
#include "../include/SemanticAnalysis.h"
#include "../include/CodeGenerate.h"
#include <string>
#include <iostream>

using namespace std;

extern Programstruct *ROOT;

int main(int argc, char *argv[]) {
    freopen("../test/CodeGen_2_qsort.pas", "r", stdin);


    if (Lexic_Syntax() == 1)
      exit(1);
    cout << "PART 1 ---> Lexical and Syntax Analyse Done!" << endl;


    if (!semantic_Error_Detect(ROOT))
        exit(2);
    cout << "PART 2 ---> Semantic Analyse Done!" << endl;


    Code_Generate(ROOT, "output");
    cout << "PART 3 ---> Code Generate Done!" << endl;


    cout << endl << "Compile All Done!" << endl;
    return 0;
}