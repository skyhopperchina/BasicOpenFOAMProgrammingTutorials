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
    #include "setRootCase.H"   //初始化运行环境
    #include "createTime.H"
    #include "createMesh.H"

Info << "Hello there, the most recent time folder found is " << runTime.timeName() << nl
		 << "The mesh has " << mesh.C().size() << " cells and " << mesh.Cf().size()
         << " internal faces in it. Wubalubadubdub!" << nl << endl;

    //     Info << "start test polymesh!";
    //     Info << "\ntest code start!\n############################################\n";
    //     Info << "";
    //     Info << "\n############################################\ntest code end! \n\n";
    //     // Foam::polyMesh mesh;
    return 0;
}