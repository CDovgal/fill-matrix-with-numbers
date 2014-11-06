#pragma once

#include <vector>

class Trace
{
public:
  Trace();

  void read(const std::vector<std::string>& route);

  void addRecord(const std::string& i_record);

  void pushToFile(const std::string& i_filename);

  void readFromFile(const std::string& i_filename);
};