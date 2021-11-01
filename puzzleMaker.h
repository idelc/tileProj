#ifndef PZZLMKR
#define PZZLMKR

#include <iostream>
using namespace std;

class Puzzle{
 public:
    Puzzle(unsigned sz): size(sz){ // pass in 3 for an 8 puzzle, hardcoded for now
        // cout << "filling in puzzle" << endl;
        zeroPos[0] = sz - 1;
        zeroPos[1] = sz - 1;
        unsigned n = 1;
        for(unsigned i = 0; i < this->size; i++){
            for(unsigned j = 0; j < this->size; j++){
                // cout << "assigning " << i << ", " << j << " = " << n << endl;
                this->pzlBoard[i][j] = n++;
            }
        }
        this->pzlBoard[this->size-1][this->size-1] = 0;
        // cout << "done filling in" << endl;
    };

    void clearPuzzle(){
        for(unsigned i = 0; i < this->size; i++){
            for(unsigned j = 0; j < this->size; j++){
                this->pzlBoard[i][j] = 0;
            }
        }
    }

    friend ostream& operator<<(ostream& o, const Puzzle& pzl){
        for(unsigned i = 0; i < pzl.size; i++){
            o << "[ ";
            for(unsigned j = 0; j < pzl.size; j++){
                 o << pzl.pzlBoard[i][j] << ' ';
            }
            o << "]" << endl;
        }
        return o;
    }

    void editPuzzle(unsigned x, unsigned y, unsigned num){
        if(num > ((this->size * this->size) - 1)){return;}

        this->pzlBoard[x][y] = num;
    }

    unsigned moveUp(){
        if(this->zeroPos[0] == 0){return 0;}
        this->pzlBoard[this->zeroPos[0]][this->zeroPos[1]] = this->pzlBoard[this->zeroPos[0]-1][this->zeroPos[1]];
        this->pzlBoard[this->zeroPos[0]-1][this->zeroPos[1]] = 0;
        this->zeroPos[0] = this->zeroPos[0] - 1;
        return 1;
    }

    // ~Puzzle(){
    //     for(int i = 0; i < this->size; i++){
    //         delete[] this->pzlBoard[i];
    //     }
    //     delete[][] pzlBoard;
    // }
    
    unsigned size; // puzzle of size x size, will test with 8
    unsigned zeroPos[2];
    unsigned pzlBoard [3][3];
};


#endif