//
//  Player.h
//  Project 3
//
//  Created by Gautam Anand on 5/23/23.
//

#ifndef Player_h
#define Player_h
#include <iostream>
#include <stdio.h>
#include <stdlib.h>    
#include "Board.h"
#include <string>
using namespace std;
class Player
{
public:
    Player(std::string name);
    std::string name() const;
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const = 0;
    virtual ~Player();
private:
    std::string m_name;
};
class HumanPlayer:public Player
{
public:
    HumanPlayer(std::string name);
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board& b, Side s) const;
//    virtual ~HumanPlayer();
};
class BadPlayer:public Player
{
public:
    BadPlayer(std::string name);
    virtual int chooseMove(const Board& b, Side s) const;
//    virtual ~BadPlayer();
};
class SmartPlayer:public Player
{
public:
    SmartPlayer(std::string name);
    virtual int chooseMove(const Board& b, Side s) const;
//    virtual ~SmartPlayer();
private:
    void makeMove(Side s, Board &b,int &bestHole, int &value, int depth) const;
    bool checkCapture(Board &b, Side s, Side end_Side, int endHole) const; 
    int random_move(int holes) const;
    int evaluate_board(Board &b, Side s) const;
};
#endif /* Player_h */
