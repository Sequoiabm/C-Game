#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

void resetScreen(){
  std::cout << "\033[2J";
  std::cout << "\033[1;1H";
}

std:: string rearrangePoem() {
  
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

  std:: cout << " \n";
  resetScreen();
  std::cout << "Rearrange the words in the following poem: \n";
  for(auto word : poem_words) {
    std::cout << word << " ";
  }

  
  std::cout << "\n";

  int num_words = poem_words.size();
  std::vector<std::string> arranged_poem(num_words);

  std::string poem = "";

  std::cout << "\033[2J";
  std::cout << "\033[1;1H"; 
for (int i = 0; i < num_words; i++) {
  std::cout << "Enter word #" << i + 1 << ": ";
  std::cin >> arranged_poem[i];
  poem += arranged_poem[i];
  if (i != num_words - 1) {
    poem += " ";
  }
 }



  
  if (poem == selected_poem) {
    std::cout << "\nCongratulations! You rearranged the poem correctly!" << "\n";
  }

    
  else{
    std::cout << "\nSorry, your rearranged poem doesn't match the original poem.";
  }

  
  return 0;
}