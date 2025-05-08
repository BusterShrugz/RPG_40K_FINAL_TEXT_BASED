#include "SpaceMarine_RE.h"

#include <iostream>
#include "raylib.h"
#include <vector>
using namespace std;
/* ***************************************************************
* Reese Edens
* SpaceMarine class constructor  
* Initializes a SpaceMarine character with specific attributes.
* ****************************************************************/
SpaceMarine::SpaceMarine( const string &name, const string &race, int health, const vector<string> &weapons, const vector<string> &items, SkillSet* skills, int marineHonor )
   : Character( name, race, health, weapons, items, skills), marineHonor( marineHonor )
{ }

void SpaceMarine::displayCharacterInWindow( int x, int y ) const
{
    Character::displayCharacterInWindow( x,  y ); // Call base class method
    std::cout << "Marine Honor: " << marineHonor << "\n"; // Display Space Marine-specific attribute
    cout << "=========================\n";
}

//RE