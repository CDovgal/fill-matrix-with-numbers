#ifndef CLASSA_H
#define CLASSA_H


class A
{
  int m_a;
public:
  A(int a) : m_a(a){}
  int Mult(int a, int b)
  {
    return a*b+m_a;
  }
  int Sum(int a, int b)
  {
    return a + b-m_a;
  }
};


int (A::*pFMult)(int, int) = &A::Mult;
int (A::*pFSum)(int, int) = &A::Sum;

#endif //!CLASSA_H