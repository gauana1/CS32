//
//  Game.h
//  Project 3
//
//  Created by Gautam Anand on 5/23/23.
//

#ifndef Game_h
#define Game_h
#include <stdio.h>
#include "Player.h"
using namespace std;
class Game
{
public:
    Game(const Board& b, Player* south, Player* north);
    void display() const;
    void status(bool& over, bool& hasWinner, Side& winner) const;
    bool move(Side s);
    void play();
    int beans(Side s, int hole) const;
private:
    Board m_b;
    Player* p1;
    Player* p2;
    Side cp;
    Side g_winner;
    bool g_over;
};

#endif /* Game_h */
