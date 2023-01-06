#include <iostream>
// #include "polyMesh.H"
#include <stdio.h>
#include <stdlib.h>

#include "fvCFD.H"

#include "fileOperation.H"
#include "fileOperationInitialise.H"
#include "fileName.H"

int main(int argc, char *argv[])
{

    int i;
    for (i = 0; i < argc; i++)
        printf("Argv[%d] = %s\n", i, argv[i]);

    // printf("FOAM_FILEHANDLER : %s\n", getenv("FOAM_FILEHANDLER"));

    Foam::word handlerType;
    handlerType = Foam::fileOperation::defaultFileHandler;

    Foam::argList args(argc, argv);
    Info << "args.rootPath()=" << args.rootPath() << "\n";
    Info << "args.path()=" << args.path() << "\n";
    Info << "args.caseName()=" << args.caseName() << "\n";
    Info << "args.checkRootCase()=" << args.checkRootCase() << "\n";

    Info << "cwd=" << cwd() << "\n";

}