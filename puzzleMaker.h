#ifndef PZZLMKR
#define PZZLMKR

class Puzzle{
 public:
    Puzzle(unsigned sz): size(sz){
        unsigned** arr = new unsigned*[sz];
        for(int i = 0; i < sz; i++){
            arr[i] = new unsigned[sz];
        }
        pzlBoard = arr;
    };
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