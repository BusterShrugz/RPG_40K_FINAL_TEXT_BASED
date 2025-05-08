#pragma once

//spaceMarine.h
#include "Character_RE.h"
/************************************************************************************
 * Reese Edens
 * SpaceMarine class:
 * Represents a Space Marine character in an RPG game.
 * Inherits from the Character class and adds specific attributes and methods.
 * - marine honor is a damage buffer that increases damage output by 5 points
 * - displayCharacter: Overrides the base class method to include marineHonor in the output.
 * - takeDamage: Public wrapper for the base class takeDamage method.
 **********************************************************************************/
class SpaceMarine : public Character
{
private:
    int marineHonor; 

public:
  //  SpaceMarine( string name, string race, int health, vector<string> weapons, vector<string> items, SkillSet* skillSet, int marineHonor );
    SpaceMarine( const string &name, const string &race, int health, const vector<string> &weapons, const vector<string> &items,
              SkillSet *skills,
              int marineHonor);
    void displayCharacterInWindow( int x, int y ) const; // Override displayCharacter
    int getMarineHonor( ) const { return marineHonor; } // Getter for marineHonor
    int getHealth( ) const { return health; } // Getter for health
    string getName( ) const { return name; } // Getter for name
    // Function to apply marine honor as a damage buffer
    void applyMarineHonor( int& dmgAmount ) const
    {
       dmgAmount += marineHonor; // Increase damage by marine honor
    }
    // Override takeDamage to apply marine honor logic
    void takeDamage( int dmgAmount )
    {
       applyMarineHonor( dmgAmount ); // Apply marine honor before taking damage
       Character::takeDamage( dmgAmount ); // Call base class takeDamage
    }
    
};

//RE