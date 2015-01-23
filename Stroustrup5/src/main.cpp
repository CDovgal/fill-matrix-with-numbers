#include <iostream>
#include <vector>
#include <string>
#include <ctime>

//struct Pair
//{
//  std::string name;
//  double value;
//};
//
//std::vector<Pair> pairs;
//
//double& value(const std::string& i_name)
//{
//  for (int i = 0; i < pairs.size(); ++i)
//  {
//    if (i_name == pairs[i].name)
//      return pairs[i].value;
//  }
//  Pair p = { i_name, 0 };
//  pairs.push_back(p);
//  return pairs[pairs.size() - 1].value;
//}
//
//typedef unsigned char u_char;
//typedef const unsigned char cu_char;
//typedef int* p_int;
//typedef char** ptp_char;
//typedef char(*p_arr)[3];
//typedef int* arr_of_pt[7];
////typedef int *arr_of_pt;
////typedef // array of 8 arrays of 7 pointers to int
//
//
//char a[3] = "av";
//p_arr parr = &a;

void swap_p(int* a, int* b)
{
  std::cout << "POINTERS. a and b before swap: " << *a << " " << *b << std::endl;
  int* temp;
  temp = a;
  a = b;
  b = temp;
  std::cout << "POINTERS. a and b before swap: " << *a << " " << *b << std::endl;
}

void swap_ref(int& a, int& b)
{
  std::cout << "REF. a and b before swap: " << a << " " << b << std::endl;
  int temp = a;
  a = b;
  b = temp;
  std::cout << "REF. a and b after swap: " << a << " " << b << std::endl;
}

void f(char){}

void g(char&){}

void h(const char&){}

struct Calendar
{
  std::string month;
  int day_count;
};

std::vector<Calendar> calend;

int main()
{
  calend.push_back({ "June", 30 });
  /*std::string buff;

  while (buff != "0")
  {
  std::cin >> buff;
  value(buff)++;
  }
  for (std::vector<Pair>::const_iterator p = pairs.begin(); p != pairs.end(); ++p)
  std::cout << "Name: " << p->name << "  " << "Value: " << p->value << std::endl;*/

  //char p = 's';

  //char* ss = &p;

  //std::cout << p << ss << std::endl;

  //int* arr[10] = {};
  //int arr2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  //int(&arr3)[10] = arr2;

  //char str_arr[] = { 'a', 'b', 'c' };
  //char* p_strarr = str_arr;

  //char* p1 = "D";

  //char* p_p = p1;
  //char** pp_p = {};

  //std::cout << p_p << pp_p << std::endl;

  //const int c_i = 5;
  //int s_i[10];
  //const int* p_c_i = s_i;
  //int* const c_p_i = s_i;

  //std::vector<int> vec_arr;
  //for (unsigned i = 0; i < vec_arr.size(); ++i)
  //  vec_arr.push_back(i);

  //std::vector<int>& ref_vec = vec_arr;

  //for (int i = 0; i < 10; ++i)
  //{
  //  std::cout << arr3[i] << std::endl;
  //  std::cout << p_strarr[i] << std::endl;
  //  //std::cout << vec_arr.at(i) << std::endl;
  //  //std::cout << ref_vec.at(i) << std::endl;
  //}

  /*int a = 1;
  int b = 9;

  swap_p(&a, &b);

  swap_ref(a, b);


  char str[] = "a short string";

  std::cout << sizeof(str) << " " << std::endl;


  char c;
  unsigned char uc;
  signed char sc;

  f('a'); g('a'); h('a');
  f(49); g(49); h(49);
  f(3300); g(3300); h(3300);

  f(c); g(c); h(c);
  f(uc); g(uc); h(uc);
  f(sc); g(sc); h(sc);*/

  /*char* month[12] = {"June","July","August", "September", "October", "November", "December", "January", "February", "March", "April", "May"};
  int day_count[12] = {30, 31, 30, 28, 29, 30, 30, 31, 30, 29, 27, 29};

  for (int i = 0; i < 12; ++i)
  {
    std::cout << month[i] << " : " << day_count[i] << std::endl;

    
  }
  for (unsigned i = 0; i < calend.size(); ++i)
  {
    std::cout << calend.at(i).month << " : " << calend.at(i).day_count << std::endl;
  }*/


  std::vector<int> i_vec;
  for (unsigned i = 0; i < 100000; ++i)
    i_vec.push_back(i);

  std::clock_t start;
  double duration;

  start = std::clock();

  for (std::vector<int>::const_iterator cit = i_vec.begin(); cit != i_vec.end(); ++cit)
    std::cout << *cit << std::endl;

  /*for (unsigned i = 0; i < i_vec.size(); ++i)
  std::cout << i_vec.at(i) << std::endl;*/

  duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

  std::cout << "printf: " << duration << '\n';

  



  return 0;
}