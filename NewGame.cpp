#include <iostream>
#include <string>
#include <iomanip>
#include <thread>
#include <fstream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

//-----------------------------------------------------------------------------

// this is the dialogue function for the a\game
std::string rearrangePoem() {
  //reset screen and cursor
  std::cout << "\033[2J";
  std::cout << "\033[1;1H"; 


  std::string default_poems[] = {
    "Spring is in the air now",
    "Is death really worth it",
    "The night was dark and cold",
    "The sun shines bright today",
    "Birds singing in the trees"
  };


  
  std::srand(std:: time(nullptr));
  int selected_poem_index = std:: rand() % 5;

  
  std::vector<std::string> poem_words;
  std::string selected_poem = default_poems[selected_poem_index];
  std::istringstream iss(selected_poem);
  std::string words;

  while(iss >> words) {
    poem_words.push_back(words);
  }

  
  std::random_shuffle(poem_words.begin(), poem_words.end());

  std::cout << "Rearrange the words in the following poem: \n";
  for(auto word : poem_words) {
    std::cout << word << " ";
  }

  
  std::cout << "\n";

  int num_words = poem_words.size();
  std::vector<std::string> arranged_poem(num_words);

  std::string poem = "";
for (int i = 0; i < num_words; i++) {
  std::cout << "Enter word #" << i + 1 << ": ";
  std::cin >> arranged_poem[i];
  poem += arranged_poem[i];
  if (i != num_words - 1) {
    poem += " ";
  }
}



  
  if (poem == selected_poem) {
    std::cout << "\nTHE BOUNTY HUNTER IS CONVINCED! YOU ARE FREE TO GO" << "\n";
    std::cout << "\n[ THE END ]" << "\n";
  }

    
  else{
    std::cout << "\nBAD POEM! THE BOUNTY HUNTER ARRESTS YOU!\n";
    std:: cout << "\nThe correct poem was: " << selected_poem << "\n";
    std:: cout << "\n[ THE END ]\n";
  }

  
  return 0;
}

// user defined function that saves the game 
//you can call this save game function 
void saveGame(const std::string& filename, int player1Health, int player1Level, const std::string& player1Name, int player2Health, int player2Level, const std::string& player2Name) {
  std::ofstream outfile;
  outfile.open(filename);
  outfile << player1Health << "\n";
  outfile << player1Level << "\n";
  outfile << player1Name << "\n";
  outfile << player2Health << "\n";
  outfile << player2Level << "\n";
  outfile << player2Name << "\n";
  outfile.close();
}

//-----------------------------------------------------------------------------


//funciton for the hgih dice roll
 int highDiceRoll(int diceRoll1, int diceRoll2) {

   // here is where we implement the randomizer, first setting the time to zero
    srand(time(0));

   // we want to simulate a dice roll between 1 and 12 because this will be two 6 sided dice rolls. 
    diceRoll1 = (rand() % 12) + 1;

    std:: cout << "\033[1;31m------------------------------------\033[0m\n";
    std::cout << "\033[1;31mYOUR ATTACK DAMAGE IS: \033[0m\n" << diceRoll1 << "\n";
    std:: cout << "\033[1;31m------------------------------------\033[0m\n";
    std::cout << "\033[1;31mBOUNTY HUNTER: NICE SHOT PAL', MY TURN!!\n";
    std:: cout << "\033[1;31m------------------------------------\033[0m\n";

   
    std::this_thread::sleep_for(std::chrono::seconds(3));
    srand(time(0));
    diceRoll2 = (rand() % 12) + 1;

    std:: cout << "\033[1;31m------------------------------------\033[0m\n";
    std::cout << "\033[1;31mYOUR ENEMIES ATTACK DAMAGE IS: \033[0m\n" << diceRoll2 << "\n";
    std:: cout << "\033[1;31m------------------------------------\033[0m\n";

   
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "\033[2J"; // Resets screen and cursor
    std::cout << "\033[1;1H";
            
    if (diceRoll1 > diceRoll2) {
        std:: cout << "\033[1;31m------------------------------------\033[0m\n";
        std::cout << "\033[1;31mYOU WIN! VICTORY COMES AT A COST.\033[0m\n";
        std:: cout << "\033[1;31m------------------------------------\033[0m\n";
    } else if (diceRoll1 < diceRoll2) {

        std:: cout << "\033[1;31m------------------------------------\033[0m\n";
        std::cout << "\033[1;31mTHE BOUNTY HUNTER WINS! NOW YOU JOIN THE GRAVEYARD\033[0m\n";
        std:: cout << "\033[1;31m------------------------------------\033[0m\n";
    } else {
        std:: cout << "\033[1;31m------------------------------------\033[0m\n";
        std::cout << "\033[1;31mTIE GAME!\033[0m\n";
        std:: cout << "\033[1;31m------------------------------------\033[0m\n"; 
    }

   return 0;
}


