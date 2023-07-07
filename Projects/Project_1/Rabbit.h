//
//  Rabbit.h
//  Project1
//
//  Created by Gautam Anand on 4/8/23.
//

#ifndef Rabbit_h
#define Rabbit_h

#include "Rabbit.h"
#include "Arena.h"
class Arena;
class Rabbit
{
  public:
      // Constructor
    Rabbit(Arena* ap, int r, int c);

      // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;

      // Mutators
    void move();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
    int    m_idleTurnsRemaining;
};

#endif /* Rabbit_h */
