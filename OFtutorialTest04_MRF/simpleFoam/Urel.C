/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2015 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.


Application
    Urel

Description
    For each time: calculate realtive velocity.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "IOMRFZoneList.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    timeSelector::addOptions();

#   include "setRootCase.H"
#   include "createTime.H"

    instantList timeDirs = timeSelector::select0(runTime, args);

#   include "createMesh.H"
    IOMRFZoneList mrfZone(mesh);

    forAll(timeDirs, timeI)
    {
        runTime.setTime(timeDirs[timeI], timeI);

        Info<< "Time = " << runTime.timeName() << endl;

        IOobject UHeader
        (
            "U",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        );

        // Check p and U exist
        if (UHeader.typeHeaderOk<volVectorField>(true))
        {
        mesh.readUpdate();

        Info<< "    Reading U" << endl;
        volVectorField U(UHeader, mesh);

        Info<< "    Calculating Urel" << endl;
        volVectorField Urel
        (
            IOobject
            (
                "Urel",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ
            ),U

        );
        mesh.readUpdate();
        Urel == U; 
        //mrfZone.relativeVelocity(Urel); 
        mrfZone.makeRelative(Urel); 
        Urel.write(); 
        }
        else
        {
            Info<< "    No U" << endl;
        }

        Info<< endl;
    }

    return 0;
}


// ************************************************************************* //
