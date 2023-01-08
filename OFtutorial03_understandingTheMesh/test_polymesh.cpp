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

    meshPtr.reset(
        //用new创建的指针刷新meshPtr,meshPtr是智能指针不需要delete释放
        //new创建fvMesh类，并用IOobject类初始化构造函数
        new Foam::fvMesh(
            Foam::IOobject(
                regionName,
                runTime.timeName(),
                runTime,
                Foam::IOobject::MUST_READ),
            false));
            
    meshPtr().init(true); // initialise all (lower levels and current)

    Foam::Info << "meshPtr()="<<meshPtr()<<Foam::endl;

    Foam::Info << "meshPtr().C().size()=？"<<meshPtr().C().size()<<Foam::endl;

    Foam::fvMesh &mesh = meshPtr(); //mesh是指向meshPtr的引用

    // meshPtr.release();


    // ************************************************************************* //

    Info << "Hello there, the most recent time folder found is " << runTime.timeName() << nl
         << "The mesh has " << mesh.C().size() << " cells and " << mesh.Cf().size()
         << " internal faces in it. Wubalubadubdub!?" << nl << endl;

    //     Info << "start test polymesh!";
    //     Info << "\ntest code start!\n############################################\n";
    //     Info << "";
    //     Info << "\n############################################\ntest code end! \n\n";
    //     // Foam::polyMesh mesh;
    return 0;
}