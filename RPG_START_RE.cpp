
#include <iostream>

#include "Character_RE.h"
#include "SkillSet_RE.h"

#include "CharacterLog_RE.h"
#include "raylib.h"



using namespace std;

   enum ScreenState {
      MAIN_MENU,
      CREATE_CHARACTER,
      VIEW_CHARACTER,
      LIST_CHARACTERS,
      VIEW_MARINE,
      VIEW_ELF,
      VIEW_KNIGHT
   };
   ScreenState currentScreen = MAIN_MENU;

   

   // Define buttons-->button creation(x,y,height,width, font size)
   Rectangle createBtn = { 200, 100, 400, 30 };  
   Rectangle viewBtn = { 200, 140, 400, 30 };
   Rectangle listBtn = { 200, 180, 400, 30 };
   Rectangle marineBtn = { 200, 220, 400, 30 };
   Rectangle elfBtn = { 200, 260, 400, 30 };
   Rectangle knightBtn = { 200, 300, 400, 30 };
   Rectangle backBtn = { 540, 520, 320, 30 };

   ////creating pointers to my pre-set characters
   SpaceMarine* marine = nullptr;
   SpaceElf* elf = nullptr;
   ChaosKnight* knight = nullptr;

/*************************************************************************
* RPG part Four
* Reese Edens
* 5/4/2025
* ***Fixed feedback from RPG part 4***
*
* main():
*     Asks the user if they would like to create, or use their own
*     character sheet.
*  They can select one of the eight options and if they choose
*  something different, it gives the user an error saying invalid
*
*  -Description:
*        Displays a menu for the user to create or view characters.
*        Allows the user to create a new character, view an existing
*        character, or view built-in characters.
*        The user can also list all saved characters.
*        The program continues until the user chooses to exit.
*  -Input:
*       The user selects an option from the menu.
*  -Output:
*       Displays character details, skills, and a list of saved characters.
*  -Returns:
*       Returns 0 on successful execution.
*
**************************************************************************/
   int main( )
   {
      // Initialize built-in characters
      initializeBuiltInCharacters( marine, elf, knight );
      InitWindow( 800, 600, "40K Player Creation" );
      SetTargetFPS( 60 );

      const char message[ 128 ] = "Welcome to the Grim Dark Future\nSelect an option.";
      int framesCounter = 0;


      Texture2D background = LoadTexture( "thumb-1920-1304586.jpg" );
      int running = 0;
      while ( WindowShouldClose( ) == false )
      {
         while ( running == 0 )
         {
            Vector2 mousePos = GetMousePosition( );
            BeginDrawing( );
            ClearBackground( BLACK );

            DrawTexture( background, 0, 0, WHITE );

            DrawText( TextSubtext( message, 0, framesCounter / 10 ), 210, 160, 20, MAROON );


            switch ( currentScreen )
            {
               case MAIN_MENU:
                  DrawText( "Main Menu", 350, 50, 20, WHITE );

                  DrawRectangleRec( createBtn, CheckCollisionPointRec( mousePos, createBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "Create Character", createBtn.x + 10, createBtn.y + 5, 20, WHITE );

                  DrawRectangleRec( viewBtn, CheckCollisionPointRec( mousePos, viewBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "View Created Character", viewBtn.x + 10, viewBtn.y + 5, 20, WHITE );

                  DrawRectangleRec( listBtn, CheckCollisionPointRec( mousePos, listBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "List of Existing Characters", listBtn.x + 10, listBtn.y + 5, 20, WHITE );

                  DrawRectangleRec( marineBtn, CheckCollisionPointRec( mousePos, marineBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "View Brother Malthus", marineBtn.x + 10, marineBtn.y + 5, 20, WHITE );

                  DrawRectangleRec( elfBtn, CheckCollisionPointRec( mousePos, elfBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "View Farseer Elarique", elfBtn.x + 10, elfBtn.y + 5, 20, WHITE );

                  DrawRectangleRec( knightBtn, CheckCollisionPointRec( mousePos, knightBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "View Lord Varkhos", knightBtn.x + 10, knightBtn.y + 5, 20, WHITE );

                  DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "Back to Main Menu", backBtn.x + 10, backBtn.y + 5, 20, DARKPURPLE );
                  if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) )
                  {
                     if ( CheckCollisionPointRec( mousePos, createBtn ) ) currentScreen = CREATE_CHARACTER;

                     else if ( CheckCollisionPointRec( mousePos, viewBtn ) )currentScreen = VIEW_CHARACTER;

                     else if ( CheckCollisionPointRec( mousePos, listBtn ) ) currentScreen = LIST_CHARACTERS;

                     else if ( CheckCollisionPointRec( mousePos, marineBtn ) ) currentScreen = VIEW_MARINE;

                     else if ( CheckCollisionPointRec( mousePos, elfBtn ) )currentScreen = VIEW_ELF;

                     else if ( CheckCollisionPointRec( mousePos, knightBtn ) ) currentScreen = VIEW_KNIGHT;
                  }
                  break;


               case CREATE_CHARACTER:
                  ClearBackground( DARKGRAY );
                  createCharacter( );
                  DrawText( "Creating character...", 250, 200, 20, GREEN );
                  DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : GRAY );
                  DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                  if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                  {
                     currentScreen = MAIN_MENU;
                  }
                  running = 1;
                  break;

               case VIEW_CHARACTER:
                  viewCharacter( );
                  DrawText( "Viewing saved character...", 250, 200, 20, GREEN );
                  DrawRectangleRec( viewBtn, CheckCollisionPointRec( mousePos, viewBtn ) ? DARKGRAY : GRAY );
                  DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                  if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                  {
                     currentScreen = MAIN_MENU;
                  }
                  running = 1;
                  break;

               case LIST_CHARACTERS:
                  listSavedCharacters( );
                  DrawText( "Listing characters...", 250, 200, 20, GREEN );
                  DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : GRAY );
                  DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                  if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                  {
                     currentScreen = MAIN_MENU;
                  }
                  running = 1;
                  break;

               case VIEW_MARINE:

                  marine->displayCharacter( );
                  DrawText( "Brother Malthus stats loaded.", 250, 200, 20, GREEN );
                  DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : GRAY );
                  DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                  if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                  {
                     currentScreen = MAIN_MENU;
                  }
                  running = 1;
                  break;

               case VIEW_ELF:
                  elf->displayCharacter( );
                  DrawText( "Farseer Elarique stats loaded.", 250, 200, 20, GREEN );
                  DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : GRAY );
                  DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                  if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                  {
                     currentScreen = MAIN_MENU;
                  }
                  running = 1;
                  break;

               case VIEW_KNIGHT:
                  knight->displayCharacter( );
                  DrawText( "Lord Varkhos stats loaded.", 250, 200, 20, GREEN );
                  DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : GRAY );
                  DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                  if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                  {
                     currentScreen = VIEW_KNIGHT;
                  }
                  running = 1;
                  break;
            }EndDrawing( ); 
         }

         
      }CloseWindow( );
   }
   //OLD CODE OF MAIN MENU VIA TERMINAL
   //   // Initialize built-in characters
         

         //   int marineAttack = 30; // Space Marine attack damage
         //   int elfAttack = 20; // Eldar attack damage
         //
         //   cout << "Welcome to the RPG Character Creator!\n";
         //   int choice;
         //   do
         //   {
         //      cout << "\n1. Create new character\n2. View created character\n3. List of existing created characters\n"
         //         "4. View Brother Malthus\n5. View Farseer Elarique\n"
         //         "6. View Lord Varkhos\n7. Sample Battle\n8. Exit\nChoose an option: ";
         //      cin >> choice;

         //      switch ( choice )
         //      {     // Create a new character
         //         case 1: createCharacter( ); break;
         //            // List player created characters
         //         case 2: viewCharacter( ); break;
         //            // List saved characters
         //         case 3: listSavedCharacters( ); break;
         //            // Display built-in characters
         //         case 4: marine->displayCharacter( ); break;
         //         case 5: elf->displayCharacter( ); break;
         //         case 6: knight->displayCharacter( ); break;
         //         case 7:
         //               {
         //                  // Simulated combat: Space Marine attacks Chaos Knight
         //                  cout << "\n*** Combat Begins ***\n";
         //                  cout << marine->getName( ) << " attacks " << knight->getName( ) << " for 30 damage (Blocked 15).\n";
         //                  knight->damageReduction( marineAttack );
         //                  cout << knight->getName( ) << "'s remaining health: " << knight->getHealth( ) << endl;

         //                  // Eldar attacks Space Marine
         //                  cout << elf->getName( ) << " attacks " << marine->getName( ) << " for 20 damage.\n";
         //                  marine->takeDamage(elfAttack);
         //                  cout << marine->getName( ) << "'s remaining health: " << marine->getHealth( ) << endl;

         //               }  break;

         //         case 8: cout << "Exiting...\n"; break;
         //         default: cout << "Invalid choice. Try again.";
         //      }
         //   } while ( choice != 8 );
         //   delete marine;
         //   delete elf;
         //   delete knight;
         //   return 0;
         //}
         // 
   
/***************************************************************************************
PROBLEMS:
   -**FIXED 2/25/25** I am having problems but working on fixing it not being able to
   read the files I already have created unless I
create them through the console on the VSC.
   - I am having problems with the display character function not displaying the skills of the character.
   - I am having problems with the display character function not displaying the skills of the character.
   - I am having problems with the display character function not displaying the skills of the character.
   fixed 4/10/25

   4/28/25
   -Removed inquisitor character to make only 3 characters to upgrade stas on and overload etc..
   -
   RE
*/
