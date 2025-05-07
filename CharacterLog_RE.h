#pragma once
#include "SpaceMarine_RE.h"
#include "ChaosKnight_RE.h"
#include "SpaceElf_RE.h"

/***********************************************************************************
* Reese Edens
* initializeBuiltInCharacters():
*   Initializes built-in characters with their respective skills and attributes.
* -Description:
*     This function creates instances of SpaceMarine, SpaceElf, and ChaosKnight
*     with predefined skills and attributes. It uses temporary variables for
*     attributes like chaosPoints, marineHonor, and elfMagic.
* -Input:
*    None, but it modifies the pointers passed by reference.
* -Output:
*    Initializes the pointers to the respective character objects.
* -Returns:
*    None, but modifies the pointers to point to the created character objects.
***********************************************************************************/
void initializeBuiltInCharacters( SpaceMarine*& marine, SpaceElf*& elf, ChaosKnight*& knight );

//RE