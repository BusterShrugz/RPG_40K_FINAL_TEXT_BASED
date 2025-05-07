
#include <iostream>
#include <vector>
#include "SpaceElf_RE.h"
using namespace std;
// SpaceElf class constructor
// Initializes a SpaceElf character with specific attributes.


SpaceElf::SpaceElf( const string &name, const string &race, int health, const vector<string> &weapons, const vector<string> &items, SkillSet* skills, int elfMagic )
    : Character( name, race, health, weapons, items, skills ), elfMagic( elfMagic )
{ }

void SpaceElf::displayCharacter( ) const
{
    Character::displayCharacter( ); // Call base class method
    std::cout << "Space Elf Wisdom: " << elfMagic << "\n"; // Display Eldar-specific attribute
    cout << "=========================\n";
}

//RE 