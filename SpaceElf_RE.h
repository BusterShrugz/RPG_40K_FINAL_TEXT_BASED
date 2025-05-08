#pragma once
// spaceElf.h
// Header file for SpaceElf class, derived from Character class

#include "Character_RE.h"

/* ***********************************************************************************
 * Reese Edens
 * SpaceElf class:
 * Represents a Space Elf character in an RPG game.
 * Inherits from the Character class and adds specific attributes and methods.
 * - elfMagic: A shield that absorbs damage before it affects health.
 * - magicShield: Method to apply the magic shield, reducing incoming damage.
 * - takeDamage: Overrides the base class method to apply the magic shield logic./
 * * **********************************************************************************/
using namespace std;

class SpaceElf : public Character  // Inherit from Character class
{
private:
   
int elfMagic; // elfMagic is a shield that soaks damage before damage going onto health

public:
    // Constructor for Space Elf
   // SpaceElf( string name, string race, int health, vector<string> weapons, vector<string> items, SkillSet* skills, int elfMagic );
    SpaceElf(const string &name, const string &race, int health, const vector<string> &weapons, const vector<string> &items,
              SkillSet *skills, int elfMagic);
    void displayCharacterInWindow( int x, int y )const; // Override displayCharacter
    int getElfMagic( ) const { return elfMagic; } // Getter for elfMagic
    int getHealth( ) const { return health; } // Getter for health
    string getName( ) const { return name; } // Getter for name

    void magicShield( int dmgAmount )  // Function to apply magic shield
    {
       // Magic shield absorbs damage before it affects health
       int shieldedDamage = dmgAmount - elfMagic; // Reduce damage by elfMagic
       if ( shieldedDamage < 0 ) shieldedDamage = 0; // Ensure no negative damage
       Character::takeDamage( shieldedDamage ); // Call base class takeDamage
    }

    // for takeDamage
    void takeDamage( int dmgAmount ) { Character::takeDamage( dmgAmount ); }
};


//RE