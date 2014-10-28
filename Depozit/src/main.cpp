#include <iostream>

using namespace std;

double day_counter(double begin_sum, double desired_sum, double depo_percent)
{
  return log(desired_sum / begin_sum) / log1p(depo_percent);
}


int main()
{
  double begin_sum, desired_sum = 0;
  double depo_percent = 0.1;

  cout << "Enter initial sum and desired sum and: \n";
  cin >> begin_sum >> desired_sum;

  int days = day_counter(begin_sum, desired_sum, depo_percent);

  cout << "Desired sum you will get at " << days << " days.\n";

  return 0;
}