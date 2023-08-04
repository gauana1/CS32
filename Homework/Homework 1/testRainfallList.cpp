//
//  testRainfallList.cpp..cpp
//  Assignment 1
//
//  Created by Gautam Anand on 4/18/23.
//
#include "Sequence.h"
#include "RainfallList.h"
#include <iostream>
#include <cassert>
using namespace std;


int main()
{
    RainfallList x;

    assert(x.add(10));
    assert(x.add(5));
    assert(x.add(300));
    assert(x.add(250));
    cout << x.minimum() << endl;
    assert(x.minimum() == 5);
    assert(x.maximum() == 300);
}





