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

  int input = 5;
  int num_vals = 2;
  int param1;
  int param2;
  // int param3;

  for (int i = 0; i < nums.size(); i += num_vals){

    // ----- 1 ------

    if (nums[i] % 10 == 1){
      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
      }

      nums[nums[i+3]] = param1 + param2;
      num_vals = 4;
    }


    // ----- 2 ------

    else if (nums[i] % 10 == 2){
      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
      }

      nums[nums[i+3]] = param1 * param2;
      num_vals = 4;
    }


    // ----- 3 ------

    else if (nums[i] % 10 == 3){
      std::cout << "3: INPUT 5" << std::endl;
      nums[nums[i+1]] = input;
      num_vals = 2;
    }


    // ----- 4 ------

    else if (nums[i] % 10 == 4){
      std::cout << "4: " << nums[nums[i+1]] << std::endl;
      num_vals = 2;
    }


    // ----- 5 ------

    else if (nums[i] % 10 == 5){
      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
      }

      if (param1 != 0){
        i = param2;
        num_vals = 0;
      }
      else {
        num_vals = 3;
      }
    }


    // ----- 6 ------

    else if (nums[i] % 10 == 6){
      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
      }

      if (param1 == 0){
        i = param2;
        num_vals = 0;
      }
      else {
        num_vals = 3;
      }
    }


    // ----- 7 ------

    else if (nums[i] % 10 == 7){
      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
      }

      if (param1 < param2){
        nums[nums[i+3]] = 1;
      }
      else {
        nums[nums[i+3]] = 0;
      }
      num_vals = 4;
    }


    // ----- 8 ------

    else if (nums[i] % 10 == 8){
      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
      }

      if (param1 < param2){
        nums[nums[i+3]] = 1;
      }
      else {
        nums[nums[i+3]] = 0;
      }

      if (param1 == param2){
        nums[nums[i+3]] = 1;
      }
      else {
        nums[nums[i+3]] = 0;
      }
      num_vals = 4;
    }

    // ----- 99 -----

    else if (nums[i] == 99){
      // std::cout << "99 END: " << nums[0] << std::endl;
      return nums[0];
    }
    else {
      std::cout << "ERROR: UNIDENTIFIED OPCODE " << nums[i] << " i: " << i << std::endl;
      return -1;
    }
  }
  return 0;
}

int main(){


  int input;
  char comma;
  std::vector<int> nums;

  std::cout << "gsfdfafad" << std::endl;

  while(std::cin >> input) {
    std::cin >> comma;
    nums.push_back(input);
  }

  print_vector(nums);

  std::cout << "HELLO" << std::endl;
  // for (int i = 0; i < 100; i++){
  //   nums[1] = i;
  //   for (int j = 0; j < 100; j++){
  //     nums[2] = j;
  //     if (program(nums) == 19690720){
  //       std::cout << "CORRECT! " << i << " " << j << std::endl;
  //       std::cout << "Answer: " << (100 * i) + j << std::endl;
  //     }
  //   }
  // }

  program(nums);

  return 0;
}
