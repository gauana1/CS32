//
//  testnewSequence.cpp
//  Assignment 1
//
//  Created by Gautam Anand on 4/18/23.
//

#include "newSequence.h"



       #include <string>
       #include <iostream>
       #include <cassert>
       using namespace std;

       void test()
       {
           Sequence s;
           s.insert(0, "lavash");
           s.insert(0, "tortilla");
           assert(s.size() == 2);
           ItemType x = "injera";
           assert(s.get(0, x) && x == "tortilla");
           assert(s.get(1, x) && x == "lavash");
       }

       int main()
       {
           test();
           cout << "Passed all tests" << endl;
       }
