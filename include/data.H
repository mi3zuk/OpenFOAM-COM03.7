/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2016 OpenFOAM Foundation
    Copyright (C) 2020 OpenCFD Ltd.
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
 
Class
    Foam::data
 
Description
    Database for solution data, solver performance and other reduced data.
 
    fvMesh is derived from data so that all fields have access to the data from
    the mesh reference they hold.
 
SourceFiles
    data.C
 
\*---------------------------------------------------------------------------*/
 
#ifndef data_H
#define data_H
 
#include "IOdictionary.H"
#include "solverPerformance.H"
 
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
 
namespace Foam
{
 
/*---------------------------------------------------------------------------*\
                            Class data Declaration
\*---------------------------------------------------------------------------*/
 
class data
:
    public IOdictionary
{
    // Private data
 
        //- Previously used time-index, used for reset between iterations
        mutable label prevTimeIndex_;
 
 
    // Private Member Functions
 
        //- No copy construct
        data(const data&) = delete;
 
        //- No copy assignment
        void operator=(const data&) = delete;
 
 
public:
 
    //- Debug switch
    static int debug;
 
 
    // Constructors
 
        //- Construct for objectRegistry
        data(const objectRegistry& obr);
 
        //- Construct for objectRegistry and initial contents
        data(const objectRegistry& obr, const dictionary& dict);
 
 
    // Member Functions
 
        //- Return the dictionary of solver performance data which
        //- includes initial and final residuals for convergence checking
        const dictionary& solverPerformanceDict() const;
 
        //- Add/set the solverPerformance entry for the named field
        template<class Type>
        void setSolverPerformance
        (
            const word& name,
            const SolverPerformance<Type>& sp
        ) const;
 
        //- Add/set the solverPerformance entry, using its fieldName
        template<class Type>
        void setSolverPerformance
        (
            const SolverPerformance<Type>& sp
        ) const;
};
 
 
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
 
} // End namespace Foam
 
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
 
#ifdef NoRepository
    #include "dataTemplates.C"
#endif
 
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
 
#endif
 
// ************************************************************************* //
