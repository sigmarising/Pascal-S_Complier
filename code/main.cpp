#include "pasc.tab.c"
#include "SemanticAnalysis.h"
#include "CodeGenerate.h"
#include <string>
using namespace std;

extern Programstruct* ROOT;

int main(int argc, char* argv[]){
    if (1 == lexyacc())
        exit(1);
    
    if (!semantic_Error_Detect(ROOT))
        exit(2);
    
    Code_Generate(ROOT, "output");

    return 0;
}