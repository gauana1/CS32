//
//  mainstack.cpp
//  maze
//
//  Created by Gautam Anand on 4/28/23.
//

#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

class Coord
{
  public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {} // define a class corrd
    int r() const { return m_r; }
    int c() const { return m_c; }
  private:
    int m_r;
    int m_c;
};


bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    stack<Coord> coordStack; //define a stack
    Coord a(sr, sc); //define a coord
    coordStack.push(a); //push the coord on the stack
    maze [sr][sc] = 'O'; //set the current position to an O
    while(!coordStack.empty()) //while stack is empty then we want to check what the coordinate on teh top of the stack is
    {
        Coord coord = coordStack.top();
        coordStack.pop();
        if(coord.r() == er && coord.c() == ec) //check win ocndition, if coordinate matches then return true
        {
            return true;
        }// after this, check each direction and see if a valid move can be made in that direction, if so then push the new coord onto the stack, and update the maze
        if(maze[coord.r()+1][coord.c()] != 'X' && maze[coord.r()+1][coord.c()] != 'O')//south
        {
            Coord coord_n(coord.r()+1,coord.c());
            coordStack.push(coord_n);
            maze[coord.r()+1][coord.c()] = 'O';
            
        }
        if(maze[coord.r()][coord.c()+1] != 'X' && maze[coord.r()][coord.c()+1] != 'O') //east
        {
            Coord coord_n(coord.r(),coord.c()+1);
            coordStack.push(coord_n);
            maze[coord.r()][coord.c()+1] = 'O';
            
        }
        if(maze[coord.r()-1][coord.c()] != 'X' && maze[coord.r()-1][coord.c()] != 'O')//north
        {
            Coord coord_n(coord.r()-1,coord.c());
            coordStack.push(coord_n);
            maze[coord.r()-1][coord.c()] = 'O';
            
        }
        if(maze[coord.r()][coord.c()-1] != 'X' && maze[coord.r()][coord.c()-1] != 'O') //west
        {
            Coord coord_n(coord.r(),coord.c()-1);
            coordStack.push(coord_n);
            maze[coord.r()][coord.c()-1] = 'O';
            
        }
        
    }
    return false; //if the algorithm didn't work, this means that there is no viable path from point A to point B on the maze and return false;
}
  // Return true if there is a path from (sr,sc) to (er,ec)
  // through the maze; return false otherwise

int main()
     {
         char maze[10][10] = {
             { 'X','X','X','X','X','X','X','X','X','X' },
             { 'X','.','.','.','X','.','.','.','.','X' },
             { 'X','.','.','X','X','.','X','X','.','X' },
             { 'X','.','X','.','.','.','.','X','X','X' },
             { 'X','X','X','X','.','X','X','X','.','X' },
             { 'X','.','.','X','.','.','.','X','.','X' },
             { 'X','.','.','X','.','X','.','.','.','X' },
             { 'X','X','.','X','.','X','X','X','X','X' },
             { 'X','.','.','.','.','.','.','.','.','X' },
             { 'X','X','X','X','X','X','X','X','X','X' }
         };

         if (pathExists(maze, 3,4, 8,1))
             cout << "Solvable!" << endl;
         else
             cout << "Out of luck!" << endl;
     }

