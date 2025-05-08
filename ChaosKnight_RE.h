#pragma once

#include "Character_RE.h"
/* *******************************************************************************
 * Reese Edens
 * ChaosKnight class:
 * Represents a Chaos Knight character in an RPG game.
 * Inherits from the Character class and adds specific attributes and methods.
 * - chaosPoints: A damage reduction modifier that divides incoming damage by 2.
 * - damageReduction: Method to apply the chaos points, reducing incoming damage.
 * - takeDamage: Overrides the base class method to apply the chaos points logic.
 * *******************************************************************************/
class ChaosKnight : public Character
{
   private:
       int chaosPoints; // chaos points are damage reduction modifiers divides damage by 2

   public:
       //ChaosKnight( string name,string race, int health,vector<string> weapons, vector<string> items, SkillSet* skills, int chaosPoints );
       ChaosKnight(const string &name,const string &race, int health,const vector<string> &weapons,const vector<string> &items,
                   SkillSet *skills, int chaosPoints);


       void displayCharacterInWindow( int x, int y ) const; // Override displayCharacter
       int getChaosPoints( ) const { return chaosPoints; } // Getter for chaospoints
       int getHealth( ) const { return health; } // Getter for health
       string getname( ) const { return name; } // Getter for name

       //damage divided by chaosPoint:
       void damageReduction( int dmgAmount )
       {
          int reducedDamage = dmgAmount / chaosPoints; // Reduce damage by chaos points
          Character::takeDamage( reducedDamage ); // Call base class takeDamage
       }

       void takeDamage( int dmgAmount ) { Character::takeDamage( dmgAmount ); }
};

//RE