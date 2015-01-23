#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdarg.h>
#include <cstdarg>
#include <stdio.h>
#include <algorithm>
#include <vector>



void mini_printf(char *format, ...)
{
  char *data = format;
  int count = 0;
  char *pch;
  char buffer[256];
  char key[] = { '%d', '%ld', '%c', '%s', '%f', '%e', '%g', '%o', '%x', '%%' };
  char *key2 = "37";
  pch = strpbrk(data, key);
  while (pch != NULL)
  {
    printf("%c ", *pch);
    pch = strpbrk(pch + 1, key);
    ++count;
  }
  printf("\n%d\n", count);
}


void error(int severity, ...)
{
  va_list arg_list;
  va_start(arg_list, severity);
  for (;;)
  {
    char* p = va_arg(arg_list, char*);
    if (p == 0) break;
    std::cerr << p << ' ';
  }
  va_end(arg_list);
  std::cerr << '\n';
  if (severity) exit(severity);
}

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


int main()
{
  const char* Null_cp = 0;
  error(0, "ehh", "fdsafa", "dsadada", Null_cp);

  char *name = "World";
  macro_printf("Hello %s %d %d %d %d!\n", name, 5, 6, 8, 7);

  

  //mini_printf("Hello World! %d %d\n");

  return 0;
}