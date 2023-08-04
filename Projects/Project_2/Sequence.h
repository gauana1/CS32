//
//  Sequence.h
//  DoubleLL
//
//  Created by Gautam Anand on 4/21/23.
//

#ifndef Sequence_h
#define Sequence_h
#include <iostream>
#include <string>
using namespace std; 
using ItemType = string;
struct Node
{
    ItemType value;
    Node *next;
    Node *prev;
};
class Sequence
{
  public:
    Sequence();
    Sequence(const Sequence&Seq);
    Sequence& operator = (const Sequence& Seq);
    ~Sequence(); 
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    void dump() const;
    
private:
    Node *dummy;
    int m_size; 
};
int subsequence(const Sequence& seq1, const Sequence& seq2);
void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result);
#endif /* Sequence_h */
