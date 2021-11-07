#ifndef ALG
#define ALG

// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
// https://en.cppreference.com/w/cpp/container/priority_queue
// https://www.cplusplus.com/reference/list/list/sort/
// https://stackoverflow.com/questions/20167685/measuring-cpu-time-in-c
// used the first two sites to review the way priority queues are defined in c++
// and used that to properly set up the code needed to sort Nodes
// ended up switching to a list because the min heap was not working
// as well as I hoped, but now I have optimal behavior at the cost of sorting speed
// last site is used to measure cpu time in linux only

#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "puzzleMaker.h"

Puzzle SOLVED_PUZZLE(3);

class Node{ // struct to hold node info
 public:
    Node(Puzzle& pzl, unsigned cst, unsigned heu, unsigned lastM):nodePzl(pzl),cost(cst),heuristic(heu), lastMove(lastM){};
    Node(const Node& nd): nodePzl(nd.nodePzl), cost(nd.cost), heuristic(nd.heuristic), lastMove(nd.lastMove){};
    Node(Node* nd): nodePzl(nd->nodePzl), cost(nd->cost), heuristic(nd->heuristic), lastMove(nd->lastMove){};
    ~Node(){}
    Puzzle nodePzl;
    unsigned cost; 
    unsigned heuristic;
    unsigned lastMove; // store last move and dont make a node undoing it
};

bool smallerNode(const Node& node1, const Node& node2){
    return ((node1.cost+node1.heuristic)<(node2.cost+node2.heuristic));
}

unsigned misplacedTile(Puzzle& currPz, Puzzle& otherPz){
    unsigned mT = 0;
    for(unsigned i = 0; i < currPz.size; i++){
            for(unsigned j = 0; j < currPz.size; j++){
                // is the temp node puzzle at the current value the same as the solved puzzle at that value?
                // asume true, if find one discrepancy set flag to false for remainder of loop
                if(currPz.pzlBoard[i][j] != otherPz.pzlBoard[i][j]){
                    mT++;
                }
            }
        }
    return mT;    
}

unsigned manhattan(const Puzzle& currPz){
    unsigned sz = currPz.size;
    unsigned manhArr [(sz*sz)][2];
    unsigned arrPnt = 1;
    manhArr[0][0] = sz-1;
    manhArr[0][1] = sz-1;
    for(unsigned i = 0; i < sz; i++){ //initialize "right possition array"
        for(unsigned j = 0; j < sz; j++){
            manhArr[arrPnt][0] = i;
            manhArr[arrPnt++][1] = j;
        }
    } 

    unsigned tempNum1, mhNum = 0;
    for(unsigned i = 0; i < sz; i++){ //check curr array pos
        for(unsigned j = 0; j < sz; j++){
            tempNum1 = currPz.pzlBoard[i][j]; 
            if(tempNum1){
                mhNum = mhNum + abs(static_cast<int>(manhArr[tempNum1][0]) - static_cast<int>(i)) + abs(static_cast<int>(manhArr[tempNum1][1]) - static_cast<int>(j));
            }
        }
    } 
    return mhNum;
}


