#include "Game.h"
    #include "Player.h"
    #include "Board.h"
    #include "Side.h"
    #include <iostream>
    #include <cassert>
    using namespace std;

    void doGameTests()
    {
        SmartPlayer bp1("Bart");
        HumanPlayer bp2("Homer");
        Board b(5, 4);
        Game g(b, &bp1, &bp2);
        g.play();
    }

    int main()
    {
        doGameTests();
        cout << "Passed all tests" << endl;
    }
