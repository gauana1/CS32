//
//  main.cpp
//  DoubleLL
//
//  Created by Gautam Anand on 4/21/23.
//

#include <iostream>
#include <cassert>
#include "Sequence.h"
using namespace std;

Sequence::Sequence()
{
    m_size = 0;
    dummy = new Node();
    dummy ->prev = dummy;
    dummy ->next = dummy;
    
}
Sequence::~Sequence() //destructor
{
    
    for(int i = 0; i<m_size;)
    {
        erase(0);
    }
    delete dummy; //delete dummy
}
Sequence::Sequence(const Sequence&Seq)
{
    m_size = 0; //set size to zero
    dummy = new Node();
    dummy -> next = dummy;
    dummy -> prev = dummy; //do the same thing as in the deffault constructor
    int counter  =0 ;
    for(Node *p = Seq.dummy -> next; p != Seq.dummy; p =p-> next)//    int counter = 0;
    {
        insert(counter, p-> value);
        counter ++; //increamente countre
    }
}
Sequence& Sequence::operator = (const Sequence& Seq)
{
    if(this != &Seq)
    {
        Sequence temp(Seq); //swap and copy method for assignment oeprator
        swap(temp);

    }
    return *this;
}
bool Sequence::empty() const
{
    if (m_size ==0)
    {
        return true; //trivial
    }
    return false;
}
int Sequence::size() const
{
 return m_size;//trivial
}
int Sequence::insert(int pos, const ItemType& value)
{
    if(pos <0 || pos > m_size)
    {
        return -1; //check if out of bounds
    }
    if(m_size ==0)
    {
        Node* item = new Node(); //method for inserting a node at the beginning
        Node *temp = dummy;
        item -> value = value;
        temp -> next = item;
        temp-> prev = item;
        item -> prev = temp;
        item -> next = temp;
        m_size++;
        return 0;
    }
    Node* item = new Node(); //method for inserting node anywehr else in the list using cirular double linekd list
    item -> value = value;
    Node *temp = dummy;
    int counter = 0;
    while(counter < pos) //move the temp until a value of interest is reached
    {
        temp = temp-> next;
        counter++;
    }
    
    item ->next = temp->next; //insert node through following lines of code
    item -> prev = temp;
    temp -> next -> prev = item;
    temp -> next = item;

    
    m_size ++; //increment size and return pos
    return pos;
}
int Sequence::insert(const ItemType& value)
{

    Node *temp = dummy-> next; //set equal to dummy node
    int counter = 0 ;

    if(m_size ==0)
    {
        insert(0,value);
        temp = temp -> next;
        return counter;
    }
    while (counter < m_size) //use a while loop to increment the temp node
    {
        
        if(temp-> value >= value)
        {
            break;
        }
        temp = temp ->next;
        counter++;
    }
    insert(counter, value); //inssert when the value match at that location
    return counter;
}
bool Sequence::erase(int pos)
{
    
    if(pos <0 || pos >= m_size || m_size ==0)
    {
        return false;
    }
    int i = 0;
    Node* temp = dummy;
    for (temp = dummy; i < pos; temp = temp->next)
    {
        i++;
    }
    Node *temp2 = temp-> next;
    temp->next = temp2->next;
    temp2->next -> prev = temp;
    delete temp2;
    m_size--;
    return true;
}
int  Sequence::remove(const ItemType& value)
{
    int count = 0;
    while(find(value) != -1)
    {
        erase(find(value));
        count++;
        
    }
    return count;
}
bool Sequence::get(int pos, ItemType& value) const
{
    if (pos >= m_size || pos < 0)    //check edge cases
    {
        return false;
    }
    int i = 0;
    Node* temp;
    for (temp = dummy->next; i < pos; temp = temp->next) //increment through the sequqnce and increment i and the pointer
    {
        i++;
    }
    value = temp->value; //place value into value
    return true;
}
bool Sequence::set(int pos, const ItemType& value) //almost hte same implementation as get, but instead of placing a value, you are inserting it
{
    if(pos <0 || pos >= m_size)
    {
        return false;
    }
    int counter = 0;
    Node *temp= dummy-> next;
    while(counter < pos)
    {
        temp = temp -> next;
        counter++;
    }
    temp -> value = value; //inset value  into the pointer
    return true;
}
int Sequence::find(const ItemType& value) const
{
    Node *temp = dummy-> next;
    int pos = -1;
    int i = 0 ;
    for(; temp!= dummy; temp = temp-> next)
    {
        if(temp -> value == value)
        {
            pos = i;
            break;
        }
        i++;
        
    }
    return pos;
}
void Sequence::swap(Sequence& other)//swap, when swapping make a temp that is otf type node pointer, and then use this temp to swap other dummy and the dummy pointers to essetiallly flip the lists. Also change the sizes of the lsits.
{
    Node *temp = other.dummy;
    other.dummy = dummy;
    dummy = temp;
    int temp_size  = other.m_size;
    other.m_size = m_size;
    m_size = temp_size;
    
}
void Sequence::dump() const //to print out sequence
{
//    for (Node* p = dummy->next; p != dummy; p = p->next)
//    {
//        cerr << p->value << endl;
//    }
}
int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    if(seq2.size() > seq1.size() || seq2.size() <= 0 || seq1.size() <=0) //check edge cases
    {
        return -1;
    }
    ItemType temp2;
    seq2.get(0, temp2);

    int counter = 0;
    for(int position = seq1.find(temp2);position  < seq1.size() ; position ++) //use a for loop in order to check if subsequence works
    {
        ItemType temp1;
        seq1.get(position, temp1);
        seq2.get(counter, temp2);
        if(temp1 == temp2)
        {
            counter++;
        }
        else if(temp1 != temp2 )
        {
            counter = 0 ; //this counter is to make sure that the items are in order
        }
        if(counter == seq2.size())
        {
            return (position-counter+1); //return this value to get when the sequence starts
        }
    }
    return -1;
}
void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    Sequence Cseq1 = seq1;
    Sequence Cseq2 = seq2;
    for(int i = 0 ; i < result.size();) //make sure that erase is empty before using concat reverse
    {
        result.erase(0);
    }
    for(int i =0 ; i < Cseq2.size(); i++)
    {
        ItemType value;
        Cseq2.get(i, value);
        result.insert(0, value);
    }
    for(int i =0 ; i < Cseq1.size(); i++)
    {
        ItemType value;
        Cseq1.get(i, value);
        result.insert(0, value);
    }
}

