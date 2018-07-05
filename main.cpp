#include <stdio.h>
#include <cstdint>
#include <iostream>

#include "SBDL_Data.h"

SBDL_Data testData;

int main (int argc, char* argv[] ) {

  testData.setData(  42  );
  std::cout << testData.getData<int32_t>() << std::endl;
  
  testData.setData(4.2f);
  std::cout << testData.getData<float>() << std::endl;
  
  testData.setData(std::string("Hello, Sailor!"));
  std::cout << testData.getData<std::string>() << std::endl;
  
  return 0;
}

