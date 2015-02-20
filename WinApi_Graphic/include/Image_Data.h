#ifndef IMAGE_DATA_H
#define IMAGE_DATA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>


//class ImageD
//{
//  COLORREF penColor;
//  COLORREF brushColor;
//  HPEN hPen;
//  HBRUSH hOldBrush, hBrush;
//public:
//  ImageD();
//  ~ImageD();
//  void RedrawImage(HWND hwnd, HDC hdc);
//  void DrawEllipse(HDC hdc, const Image_Object& i_object);
//  void DrawRectangle(HDC hdc, const Image_Object& i_object);
//};

enum DrawKind
{
  RECTANGLE,
  ELLIPSE
};

struct Color //divide into pen and brush111111111111111111111111111111111111
{
  COLORREF m_pen_color,
  m_brush_color;
  Color(COLORREF pen_color, COLORREF brush_color);
  friend std::ostream& operator<<(std::ostream& output, const Color& i_color);
  friend std::istream& operator>>(std::istream& input, Color& i_color);
};

struct Shape_size
{
  int left,
  top,
  right,
  bottom;
  Shape_size(int i_left, int i_top, int i_right, int i_bottom);
  friend std::ostream& operator<<(std::ostream& output, const Shape_size& i_size);
  friend std::istream& operator>>(std::istream& input, Shape_size& i_size);
};

struct Shape_coords
{
  int x, y;
  Shape_coords(int i_x, int i_y);
  friend std::ostream& operator<<(std::ostream& output, const Shape_coords& i_coords);
  friend std::istream& operator>>(std::istream& input, Shape_coords& i_coords);
};


struct Image_Object
{
  Shape_size size;
  Shape_coords coords;
  Color color;
  DrawKind type;
  Image_Object(const Shape_size& i_size, const Shape_coords& i_coords, const Color& i_color, const DrawKind& i_type);
  Image_Object();
  friend std::ostream& operator<<(std::ostream& output, const Image_Object& i_object);
  friend std::istream& operator>>(std::istream& input, Image_Object& i_object);
};

//std::vector<Image_Object> object_container;

#endif // !IMAGE_DATA_H