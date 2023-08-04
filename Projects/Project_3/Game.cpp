//
//  Game.cpp
//  Project 3
//
//  Created by Gautam Anand on 5/23/23.
//

#include "Game.h"
Game::Game(const Board& b, Player* south, Player* north):m_b(b)
{
    p1 = south;
    p2 = north;
    cp = SOUTH;
    g_over = false;
}
void Game::display() const
{
    for(int i =0 ; i < m_b.holes(); i++)
    {
        cout << "  ";
    }
    cout << p2-> name() << endl;
    for(int i = 1; i <= m_b.holes();i++)
    {
        cout << "   "<< m_b.beans(NORTH,i);
    }
    cout << endl;
    cout << m_b.beans(NORTH,0) ;
    for(int i = 0; i <= m_b.holes()-1;i++)
    {
        cout << "    ";
    }
    cout << m_b.beans(SOUTH,0) << endl;
    for(int i = 1; i <= m_b.holes();i++)
    {
        cout << "   "<< m_b.beans(SOUTH,i);
    }
    cout << endl;
    for(int i =0 ; i < m_b.holes(); i++)
    {
        cout << "  ";
    }
    cout << p1->name() << endl;
    
}
void Game::status(bool& over, bool& hasWinner, Side& winner) const
{
    if(m_b.beansInPlay(SOUTH) != 0 ||m_b.beansInPlay(NORTH) != 0  )//if game not over, over = false
    {
        over = false;
    }
    else
    {
        over = true;
    }
    if(m_b.beans(SOUTH,0)> m_b.beans(NORTH, 0))//set winner depending on win conditions
    {
        winner = SOUTH;
        hasWinner = true;
    }
    else if(m_b.beans(SOUTH,0) < m_b.beans(NORTH, 0))
    {
        winner = NORTH;
        hasWinner = true;
    }
    else
    {
        hasWinner = false;//if tie, then there is no winner
    }
}
bool Game::move(Side s)
{
    cp =s;
    if(cp == SOUTH)//move depending on current player
    {
        Side temp;
        temp = s;
        int endHole=100;
        do
        {
            cout << p1-> name() << "'s turn" << endl;
            int move_taken = p1->chooseMove(m_b, cp);//p1 moves first
            if(move_taken!= -1)
            {
                m_b.sow(s, move_taken, temp, endHole);
                if(temp == s && endHole != 0 && endHole != m_b.holes()+1 && m_b.beans(s, endHole)==1 && m_b.beans(opponent(s), endHole)!=0)//if the capture conditions are met, then capture
                {
                    m_b.moveToPot(cp, endHole, SOUTH);
                    m_b.moveToPot(opponent(cp), endHole, SOUTH);
                }
                display();
            }
        }
        while(endHole == m_b.holes()+1 &&  s==temp && m_b.beansInPlay(cp)!=0);//while the side is the same and end hole is the pot
        if(m_b.beansInPlay(cp)==0)
        {
            for(int i = 1; i <= m_b.holes(); i++)
            {
                m_b.moveToPot(opponent(cp),i,opponent(cp));
            }
            g_over = true;
            if(m_b.beans(SOUTH, 0) >m_b.beans(NORTH, 0) )//check win conditions and set winner
            {
                g_winner = SOUTH;
            }
            else
            {
                g_winner = NORTH;
            }
            
            return false;
        }
        cp = opponent(cp);//set cp to opponent
        return true;
    }
    else//same process but for north player
    {
        Side temp;
        temp = s;
        int endHole=100;
        do
        {
            cout << p2-> name() << "'s turn" << endl;
            int move_taken = p2->chooseMove(m_b, cp);
            if(move_taken!= -1)
            {
                m_b.sow(s, move_taken, temp, endHole);
                if(temp == s && endHole != 0 && endHole != m_b.holes()+1 && m_b.beans(s, endHole)==1 && m_b.beans(opponent(s), endHole)!=0)
                {
                    m_b.moveToPot(cp, endHole, NORTH);
                    m_b.moveToPot(opponent(cp), endHole, NORTH);
                }
                display();
            }
        }
        while(endHole == 0 && s==temp && m_b.beansInPlay(cp)!=0);
        if(m_b.beansInPlay(cp)==0)
        {
            for(int i = 1; i <= m_b.holes(); i++)
            {
                m_b.moveToPot(opponent(cp),i,opponent(cp));
            }
            g_over = true;
            if(m_b.beans(SOUTH, 0) >m_b.beans(NORTH, 0) )
            {
                g_winner = SOUTH;
            }
            else
            {
                g_winner = NORTH;
            }
            return false;
        }
        cp = opponent(cp);
        return true;
    }
}
void Game::play()
{
    display();

    while(g_over!= true)
    {
        if(!(p1->isInteractive()) && !(p2->isInteractive()))//check if both players are virtual
        {
            cout << "Press Enter to see next move";
            cin.ignore();
            move(cp);
            
        }
        else{
            
            move(cp);
        }
  
    }
    
    Side Winner;
    bool over,hasWinner;
    display();
    status(over,hasWinner,Winner);
    if(hasWinner == false)
    {
        cout << "Tie Game!" << endl;
    }
    else if(g_winner == SOUTH)//check and cout depending on the win conditions
    {
        cout << "Winner Is:";
        cout << p1-> name() << endl;
    }
    else if(g_winner == NORTH)
    {
        cout << "Winner Is:";
        cout << p2-> name() << endl;
    }
}
int Game::beans(Side s, int hole) const
{
    return (m_b.beans(s, hole));//return the beans in the hole
}
