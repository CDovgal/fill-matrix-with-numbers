#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<string> correlationCodeGenerator(int number)
{
  deque<int> bin;
  deque<string> transformed;

  for (; number; number >>= 1)
  {
    bin.push_front(number & 1);
  }
  transformed.resize(bin.size());

  transform(begin(bin), end(bin), begin(transformed), [](int i){ return i==0 ? "01" : "10"; });

  return transformed;
}


int main()
{
  int number;
  cout << "Enter number:" << endl;
  cin >> number;

  deque<string> transf = correlationCodeGenerator(number);

  for (unsigned i = 0; i < transf.size(); ++i)
    cout << transf.at(i).c_str();
  cout << endl;

  return 0;
}