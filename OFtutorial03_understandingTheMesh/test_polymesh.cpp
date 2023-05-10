#include <iostream>
// #include "polyMesh.H"
#include <stdio.h>
#include <stdlib.h>

#include "fvCFD.H"

// #include "fileOperation.H"
// #include "fileOperationInitialise.H"
// #include "fileName.H"

int main(int argc, char *argv[])
{
    // #include "setRootCase.H"   //初始化运行环境
    Foam::argList args(argc, argv);
#include "createTime.H"

    // #include "createMesh.H"
    Foam::autoPtr<Foam::fvMesh> meshPtr;
    Foam::word regionName(Foam::polyMesh::defaultRegion);

    Foam::Info << "Main begain:\n";
    Foam::Info << "Create mesh\n";
    Foam::Info << "regionName: " << regionName<< Foam::nl;
    Foam::Info << "runTime.timeName(): " << runTime.timeName() << Foam::nl;
    std::cout<<"std count"<<std::endl;
    // Foam::Info << "runTime: " << runTime << Foam::nl;
    std::cout<<"create IOobject2023032006"<<std::endl;
    Foam::IOobject IO(
                regionName,
                runTime.timeName(),
                runTime,
<<<<<<< HEAD
                Foam::IOobject::MUST_READ),
            false));
        //fvMesh在构造过程中已经载入了网格数据
            
    meshPtr().init(true); // initialise all (lower levels and current)

    // Foam::Info << "meshPtr()="<<meshPtr()<<Foam::endl;

    Foam::Info << "meshPtr().C().size()=?"<<meshPtr().C().size()<<Foam::endl;
=======
                Foam::IOobject::MUST_READ);

    Foam::fvMesh newfvMesh(IO,false);

    Foam::Info << "meshPtr().C().size()="<<newfvMesh.C().size()<<Foam::endl;
    Foam::Info << "meshSubDir="<<newfvMesh.meshSubDir<<Foam::endl;
    Foam::Info << "defaultRegion="<<newfvMesh.defaultRegion<<Foam::endl;
    Foam::Info << "sizeof newfvMesh="<<sizeof(newfvMesh)<<Foam::endl;    
>>>>>>> 0a6247bb246235e36c2e04f36c8309ea7b168888

    std::cout<<"create new polymesh"<<std::endl;
    Foam::polyMesh newpolyMesh(IO,false);
    Foam::Info << "newpolyMesh meshSubDir="<<newpolyMesh.meshSubDir<<Foam::endl;
    Foam::Info << "newpolyMesh  meshDir()="<<newpolyMesh.meshDir()<<Foam::endl;
    Foam::Info << "newpolyMesh  pointsInstance()="<<newpolyMesh.pointsInstance()<<Foam::endl;
    // Foam::Info << "newpolyMesh  points()="<<newpolyMesh.points()<<Foam::endl;
    
    
    
    // meshPtr.reset(
    //     //用new创建的指针刷新meshPtr,meshPtr是智能指针不需要delete释放
    //     //new创建fvMesh类，并用IOobject类初始化构造函数
    //     new Foam::fvMesh(
    //         IO,
    //         false));
    
    // meshPtr().init(true); // initialise all (lower levels and current)

    Foam::Info << "regionName="<<regionName<<Foam::endl;
    Foam::Info << "runTime.timeName()="<<runTime.timeName()<<Foam::endl;

    

    // Foam::Info << "meshPtr().C().size()="<<meshPtr().C().size()<<Foam::endl;

    // Foam::fvMesh &mesh = meshPtr(); //mesh是指向meshPtr的引用

    // Foam::Info << "meshSubDir="<<mesh.meshSubDir<<Foam::endl;
    // Foam::Info << "defaultRegion="<<mesh.defaultRegion<<Foam::endl;
    // Foam::pointZoneMesh& point=mesh.pointZones();

    Foam::Info << "FOAM_FILEHANDLER=" << getEnv("FOAM_FILEHANDLER")<<Foam::endl;

    // meshPtr.release();


    // ************************************************************************* //

    // Info << "Hello there, the most recent time folder found is " << runTime.timeName() << nl
    //      << "The mesh has " << mesh.C().size() << " cells and " << mesh.Cf().size()
    //      << " internal faces in it. Wubalubadubdub!?" << nl << endl;

    //     Info << "start test polymesh!";
    //     Info << "\ntest code start!\n############################################\n";
    //     Info << "";
    //     Info << "\n############################################\ntest code end! \n\n";
    //     // Foam::polyMesh mesh;
    return 0;
}