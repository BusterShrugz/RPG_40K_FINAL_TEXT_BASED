#include <string>
#include <iostream>
#include <vector>

#include <filesystem>
#include <fstream>
#include "SkillSet_RE.h"
#include "Character_RE.h"
#include "raylib.h"


namespace fs = std::filesystem;
using namespace std;
/*********************************************************************
* Reese Edens
* createCharacterFile():
*   Creates .txt file of the users input of characters and skills
*   of each character.
*  IF the user has a character sheet made already they have
*  the option to load their own sheet into the console.
*  RETURNS: Error if one occurred, and a .txt file or tells
*          the user the file they made was successful.
*********************************************************************/
void createCharacter( )
{  
   cout << "Enter character name, Press enter to create character.): ";
   string name;
   cin.ignore( );
   // Clear newline from previous input
   getline( cin, name );
   if ( name.empty( ) )
   {
      cout << "Error: Character name cannot be empty!" << endl;
      return;
   }
   // Replace spaces with underscores
   for ( char& c : name )
   {
      if ( c == ' ' ) c = '_'; // Replace spaces with underscores
   }
   // Create filename with .txt extension
   // Check if file already exists
   if ( fs::exists( name + ".txt" ) )
   {
      cout << "Error: Character file already exists! Please choose a different name." << endl;
      return;
   }
   // Create the file
   // Create a file with the character name
   // and write the character details to it
   string filename = name + ".txt";
   ofstream file( filename );

   if ( !file )
   {
      cout << "Error: Could not create file!" << endl;
      return;
   }

   cout << "Enter race: (Enter to continue) ";
   vector<string> raceList;
   string race;
   cin.ignore( );
   while ( race.empty() )
   {
      getline( cin, race);
      if ( race.empty( ) );
      raceList.push_back( race );
   }
   if ( raceList.empty( ) )
   {
      cout << "No race entered. Defaulting to 'None'." << endl;
      raceList.push_back( "None" );
   }

   cout << "Enter weapons (type one per line, press Enter on empty line to finish): ";
   vector<string> weaponList;
   string weapon;

   cin.ignore( ); // clear newline after previous input

   while ( weapon.empty())
   {
      getline( cin, weapon );
      if ( weapon.empty( ) );
      weaponList.push_back( weapon );
   }
   if ( weaponList.empty( ) )
   {
      cout << "No weapons entered. Defaulting to 'None'." << endl;
      weaponList.push_back( "None" );
   }
   // Items list
   // Prompt for items
   cout << "Enter items (type one per line, press Enter on empty line to finish): ";
   vector<string> itemList;
   string items;

   cin.ignore( ); // clear newline after previous input

   while ( items.empty() )
   {
      getline( cin, items );
      if ( items.empty( ) );
      itemList.push_back( items );
   }
   if ( itemList.empty( ) )
   {
      cout << "No items entered. Defaulting to 'None'." << endl;
      itemList.push_back( "None" );  // <- Use the vector, not the string
   }

   // Write to file
   file << "# Character Sheet\n";
   file << "# Character: " << name << endl;
   // Write race to file
   file << "Race: " << race << endl;
   // Write weapons to file
   file << "Weapons: ";
   for ( size_t i = 0; i < weaponList.size( ); ++i )
   {
      file << weaponList[ i ];
      if ( i < weaponList.size( ) - 1 ) file << ", ";
   }
   file << endl;
   // Write items to file
   file << "Items: ";
   for ( size_t i = 0; i < itemList.size( ); ++i )
   {
      file << itemList[ i ];
      if ( i < itemList.size( ) - 1 ) file << ", ";
   }
   file << endl;
   file << "\n# Attributes:\n";

   string attributes[ ] =
   {
       "Combat Proficiency: Skill with weapons and melee fighting",
       "Tactical Acumen: Strategy, planning, and decision - making",
       "Psychic Potential: Warp - based abilities, mind control, foresight",
       "Survival Instinct: Ability to endure harsh conditions and escape danger",
       "Tech Mastery: Understanding of technology and machinery",
       "Stealth & Infiltration: Ability to move unseen and perform assassinations",
       "Persuasion & Intimidation: Influence over allies and enemies",
       "Faith & Zealotry: Belief in gods, emperors, or the warp",
       "Medical & Biotech Knowledge: Healing, augmentations, and cybernetics",
       "Piloting & Vehicle Handling: Skill with aircraft, mechs, or ground vehicles"
   };

   for ( const string& attr : attributes )
   {
      int value;
      cout << "Enter " << attr << " (0-10): ";  // make sure loop has an exit condition
      cin >> value;
      file << attr << ": " << value << endl;
   }

   file.close( );
   cout << "Character saved in " << filename << endl;
}

/********************************************************************
* takeDamage():
*   Reduces the character's health by the specified damage amount.
*   If health drops below zero, it is set to zero.
******************************************************************/
void Character::takeDamage( int dmgAmount )
{
   health -= dmgAmount;
   if ( health < 0 ) health = 0;
}

