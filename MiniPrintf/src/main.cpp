#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdarg.h>
#include <cstdarg>
#include <stdio.h>
#include <string>

/*
%d	print an int argument in decimal
%ld	print a long int argument in decimal
%c	print a character
%s	print a string
%f	print a float or double argument
%e	same as %f, but use exponential notation
%g	use %e or %f, whichever is better
%o	print an int argument in octal (base 8)
%x	print an int argument in hexadecimal (base 16)
%%	print a single %
*/

void macro_printf(const char *format, ...)
{
  char buffer[256];
  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  perror(buffer);
  va_end(args);
}

void mini_printf(const char* pStr, ...)
{
  const char** ppS = &pStr;
  void* pV = ppS + 1;
  int i = 0;
  while (pStr[i] != 0)
  {
    if (pStr[i] == '%')
    {
      switch (pStr[++i])
      {
      case 'ld':
      {
                 long int* pLInt = (long int*)pV;
                 std::cout << *pLInt;
                 pV = pLInt + 1;
                 ++i;
                 break;
      }
      case 'd':
      {
                int* pInt = (int*)pV;
                std::cout << *pInt;
                pV = pInt + 1;
                ++i;
                break;
      }
      case 'c':
      {
                 char* pChar = (char*)pV;
                 std::cout << *pChar;
                 pV = pChar + 1;
                 ++i;
                 break;
      }
      case 's':
      {
                char** pString = (char**)pV;
                std::cout << *pString;
                pV = pString + 1;
                ++i;
                break;
      }
      case 'f':
      {
                double* pDbl = (double*)pV;
                std::cout << *pDbl;
                pV = pDbl + 1;
                ++i;
                break;
      }
        break;
      }
    }
    else
    {
      std::cout << pStr[i];
      ++i;
    }
  }
  std::cout << std::endl;
}


int main()
{
  /*char *name = "World";
  macro_printf("Hello %s %d %d %d %d!\n", name, 5, 6, 8, 7);*/

  mini_printf("Hello %s %d %d %f", "ololo", 2, 2, 2.2);

  return 0;
}