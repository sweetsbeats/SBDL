#include "SBDL_Data.h"


void SBDL_Data::setData( std::string s ) {
  wipeCurrent();
  
  data = new std::string(s);
  dataType = DataType::STRING;
}

void SBDL_Data::setData( int32_t i ) {
  wipeCurrent();
  
  data = new int32_t{i};
  dataType = DataType::INT;
}

void SBDL_Data::setData( float f ) {
  wipeCurrent();
  
  data = new float{f};
  dataType = DataType::FLOAT;
}




template <>
std::string SBDL_Data::getData<std::string>() {
  if ( dataType !=  DataType::STRING ) {
    printf("Error in SBDL_Data: '%s' is not of type string!\n");
    return std::string("err");
  }
  else {
    return *(std::string*)data;
  }
}



template <>
int32_t SBDL_Data::getData<int32_t>() {
  if (dataType != DataType::INT) {
    printf("Error in SBDL_Data: '%s' is not of type int!\n");
    return 0;
  }
  else {
    return *(int32_t*)data;
  }
}



template <>
float SBDL_Data::getData<float>() {
  if ( dataType !=  DataType::FLOAT ) {
    printf("Error in SBDL_Data: '%s' is not of type float!\n");
    return 0.0f;
  }
  else {
    return *(float*)data;
  }
}



void SBDL_Data::wipeCurrent() {
  if ( dataType == DataType::NIL ) {

  }
  else {
    if ( dataType == DataType::STRING )
      delete (std::string*)data;
    
    if ( dataType == DataType::INT )
      delete (int32_t*)data;
    
    if ( dataType == DataType::FLOAT )
      delete (float*)data;

    data = nullptr;
    
  }
}


SBDL_Data::SBDL_Data() {

}

SBDL_Data::~SBDL_Data() {
  wipeCurrent();
}
