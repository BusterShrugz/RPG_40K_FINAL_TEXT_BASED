#pragma once

// Class: SkillSet
// Purpose: Stores 10 RPG-related skill attributes for a character.
//          Provides methods to set and get skill values, and display skills.
/**************************************************************************************
* skillset.h   
*  -Description:
*     This header file defines the SkillSet class, which is used to manage
*     the skills of a character in an RPG game. The class includes attributes
*     for various skills such as combat proficiency, tactical mastery, and
*     psychic potential, among others. It provides constructors for initializing
*     these skills, getter methods to retrieve individual skill values, and a
*     method to display all skills in a formatted manner.
*  -Input:
*     The class can be initialized with specific skill values through its
*     parameterized constructor, or it can be initialized with default values
*     using the default constructor.
*  -Output:
*     The displaySkills method outputs the skill values to the console in a
*     readable format.
*  -Returns:
*     The class does not return any values directly, but it provides methods
*     to access and display the skill values.
***************************************************************************************/

using namespace std;
class SkillSet {

   private:
   int combatProficiency;
   int tacticalMastery;
   int psychicPotential;
   int survivalInstinct;
   int techMastery;
   int stealthSkill;
   int persuasionInt;
   int faithZeal;
   int medicalTech;
   int pilotSkill;

   public:
   // Constructors
   SkillSet( );
   SkillSet( int combat, int tact, int psychic, int survive, int tech, int stealth, int persuade, int faith, int medi, int pilot );

   void displaySkills( int x, int y, int lineSpacing ) const;

   //getter functions for each skill
   int getCombat( ) const { return combatProficiency; }
   int getTact( ) const { return tacticalMastery; }
   int getPsychic( ) const { return psychicPotential; }
   int getSurvive( ) const { return survivalInstinct; }
   int getTech( ) const { return techMastery; }
   int getStealth( ) const { return stealthSkill; }
   int getPersuade( ) const { return persuasionInt; }
   int getFaith( ) const { return faithZeal; }
   int getMedi( ) const { return medicalTech; }
   int getPilot( ) const { return pilotSkill; }

  
};


  //RE