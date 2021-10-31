#ifndef PZZLMKR
#define PZZLMKR

// referencing https://stackoverflow.com/questions/9219712/c-array-expression-must-have-a-constant-value
// used to dynamically allocate array to allow scaling 

#include <iostream>
using namespace std;

class Puzzle{
 public:
    Puzzle(unsigned sz): size(sz){ // pass in 3 for an 8 puzzle
        unsigned** arr = new unsigned*[sz];
        for(int i = 0; i < sz; i++){
            arr[i] = new unsigned[sz];
        }

        for(unsigned i = 0; i < ((sz*sz)-1); i++){
            arr[i][i] = i+1;
        }
        arr[sz-1][sz-1] = 0;

        pzlBoard = arr;
    };

    void clearPuzzle(){
        for(unsigned i = 0; i < (this->size*this->size); i++){
            this->pzlBoard[i][i] = 0;
        }
    }

    friend ostream& operator<<(ostream& o, const Puzzle& pzl){
        for(unsigned i = 0; i < pzl.size; i++){
            o << "\n[";
            for(unsigned j = 0; i < pzl.size; i++){
                 o << pzl.pzlBoard[i][i] << ' ';
            }
            o << "]" << endl;
        }
    }

    void editPuzzle(unsigned x, unsigned y, unsigned num){
        if(num > ((this->size * this->size) - 1)){return;}

        this->pzlBoard[x][y] = num;
    }

    ~Puzzle(){
        for(int i = 0; i < this->size; i++){
            delete[] this->pzlBoard[i];
        }
        delete[] pzlBoard;
    }
    
    unsigned size; // puzzle of size x size, will test with 8
    unsigned** pzlBoard;
};


#endif