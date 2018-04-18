#include "pasc.tab.h"
#include "SemanticAnalysis.h"
#include "CodeGenerate.h"
#include <string>
#include <iostream>
using namespace std;

extern Programstruct* ROOT;

int main(int argc, char* argv[]){
    if (1 == lexyacc())
        exit(1);
    cout << "part 1 ok!" <<endl;

    if (!semantic_Error_Detect(ROOT))
        exit(2);
    cout << "part 2 ok!" <<endl;
    
    Code_Generate(ROOT, "output");
    cout << "part 3 ok!" <<endl;

    return 0;
}