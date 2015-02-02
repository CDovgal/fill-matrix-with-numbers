#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main()
{
  std::vector<char> alphabet;
  for (int i = 65; i < 91; ++i)
    alphabet.push_back(i);

  for (int i = 0; i < alphabet.size(); ++i)
    std::cout << alphabet.at(i);
  std::cout << std::endl;

  for (std::vector<char>::const_iterator cit = alphabet.cbegin(); cit != alphabet.cend(); ++cit)
    std::cout << *cit;
  std::cout << std::endl;

  for (std::vector<char>::const_reverse_iterator rcit = alphabet.crbegin(); rcit != alphabet.crend(); ++rcit)
    std::cout << *rcit;
  std::cout << std::endl;

  std::vector<std::string> fruits;
  std::string fruit;
  for (int i = 0; i < 6; ++i)
  {
    std::cin >> fruit;
    fruits.push_back(fruit);
  }
  if (!std::is_sorted(fruits.begin(), fruits.end()))
    std::sort(fruits.begin(), fruits.end());
  else
    std::cout << "The container is sorted." << std::endl;
  for (unsigned i = 0; i < fruits.size(); ++i)
    std::cout << fruits.at(i) << " ";
  std::cout << std::endl;
  std::cout << fruits.size() << std::endl;




  return 0;
}