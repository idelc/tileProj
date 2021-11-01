#ifndef ALG
#define ALG

// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
// https://en.cppreference.com/w/cpp/container/priority_queue
// used these two sites to review the way priority queues are defined in c++
// and used that to properly set up the code needed to sort Nodes

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include "puzzleMaker.h"

const Puzzle SOLVED_PUZZLE(3);

class Node{ // struct to hold node info
 public:
    Node(Puzzle& pzl, unsigned cst, unsigned heu):nodePzl(pzl),cost(cst),heuristic(heu){};
    Puzzle nodePzl;
    unsigned cost; 
    unsigned heuristic;
    bool operator>(const Node&); //overloading comparitor
};

bool Node::operator>(const Node& node) { //overload comparison to allow priority queue to sort properly
        return (this->cost + this->heuristic) > (node.cost + node.heuristic);
}

void uniformCostSearch(Puzzle& pzl){
    priority_queue<Node*, vector<Node*>, std::greater<Node*>> nodes; // min priority queue 
    nodes.push(new Node(pzl,0,0));
    bool solved = false; // loop condition
    int times = 0;
    ofstream write;
    write.open("UCtrace.txt");
    if(!write.is_open()){
        cout << "error opening file" << endl;
    }
    while((!solved) && times++ < 500){
        if(nodes.empty()){
            cout << "Failed to solve the puzzle" << endl;
            return;
        }
        Node* temp = nodes.top();
        nodes.pop();
        write << temp->nodePzl << "cost: " << temp->cost << " in queue: " << nodes.size() << endl;
        bool match = true;
        unsigned nodePzlSize = temp->nodePzl.size;
        for(unsigned i = 0; i < nodePzlSize; i++){
            for(unsigned j = 0; j < nodePzlSize; j++){
                // is the temp node puzzle at the current value the same as the solved puzzle at that value?
                // asume true, if find one discrepancy set flag to false for remainder of loop
                if(temp->nodePzl.pzlBoard[i][j] != SOLVED_PUZZLE.pzlBoard[i][j]){
                    match = false;
                }
            }
        }
        if(match){
            cout << "solution found at depth " << temp->cost << endl;
            return;
        }
        else{
            for(unsigned i = 0; i < 4; i++){
                Node tempMoves = *temp;
                switch (i){
                case 0:
                    tempMoves.nodePzl.moveUp();
                    tempMoves.cost++;
                    nodes.push(new Node(tempMoves.nodePzl, tempMoves.cost, tempMoves.heuristic));
                    //cout << "up" << endl;
                    break;
                
                case 1:
                    tempMoves.nodePzl.moveLeft();
                    tempMoves.cost++;
                    nodes.push(new Node(tempMoves.nodePzl, tempMoves.cost, tempMoves.heuristic));
                    //cout << "left" << endl;
                    break;

                case 2: 
                    tempMoves.nodePzl.moveRight();
                    tempMoves.cost++;
                    nodes.push(new Node(tempMoves.nodePzl, tempMoves.cost, tempMoves.heuristic));
                    //cout << "right" << endl;
                    break;

                case 3:
                    tempMoves.nodePzl.moveDown();
                    tempMoves.cost++;
                    nodes.push(new Node(tempMoves.nodePzl, tempMoves.cost, tempMoves.heuristic));
                    //cout << "down" << endl;
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