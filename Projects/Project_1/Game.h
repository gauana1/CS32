//
//  Game.h
//  Project1
//
//  Created by Gautam Anand on 4/8/23.
//

#ifndef Game_h
#define Game_h
#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>

using namespace std;
class Arena;
class Game
{
  public:
      // Constructor/destructor
    Game(int rows, int cols, int nRabbits);
    ~Game();

      // Mutators
    void play();

  private:
    Arena* m_arena;

      // Helper functions
    string takePlayerTurn();
};
bool recommendMove(const Arena& a, int r, int c, int& bestDir);


#endif /* Game_h */
