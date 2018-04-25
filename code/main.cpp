#include "../include/pasc.tab.h"
#include "../include/SemanticAnalysis.h"
#include "../include/CodeGenerate.h"
#include <string>
#include <iostream>

using namespace std;

extern Programstruct *ROOT;
extern int yacc();
int main(int argc, char *argv[]) {
    cout << "1111" << endl;
//    if (yacc() == 1)
//      exit(1);
    cout << "yacc: " << yacc() << endl;
    cout << "part 1 ok!" << endl;
    if (!semantic_Error_Detect(ROOT))
        exit(2);
    cout << "part 2 ok!" << endl;

    Code_Generate(ROOT, "output");
    cout << "part 3 ok!" << endl;

    return 0;
}