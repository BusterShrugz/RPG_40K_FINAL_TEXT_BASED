
#include "Character_RE.h"
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

   // Declare the variable using the enum type
   ScreenState currentScreen = ScreenState::MAIN_MENU;

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
      bool screenInitialized = false;

      Texture2D background = LoadTexture( "thumb-1920-1304586.jpg" );
      

      while ( !WindowShouldClose( ) )
      {
            Vector2 mousePos = GetMousePosition( );
            BeginDrawing( );
            ClearBackground( BLACK );
            DrawTexture( background, 0, 0, WHITE );
            DrawText( TextSubtext( message, 0, framesCounter / 10 ), 210, 160, 20, MAROON );

           switch ( currentScreen )
            {
               case MAIN_MENU:
                  DrawText( "Character Creation Menu", 200, 70, 20, RAYWHITE );
                      //creating button for character creation
                  DrawRectangleRec( createBtn, CheckCollisionPointRec( mousePos, createBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "Create Character", createBtn.x+ 10, createBtn.y + 5, 20, DARKPURPLE );
                      //creating button for created character visual
                  DrawRectangleRec( viewBtn, CheckCollisionPointRec( mousePos, viewBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "View Created Character", viewBtn.x + 10, viewBtn.y + 5, 20, DARKPURPLE );
                      //creating button for listing characters created
                  DrawRectangleRec( listBtn, CheckCollisionPointRec( mousePos, listBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "List of Existing Characters", listBtn.x + 10, listBtn.y + 5, 20, DARKPURPLE );
                      //creating button for marine visual
                  DrawRectangleRec( marineBtn, CheckCollisionPointRec( mousePos, marineBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "View Brother Malthus", marineBtn.x + 10, marineBtn.y + 5, 20, DARKPURPLE );
                      //creating button for eldar visual
                  DrawRectangleRec( elfBtn, CheckCollisionPointRec( mousePos, elfBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "View Farseer Elarique", elfBtn.x + 10, elfBtn.y + 5, 20, DARKPURPLE );
                      //creating button for knight visual
                  DrawRectangleRec( knightBtn, CheckCollisionPointRec( mousePos, knightBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "View Lord Varkhos", knightBtn.x + 10, knightBtn.y + 5, 20, DARKPURPLE );
                      //creating button for main menu return creation
                  /*DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : LIGHTGRAY );
                  DrawText( "Back to Main Menu", backBtn.x + 10, backBtn.y + 5, 20, DARKPURPLE );*/

                  if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) ) {
                     if ( CheckCollisionPointRec( mousePos, createBtn ) ){ currentScreen = CREATE_CHARACTER;}

                     else if ( CheckCollisionPointRec( mousePos, viewBtn ) ){currentScreen = VIEW_CHARACTER;}

                     else if ( CheckCollisionPointRec( mousePos, listBtn ) ){ currentScreen = LIST_CHARACTERS;}

                     else if ( CheckCollisionPointRec( mousePos, marineBtn ) ) {currentScreen = VIEW_MARINE;}

                     else if ( CheckCollisionPointRec( mousePos, elfBtn ) ){currentScreen = VIEW_ELF;}

                     else if ( CheckCollisionPointRec( mousePos, knightBtn ) ) {currentScreen = VIEW_KNIGHT;}
                  }
                  break;
                  /*******************************************************************************
                  * Create character screen
                  * If the user clicks on the create button, go to the create character screen
                  * If the user clicks on the view button, go to the view character screen
                  * If the user clicks on the list button, go to the list characters screen
                  * If the user clicks on the marine button, go to the view marine screen
                  * If the user clicks on the elf button, go to the view elf screen
                  * If the user clicks on the knight button, go to the view knight screen
                  ********************************************************************************/
                     case CREATE_CHARACTER:
                        if ( !screenInitialized )
                        {  
                           createCharacter( );
                           screenInitialized = true;
                        }
                        DrawText( "Creating character...", 250, 200, 20, GREEN );
                        DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : GRAY );
                        DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                        if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                        {
                           currentScreen = ScreenState::MAIN_MENU;
                           screenInitialized = false; // Reset the flag for the next time
                        }
                        break;
                     
                     case VIEW_CHARACTER:

                        // Update the function call to use the defined variable  
                        viewCharacterInWindow( " TEST 1", 100, 100 );
                        if ( !screenInitialized )
                        {
                           viewCharacterInWindow( " TEST 2", 100, 100 );
                           screenInitialized = true;
                        }
                        DrawText( "Viewing saved character...", 100, 75, 20, GREEN );
                        DrawRectangleRec( viewBtn, CheckCollisionPointRec( mousePos, viewBtn ) ? DARKGRAY : GRAY );
                        DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                        if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                        {
                           currentScreen = ScreenState::MAIN_MENU;
                           screenInitialized = false; // Reset the flag for the next time
                        }
                        break;

                     case LIST_CHARACTERS:
                        if ( !screenInitialized )
                        {
                           
                           listSavedCharactersInWindow( 100, 100);
                           screenInitialized = true;
                        }
                        listSavedCharactersInWindow(100,100);
                        DrawText( "Listing characters...", 100, 75, 20, GREEN );
                        DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : GRAY );
                        DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                        if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                        {
                           currentScreen = ScreenState::MAIN_MENU; 
                        }
                        break;

                     case VIEW_MARINE:
                        marine->displayCharacterInWindow( 100, 100 );
                        DrawText( "Brother Malthus stats loaded.", 250, 75, 20, GREEN );
                        DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : GRAY );
                        DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                        if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                        {
                           currentScreen = ScreenState::MAIN_MENU;
                        }
                        break;
                     
                     case VIEW_ELF:
                        elf->displayCharacterInWindow( 100, 100 );
                        DrawText( "Farseer Elarique stats loaded.", 250, 75, 20, GREEN );
                        DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : GRAY );
                        DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                        if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                        {
                           currentScreen = ScreenState::MAIN_MENU;
                        }
                        break;
                     
                     case VIEW_KNIGHT:

                        knight->displayCharacterInWindow( 100, 100 );
                        DrawText( "Lord Varkhos stats loaded.", 250, 75, 20, GREEN );   
                        DrawRectangleRec( backBtn, CheckCollisionPointRec( mousePos, backBtn ) ? DARKGRAY : GRAY );
                        DrawText( "Back", backBtn.x + 10, backBtn.y + 5, 20, WHITE );
                        if ( IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) && CheckCollisionPointRec( mousePos, backBtn ) )
                        {
                           currentScreen = ScreenState::MAIN_MENU;
                        }
                        break;
                     default:
                        break;
                     
            }EndDrawing( );
      }
      CloseWindow( );
      return 0;
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
