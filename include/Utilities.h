/// \file Utilities.h
/// \brief A header file containing utility functions and constants.
/// 
/// This file contains the constants and enums used throughout the game.

#pragma once

// Enum for the direction of the characters
enum Direction { Up, Down, Left, Right, Idle };

// Animation constants
constexpr auto ANIMATION_TIME = 0.2f;
constexpr auto ANIMATION_SETS = 3;

// Game constants
constexpr auto TIME_PRESENT = 20.f;
constexpr auto FREEZE_PRESENT = 6.f;
constexpr auto CHEESE_SCORE = 10;
constexpr auto DOOR_SCORE = 2;
constexpr auto PRESENT_SCORE = 5;
constexpr auto CAT_ALIVE_SCORE = 5;
constexpr auto LEVEL_SCORE = 25;
constexpr auto MAX_LIVES = 3;

constexpr int MOUSE_SPEED = 100;
constexpr int CAT_SPEED = 90;
constexpr int SMART_CAT_SPEED = 80;

// Game map constants 
constexpr auto POS_OFFSET = 32;
constexpr auto GRID_SIZE = 64;

// UI constants
constexpr auto UI_HEIGHT = 64;