//-----------------------------------------------------------------------------



 int lowDiceRoll(int diceRoll1, int diceRoll2) {
    srand(time(0));
            int diceRoll3 = (rand() % 6) + 1;
            std::cout << "\033[1;31m------------------------------------\033[0m\n";
            std::cout << "\033[1;31mYOUR ROLL IS: \033[0m" << "\033[1;31m" << diceRoll3 << "\033[0m\n";
            std::cout << "\033[1;31m------------------------------------\033[0m\n";
            std::cout << "\033[1;31mBOUNTY HUNTER: NICE SHOT PAL', MY TURN!!\033[0m\n";
            std::cout << "\033[1;31m------------------------------------\033[0m\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            srand(time(0));
            int diceRoll4 = (rand() % 6) + 1;
            
            std::cout << "\033[1;31mENEMY ROLL IS: \033[0m" << "\033[1;31m" << diceRoll4 << "\033[0m\n";
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::cout << "\033[2J"; // Resets screen and cursor
            std::cout << "\033[1;1H";
            if (diceRoll3 < diceRoll4) {
                std:: cout << "\033[1;31m------------------------------------\033[0m\n";
                std::cout << "\033[1;31mYOU WIN! VICTORY COMES AT A COST.\033[0m\n";
                std:: cout << "\033[1;31m------------------------------------\033[0m\n";
            } else if (diceRoll3 > diceRoll4) {
                std:: cout << "\033[1;31m------------------------------------\033[0m\n";
                std::cout << "\033[1;31mTHE BOUNTY HUNTER WINS! NOW YOU JOIN THE GRAVEYARD\033[0m\n";
                std:: cout << "\033[1;31m------------------------------------\033[0m\n";
            } else {
                std:: cout << "\033[1;31m------------------------------------\033[0m\n";
                std::cout << "\033[1;31mTIE GAME!\033[0m\n";
                std:: cout << "\033[1;31m------------------------------------\033[0m\n";
            }

   return 0;
 }

//-----------------------------------------------------------------------------


struct character {
  int health;
  int level;
  std:: string name;
  };


//-----------------------------------------------------------------------------


// move the struct definition outside the intro function
character player; 
character player2;





//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------




