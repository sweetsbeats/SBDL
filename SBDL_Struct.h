#pragma once

struct SBDL_Struct {

  std::string name;
  std::map<std::string, SBDL_Data> member_data;

  template <class T>
  T get( std::string key );
  
};
