//
//  RainfallList.cpp
//  Assignment 1
//
//  Created by Gautam Anand on 4/17/23.
//

#include "RainfallList.h"

RainfallList::RainfallList():Seq()
{
    
}// Create an empty rainfall list.

bool RainfallList::add(unsigned long rainfall)
{
    if(rainfall < 0 || rainfall > 400 ||  Seq.size() >= DEFAULT_MAX_ITEMS)
    {
        return false;
    }
    else
    {
        Seq.insert(rainfall);
        return true;
    }

}
// If the rainfall is valid (a value from 0 to 400) and the rainfall list
// has room for it, add it to the rainfall list and return true.
// Otherwise, leave the rainfall list unchanged and return false.

bool RainfallList::remove(unsigned long rainfall)
{
    int position = Seq.find(rainfall);
    if(position == -1)
    {
        return false;
    }
    return Seq.erase(position);
}
// Remove one instance of the specified rainfall from the rainfall list.
// Return true if a rainfall was removed; otherwise false.

int RainfallList::size() const
{
    const int size = Seq.size();
    return size;
}// Return the number of rainfalls in the list.

unsigned long RainfallList::minimum() const
{
    if(Seq.size() == 0)
    {
        return NO_RAINFALLS;
    }
    unsigned long temp1;
    Seq.get(0,temp1);
    unsigned long temp2;
    for(int i = 0 ; i < Seq.size(); i++)
    {
        if(Seq.get(i,temp2) == true && temp2 < temp1)
        {
            temp1 = temp2;
        }
            
    }
    return temp1;
}
// Return the lowest-valued rainfall in the rainfall list.  If the list is
// empty, return NO_RAINFALLS.

unsigned long RainfallList::maximum() const
{
    if(Seq.size() == 0)
    {
        return NO_RAINFALLS;
    }
    unsigned long temp1;
    Seq.get(0,temp1);
    unsigned long temp2;
    for(int i = 0 ; i < Seq.size(); i++)
    {
        if(Seq.get(i,temp2) == true && temp2 > temp1)
        {
            temp1 = temp2;
        }
            
    }
    return temp1;
}
// Return the highest-valued rainfall in the rainfall list.  If the list is
// empty, return NO_RAINFALLS.

