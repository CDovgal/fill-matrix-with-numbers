#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include "Vector.h"


int main()
{
  /*std::vector<char> alphabet;
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

  std::vector<std::string> fruits;*/
  /*std::string fruit;
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
  std::cout << fruits.size() << std::endl;*/
  /*fruits.push_back("peach");
  fruits.push_back("apple");
  fruits.push_back("kivifruit");
  fruits.push_back("pear");
  fruits.push_back("starfruit");
  fruits.push_back("grape");;
  fruits.push_back("avocado");
  fruits.push_back("orange");
  fruits.push_back("lemon");

  std::vector<std::string> citrus;
  citrus.push_back("orange");
  citrus.push_back("lemon");

  for (unsigned i = 0; i < citrus.size(); ++i)
  {
    for (unsigned j = 0; j < fruits.size(); ++j)
    {
      if (citrus.at(i) == fruits.at(j))
        fruits.erase(fruits.begin()+j);
    }
  }*/
  /*for (unsigned i = 0; i < fruits.size(); ++i)
  {
  if (fruits.at(i).at(0) == 'a')
  std::cout << fruits.at(i) << std::endl;
  }*/
  

  /*for (unsigned i = 0; i < fruits.size(); ++i)
  {
    if (fruits.at(i).at(0) == 'a')
      fruits.erase(fruits.begin() + i);
  }*/
  /*for (unsigned i = 0; i < fruits.size(); ++i)
  {
    std::cout << fruits.at(i) << std::endl;
  }*/

  Vector<int> vec(5);
  
  std::cout << vec.size() << std::endl;




  return 0;
}