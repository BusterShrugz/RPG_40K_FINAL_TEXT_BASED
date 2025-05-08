#include "SkillSet_RE.h"

#include "raylib.h"
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
*  -Description:
*       Displays the skill levels of a character to the console.
*  -Input:
*       None
*  -Output:
*       Text output listing each skill and its corresponding value.
*  -Returns:
*       Nothing (void function).
******************************************************************************************/
void SkillSet::displaySkills(int x, int y, int lineSpacing ) const
{
	DrawText( "Skills:\n", 100,255, 20, BLUE );
	y += lineSpacing;
	
   DrawText( TextFormat( "Combat Proficiency: %d", combatProficiency ), x, y, 18, LIGHTGRAY ); y += lineSpacing;
   DrawText( TextFormat( "Tactical Mastery: %d", tacticalMastery ), x, y, 18, LIGHTGRAY ); y += lineSpacing;
   DrawText( TextFormat( "Psychic Potential: %d", psychicPotential ), x, y, 18, LIGHTGRAY ); y += lineSpacing;
   DrawText( TextFormat( "Survival Instinct: %d", survivalInstinct ), x, y, 18, LIGHTGRAY ); y += lineSpacing;
   DrawText( TextFormat( "Tech Mastery: %d", techMastery ), x, y, 18, LIGHTGRAY ); y += lineSpacing;
   DrawText( TextFormat( "Stealth Skill: %d", stealthSkill ), x, y, 18, LIGHTGRAY ); y += lineSpacing;
   DrawText( TextFormat( "Persuasion Intellect: %d", persuasionInt ), x, y, 18, LIGHTGRAY ); y += lineSpacing;
   DrawText( TextFormat( "Faith Zeal: %d", faithZeal ), x, y, 18, LIGHTGRAY ); y += lineSpacing;
   DrawText( TextFormat( "Medical Tech: %d", medicalTech ), x, y, 18, LIGHTGRAY ); y += lineSpacing;
   DrawText( TextFormat( "Pilot Skill: %d", pilotSkill ), x, y, 18, LIGHTGRAY );
}
/************************************************************************************/