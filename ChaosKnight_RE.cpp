#include <iostream>
#include <vector>
#include "raylib.h"
#include "ChaosKnight_RE.h"


using namespace std;
/* 
* ChaosKnight class constructor
* Initializes a ChaosKnight character with specific attributes.
*/

ChaosKnight::ChaosKnight(const string &name, const string &race, int health, const vector<string> &weapons, const vector<string> &items, SkillSet* skills, int chaosPoints )
   : Character( name, race, health, weapons, items, skills), chaosPoints( chaosPoints )
{ }

void ChaosKnight::displayCharacterInWindow( int x, int y ) const
{
    Character::displayCharacterInWindow( x, y ); // Call base class method
    DrawText( TextFormat( "Chaos Points: %d", chaosPoints ), 100, 40, 20, RED );
}

//RE