/********************************************************************
* Character::Character():
*   Constructor for the Character class.
/********************************************************************/
// Constructor
Character::Character(const string &name,const string &race, int health,const vector<string> &weapons, const vector<string> &items, SkillSet* skills )
   : name( name ), race( race ), health( health ), weapons( weapons ), items( items ), skills( skills )
{ }
/********************************************************************
* Character::~Character():
*   Destructor for the Character class.
*   It deletes the dynamically allocated SkillSet object.
* ********************************************************************/
Character::~Character( )
{
   delete skills;
}

/********************************************************************
* Character::displayCharacter():
*  Displays character details
*  Copy constructor
********************************************************************/

Character::Character( const Character& other )
   : name( other.name ), race( other.race ), health( other.health ), weapons( other.weapons ), items( other.items )
{
   skills = new SkillSet( *other.skills );
}

// Assignment operator overload
/********************************************************************
* Character& Character::operator=():
*   Assignment operator overload for the Character class.
*   It checks for self-assignment and copies the attributes from another Character.
*   It also deletes the old SkillSet and creates a new one.
* *******************************************************************/
Character& Character::operator=( const Character& other )
{
   if ( this == &other ) return *this; // Self-assignment check

   name = other.name;
   race = other.race;
   health = other.health;
   weapons = other.weapons;
   items = other.items;

   delete skills; // Clean up old skillSet
   skills = new SkillSet( *other.skills ); // Create a new SkillSet

   return *this;
}

/**********************************************************************************
* displayCharacter():
* Summary:
* Displays character stats, weapons, items, and skills.
**********************************************************************************/
void Character::displayCharacterInWindow( int x, int y ) const
{

   int spacing = 30; // vertical space between lines
   int fontSize = 20; // font size for text
   Color fontColor = RAYWHITE; // font color 

   DrawText( ( "Character: " + name ).c_str( ), x, y, fontSize, fontColor );
   DrawText( ( "Race: " + race ).c_str( ), x, y + spacing, fontSize, fontColor );
   DrawText( ( "Health: " + std::to_string( health ) ).c_str( ), x, y + 2 * spacing, fontSize, fontColor );

   // Weapons
   std::string weaponText = "Weapons: ";
   for ( const auto& w : weapons ) weaponText += w + ", ";
   DrawText( weaponText.c_str( ), x, y + 3 * spacing, fontSize, fontColor );

   // Items
   std::string itemText = "Items: ";
   for ( const auto& i : items ) itemText += i + ", ";
   DrawText( itemText.c_str( ), x, y + 4 * spacing, fontSize, fontColor );

   // Skills (if SkillSet has a graphical display method)
   if ( skills )
   {
      skills->displaySkills( 100, 250, 30);
   }
   else
   {
      DrawText( "No skills assigned.", x, y + 5 * spacing, fontSize, fontColor );
   }
}

//     THIS IS DISPLAY TO TERMINAL WINDOW
//   // Display character details
//   cout << "=========================\n";
//   cout << "Character: " << name << "\n";
//   cout << "Race: " << race << "\n";
//   cout << "Starting Health: " << health << "\n";
//
//   cout << "Weapons: ";
//   for ( const auto& w : weapons ) cout << w << ", ";
//   cout << "\n";
//
//   cout << "Items: ";
//   for ( const auto& i : items ) cout << i << ", ";
//   cout << "\n";
//
//   // Display skills
//   if ( skills )
//   {
//      skills->displaySkills( );
//   }
//   else
//   {
//      cout << "No skills assigned.\n";
//   }
//   cout << "=========================\n";
//}
/********************************************************************
* Character::getName():
*   Returns the name of the character.
*   If no name is set, it returns an empty string.
* ********************************************************************/

string Character::getName( ) const
{
   return name;
}

// Operator overloads
/********************************************************************
* Character::operator<():
*   Less than operator overload for the Character class.
*   It compares characters based on their health.
* ********************************************************************/
bool Character::operator<( const Character& other ) const
{
   return this->health < other.health; // Compare based on health
}

ostream& operator<<( ostream& os, const Character& character )
{
   os << "Character " << character.name << " (" << character.race << ")\n";
   os << "Health: " << character.health << "\n";
   return os;
}


/********************************************************************
* viewCharacter():
*   Displays character details from a .txt file.
*   If the file does not exist, it shows an error message.
*********************************************************************/
// Function to view a character's details from a file
void viewCharacter( )
{
   string name;
   cout << "Enter character name (use underscores instead of spaces): ";
   cin >> name;
   string filename = name + ".txt";
   ifstream file( filename );

   if ( !file )
   {
      cout << "Error: Character file not found!" << endl;
      return;
   }

   string line;
   while ( getline( file, line ) )
   {
      cout << line << endl;
   }
   //if no name is entered, prompt again
   if ( line.empty( ) )
   {
      cout << "Error: Character file is empty!" << endl;
      return;
   }

   file.close( );
}

void listSavedCharacters( )
{
   cout << "===== Saved Characters =====\n";
   int count = 0;

   for ( const auto& entry : fs::directory_iterator( "." ) )
   {
      if ( entry.is_regular_file( ) && entry.path( ).extension( ) == ".txt" )
      {
         cout << "- " << entry.path( ).filename( ).string( ) << endl;
         ++count;
      }
   }
   if ( count == 0 )
   {
      cout << "No saved characters found.\n";
   }
   else
   {
      cout << "Total characters found: " << count << endl;
   }
   cout << "===========================\n";
}

//RE