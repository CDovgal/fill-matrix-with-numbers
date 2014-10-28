#include <iostream>

using namespace std;

float day_counter(int begin_sum, int desired_sum) // we'll get 365 days in year and 30 in month
{
  int days = 0;
  float depo_percent = 0.1;
  float income_aday = 0;

  income_aday = (begin_sum * depo_percent) / 365;

  days = (desired_sum - begin_sum) / income_aday;

  return days;
}


int main()
{
  int begin_sum, desired_sum = 0;

  cout << "Enter initial sum and desired sum: \n";
  cin >> begin_sum >> desired_sum;

  int days = day_counter(begin_sum, desired_sum);

  cout << "Desired sum you will get at " << days << " days.\n";

  return 0;
}