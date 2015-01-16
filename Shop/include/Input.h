#include <iostream>
#include "Category.h"


class BaseInput : public Category
{
public:
  BaseInput();
};

class AliveInput : public BaseInput
{
public:
  AliveInput(){};
};

class UnaliveInput : public BaseInput
{
public:
  UnaliveInput(){};
};


class BaseOutput : public Category
{
public:
  BaseOutput();
};

class AliveOutput : public BaseOutput
{
public:
  AliveOutput();
};

class UnaliveOutput : public BaseOutput
{
public:
  UnaliveOutput();
};

