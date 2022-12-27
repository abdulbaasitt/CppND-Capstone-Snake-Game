#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"



class Point {
public :
	float x;
	float y;
	Point(float X, float Y) : x(X), y(Y) {};
};


class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height);
      // : grid_width(grid_width),
      //   grid_height(grid_height),
      //   head_x(grid_width / 2),
      //   head_y(grid_height / 2) {}

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);
  void ChangeDirection(Direction input);

  Direction direction = Direction::kUp;

  bool IsAlive() const { return alive; }
  SDL_Point GetHead() const { return {static_cast<int>(head_x), static_cast<int>(head_y)}; }
  const std::vector<SDL_Point>& GetBody() const { return body; }
  void ScaleSpeed(float factor) { speed *= factor; } 
  int GetSize() const { return size; }
  bool SizeInBounds(int lower, int higher) const { return size > lower && size < higher; }


 private:
  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

  Point IncrHead(float x, float y);
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);
  std::vector<int> NextCell();
  bool WallOrBody(SDL_Point point);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif