//
//  newSequence.cpp
//  Assignment 1
//
//  Created by Gautam Anand on 4/17/23.
//

#include "newSequence.h"
#include <iostream>

Sequence::Sequence()
{
    m_capacity = DEFAULT_MAX_ITEMS;
    m_arr = new ItemType[DEFAULT_MAX_ITEMS];
    m_size = 0;
}
Sequence::Sequence(int capacity)
{
    m_capacity = capacity;
    m_arr = new ItemType[capacity];
    m_size = 0;
}
Sequence::Sequence(const Sequence& Seq)
{
    m_capacity = Seq.m_capacity;
    m_size = Seq.size();
    m_arr = new ItemType[Seq.m_capacity];
    for(int i = 0; i < m_size ; i++)
    {
        m_arr[i] = Seq.m_arr[i];
    }
}
Sequence& Sequence::operator = (const Sequence& Seq)
{
    if(this != &Seq)
    {
        Sequence temp(Seq);
        swap(temp);

    }
    return *this; 
}
bool Sequence::empty() const  // Return true if the sequence is empty, otherwise false.
{
    if(m_size ==0)
    {
        return true;
    }
    return false;
}
int Sequence::size() const
{
    return m_size;
}
// Return the number of items in the sequence.
int Sequence::insert(int pos, const ItemType& value)
{
    if( pos < 0 || pos > m_size)
    {
        return -1;
    }

    for(int i = m_size; i > pos ; i--)
    {
        if(pos == m_size)
        {
            m_arr[i] = value;
            m_size++;
            return pos;
        }
        else
            m_arr[i] = m_arr[i-1];

    }
    m_arr[pos]= value;
    m_size++;
    return pos;


}
      // Insert value into the sequence so that it becomes the item at
      // position pos.  The original item at position pos and those that
      // follow it end up at positions one greater than they were at before.
      // Return pos if 0 <= pos <= size() and the value could be
      // inserted.  (It might not be, if the sequence has a fixed capacity,
      // e.g., because it's implemented using a fixed-size array.)  Otherwise,
      // leave the sequence unchanged and return -1.  Notice that
      // if pos is equal to size(), the value is inserted at the end.

    int Sequence::insert(const ItemType& value)
{
        if(m_size >= m_capacity)
        {
            return -1; 
        }
        int smallest_p = 10000000 ;
        for(int p = 0; p < m_size ; p++)
        {
            if(value <= m_arr[p] && p < smallest_p)
            {
                smallest_p = p;
            }
        }
        if(smallest_p == 10000000)
        {
            smallest_p = m_size;
        }
        for(int i = m_size; i > smallest_p ; i--)
        {
            if(smallest_p == m_size && smallest_p  < DEFAULT_MAX_ITEMS)
            {
                m_arr[i] = value;
                m_size++;
                return smallest_p;
            }
//            else if(i == 0)
//            {
//                m_arr[i] = value;
//            }
            else
                m_arr[i] = m_arr[i-1];
            
        }
        m_arr[smallest_p]=value;
//        if(smallest_p < DEFAULT_MAX_ITEMS)
//        {
//            if(m_arr[0] == value)
//            {
//                m_size++;
//                return smallest_p;
//            }
//            else
//            {
//                m_arr[smallest_p--]= value;
//                m_size++;
//                return smallest_p;
//            }
//
//        }
        return smallest_p;    }
     
    bool Sequence::erase(int pos)
{
        if( pos < 0 || pos >= m_size)
        {
            return false;
        }
        for(int i = pos; i < m_size; i++)
        {

            m_arr[i] = m_arr[i+1];
        }
        m_size--;
        
        return true;
}
        
      // If 0 <= pos < size(), remove the item at position pos from
      // the sequence (so that all items that followed that item end up at
      // positions one lower than they were at before), and return true.
      // Otherwise, leave the sequence unchanged and return false.
     
    int Sequence::remove(const ItemType value)
{
        int counter =0 ;
        for(int i = m_size-1; i >= 0; i--)
        {
            if(m_arr[i] == value)
            {
                if(erase(i))
                    counter++;
            }
        }
        return counter;
}
      // Erase all items from the sequence that == value.  Return the
      // number of items removed (which will be 0 if no item == value).

    bool Sequence::get(int pos, ItemType& value) const
{
        if( pos < 0 || pos >= m_size)
        {
            return false;
        }
        value = m_arr[pos];
        return true;
}
      // If 0 <= pos < size(), copy into value the item in position pos
      // of the sequence and return true.  Otherwise, leave value unchanged
      // and return false.

    bool Sequence::set(int pos, const ItemType& value)
{
        if( pos < 0 || pos >= m_size)
        {
            return false;
        }
        m_arr[pos] = value;
        return true;
}
      // If 0 <= pos < size(), replace the item at position pos in the
      // sequence with value and return true.  Otherwise, leave the sequence
      // unchanged and return false.

    int Sequence::find(const ItemType& value) const
{
        for(int p = 0 ; p < m_size; p++)
        {
            if(m_arr[p] == value)
                return p;
        }
        return -1;
}
      // Let p be the smallest integer such that value == the item at
      // position p in the sequence; if no such item exists, let p be -1.
      // Return p.

    void Sequence::swap(Sequence& other)
{
    int temp_size = m_size;
    m_size = other.m_size;
    other.m_size = temp_size;
    
    ItemType* temp_ptr = other.m_arr;
    other.m_arr = m_arr;
    m_arr = temp_ptr;

    int temp_capacity;
    temp_capacity = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = temp_capacity;
        
        


      // Exchange the contents of this sequence with the other one.
}
Sequence::~Sequence()
{
    delete [] m_arr; 
}