int main() {

  int choice;
  // define players
  character player;
  player.health = 100;
  player.level = 1;
  character player2;
  player2.health = 100;
  player2.level = 1;



//-----------------------------------------------------------------------------
  

  // enter player names 
  for(int i = 0; i < 2; i++){
    if(i == 0){
       //reset screen and cursor
      std::cout << "\033[2J";
      std::cout << "\033[1;1H";

      std:: cout << "\033[1;31mENTER PLAYER ONE NAME: \033[0m";
      std:: cin >> player.name;
    }
    else{
       
      std::cout << "\033[1;31mENTER PLAYER TWO NAME: \033[0m";
      std::cin >> player2.name;
    }
  }



//-----------------------------------------------------------------------------

  
  // display player names 
  
  // clear screen and reset cursor to line one
  std::cout << "\033[2J";
  std::cout << "\033[1;1H";




//-----------------------------------------------------------------------------


  
  // read player names out (in color)
  
  //player 1:
  std:: cout << "\033[1;31m------------------------------------\033[0m\n";
  std:: cout << "\033[1;31mP L A Y E R # 1: \033[0m" 
  << "\033[1;32m" << player.name << "\033[0m" << "\n";
  std:: cout << "\033[1;31mHP:  \033[0m"<< "\033[1;32m" << player.health << "\033[0m" << "\n";
  std:: cout << "\033[1;31mLEVEL: \033[0m"<< "\033[1;32m" << player.level << "\033[0m" << "\n";
  //-----------------------------------------------------------------------------
  //player 2:
  std:: cout << "\033[1;31mP L A Y E R # 2: \033[0m" 
  << "\033[1;32m" << player2.name << "\033[0m" << " \n";
  std:: cout << "\033[1;31mHP:  \033[0m"<< "\033[1;32m" << player2.health << "\033[0m" << "\n";
  std:: cout << "\033[1;31mLEVEL: \033[0m"<< "\033[1;32m" << player2.level << "\033[0m" << "\n";
  std:: cout << "\033[1;31m------------------------------------\033[0m\n";



//-----------------------------------------------------------------------------




  
  //wait for 2 seconds
  std::this_thread::sleep_for(std::chrono::seconds(3)); 

  //reset screen and cursor
  std::cout << "\033[2J";
  std::cout << "\033[1;1H"; 






//-----------------------------------------------------------------------------





  
  // game start screen 
  std:: cout << "\033[1;31m------------------------------------\033[0m\n";
  std::cout << "\033[1;31mWELCOME TO MILK RUN: THE RPG GAME \033[0m" << "\n";
  std::cout << "\033[1;31mYOU ENCOUNTER A BOUNTY HUNTER, YOU ARE WANTED! \033[0m" << "\n";
  std:: cout << "\033[1;31m------------------------------------\033[0m\n";
  std::cout << "\033[1;31mGO FIGHT [1] TALK IT OUT [2] FLEE [3] OR SAVE GAME [4] \033[0m";
  std:: cin >> choice;





//-----------------------------------------------------------------------------





  // !!!!!!! _____________________ MAIN BRANCH _________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  switch(choice) {



    // THIS IS THE FIGHTING FUNCTION 
    case 1:
      std:: cout << "\033[1;31m------------------------------------\033[0m\n";
      std::cout << "\033[1;31mYOU BEGIN TO FIGHT THE BOUNTY HUNTER, ROLL THE DICE FOR YOUR ATTACK! \033[0m" << "\n";
      std:: cout << "\033[1;31m------------------------------------\033[0m\n";
      std::cout << "\033[1;31mGO HIGH DICE ROLL [1] LOW DICE ROLL [2] OR SAVE GAME [4] \033[0m";
      std:: cin >> choice;
          if(choice == 1){
            std::cout << "\033[2J";
            std::cout << "\033[1;1H"; 
           int diceRoll1 = 0;
              int diceRoll2 = 0;
              highDiceRoll(diceRoll1, diceRoll2);
                
          }
          else if(choice == 2){
            std::cout << "\033[2J";
            std::cout << "\033[1;1H"; 
             int diceRoll1 = 0;
                int diceRoll2 = 0;
                lowDiceRoll(diceRoll1, diceRoll2);
                  
          }
            else{
              std::cout << "\033[2J";
              std::cout << "\033[1;1H"; 
              std:: cout << "ERROR: INVALID ENTRY!\n";
            }
        //dice roll pre defined funciton 
    break;
    









    // THIS IS THE DODEG FUNCITON 
    case 2:
      std:: cout << rearrangePoem();
    break;








    // THIS IS THE FLEE FUNCTION 
    case 3:
      // this function could mean continuing the game story, or possibly filtering to a new opponent. 
      //or even just skipping a turn ior something
      std:: cout << "TRY TO RUN FUNCTION\n";
    break;





    // THIS IS THE SAVE GAME FUNCTION 
    case 4:
      saveGame("SaveGame.txt", player.health, player.level, player.name, player2.health, player2.level, player2.name);
      std:: cout << "GAME SAVED!\n";
    break;
    
    default:
      std:: cout << "Error, invalid input\n";
    break;
  }
  


  // THIS IS THE END OF THE MAIN SWITCH FUNCITON 
  return 0;
}







//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------









// UNDER CONSTRUCTION THIS IS THE SECOND FUNCTION
int intro(character& player, character& player2){
  std::ifstream infile("playerdata.txt");
  
  infile >> player.health;
  infile >> player.level;
  infile >> player.name;
  infile >> player2.health;
  infile >> player2.level;
  infile >> player2.name;
  infile.close();
  std:: cout << "\033[1;31m------------------------------------\033[0m\n";
  std::cout << "\033[1;31mWELCOME TO MILK RUN: THE RPG GAME \033[0m" << "\n";
  std:: cout << "\033[1;31m------------------------------------\033[0m\n";
 
  return 0;
}
  











//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// cyoa game 

// structs (classes) 

// arrays

// fstream 

// user defined functions

// library functions 

// function for a dice roll radnomizer

// if you roll roll wrong and loose then you die 

// if you win the dice roll it declares that you win and this is one of the endings 

// for the dodge, the ai rolls the dice aswell as you and whoevers dice roll is higher wins

//make a poetry check in specch check where you organize words from an array

