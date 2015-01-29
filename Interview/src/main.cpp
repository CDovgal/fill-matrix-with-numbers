#include <iostream>
#include <vector>
#include <string>

template <typename T>
void bubble_sort(T& i_container)
{
  for (T::size_type i = 0; i < i_container.size() - 1; ++i)
  {
    for (T::size_type j = i; j + 1 > 0; --j)
    {
      if (i_container[j] > i_container[j + 1])
        std::swap(i_container[j], i_container[j + 1]);
    }
  }
}

template <typename T>
void invert_string(T& i_str)
{
  T::size_type length = i_str.size();
  for (T::size_type i = 0; i < (length / 2); ++i)
    std::swap(i_str[i], i_str[length - i - 1]);
}

int main()
{
  std::vector<int> int_vec;
  int_vec.push_back(2);
  int_vec.push_back(5);
  int_vec.push_back(3);
  int_vec.push_back(1);
  for (unsigned i = 0; i < int_vec.size(); ++i)
    std::cout << int_vec.at(i) << std::endl;

  bubble_sort(int_vec);

  for (unsigned i = 0; i < int_vec.size(); ++i)
    std::cout << int_vec.at(i) << std::endl;

  std::string str = "abcdef";
  invert_string(str);
  std::cout << str.c_str() << std::endl;


  int i = 5;
  printf("%d %d %d \n", ++i, ++i, ++i);






  return 0;
}