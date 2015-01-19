#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdarg.h>
#include <stdio.h>
#include <algorithm>
#include <vector>


char *convert(unsigned int num, int base)
{
  static char buf[33];
  char *ptr;

  ptr = &buf[sizeof(buf)-1];
  *ptr = '\0';
  do
  {
    *--ptr = "0123456789abcdef"[num%base];
    num /= base;
  } while (num != 0);
  return(ptr);
  return 0;
}
//-----------------------------------------------------


void macro_printf(const char *format, ...)
{
  char buffer[256];
  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  perror(buffer);
  va_end(args);
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




void string_printf(char *format, ...)
{
  std::string data = format;
  std::cout << data.c_str() << std::endl;
  std::vector<std::string> key = { "%%d", "%%ld", "%%c", "%%s", "%%f", "%%e", "%%g", "%%o", "%%x", "%%%" };

  for (unsigned i = 0; i < key.size(); ++i)
  {
    if (data.find(key.at(i)))
      std::cout << "found" << std::endl;
  }
}

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



int main()
{
  char *name = "World";
  //printf("Hello World!%d%d\n",2,2,2);

  //macro_printf("Hello %s %d %d!\n", name, 5, 6);

  mini_printf("Hello World! %d %d\n");

  //string_printf("Hello World! %d %d\n");

  return 0;
}