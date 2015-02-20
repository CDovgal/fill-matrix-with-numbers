#include "Image_Data.h"

Image_Object::Image_Object(const Shape_size& i_size, const Shape_coords& i_coords, const Color& i_color, const DrawKind& i_type) :
size(i_size),
coords(i_coords),
color(i_color),
type(i_type){}

Image_Object::Image_Object() : 
size({ 0, 0, 0, 0 }), 
coords({ 0, 0 }), 
color(RGB(255, 255, 255), RGB(255, 255, 255)), 
type((DrawKind)0){}


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

Color::Color(COLORREF pen_color, COLORREF brush_color) :
m_pen_color(pen_color),
m_brush_color(brush_color){}

std::ostream& operator<<(std::ostream& output, const Color& i_color)
{
  output << i_color.m_pen_color << std::endl
    << i_color.m_brush_color << std::endl;
  return output;
}

std::istream& operator>>(std::istream& input, Color& i_color)
{
  input >> i_color.m_pen_color >> i_color.m_brush_color;
  return input;
}

Shape_size::Shape_size(int i_left, int i_top, int i_right, int i_bottom) :
left(i_left),
top(i_top),
right(i_right),
bottom(i_bottom){}

std::ostream& operator<<(std::ostream& output, const Shape_size& i_size)
{
  output << i_size.left << std::endl <<
    i_size.top << std::endl <<
    i_size.bottom << std::endl <<
    i_size.right << std::endl;
  return output;
}

std::istream& operator>>(std::istream& input, Shape_size& i_size)
{
  input >> i_size.left >> i_size.top >> i_size.bottom >> i_size.right;
  return input;
}

Shape_coords::Shape_coords(int i_x, int i_y) :
x(i_x),
y(i_y){}

std::ostream& operator<<(std::ostream& output, const Shape_coords& i_coords)
{
  output << i_coords.x << std::endl
    << i_coords.y << std::endl;
  return output;
}

std::istream& operator>>(std::istream& input, Shape_coords& i_coords)
{
  input >> i_coords.x >> i_coords.y;
  return input;
}


std::ostream& operator<<(std::ostream& output, const Image_Object& i_object)
{
  output << i_object.size <<
    i_object.coords <<
    i_object.color <<
    i_object.type << std::endl;
  return output;
}

std::istream& operator>>(std::istream& input, Image_Object& i_object)
{
  input >> i_object.size >> i_object.coords >> i_object.color >> i_object.type;
  return input;
}


//ImageD::ImageD() : penColor(RGB(0, 0, 0)), brushColor(RGB(255, 255, 255))
//{
//  hPen = CreatePen(PS_SOLID, 1, penColor);
//  hOldBrush, hBrush = CreateSolidBrush(brushColor);
//  /*HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
//  hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);*/
//}
//
//
//ImageD::~ImageD()
//{
//  DeleteObject(hPen);
//}
//
//void ImageD::RedrawImage(HWND hwnd, HDC hdc)
//{
//  hdc = GetDC(hwnd);
//  for (unsigned i = 0; i < object_container.size(); ++i)
//  {
//    switch (object_container.at(i).type)
//    {
//    case RECTANGLE:
//      DrawRectangle(hdc, object_container.at(i));
//      break;
//    case ELLIPSE:
//      DrawEllipse(hdc, object_container.at(i));
//      break;
//    }
//  }
//  ReleaseDC(hwnd, hdc);
//}
//
//void ImageD::DrawEllipse(HDC hdc, const Image_Object& i_object)
//{
//  Ellipse(hdc, i_object.size.left, i_object.size.top, i_object.size.right, i_object.size.bottom);
//}
//
//void ImageD::DrawRectangle(HDC hdc, const Image_Object& i_object)
//{
//  Rectangle(hdc, i_object.size.left, i_object.size.top, i_object.size.right, i_object.size.bottom);
//}