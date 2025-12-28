# Mouse & Cheese Game

A 2D game where the player controls a mouse.
The objective is to collect all the cheese on the map while avoiding getting caught by cats.

Each level has a time limit, so the player must act quickly.

The player can:
- Collect keys to open doors
- Pick up presents that grant different bonuses (explained in the tutorial window)
- Progress through multiple levels loaded from external files

---

## Gameplay Overview

- Player: Mouse controlled by the user
- Enemies:
  - Regular cats with semi-random movement
  - Smart cats that actively chase the player
- Objective:
  - Collect all cheese
  - Avoid getting caught
  - Finish the level before time runs out

---

## Project Structure

### Core Architecture

- Observer.cpp / Observer.h  
  Abstract observer design pattern used to notify the game when a window or game state changes.

- Controller.cpp / Controller.h  
  Controls the entire game, runs the main game loop, and manages game states.

- GameState.cpp / GameState.h  
  Maintains the currently active game window.

---

### Game States

- MainMenu.cpp / MainMenu.h  
  Main menu window.

- HelpMenu.cpp / HelpMenu.h  
  Tutorial and help window.

- GameOver.cpp / GameOver.h  
  Game over screen.

- EndGameMenu.cpp / EndGameMenu.h  
  End game screen.

---

### Game Logic and Entities

- Resources.cpp / Resources.h  
  Loads all game resources (textures, sounds, etc.) using the Singleton design pattern.

- MousePlayer.cpp / MousePlayer.h  
  Player object responsible for user input and interaction with the map.

- CatEnemy.cpp / CatEnemy.h  
  Enemy with basic movement logic.

- SmartCatEnemy.cpp / SmartCatEnemy.h  
  Enemy that actively follows the player using pathfinding.

- GameObjects.cpp / GameObjects.h  
  Base class for all objects on the map.

---

### Map Objects (Double Dispatch)

- Wall / Floor / Presents / Door / Key / CheeseObjects (.cpp / .h)  
  Handle rendering and player collision using double dispatch.

Note:
The Floor object is texture-only and does not participate in collision detection.

---

### Level and UI

- GameLevel.cpp / GameLevel.h  
  Controls a single game level including players, enemies, objects, and the level loop.

- LevelLoader.cpp / LevelLoader.h  
  Loads level files and creates the corresponding game objects.

- PlayerUI.cpp / PlayerUI.h  
  Handles the player HUD displayed during gameplay.

---

### Utilities

- Configs.h  
  Holds game parameters such as resolution and volume.

- Utilities.h  
  Contains constants used for object configuration.

- ObjectsInclude.h  
  Central include file for all game object definitions.

---

## Data Structures

The GameLevel class contains:
- A unique_ptr to the player
- A vector of unique_ptr enemies
- A vector of unique_ptr collidable objects
- A vector of unique_ptr static non-collidable objects

Pathfinding helper type:

typedef std::vector<sf::Vector2i> GridPath;

This structure stores possible movement paths using grid indices instead of world coordinates.

---

## Algorithms

### CatEnemy

- Uses a simple movement algorithm
- Changes direction when colliding with an impassable object
- Uses a timer with randomness to:
  - Change direction at intersections
  - Avoid immediately reversing direction

---

### SmartCatEnemy

- Uses a Breadth-First Search (BFS) algorithm to find the shortest path to the player
- Calculates all possible paths on the map
- Uses:
  - A 1D boolean vector to track visited nodes
  - A 1D vector of vectors to store node ancestors
- Grid positions are converted to unique linear indices for storage
- The enemy continuously follows the player until the player is caught

---

## Known Bugs (Features)

- Cats may take some time to escape obstacles, but they eventually do
- Collision boundaries may feel slightly off due to sprite visuals
- Some intersections may appear passable visually but still block movement

---

## Level Files

Levels are stored in the source folder.

Naming format:

Level_XXX.txt

Where XXX is a zero-padded number starting from 001.

Examples:

Level_001.txt
Level_002.txt
Level_003.txt

---

## Notes

- Implemented using object-oriented design principles
- Uses multiple design patterns such as Singleton and Observer
- Emphasis on clean architecture and separation of responsibilities
