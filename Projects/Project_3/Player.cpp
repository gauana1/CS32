//
//  Player.cpp
//  Project 3
//
//  Created by Gautam Anand on 5/23/23.
//

#include "Player.h"
//========================================================================
// Timer t;                 // create and start a timer
// t.start();               // restart the timer
// double d = t.elapsed();  // milliseconds since timer was last started
//========================================================================

#include <chrono>

class Timer
{
  public:
    Timer()
    {
        start();
    }
    void start()
    {
        m_time = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const
    {
        std::chrono::duration<double, std::milli> diff =
                          std::chrono::high_resolution_clock::now() - m_time;
        return diff.count();
    }
  private:
    std::chrono::high_resolution_clock::time_point m_time;
};

//========================================================================
Timer timer;
Player::Player(std::string name) //constructot, set name for player given a string argument
{
    m_name = name;
}
std::string Player::name() const
{
    return m_name; //return name
}
Player::~Player()//destructor
{
}
bool Player::isInteractive() const//return false default
{
    return false;
}
HumanPlayer::HumanPlayer(std::string name):Player(name)//constructor using intializer list for human player
{
    
}
bool HumanPlayer::isInteractive() const
{
    return true;//return true for human player only
}
int HumanPlayer::chooseMove(const Board& b, Side s) const
{
    if(b.beansInPlay(s)==0)
    {
        return -1;
    }
    int number=0;
    cout << "Choose a hole: ";
    std::cin>> number;
    while(number ==0 || b.beans(s,number) ==-1 || b.beans(s, number ) ==0)//use a while loop until a valid input is recieved
    {
        std::cout << "Please select a valid hole: ";
        std::cin>> number;
    }
    return number;
}
BadPlayer::BadPlayer(std::string name):Player(name)//constructor and intializer list for badplayer
{
    
}
int BadPlayer::chooseMove(const Board& b, Side s) const
{
    if(b.beansInPlay(s)==0)
    {
        return -1;
    }
    for(int i = 1; i <= b.holes(); i++)//chose the first availible hole for badplayer
    {
        if(b.beans(s,i)!=-1 && b.beans(s,i)!=0)
        {
            return i;
        }
    }
    return -1;
}
SmartPlayer::SmartPlayer(std::string name):Player(name)
{
    //constructor and initilzier list for smartplayer
}
int SmartPlayer::chooseMove(const Board& b, Side s) const
{
    if(b.beansInPlay(SOUTH) == 0 || b.beansInPlay(NORTH) == 0)//if game over, return -1
           return -1;
       
    int value;
    int bestHole = random_move(b.holes());//use random holes to set initially
    Board temp_b = b;
    timer.start();
    makeMove(s,temp_b,bestHole, value, 0);//make a move calling make move, which is the minimax function
    return bestHole;
}

void SmartPlayer::makeMove(Side s, Board&  b,int &bestHole, int &value, int depth) const
{
    if(s == SOUTH)
    {
        value = -10000000;//if player is south set large negative value
    }
    else
    {
        value = 10000000;//set large pos value
    }
    if(b.beansInPlay(SOUTH)==0 || b.beansInPlay(NORTH)==0)//if gamenot over, then put all the beans on each side into corresponding pots
    {
        for(int i =1; i<= b.holes();i++)
        {
            b.moveToPot(opponent(s),i, opponent(s));
        }
        bestHole = -1;
        if(b.beans(SOUTH, 0) > b.beans(NORTH,0))//set value depending on the win condition
            
        {
            value= 10000000;
        }
        else if(b.beans(SOUTH, 0) < b.beans(NORTH,0))
        {
            value= -1000000;
        }
        else
        {
            value =0;
        }
        return;
    }
    if(timer.elapsed() > 4300)
    {
        value = evaluate_board(b,s);
    }
    if(depth >=8)//set a depth of 5
    {
        bestHole = -1;
        if(s==SOUTH)
        {
            value = evaluate_board(b, s);//heuristic is just the difference between the pots
        }
        else
        {
            value =evaluate_board(b, s);;
        }
        return;
    }
    for(int i =1; i <= b.holes(); i++)//for each possible hole
    {
        Side es;
        int eh;
        Board temp_b = b;
        if(temp_b.sow(s,i,es,eh))//check if sow returns true, if so check capture
        {
            if(checkCapture(temp_b, s, es, eh))
            {
                value += 1 + temp_b.beans(opponent(s),eh);//add captured beans to value
            }

            while(s == es && (eh == 0 || eh == temp_b.holes() + 1) && temp_b.beansInPlay(s) > 0 && temp_b.beansInPlay(opponent(s)) > 0)//while the side remains the same
            {
                int num;
                    do
                    {
                        num = random_move(temp_b.holes());//make a random  move
                    }
                    while(temp_b.beansInPlay(s) != 0 && temp_b.beansInPlay(opponent(s)) != 0 && temp_b.beans(s, num) == 0);
                    if(!temp_b.sow(s, num, es, eh))//if move is valid, then break
                    {
                        break;
                    }
                    value +=1;
                    
            }
            int h2,v2;
            makeMove(opponent(s), temp_b, h2, v2, depth+1);
            temp_b = b;
            if(s == NORTH)//set besthole and value depending on the player
            {
                if(v2<value)
                {
                    bestHole = i;
                    value = v2;
                }
            }
            else if(s==SOUTH)
            {
                if(v2>value)
                {
                    bestHole = i;
                    value = v2;
                }
            }
            
        }
    }
    return;
}
bool SmartPlayer::checkCapture(Board &b, Side s, Side end_Side ,int endHole) const
{
    if(end_Side == s && endHole != 0 && endHole != b.holes()+1 && b.beans(s, endHole)==1 && b.beans(opponent(s), endHole)!=0)//if capture conditions, then place beans on either side into the pot
    {
        if(s == SOUTH)
        {
            b.moveToPot(s, endHole, SOUTH);
            b.moveToPot(opponent(s), endHole, SOUTH);
        }
        else
        {
            b.moveToPot(s, endHole, NORTH);
            b.moveToPot(opponent(s), endHole, NORTH);
        }
        return true;
    }
    return false;
}
int SmartPlayer::random_move(int holes) const
{
    int number = random()%holes + 1;//use random move and return the int
    return number;
}
int SmartPlayer::evaluate_board(Board &b, Side s) const 
{
    int value = 0;
    int endHole;
    Side endSide;
    for(int i = 1; i <= b.holes();i++)
    {
        if(b.sow(s, i, endSide, endHole))
        {
            if(b.beansInPlay(s)==0 && b.beansInPlay(opponent(s))==0)
            {
                if(s==NORTH)
                    value = -1000;
                else
                    value = 1000;
            }
            else if(checkCapture(b, s, endSide, endHole))
            {
                if(s==NORTH)
                    value = -100;
                else
                    value = 100;
            }
            else if(endSide == s && (endHole == 0 || endHole == b.holes()+1))
            {
                if(s==NORTH)
                    value = -50;
                else
                    value = 50;
            }
        }
    }
    if(s==NORTH)
    {
        if(value < (b.beans(SOUTH,0)- b.beans(NORTH,0)))
        {
            return value;
        }
        else
        {
            return (b.beans(SOUTH,0)- b.beans(NORTH,0));
        }
        
    }
    else
    {
        if(value > (b.beans(SOUTH,0)- b.beans(NORTH,0)))
        {
            return value;
        }
        else
        {
            return (b.beans(SOUTH,0)- b.beans(NORTH,0));
        }
    }
        
    return (b.beans(SOUTH,0)- b.beans(NORTH,0));
}
