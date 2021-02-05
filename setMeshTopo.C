/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2021 2021 AUTHOR,AFFILIATION
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
    myBlockMesh

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "MeshedSurfaces.H"
#include "dynamicFvMesh.H"
//#include "scalar.H"
//#include "scalarList.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{

    #include "createArgList.H"
    #include "setRootCase.H"
    #include "createTime.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    // load surf files
    Info << nl;
    Info << "Loading surface files..." << endl;
    fileName surfFileName(args["surface"]);
    meshedSurface surf(surfFileName);
    surf.writeStats(Info);
    //pointField cornerPts(boundBox(surf.points(), false).points());
    //cornerPts.writeEntry("cornerPts", Info);

    // Load into polyMesh for OpenFOAM-compliant data handling
    #include "createNamedDynamicFvMesh.H"
    Info <<  "mesh.points().size() = " <<  mesh.points().size() << endl;
    Info <<  "Is mesh dynamic? " << mesh.dynamic() << endl; 
    const polyBoundaryMesh& pbm = mesh.boundaryMesh();
    Info << "patch names: " << pbm.names() << endl;
    const polyPatch& groundPatch = pbm["ground"];

    pointField p0 = groundPatch.localPoints(); // load blockMesh bottom points
    Info << "current available patch: " << groundPatch.name() << endl;
    Info << "p0.size() " << p0.size() <<endl;
    boundBox bbox(p0);
    Info << "boundBox.min(): " << bbox.min() << endl;
    Info << "p0[10].x(): " << p0[10].x() << endl;



    return 0;
}
// ************************************************************************* //
