//
//  Board.h
//  Project 3
//
//  Created by Gautam Anand on 5/23/23.
//

#ifndef Board_h
#define Board_h

#include <stdio.h>
#include "Side.h"
#include <vector>
using namespace std;
class Board
{
public:
    Board(int nHoles, int nInitialBeansPerHole);
    Board(const Board &b);
    int holes() const;
    int beans(Side s, int hole) const;
    int beansInPlay(Side s) const;
    int totalBeans() const;
    bool sow(Side s, int hole, Side& endSide, int& endHole);
    bool moveToPot(Side s, int hole, Side potOwner);
    bool setBeans(Side s, int hole, int beans);
private:
    int m_holes; //private members of board
    int m_ibph; // need holes, holes per pot at start and vectors for the dtata for north and south
//    int m_pots;
    vector<int> P0N_data;
    vector<int> P1S_data;
    int beans_Npot; //ints representing the pots for north and south
    int beans_Spot;

    
    
};


#endif /* Board_h */
