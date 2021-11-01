#include <iostream>

using namespace std;

#include "puzzleMaker.h"
#include "algorithms.h"

int main(){
    //test init
    unsigned pzlSize = 3;
    Puzzle pzlToUse(pzlSize);
    cout << pzlToUse << endl;
    // pzlToUse.editPuzzle(0,0,5);
    // cout << pzlToUse << endl;
    // pzlToUse.clearPuzzle();
    // cout << pzlToUse << endl;   

    pzlToUse.scramblePuzzle();
    cout << pzlToUse << endl;
    cout << pzlToUse.zeroPos[0] << ' ' << pzlToUse.zeroPos[1] << endl;

    Puzzle pzlTwo(pzlToUse);
    cout << pzlTwo << endl;
    cout << pzlTwo.zeroPos[0] << ' ' << pzlTwo.zeroPos[1] << endl;

    pzlTwo.moveDown();
    pzlToUse = pzlTwo;
    cout << pzlToUse << endl;
    cout << pzlToUse.zeroPos[0] << ' ' << pzlToUse.zeroPos[1] << endl;

    return 0;
}