//
//  History.cpp
//  Project1
//
//  Created by Gautam Anand on 4/10/23.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>
#include "History.h"
History::History(int nRows, int nCols)
{
    rows = nRows;
    cols = nCols;
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            m_arena[i][j] = 0;
        }
    }
}
    
bool History::record(int r, int c)
{
    if (r>rows || r < 1 || c > cols || c <1)
    {       
        return false;
    }
    m_arena[r-1][c-1] += 1;
    return true;
}

void History::display() const
{
    clearScreen();
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(m_arena[i][j] == 0)
                cout << ".";
            else
            {
            char a = 'A' - 1 + m_arena[i][j];
            cout <<a;
            
            }
        }
        cout << endl;
    }
    cout << endl; 
    
}

