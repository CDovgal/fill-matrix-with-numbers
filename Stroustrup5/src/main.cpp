#include <iostream>
#include <vector>

struct Pair
{
  std::string name;
  double value;
};

std::vector<Pair> pairs;

double& value(const std::string& i_name)
{
  for (int i = 0; i < pairs.size(); ++i)
  if (i_name == pairs[i].name) return pairs[i].value;
  Pair p = {i_name, 0};
  pairs.push_back(p);
  return pairs[pairs.size() - 1].value;
}

int main()
{
  

  std::string buff;

  while (std::cin >> buff) value(buff)++;

  return 0;
}