#ifndef IMAGE_DATA_H
#define IMAGE_DATA_H

#include <iostream>
#include <fstream>
#include <vector>


enum DrawKind
{
  RECTANGLE,
  ELLIPSE
};
std::ostream& operator<<(std::ostream& output, const DrawKind& i_type)
{
  output << (int)i_type << std::endl;
  return output;
}
std::istream& operator>>(std::istream& input, DrawKind& i_type)
{
  int typ;
  input >> typ;
  i_type = (DrawKind)typ;
  return input;
}

struct Color //divide into pen and brush111111111111111111111111111111111111
{
  COLORREF m_pen_color,
  m_brush_color;
  Color(COLORREF pen_color, COLORREF brush_color) :
    m_pen_color(pen_color),
    m_brush_color(brush_color){}
  friend std::ostream& operator<<(std::ostream& output, const Color& i_color)
  {
    output << i_color.m_pen_color << std::endl
      << i_color.m_brush_color << std::endl;
    return output;
  }
  friend std::istream& operator>>(std::istream& input, Color& i_color)
  {
    input >> i_color.m_pen_color >> i_color.m_brush_color;
    return input;
  }
};

struct Shape_size
{
  int left,
  top,
  right,
  bottom;
  Shape_size(int i_left, int i_top, int i_right, int i_bottom) :
    left(i_left),
    top(i_top),
    right(i_right),
    bottom(i_bottom){}
  friend std::ostream& operator<<(std::ostream& output, const Shape_size& i_size)
  {
    output << i_size.left << std::endl <<
      i_size.top << std::endl <<
      i_size.bottom << std::endl <<
      i_size.right << std::endl;
    return output;
  }
  friend std::istream& operator>>(std::istream& input, Shape_size& i_size)
  {
    input >> i_size.left >> i_size.top >> i_size.bottom >> i_size.right;
    return input;
  }
};

struct Shape_coords
{
  int x, y;
  Shape_coords(int i_x, int i_y) :
    x(i_x),
    y(i_y){}
  friend std::ostream& operator<<(std::ostream& output, const Shape_coords& i_coords)
  {
    output << i_coords.x << std::endl
      << i_coords.y << std::endl;
    return output;
  }
  friend std::istream& operator>>(std::istream& input, Shape_coords& i_coords)
  {
    input >> i_coords.x >> i_coords.y;
    return input;
  }
};


struct Image_Object
{
  Shape_size size;
  Shape_coords coords;
  Color color;
  DrawKind type;
  Image_Object(const Shape_size& i_size, const Shape_coords& i_coords, const Color& i_color, const DrawKind& i_type) :
    size(i_size),
    coords(i_coords),
    color(i_color),
    type(i_type){}
  Image_Object() : size({ 0, 0, 0, 0 }), coords({ 0, 0 }), color(RGB(255, 255, 255), RGB(255, 255, 255)), type((DrawKind)0){}
  friend std::ostream& operator<<(std::ostream& output, const Image_Object& i_object)
  {
    output << i_object.size <<
      i_object.coords <<
      i_object.color <<
      i_object.type << std::endl;
    return output;
  }
  friend std::istream& operator>>(std::istream& input, Image_Object& i_object)
  {
    input >> i_object.size >> i_object.coords >> i_object.color >> i_object.type;
    return input;
  }
};

#endif // !IMAGE_DATA_H