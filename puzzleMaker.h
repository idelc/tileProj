#ifndef PZZLMKR
#define PZZLMKR

#include <iostream>
#include <cstdlib>
using namespace std;

class Puzzle{
 public:

    //constructor. currently hardcoded to make an 8 puzzle, though minor changes could be made to increase size
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

    Puzzle(unsigned initArr[9]): size(3){
        unsigned n = 0;
        for(unsigned i = 0; i < this->size; i++){
            for(unsigned j = 0; j < this->size; j++){
                // cout << "assigning " << i << ", " << j << " = " << initArr[n] << endl;
                this->pzlBoard[i][j] = initArr[n];
                if(!(initArr[n++])){
                    zeroPos[0] = i;
                    zeroPos[1] = j;
                }
            }
        }
    };

    // the copy constructor. Performs deep copy of all arrays.
    Puzzle(const Puzzle &cpy): size(cpy.size){
        for(unsigned i = 0; i < this->size; i++){
            for(unsigned j = 0; j < this->size; j++){
                this->pzlBoard[i][j] = cpy.pzlBoard[i][j];
            }
        }
        this->zeroPos[0] = cpy.zeroPos[0];
        this->zeroPos[1] = cpy.zeroPos[1];
    }; 

	// the overloaded assignment operator. This performs deep copy.
    // Takes in puzzle, makes constant, and edits puzzle on lhs of operator
    Puzzle & operator=(const Puzzle &rhs){
        if(this->size != rhs.size) {exit(1);} // do not copy to mismatched sizes.

        for(unsigned i = 0; i < this->size; i++){
            for(unsigned j = 0; j < this->size; j++){
                this->pzlBoard[i][j] = rhs.pzlBoard[i][j];
            }
        }
        this->zeroPos[0] = rhs.zeroPos[0];
        this->zeroPos[1] = rhs.zeroPos[1];
        return *this;
    }

    // sets everything to 0
    void clearPuzzle(){
        for(unsigned i = 0; i < this->size; i++){
            for(unsigned j = 0; j < this->size; j++){
                this->pzlBoard[i][j] = 0;
            }
        }
    }


    // overload of stream operator to easily print the puzzle when needed
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


    // will allow any cell to be edited with no verification of validity
    void editPuzzle(unsigned x, unsigned y, unsigned num){
        if(num > ((this->size * this->size) - 1)){return;}

        this->pzlBoard[x][y] = num;
    }


    // all the movement functions swap the 0 with whatever is in the spot that is being switched to
    // they all have boundary checking to ensure the movement is legal
    // the position of the 0 is stored, and they return 0 or 1 depending on wether the move was legal
    unsigned moveUp(){
        if(this->zeroPos[0] == 0){return 0;}
        this->pzlBoard[this->zeroPos[0]][this->zeroPos[1]] = this->pzlBoard[this->zeroPos[0]-1][this->zeroPos[1]];
        this->pzlBoard[this->zeroPos[0]-1][this->zeroPos[1]] = 0;
        this->zeroPos[0] = this->zeroPos[0] - 1;
        return 1;
    }

    unsigned moveLeft(){
        if(this->zeroPos[1] == 0) {return 0;}
        this->pzlBoard[this->zeroPos[0]][this->zeroPos[1]] = this->pzlBoard[this->zeroPos[0]][this->zeroPos[1]-1];
        this->pzlBoard[this->zeroPos[0]][this->zeroPos[1]-1] = 0;
        this->zeroPos[1] = this->zeroPos[1] - 1;
        return 1;
    }

    unsigned moveDown(){
        if(this->zeroPos[0] == (this->size - 1)){return 0;}
        this->pzlBoard[this->zeroPos[0]][this->zeroPos[1]] = this->pzlBoard[this->zeroPos[0]+1][this->zeroPos[1]];
        this->pzlBoard[this->zeroPos[0]+1][this->zeroPos[1]] = 0;
        this->zeroPos[0] = this->zeroPos[0] + 1;
        return 1;
    }

    unsigned moveRight(){
        if(this->zeroPos[1] == (this->size - 1)) {return 0;}
        this->pzlBoard[this->zeroPos[0]][this->zeroPos[1]] = this->pzlBoard[this->zeroPos[0]][this->zeroPos[1]+1];
        this->pzlBoard[this->zeroPos[0]][this->zeroPos[1]+1] = 0;
        this->zeroPos[1] = this->zeroPos[1] + 1;
        return 1;
    }



    // scramble function. Will take the puzzle and scramble it in a legal way
    // does not "remove tiles", will simply use the move functions to scramble
    // so as to avoid switching problem space
    void scramblePuzzle(){
        srand(3);
        unsigned numShifts = (rand() % 10) + 1; // limit to 1-10 moves to avoid making problem too wide
        unsigned shifts[numShifts];
        //cout << numShifts << " moves" << endl;
        for(unsigned i = 0; i < numShifts; i++){ // will choose a move at random
            shifts[i] = rand() % 4;
            //cout << shifts[i] << ' ';
        }
        //cout << endl;

        unsigned move;
        for(unsigned i = 0; i < numShifts; i++){ 
            move = shifts[i];
            switch (move)
            {
            case 0:
                this->moveUp();
                //cout << "up" << endl;
                break;
            
            case 1:
                this->moveLeft();
                //cout << "left" << endl;
                break;

            case 2: 
                this->moveRight();
                //cout << "right" << endl;
                break;

            case 3:
                this->moveDown();
                //cout << "down" << endl;
                break;

            default:
                cout << "error in shuffle" << endl;
                exit(1);
                break;
            }
        }
    }

    // ~Puzzle(){ //destructor, not in use due to removal of dynamic alloc
    //     for(unsigned i = 0; i < this->size; i++){
    //         for(unsigned j = 0; j < this->size; j++){
    //             delete this->pzlBoard[i][j];
    //         }
    //     }
    // }
    

    // variables
    unsigned size; // puzzle of size x size, will test with 8
    unsigned zeroPos[2]; //position of "0"
    unsigned pzlBoard [3][3]; // size of board, hardcoded for now
};


#endif