/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Application
    AUSMplusPreFlux

Description
    AUSM+ Arbitrary Lagrangian-Eulerian (ALE) flux class, computes numerical
    fluxes based on AUSM+ ALE scheme. Uses primitive variables as input and
    gives back conservative numerical fluxes.

    Luo, H.; Baum, Joseph D. and Löhner R. "On the computation of multi-
    material flows using ALE formulation."
    Journal of Computational Physics 194 (2004): 304–328.

Author
    Oliver Borm  All rights reserved.

SourceFiles
    AUSMplusPreFlux.H

\*---------------------------------------------------------------------------*/

#ifndef AUSMplusPreFlux_H
#define AUSMplusPreFlux_H

#include "fvCFD.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class AUSMplusPreFlux Declaration
\*---------------------------------------------------------------------------*/

class AUSMplusPreFlux
{

public:

    //- Default Constructor
    AUSMplusPreFlux(){}


    // Destructor - default

    // Member Functions

    //- Update fluxes based on current left and right states
    void evaluateFlux
    (
        scalar& rhoFlux,
        vector& rhoUFlux,
        scalar& rhoEFlux,
        const scalar pLeft,
        const scalar pRight,
        const vector ULeft,
        const vector URight,
// //
//     const scalar TLeft,
//     const scalar TRight,
// //
        const scalar rhoLeft,
        const scalar rhoRight,
// //
        const scalar kLeft,
        const scalar kRight,

	const scalar UrefLeft2,
	const scalar UrefRight2,
// //
//     const scalar RLeft,
//     const scalar RRight,
//     const scalar CvLeft,
//     const scalar CvRight,
// //
        const scalar kappaLeft,
        const scalar kappaRight,
// //
        const vector Sf,
        const scalar magSf,
        const vector dotX,
        const scalar Konstant
    ) const;

};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
