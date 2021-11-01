#include <iostream>

using namespace std;

#include "puzzleMaker.h"
#include "algorithms.h"

int main(){
    //test init
    unsigned pzlSize = 3;
    Puzzle pzlToUse(pzlSize);
    pzlToUse.moveLeft();
    pzlToUse.moveLeft();
    pzlToUse.moveUp();
    pzlToUse.moveRight();
    cout << pzlToUse << endl;

    cout << "testing using the uniform cost algorithm" << endl;
    cout << "depth 4\n" << endl;

    uniformCostSearch(pzlToUse);

    return 0;
}