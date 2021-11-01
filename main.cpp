#include <iostream>

using namespace std;

#include "puzzleMaker.h"

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

    return 0;
}