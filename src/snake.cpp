#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update()
{
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)}; // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)}; // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y)
  {
    UpdateBody(current_cell, prev_cell);
  }
}

Point Snake::IncrHead(float x, float y)
{
  switch (direction)
  {
  case Direction::kUp:
    y -= speed;
    break;

  case Direction::kDown:
    y += speed;
    break;

  case Direction::kLeft:
    x -= speed;
    break;

  case Direction::kRight:
    x += speed;
    break;
  }
  return Point{x, y};
}

void Snake::UpdateHead()
{
  bool redirected = false;
  Point proj_head = IncrHead(head_x, head_y);
  int x = static_cast<int>(head_x);
  int y = static_cast<int>(head_y);
  int updated_x = static_cast<int>(proj_head.x);
  int updated_y = static_cast<int>(proj_head.y);
  switch (direction)
  {
  case Direction::kUp:
    // head_y -= speed;
    if (proj_head.y < 0 || (y != updated_y && SnakeCell(updated_x, updated_y)))
    {
      redirected = true;
      if (x <= 0 || SnakeCell(x - 1, y))
        direction = Direction::kRight;
      else
        direction = Direction::kLeft;
    }
    break;

  case Direction::kDown:
    // head_y += speed;
    if (proj_head.y >= grid_height || (y != updated_y && SnakeCell(updated_x, updated_y)))
    {
      redirected = true;
      if (x >= grid_width - 1 || SnakeCell(x + 1, y))
        direction = Direction::kLeft;
      else
        direction = Direction::kRight;
    }
    break;

  case Direction::kLeft:
    // head_x -= speed;
    if (proj_head.x < 0 || (x != updated_x && SnakeCell(updated_x, updated_y)))
    {
      redirected = true;
      if (y <= 0 || SnakeCell(x, y - 1))
        direction = Direction::kDown;
      else
        direction = Direction::kUp;
    }
    break;

  case Direction::kRight:
    // head_x += speed;
    if (proj_head.x >= grid_width || (x != updated_x && SnakeCell(updated_x, updated_y)))
    {
      redirected = true;
      if (y >= grid_height - 1 || SnakeCell(x, y + 1))
        direction = Direction::kUp;
      else
        direction = Direction::kDown;
    }
    break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  // head_x = fmod(head_x + grid_width, grid_width);
  // head_y = fmod(head_y + grid_height, grid_height);

  if (!redirected)
  {
    head_x = proj_head.x;
    head_y = proj_head.y;
  }
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell)
{
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing)
  {
    // Remove the tail from the vector.
    body.erase(body.begin());
  }
  else
  {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body)
  {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y)
    {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y)
{
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y))
  {
    return true;
  }
  for (auto const &item : body)
  {
    if (x == item.x && y == item.y)
    {
      return true;
    }
  }
  return false;
}

Snake::Snake(int grid_width, int grid_height)
    : grid_width(grid_width),
      grid_height(grid_height),
      head_x(grid_width / 2),
      head_y(grid_height / 2)
{
  int incr_x, incr_y;
  switch (direction)
  {
  case Direction::kUp:
    incr_x = 0;
    incr_y = -1;
    break;
  case Direction::kDown:
    incr_x = 0;
    incr_y = 1;
    break;
  case Direction::kLeft:
    incr_x = -1;
    incr_y = 0;
    break;
  case Direction::kRight:
    incr_x = 1;
    incr_y = 0;
    break;
    for (int i = 1; i < size; i++)
    {
      SDL_Point body_cell{static_cast<int>(head_x + i * incr_x),
                          static_cast<int>(head_y + i * incr_y)};
      body.push_back(body_cell);
    }
  }
}

std::vector<int> Snake::NextCell()
{
  std::vector<int> next_cell{0, 0};
  int x = static_cast<int>(head_x);
  int y = static_cast<int>(head_y);
  switch (direction)
  {
  case Direction::kUp:
    y -= 1;
    break;

  case Direction::kDown:
    y += 1;
    break;

  case Direction::kLeft:
    x -= 1;
    break;

  case Direction::kRight:
    x += 1;
    break;
  }
  next_cell[0] = x;
  next_cell[1] = y;
  return next_cell;
}

void Snake::ChangeDirection(Snake::Direction input)
{
  Direction currentDirection = direction;
  direction = input;
  std::vector<int> next_cell = NextCell();
  int x = next_cell[0];
  int y = next_cell[1];
  if (x < 0 || x >= grid_width || y < 0 || y >= grid_height)
  {
    direction = currentDirection;
  }
}