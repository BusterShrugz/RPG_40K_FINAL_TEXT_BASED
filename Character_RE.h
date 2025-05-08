#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "SkillSet_RE.h"

using namespace std;
// Function prototypes
void createCharacter( );
void viewCharacter( );
void listSavedCharacters( );    // Function to list saved characters
/***********************************************************************************
*  Reese Edens
* Class: Character
* Class Purpose: Represents a character in an RPG game.
* Description:
*     The Character class encapsulates the attributes and behaviors of a character
***********************************************************************************/
class Character {

   private:
   
   protected:
      void takeDamage( int damage ); // Function to take damage
      int health;// Default health value  
      void damageReduction( int amount );   // Applies reduced damage (e.g., armor mitigation)
      string name;
      string race;
      
      vector<string> weapons; // List of weapons
      vector<string> items;   // List of items
      // Pointer to SkillSet object for skills
      SkillSet* skills;

   public:
    
      Character(const string &name, const string &race, int health, const vector<string> &weapons, const vector<string> &items, SkillSet* skills );
      ~Character( ); // Destructor to clean up SkillSet memory
      Character( const Character& other ); // Copy constructor
      Character& operator=( const Character& other ); // Overloaded assignment operator
      // Display character details
      // // Function to display character stats, weapons, items, and skills
      void displayCharacterInWindow( int x, int y ) const;

      virtual string getName( ) const; // Getter for name
      string getRace( ) const; // Getter for race
      int getHealth( ) const;  // Getter for health
      //virtual void takeDamage( int amount ); // Virtual function to take damage, can be overridden by derived classes
      void addWeapon( const string& weapon ); // Add a weapon
      void addItem( const string& item ); // Add an item

      //Operator overloads
      bool operator<( const Character& other ) const;  //comapre characters based on health
      friend ostream& operator<<( ostream& os, const Character& character ); // Stream I/O
};

//RE