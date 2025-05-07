#include "SkillSet_RE.h"
#include <iostream>



SkillSet::SkillSet( )
	: combatProficiency( 0 ), tacticalMastery( 0 ), psychicPotential( 0 ), survivalInstinct( 0 ),
techMastery( 0 ), stealthSkill( 0 ), persuasionInt( 0 ), faithZeal( 0 ), medicalTech( 0 ), pilotSkill( 0 )
{ }

SkillSet::SkillSet( int combat, int tact, int psychic, int survive, int tech, int stealth,
						  int persuade, int faith, int medi, int pilot )
	: combatProficiency( combat ), tacticalMastery( tact ), psychicPotential( psychic ), survivalInstinct( survive ),
	techMastery( tech ), stealthSkill( stealth ), persuasionInt( persuade ),
	faithZeal( faith ), medicalTech( medi ), pilotSkill( pilot )
{ }

  
/******************************************************************************************
* SkillSet::displaySkills( ):
*     Displays the skills of the character.
*     It prints out each skill with its value.
*     This function is called by the Character class to display skills.
*  -Description:
*        Creates several characters with their respective skills.
*  -Input:
*       None, as these characters are predefined.
*  -Output:
*       Displays the skills of each character when their displayCharacter method is called.
* *  -Returns:
*       None, as this is part of the character initialization process.
******************************************************************************************/
void SkillSet::displaySkills( ) const
{
	cout << "=========================\n";
	cout << "Skills:\n";
	cout << "Combat Proficiency: " << combatProficiency << "\n";
	cout << "Tactical Mastery: " << tacticalMastery << "\n";
	cout << "Psychic Potential: " << psychicPotential << "\n";
	cout << "Survival Instinct: " << survivalInstinct << "\n";
	cout << "Tech Mastery: " << techMastery << "\n";
	cout << "Stealth Skill: " << stealthSkill << "\n";
	cout << "Persuasion Intellect: " << persuasionInt << "\n";
	cout << "Faith Zeal: " << faithZeal << "\n";
	cout << "Medical Tech: " << medicalTech << "\n";
	cout << "Pilot Skill: " << pilotSkill << "\n";
	//cout << "=========================\n";
}
/************************************************************************************/