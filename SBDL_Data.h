#pragma once

#include <string>

#include <cstdint>

enum class DataType {
  STRING,
  INT,
  FLOAT,
  STRUCT,
  NIL  
    
};

struct SBDL_Data {
  std::string name;
  
  DataType dataType = DataType::NIL;

  void* data;

  void setData( std::string s );
  void setData( int32_t     i );
  void setData( float       f );

  template <class T>
  T getData();

  
  void wipeCurrent();

  SBDL_Data();
  ~SBDL_Data();
  
};
