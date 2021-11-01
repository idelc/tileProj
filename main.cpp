#include <iostream>

using namespace std;

#include "puzzleMaker.h"
#include "algorithms.h"

int main(){
    //test init
    unsigned pzlSize = 3;
    Puzzle pzlToUse(pzlSize);
    pzlToUse.editPuzzle(0,1,3);
    pzlToUse.editPuzzle(0,2,6);
    pzlToUse.editPuzzle(1,0,5);
    pzlToUse.editPuzzle(1,1,0);
    pzlToUse.editPuzzle(1,2,2);
    pzlToUse.editPuzzle(2,0,4);
    pzlToUse.editPuzzle(2,1,7);
    pzlToUse.editPuzzle(2,2,8);
    pzlToUse.zeroPos[0] = 1;
    pzlToUse.zeroPos[1] = 1;

    cout << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;

    cout << "testing using the uniform cost algorithm" << endl;
    cout << "depth 6\n" << endl;

    uniformCostSearch(pzlToUse);

    return 0;
}