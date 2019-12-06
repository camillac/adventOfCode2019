#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cctype>
#include <vector>


int orbits(std::string name, std::vector<std::string> center, std::vector<std::string> orbiting, int num){
  // std::cout << "RECURSION!!" << std::endl;
  std::vector<int> indexes;

  for (int i = 0; i < center.size(); i++){
    if (center[i] == name){
      indexes.push_back(i);
    }
  }

  // int nums = 0;

  if (indexes.size() == 0){
    // std::cout << name << " " << num << std::endl;
    return num;
  }

  int nums = 0;
  for (int i = 0; i < indexes.size(); i++){
    nums += orbits(orbiting[indexes[i]], center, orbiting, num+1);
    // std::cout << name << " " << nums << std::endl;

  }

  return nums + num;

}

bool not_in(std::vector<int> used, int index){
  for (int i = 0; i < used.size(); i++){
    if (used[i] == index){
      return false;
    }
  }
  return true;
}

int star2(std::string name, std::vector<std::string> center, std::vector<std::string> orbiting, int num, std::vector<int> * used, int & final){
  // std::cout << "RECURSION!!" << std::endl;
  std::vector<int> indexes0;
  std::vector<int> indexes1;

  for (int i = 0; i < center.size(); i++){
    if (orbiting[i] == name && not_in(*used, i)){
      indexes0.push_back(i);
      used->push_back(i);
    }
  }
  for (int i = 0; i < center.size(); i++){
    if (center[i] == name && not_in(*used, i)){
      indexes1.push_back(i);
      used->push_back(i);
    }
  }

  if (name == "SAN"){
    // std::cout << name << " " << num << std::endl;
    final = num - 2;
    return true;
  }

  int nums = 0;
  for (int i = 0; i < indexes0.size(); i++){
    if (star2(center[indexes0[i]], center, orbiting, num+1, used, final)) {
      return true;
    }
    // std::cout << name << " " << nums << std::endl;

  }
  for (int i = 0; i < indexes1.size(); i++){
    if (star2(orbiting[indexes1[i]], center, orbiting, num+1, used, final)){
      return true;
    }
    // std::cout << name << " " << nums << std::endl;

  }

  return false;

}

int main(){

  std::string input0, input1;

  std::vector<std::string> center;
  std::vector<std::string> orbiting;

  // std::vector<std::string> all;
  int numOrbits;


  while(std::cin >> input0 >> input1) {
    center.push_back(input0);
    orbiting.push_back(input1);
  }

  std::vector<int> * used = new std::vector<int>;
  int i = 0;

  std::cout << orbits("COM", center, orbiting, 0) << std::endl;
  std::cout << star2("YOU", center, orbiting, 0, used, i) << " " << i << std::endl;

  delete used;

  return 0;
}
