#pragma once

enum Direction { Up, Down, Left, Right, Idle };
constexpr auto ANIMATION_TIME = 0.2f;
constexpr auto ANIMATION_SETS = 3;
constexpr auto TIME_PRESENT = 20.f;
constexpr auto FREEZE_PRESENT = 6.f;
constexpr auto CHEESE_SCORE = 10;
constexpr auto DOOR_SCORE = 2;
constexpr auto PRESENT_SCORE = 5;
constexpr auto CAT_ALIVE_SCORE = 5;
constexpr auto LEVEL_SCORE = 25;
constexpr auto MAX_LIVES = 3;

constexpr auto POS_OFFSET = 32;
constexpr auto GRID_SIZE = 64;

constexpr auto UI_HEIGHT = 64;