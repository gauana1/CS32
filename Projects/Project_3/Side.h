//
//  Header.h
//  Project 3
//
//  Created by Gautam Anand on 5/23/23.
//

#ifndef Side_h
#define Side_h
enum Side { NORTH, SOUTH };

    const int NSIDES = 2;
    const int POT = 0;

    inline
    Side opponent(Side s)
    {
        return Side(NSIDES - 1 - s);
    }
#endif /* Header_h */
