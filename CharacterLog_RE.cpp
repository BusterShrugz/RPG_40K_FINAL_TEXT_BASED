#include "CharacterLog_RE.h"
#include "ChaosKnight_RE.h"
#include "SpaceMarine_RE.h"
#include "SpaceElf_RE.h"
/**********************************************************************************
* initializeBuiltInCharacters():
*     Initializes built-in characters with their respective skills and attributes.
*  -Description:
*        This function creates instances of SpaceMarine, SpaceElf, and ChaosKnight
*        with predefined skills and attributes. It uses temporary variables for
*        attributes like chaosPoints, marineHonor, and elfMagic.
*  -Input:
*       None, but it modifies the pointers passed by reference.
*  -Output:
*       Initializes the pointers to the respective character objects.
*  -Returns:
*       None, but modifies the pointers to point to the created character objects.
*  -Note:
*       The function uses dynamic memory allocation for SkillSet objects and
*       character objects, which should be managed properly to avoid memory leaks.
* ********************************************************************************/


using namespace std;
void initializeBuiltInCharacters( SpaceMarine*& marine, SpaceElf*& elf, ChaosKnight*& knight )
{
   SkillSet* marineSkills = new SkillSet( 10, 8, 7, 6, 5, 3, 6, 9, 4, 7 );
   SkillSet* eldarSkills = new SkillSet( 7, 9, 10, 6, 6, 8, 5, 10, 4, 5 );
   SkillSet* chaosKnightSkills = new SkillSet( 10, 6, 8, 9, 5, 4, 7, 3, 6, 8 );

   int chaosPoints = 2; // chaos points are damage reduction modifiers divides damage by 2
   knight = new ChaosKnight( "Lord Varkhos", "Chaos Knight", 500, { "Doomsday Axe", "Corrupted Sigil" },
                             { "Daemon Engine" }, chaosKnightSkills, chaosPoints );

   int marineHonor = 15; // marine honor is a damage buffer that increases damage output by 5 points
   marine = new SpaceMarine( "Brother Malthus", "Space Marine", 150,
                             { "Chainsword", "Bolter" }, { "Frag Grenade" },
                             marineSkills, marineHonor );

   int elfMagic = 50; // elf magic is a shield that soaks damage before damage going onto health
   elf = new SpaceElf( "Farseer Elarique", "Eldar", 100, { "Witchblade" },
                       { "Spirit Stone", "Rune Armor" }, eldarSkills, elfMagic );
}

//RE