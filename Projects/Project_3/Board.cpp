//
//  Board.cpp
//  Project 3
//
//  Created by Gautam Anand on 5/23/23.
//

#include "Board.h"
Board::Board(int nHoles, int nInitialBeansPerHole) //constructor for board needded since default does not work
{
    if(nHoles <=0)
    {
        nHoles =1;
    }
    m_holes = nHoles;

    if(nInitialBeansPerHole < 0)
    {
        nInitialBeansPerHole =0;
    }
    m_ibph = nInitialBeansPerHole;
    for(int i = 0; i< nHoles; i++)
    {
        P0N_data.push_back(nInitialBeansPerHole); //push back data entries onto the data
        P1S_data.push_back(nInitialBeansPerHole);
    }
    beans_Npot =0; //set the pots to zero initially
    beans_Spot = 0;
}
Board::Board(const Board&b) //copy constructor when teh board is a const board
{
    m_holes = b.holes();
    beans_Npot = b.beans(NORTH, 0);
    beans_Spot  = b.beans(SOUTH, 0);
    for(int i = 1; i<= m_holes; i++)
    {
        P0N_data.push_back(b.beans(NORTH, i));
        P1S_data.push_back(b.beans(SOUTH, i));
    }
    
}
int Board::holes() const 
{
    return m_holes;
}
int Board::beans(Side s, int hole) const
{
    if(s== NORTH && hole == 0) //if ending hole is the pot return the north pot
    {
        return beans_Npot;
    }
    if(s== SOUTH && hole == 0) //if ending hole is south pot, return the south pot value
    {
        return beans_Spot;
    }
    if(hole>m_holes) //return -1 if out of bounds
    {
        return -1;
    }
    if(s==NORTH && P0N_data[hole-1]!=0) //return the entry in teharray corresponding to the side otherwise, return 0
    {
        return P0N_data[hole-1];
    }
    else if(s==SOUTH && P1S_data[hole-1]!=0)
    {
        return P1S_data[hole-1];
    }
    return 0;
}
int Board::beansInPlay(Side s) const
{
    int count =0;
    if(s==NORTH) //total up the beans on each side using a for loop
    {
        for(int i =0; i < P0N_data.size(); i++)
        {
            count+= P0N_data[i];
        }
    }
    else if(s == SOUTH)
    {
        for(int i =0; i < P1S_data.size(); i++)
        {
            count+= P1S_data[i];
        }
    }
    return count; 
}
int Board::totalBeans() const
{
    int total =0;
    total += beansInPlay(NORTH);
    total += beansInPlay(SOUTH);
    total += (beans_Npot + beans_Spot);
    return total; //add up beansInPlay for both sides
    
}
bool Board::sow(Side s, int hole, Side& endSide, int& endHole)
{
    bool endS= false; //set bools equal to false initially.
    bool endN = false;
    if(hole ==0 || beans(s, hole) == -1 || beans(s, hole) ==0){return false;} //check if its a valid hole, else return false
    int num_beans = beans(s,hole); //assign beans in a whole to an int
    if(s == SOUTH)
    {
        P1S_data[hole-1] =0;
    }
    else
    {
        P0N_data[hole-1] =0;
    }
    while(num_beans!= 0) //while the number of beans in hand is not zero
    {
        if(s == SOUTH)
        {
            if(hole < m_holes) //if hole is not the pot, then add
            {
                num_beans--;
                P1S_data[hole]+=1;
                hole++;
            }
            else if(hole == m_holes) //if hole is the pot, then add the beans and then switch sides and set endS accordingly
            {
                num_beans--;
                beans_Spot+=1;
                endS = true;
                if(num_beans>0)
                {
                    s=NORTH;
                    hole= m_holes+1;
                    endS = false;
                }
            }
        }
        else
        {
            if(hole > 1)//if hole is not pot add beans
            {
                num_beans--;
                P0N_data[hole-2]+=1;
                hole--;
            }
            else if(hole == 1) //if hole is north pot, then if there are beans left then endN is false  but add the bean
            {
                num_beans--;
                beans_Npot+=1;
                endN = true;
                if(num_beans>0)
                {
                    s=SOUTH;
                    hole = 0;
                    endN= false;
                }
            }
        }
    }
    //code to determine end side and endhole
    if(s==SOUTH && hole == m_holes&& endS == true)
    {
        endHole = hole+1;
        endSide = SOUTH;
    }
    else if(s==NORTH && hole ==1 && endN == true)
    {
        endHole = hole-1;
        endSide = NORTH;
    }
    else
    {
        endHole = hole;
        endSide = s;
    }
    
    return true;
}
bool Board::moveToPot(Side s, int hole, Side potOwner)
{
    if(beans(s, hole) == -1){return false;} //if no beans in hole return false
    if(potOwner == SOUTH)//move the hole to the corrsponding pot depending on teh input params
    {
        if(s == SOUTH)
        {
            beans_Spot+=P1S_data[hole-1];
            P1S_data[hole-1]= 0;
        }
        else
        {
            beans_Spot+=P0N_data[hole-1];
            P0N_data[hole-1]= 0;
        }
    }
    else
    {
        if(s == SOUTH)
        {
            beans_Npot+=P1S_data[hole-1];
            P1S_data[hole-1]= 0;
        }
        else
        {
            beans_Npot+=P0N_data[hole-1];
            P0N_data[hole-1]= 0;
        }
    }
    return true; 
}

bool Board::setBeans(Side s, int hole, int beans)
{
    if(s==SOUTH)//set beans depending on the side
    {
        P1S_data[hole-1] = beans;
    }
    else
    {
        P0N_data[hole-1] = beans;
    }
    return true;
}

