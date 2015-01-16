#include <iostream>

class Category
{
public:
  Category(){};
};

class Product : public Category
{
public:
  Product(){};
};

class Alive : public Product
{
public:
  Alive(){};
};

class Unalive : public Product
{
public:
  Unalive(){};
};