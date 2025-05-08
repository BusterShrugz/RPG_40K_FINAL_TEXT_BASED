
#include <iostream>
#include <vector>
#include "raylib.h"
#include "SpaceElf_RE.h"
using namespace std;
// SpaceElf class constructor
// Initializes a SpaceElf character with specific attributes.


SpaceElf::SpaceElf( const string &name, const string &race, int health, const vector<string> &weapons, const vector<string> &items, SkillSet* skills, int elfMagic )
    : Character( name, race, health, weapons, items, skills ), elfMagic( elfMagic )
{ }

void SpaceElf::displayCharacterInWindow( int x, int y ) const
{
    Character::displayCharacterInWindow( x, y ); // Call base class method
    DrawText( TextFormat( "Elf Magic: %d", elfMagic ), 100, 40, 20, BLUE );
}

//RE 