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

    // test movement
    cout << "\nZero pos: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1] << endl;
    pzlToUse.moveUp();
    cout << pzlToUse << endl;
    cout << "\nZero pos: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1] << endl;

    cout << "\nZero pos: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1] << endl;
    pzlToUse.moveUp();
    cout << pzlToUse << endl;
    cout << "\nZero pos: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1] << endl;

    cout << "\nZero pos: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1] << endl;
    pzlToUse.moveUp();
    cout << pzlToUse << endl;
    cout << "\nZero pos: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1] << endl;

    cout << "\nZero pos: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1] << endl;
    pzlToUse.moveUp();
    cout << pzlToUse << endl;
    cout << "\nZero pos: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1] << endl;
    

    return 0;
}