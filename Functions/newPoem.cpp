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

std::string rearrangePoem() {

  std::string default_poems[] = {
    "Spring is in the air now",
    "Is death really worth it",
    "The night was dark and cold",
    "The sun shines bright today",
    "Birds singing in the trees"
  };


  std::srand(std::time(nullptr));
  int selected_poem_index = std::rand() % 5;

  std::vector<std::string> poem_words = std::split(default_poems[selected_poem_index], " ");

  std::random_shuffle(poem_words.begin(), poem_words.end());

  std::cout << "\n";
  resetScreen();
  std::cout << "Rearrange the words in the following poem: \n";
  for (auto word : poem_words) {
    std::cout << word << " ";
  }

  std::cout << "\n";

  std::string poem = "";
  for (auto word : poem_words) {
    poem += word;
    if (word != poem_words.back()) {
      poem += " ";
    }
  }

  std::cout << "\n";
  std::cout << "Enter the rearranged poem: ";
  std::string rearranged_poem;
  std::cin >> rearranged_poem;

  if (poem == rearranged_poem) {
    std::cout << "\nCongratulations! You rearranged the poem correctly!" << "\n";
  } else {
    std::cout << "\nSorry, your rearranged poem doesn't match the original poem.";
  }

  return 0;
}