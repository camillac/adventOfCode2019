#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cctype>
#include <vector>

void print_vector(std::vector<int> nums){
  for (int i = 0; i < nums.size(); i++){
    std::cout << nums[i] << ",";
    if (i%4 == 3){
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

int program(std::vector<int> nums){

  for (int i = 0; i < nums.size(); i += 4){
    if (nums[i] == 1){
      nums[nums[i+3]] = nums[nums[i+1]] + nums[nums[i+2]];
    }
    else if (nums[i] == 2){
      nums[nums[i+3]] = nums[nums[i+1]] * nums[nums[i+2]];
    }
    else if (nums[i] == 99){
      // std::cout << "99 END: " << nums[0] << std::endl;
      return nums[0];
    }
    else {
      std::cout << "ERROR: UNIDENTIFIED OPCODE" << std::endl;
      return -1;
    }
  }
  return 0;
}

int main(){


  int input;
  char comma;
  std::vector<int> nums;

  while(std::cin >> input) {
    std::cin >> comma;
    nums.push_back(input);
  }

  print_vector(nums);


  for (int i = 0; i < 100; i++){
    nums[1] = i;
    for (int j = 0; j < 100; j++){
      nums[2] = j;
      if (program(nums) == 19690720){
        std::cout << "CORRECT! " << i << " " << j << std::endl;
        std::cout << "Answer: " << (100 * i) + j << std::endl;
      }
    }
  }

  return 0;
}
