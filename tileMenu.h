#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>

#include "algorithms.h"
#include "puzzleMaker.h"

void testDepthZero(){
    
    unsigned pzlSize = 3;
    {
        Puzzle pzlToUse(pzlSize);
        cout << pzlToUse << "Zero at: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
        cout << "Testing Depth 0 using: Uniform Cost Search\n" << endl;
        generalSearch(pzlToUse, 2);
    }
    {
        Puzzle pzlToUse(pzlSize);
        cout << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
        cout << "Testing Depth 0 using: A* Misplaced Tile\n" << endl;
        generalSearch(pzlToUse, 0);
    }
    {
        Puzzle pzlToUse(pzlSize);
        cout << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
        cout << "Testing Depth 0 using: A* Manhattan\n" << endl;
        generalSearch(pzlToUse, 1);
    }
}

#endif