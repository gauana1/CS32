//
//  main.cpp
//  prob 3
//
//  Created by Gautam Anand on 5/8/23.
//

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
    Coord a(sr, sc); //create a coord
    if(a.r() == er && a.c() == ec)
    {
        return true; //if winning conditions are met, then return true
    }
    maze [sr][sc] = 'O';//set the current point on the maze to O
    if(maze[a.r()+1][a.c()] != 'X' && maze[a.r()+1][a.c()] != 'O')//south
    {
        bool d= pathExists(maze, a.r()+1, a.c(), er, ec);
        if(d)
        {
            return true;
        }
    }
    if(maze[a.r()][a.c()+1] != 'X' && maze[a.r()][a.c()+1] != 'O')//south
    {
        bool d = pathExists(maze, a.r(), a.c()+1, er, ec);
        if (d)
        {
            return true;
        }
    }
    if(maze[a.r()-1][a.c()] != 'X' && maze[a.r()-1][a.c()] != 'O')//north
    {
        bool d= pathExists(maze, a.r()-1, a.c(), er, ec);
        if(d)
        {
            return true;
        }
    }
    if(maze[a.r()][a.c()-1] != 'X' && maze[a.r()][a.c()-1] != 'O') //west
    {
        bool d= pathExists(maze, a.r(), a.c()-1, er, ec);
        if(d)
        {
            return true;
        }
    }
    return false; //return false if the algorithm couldnt connect points A and B.
}
  // Return true if there is a path from (sr,sc) to (er,ec)
  // through the maze; return false otherwise


