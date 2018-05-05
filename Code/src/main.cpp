#include "../include/pasc.tab.h"
#include "../include/SemanticAnalysis.h"
#include "../include/CodeGenerate.h"
#include <string>
#include <iostream>
#include <exception>

#define DETIAL_OUTPUT   false
#define DO_GCC_JOB      true

using namespace std;

extern Programstruct *ROOT;

int main(int argc, char *argv[]) {
    try {

        string filename_WithExten;
        string filename_WithoutExten;

        // check arguments input, get the filename, and freopen with filename
        {
            if (argc != 2) {
                throw "Invalid arguments input!";
            }

            filename_WithExten = argv[1];
            filename_WithoutExten;

            int pos = filename_WithExten.find('.');
            if (pos == -1) {
                throw "Invalid filename_withExten";
            }

            filename_WithoutExten = filename_WithExten.substr(0, pos);
            freopen(argv[1], "r", stdin);
        }

        // the pas2c mission
        {
            if (DETIAL_OUTPUT)
                cout << "START\t->\tMISSION START!" << endl;


            if (Lexic_Syntax() == 1)
                exit(1);
            if (DETIAL_OUTPUT)
                cout << "   PAS2C PART 1 : Lexical and Syntax Analyse Done!" << endl;


            if (!semantic_Error_Detect(ROOT))
                exit(2);
            if (DETIAL_OUTPUT)
                cout << "   PAS2C PART 2 : Semantic Analyse Done!" << endl;


            Code_Generate(ROOT, filename_WithoutExten);
            if (DETIAL_OUTPUT)
                cout << "   PAS2C PART 3 : Code Generate Done!" << endl;


            cout << "PAS2C\t->\tCompile .pas to .c Done!" << endl;
        }

        // the gcc mission
        if (DO_GCC_JOB) {
            string gcc_job = "gcc -o ";
            gcc_job += filename_WithoutExten;
            gcc_job += " ";
            gcc_job += filename_WithoutExten;
            gcc_job += ".c";
            if (DETIAL_OUTPUT)
                cout << "   GCC PART 1: Doing gcc Compile!\n     "+ gcc_job << endl;
            system(gcc_job.data());
            cout << "GCC\t->\tgcc Compile Done!" << endl;
        }

        cout << "____________________________________________________________" << endl << endl;
        cout << "DONE\t->\tOutput EXE is \'" + filename_WithoutExten + "\'"<< endl;
        return 0;

    }
    catch (exception &e){
        cout << e.what() << endl;
        return 100;
    }
}