
struct Border
{
  bool closed;
  bool can_be_pulled_up;
  bool is_enter;
  bool is_exit;
};

struct Wall
{
  bool west_wall_closed;
  bool east_wall_closed;
  bool north_wall_closed;
  bool south_wall_closed;
};

struct Backtrack
{
  bool goes_back_west;
  bool goes_back_east;
  bool goes_back_north;
  bool goes_back_south;
};

struct Solution
{
  bool goes_west;
  bool goes_east;
  bool goes_north;
  bool goes_south;
};

class Labyrinth
{
public:
  Labyrinth();
  ~Labyrinth();
private:

};