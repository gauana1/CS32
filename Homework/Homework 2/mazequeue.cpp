//
//  main.cpp
//  mazequeue
//
//  Created by Gautam Anand on 4/28/23.
//

//
//  mainstack.cpp
//  maze
//
//  Created by Gautam Anand on 4/28/23.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Coord
{
  public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {} //define class coord
    int r() const { return m_r; }
    int c() const { return m_c; }
  private:
    int m_r;
    int m_c;
};


bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    queue<Coord> coordQueue; //create a coordQueue
    Coord a(sr, sc); //create a coord
    coordQueue.push(a); //push the cord onto the queue
    maze [sr][sc] = 'O'; //set the current point on the maze to O
    while(!coordQueue.empty()) //while the queue is not empty
    {
        Coord coord = coordQueue.front(); //set the  coord to the coord in the front of the queue
        coordQueue.pop(); //pop the queue
        if(coord.r() == er && coord.c() == ec)
        {
            return true; //if winning conditions are met, then return true
        }//try to traverse in each possible direction if posisble, and if the step in that directiono is valid, then push the now coodinate onto the queue, and update the maze so that the position is now O.
        if(maze[coord.r()+1][coord.c()] != 'X' && maze[coord.r()+1][coord.c()] != 'O')//south
        {
            Coord coord_n(coord.r()+1,coord.c());
            coordQueue.push(coord_n);
            maze[coord.r()+1][coord.c()] = 'O';
            
        }
        if(maze[coord.r()][coord.c()+1] != 'X' && maze[coord.r()][coord.c()+1] != 'O') //east
        {
            Coord coord_n(coord.r(),coord.c()+1);
            coordQueue.push(coord_n);
            maze[coord.r()][coord.c()+1] = 'O';
            
        }
        if(maze[coord.r()-1][coord.c()] != 'X' && maze[coord.r()-1][coord.c()] != 'O')//north
        {
            Coord coord_n(coord.r()-1,coord.c());
            coordQueue.push(coord_n);
            maze[coord.r()-1][coord.c()] = 'O';
            
        }
        if(maze[coord.r()][coord.c()-1] != 'X' && maze[coord.r()][coord.c()-1] != 'O') //west
        {
            Coord coord_n(coord.r(),coord.c()-1);
            coordQueue.push(coord_n);
            maze[coord.r()][coord.c()-1] = 'O';
            
        }
        
    }
    return false; //return false if the algorithm couldnt connect points A and B.
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

