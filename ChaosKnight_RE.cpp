#include <iostream>
#include <vector>
#include "ChaosKnight_RE.h"


using namespace std;
/* 
* ChaosKnight class constructor
* Initializes a ChaosKnight character with specific attributes.
*/

ChaosKnight::ChaosKnight(const string &name, const string &race, int health, const vector<string> &weapons, const vector<string> &items, SkillSet* skills, int chaosPoints )
   : Character( name, race, health, weapons, items, skills), chaosPoints( chaosPoints )
{ }

void ChaosKnight::displayCharacter( ) const
{
    Character::displayCharacter( ); // Call base class method
    std::cout << "Chaos Points: " << chaosPoints << "\n"; // Display knight-specific attribute
    cout << "=========================\n";
}

//RE