void generalSearch(Puzzle& pzl, const unsigned heu, bool print){
    // priority_queue<Node*, vector <Node*>, std::greater<Node*> > nodes; // min priority queue 
    clock_t timeS = clock();
    list<Node*> nodes;
    unsigned mostExpanded = 0;
    unsigned sizeTemp = 0;
    unsigned totalExp = 0; 
    nodes.push_front(new Node(pzl,0,0,4)); //First node, no cost, no heuristic, last move is invalid
    bool solved = false; // loop condition
    ofstream write;
    write.open("Trace.txt");
    if(!write.is_open()){
        cout << "error opening file" << endl;
        exit(1);
    }
    while(!solved){
        if(nodes.empty()){
            cout << "Failed to solve the puzzle" << endl;
            return;
        }
        nodes.sort(smallerNode);
        Node temp = *nodes.front(); // make a copy so as to not need top directly
        nodes.pop_front(); // delete top
        sizeTemp = nodes.size();
        totalExp++;
        mostExpanded = max(mostExpanded, sizeTemp);

        if(print){ write << "\n\n" << temp.nodePzl << "cost: " << temp.cost << " heu: " << temp.heuristic <<" in queue: " << nodes.size() << "\n" << endl;}
        bool match = true;
        unsigned nodePzlSize = temp.nodePzl.size;
        for(unsigned i = 0; i < nodePzlSize; i++){
            for(unsigned j = 0; j < nodePzlSize; j++){
                // is the temp node puzzle at the current value the same as the solved puzzle at that value?
                // asume true, if find one discrepancy set flag to false for remainder of loop
                if(temp.nodePzl.pzlBoard[i][j] != SOLVED_PUZZLE.pzlBoard[i][j]){
                    match = false;
                }
            }
        }
        if(match){
            cout << "Solution found at depth: " << temp.cost; 
            cout << "\nTotal nodes expanded: " << totalExp;
            cout << "\nMax size of queue: "<< mostExpanded;
            cout << "\nCPU time (linux only): " << static_cast<double>((clock()-timeS))/CLOCKS_PER_SEC << " seconds";
            cout << "\nNodes at frontier: " << nodes.size() << endl;
            write.close();
            return;
        }
        else{
            Node tempMoves = temp;
            unsigned int validMove = 0;
            for(unsigned i = 0; i < 4; i++){
                tempMoves = temp;
                validMove = false;
                switch (i){
                    case 0:
                        if(tempMoves.lastMove == 3) {break;}
                        if(!(tempMoves.nodePzl.moveUp())) {break;}
                        tempMoves.lastMove = 0;
                        tempMoves.cost = tempMoves.cost + 1;
                        switch (heu){
                            case 0:
                                // misplaced tile
                                tempMoves.heuristic = misplacedTile(tempMoves.nodePzl, SOLVED_PUZZLE);
                                break;

                            case 1:
                                // manhattan
                                tempMoves.heuristic = manhattan(tempMoves.nodePzl);
                                break;

                            default:
                                // uniform cost
                                tempMoves.heuristic = 0;
                                break;
                        }
                        nodes.push_front(new Node(tempMoves.nodePzl, tempMoves.cost, tempMoves.heuristic, tempMoves.lastMove));
                        // write << "up\n" << tempMoves.nodePzl << "cost: " << tempMoves.cost << " heu: " << tempMoves.heuristic << " in queue: " << nodes.size() << endl;
                        break;
                    
                    case 1:
                        if(tempMoves.lastMove == 2) {break;}
                        if(!(tempMoves.nodePzl.moveLeft())) {break;}
                        tempMoves.lastMove = 1;
                        tempMoves.cost = tempMoves.cost + 1;
                        switch (heu){
                            case 0:
                                // misplaced tile
                                tempMoves.heuristic = misplacedTile(tempMoves.nodePzl, SOLVED_PUZZLE);
                                break;

                            case 1:
                                // manhattan
                                tempMoves.heuristic = manhattan(tempMoves.nodePzl);
                                break;

                            default:
                                // uniform cost
                                tempMoves.heuristic = 0;
                                break;
                        }
                        nodes.push_front(new Node(tempMoves.nodePzl, tempMoves.cost, tempMoves.heuristic, tempMoves.lastMove));
                        // write << "left\n" << tempMoves.nodePzl << "cost: " << tempMoves.cost << " heu: " << tempMoves.heuristic << " in queue: " << nodes.size() << endl;
                        break;

                    case 2: 
                        if(tempMoves.lastMove == 1) {break;}
                        if(!(tempMoves.nodePzl.moveRight())) {break;}
                        tempMoves.lastMove = 2;
                        tempMoves.cost = tempMoves.cost + 1;
                        switch (heu){
                            case 0:
                                // misplaced tile
                                tempMoves.heuristic = misplacedTile(tempMoves.nodePzl, SOLVED_PUZZLE);
                                break;

                            case 1:
                                // manhattan
                                tempMoves.heuristic = manhattan(tempMoves.nodePzl);
                                break;

                            default:
                                // uniform cost
                                tempMoves.heuristic = 0;
                                break;
                        }
                        nodes.push_front(new Node(tempMoves.nodePzl, tempMoves.cost, tempMoves.heuristic, tempMoves.lastMove));
                        // write << "right\n" << tempMoves.nodePzl << "cost: " << tempMoves.cost << " heu: " << tempMoves.heuristic << " in queue: " << nodes.size() << endl;
                        break;

                    case 3:
                        if(tempMoves.lastMove == 0) {break;}
                        if(!(tempMoves.nodePzl.moveDown())) {break;}
                        tempMoves.lastMove = 3;
                        tempMoves.cost = tempMoves.cost + 1;
                        switch (heu){
                            case 0:
                                // misplaced tile
                                tempMoves.heuristic = misplacedTile(tempMoves.nodePzl, SOLVED_PUZZLE);
                                break;

                            case 1:
                                // manhattan
                                tempMoves.heuristic = manhattan(tempMoves.nodePzl);
                                break;

                            default:
                                // uniform cost
                                tempMoves.heuristic = 0;
                                break;
                        }
                        nodes.push_front(new Node(tempMoves.nodePzl, tempMoves.cost, tempMoves.heuristic, tempMoves.lastMove));
                        // write << "down\n" << tempMoves.nodePzl << "cost: " << tempMoves.cost << " heu: " << tempMoves.heuristic << " in queue: " << nodes.size() << endl;
                        break;

                    default:
                        cout << "error in expanding UC children" << endl;
                        exit(1);
                        break;
                }
            }
        }
    }
}

#endif