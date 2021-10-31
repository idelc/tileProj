#include <iostream>

using namespace std;

#include "puzzleMaker.h"

int main(){
    Puzzle pzlToUse(3);
    cout << pzlToUse;
    pzlToUse.editPuzzle(0,0,5);
    cout << pzlToUse;
    pzlToUse.clearPuzzle();
    cout << pzlToUse;    
    return 0;
}