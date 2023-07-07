//
//  History.hpp
//  Project1
//
//  Created by Gautam Anand on 4/10/23.
//

#ifndef History_hpp
#define History_hpp

#include <stdio.h>
#include "globals.h"
class History
{
  public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;

private:
    int rows;
    int cols;
    int m_arena[MAXROWS][MAXCOLS];
};
#endif /* History_hpp */
