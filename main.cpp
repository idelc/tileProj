#include <iostream>

using namespace std;

#include "puzzleMaker.h"

int main(){
    Puzzle pzlToUse(3);
    cout << pzlToUse << endl;
    pzlToUse.editPuzzle(0,0,5);
    cout << pzlToUse << endl;
    pzlToUse.clearPuzzle();
    cout << pzlToUse << endl;    
    return 0;
}