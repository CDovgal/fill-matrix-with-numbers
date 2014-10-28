#include <iostream>

using namespace std;

double day_counter(double begin_sum, double desired_sum) // we'll take 365 days in year and 30 in month
{
  double days = 0;
  double depo_percent = 0.1;

  days = log10(desired_sum / begin_sum) / log10(1 + depo_percent);

  return days;
}


int main()
{
  double begin_sum, desired_sum = 0;

  cout << "Enter initial sum and desired sum: \n";
  cin >> begin_sum >> desired_sum;

  int days = day_counter(begin_sum, desired_sum);

  cout << "Desired sum you will get at " << days << " days.\n";

  return 0;
}