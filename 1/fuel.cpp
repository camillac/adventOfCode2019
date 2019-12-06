#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cctype>

int fuel(int i){
  int fuel_needed = i/3 - 2;
  if (fuel_needed < 0){
    return 0;
  }
  return fuel_needed + fuel(fuel_needed);
}

int main(){
  int total = 0;
  int i = 0;

  std::ifstream fin("input.txt");
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }

  std::string input;

  while(getline(fin,input)) {
    i = stoi(input);
    total += fuel(i);
    std::cout << total << std::endl;
  }

  std::cout << "Final: " << total << std::endl;

}
