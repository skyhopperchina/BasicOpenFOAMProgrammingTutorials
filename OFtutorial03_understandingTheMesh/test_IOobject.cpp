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

    // #include "createMesh.H"
    Foam::autoPtr<Foam::fvMesh> meshPtr;
    Foam::word regionName(Foam::polyMesh::defaultRegion);

    Foam::Info << "Create mesh";
    if (args.readIfPresent("region", regionName))
    {
        Foam::Info << ' ' << regionName;
    }
    Foam::Info << " for time = " << runTime.timeName() << Foam::nl;

    Foam::IOobject testIO(
                regionName,
                runTime.timeName(),
                runTime,
                Foam::IOobject::MUST_READ);
    
    Foam::Info << "regionName="<<regionName<<Foam::endl;
    Foam::Info << "runTime.timeName()="<<runTime.timeName()<<Foam::endl;



    return 0;
}