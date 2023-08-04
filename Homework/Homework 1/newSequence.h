//
//  newSequence.hpp
//  Assignment 1
//
//  Created by Gautam Anand on 4/17/23.
//

#ifndef newSequence_hpp
#define newSequence_hpp
#include <string>


using ItemType = std::string;
const int DEFAULT_MAX_ITEMS = 160;
class Sequence
{
public:
    Sequence();
    Sequence(int capacity);// Create an empty sequence (i.e., one whose size() is 0).
    Sequence(const Sequence& Seq);
    Sequence& operator = (const Sequence& Seq);
    ~Sequence();
    bool empty() const;  // Return true if the sequence is empty, otherwise false.
    int size() const;    // Return the number of items in the sequence.
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value)    const ;
    void swap(Sequence& other);
private:
    ItemType* m_arr;
    int m_size;
    int m_capacity; 
};
#endif /* newSequence_hpp */
