#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include <locale>

#include "algorithms.h"
#include "puzzleMaker.h"


void testCaseManager(){
    cout << "Which test would you like to do?\n\n 0, 2, 4, 8, 12, 16, 20, 24\n" << endl;
    unsigned choice = 32;
    cin >> choice;
    switch (choice){
        case 0:
            {
            unsigned depthZeroInit [9] = {1,2,3,4,5,6,7,8,0};
            // cout << pzlTest << endl << pzlTest.zeroPos[0] << ", " << pzlTest.zeroPos[1] << endl;
            {
                Puzzle pzlToUse(depthZeroInit);
                cout << endl << pzlToUse << "Zero at: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 0 using: Uniform Cost Search\n" << endl;
                generalSearch(pzlToUse, 2);
            }
            {
                Puzzle pzlToUse(depthZeroInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 0 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0);
            }
            {
                Puzzle pzlToUse(depthZeroInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 0 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1);
            }
            }
            break;

        case 2:
            {
            unsigned depthTwoInit [9] = {1,2,3,4,5,6,0,7,8};
            // cout << pzlTest << endl << pzlTest.zeroPos[0] << ", " << pzlTest.zeroPos[1] << endl;
            {
                Puzzle pzlToUse(depthTwoInit);
                cout << endl << pzlToUse << "Zero at: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 2 using: Uniform Cost Search\n" << endl;
                generalSearch(pzlToUse, 2);
            }
            {
                Puzzle pzlToUse(depthTwoInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 2 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0);
            }
            {
                Puzzle pzlToUse(depthTwoInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 2 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1);
            }
            }
            break;

        case 4:
            {
            unsigned depthFourInit [9] = {1,2,3,5,0,6,4,7,8};
            // cout << pzlTest << endl << pzlTest.zeroPos[0] << ", " << pzlTest.zeroPos[1] << endl;
            {
                Puzzle pzlToUse(depthFourInit);
                cout << endl << pzlToUse << "Zero at: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 4 using: Uniform Cost Search\n" << endl;
                generalSearch(pzlToUse, 2);
            }
            {
                Puzzle pzlToUse(depthFourInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 4 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0);
            }
            {
                Puzzle pzlToUse(depthFourInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 4 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1);
            }
            }
            break;

        case 8:
            {
            unsigned depthEightInit [9] = {1,3,6,5,0,2,4,7,8};
            // cout << pzlTest << endl << pzlTest.zeroPos[0] << ", " << pzlTest.zeroPos[1] << endl;
            {
                Puzzle pzlToUse(depthEightInit);
                cout << endl << pzlToUse << "Zero at: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 8 using: Uniform Cost Search\n" << endl;
                generalSearch(pzlToUse, 2);
            }
            {
                Puzzle pzlToUse(depthEightInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 8 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0);
            }
            {
                Puzzle pzlToUse(depthEightInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 8 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1);
            }
            }
            break;

        case 12:
            {
            unsigned depthTwelveInit [9] = {1,3,6,5,0,7,4,8,2};
            // cout << pzlTest << endl << pzlTest.zeroPos[0] << ", " << pzlTest.zeroPos[1] << endl;
            {
                Puzzle pzlToUse(depthTwelveInit);
                cout << endl << pzlToUse << "Zero at: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 12 using: Uniform Cost Search\n" << endl;
                generalSearch(pzlToUse, 2);
            }
            {
                Puzzle pzlToUse(depthTwelveInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 12 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0);
            }
            {
                Puzzle pzlToUse(depthTwelveInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 12 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1);
            }
            }
            break;

        case 16:
            {
            unsigned depthSixteenInit [9] = {1,6,7,5,0,3,4,8,2};
            // cout << pzlTest << endl << pzlTest.zeroPos[0] << ", " << pzlTest.zeroPos[1] << endl;
            cout << "Uniform Cost omitted to avoid memory error\n" << endl;
            {
                Puzzle pzlToUse(depthSixteenInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 16 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0);
            }
            {
                Puzzle pzlToUse(depthSixteenInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 16 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1);
            }
            }
            break;

        case 20:
            {
            unsigned depthTwentyInit [9] = {7,1,2,4,8,5,6,3,0};
            // cout << pzlTest << endl << pzlTest.zeroPos[0] << ", " << pzlTest.zeroPos[1] << endl;
            cout << "Uniform Cost and Missplaced tile omitted to avoid memory error\n" << endl;
            {
                Puzzle pzlToUse(depthTwentyInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 20 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1);
            }
            }
            break;

        case 24:
            {
            unsigned depthTwFrInit [9] = {0,7,2,4,6,1,3,5,8};
            // cout << pzlTest << endl << pzlTest.zeroPos[0] << ", " << pzlTest.zeroPos[1] << endl;
            cout << "Uniform Cost and Missplaced tile omitted to avoid memory error\n" << endl;
            {
                Puzzle pzlToUse(depthTwFrInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 24 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1);
            }
            }
            break;
        
        default:
            cout << "Unrecognized Input.\nReturning to Main Menu...\n\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
    }
}

void customTest(){
    cout << "Please enter a string of 9 values, from 0 to 8.\nIncorrect configurations will be discarded\n" << endl;
    char n = 'a';
    unsigned initArr[9];
    for(unsigned i = 0; i < 9; i++){
        cin >> n;
        // cout << static_cast<unsigned>(n) - 48;
        if(!isalpha(n) && (static_cast<unsigned>(n) > 47) && (static_cast<unsigned>(n) < 57)){
            initArr[i] = static_cast<unsigned>(n) - 48;
        }
        else{
            cout << "\nYour input was impropper. Please only include numbers with no spaces (ex: 012345678)\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }
    }

    Puzzle customPuzzle(initArr);
    cout << "\n\n8 puzzle you have made:\n" << customPuzzle;
    cout << "Zero is at: " << customPuzzle.zeroPos[0] << ", " << customPuzzle.zeroPos[1] << endl;
    cout << "\nWhich method would you like to use to solve?\n0.Misplaced Tile\n1.Manhattan\n2.Uniform Cost Search\n" << endl; 
    int type = 4;
    cin >> type;
    cin.clear();
    cin.ignore(10000, '\n');
    switch (type){
    case 0:
        generalSearch(customPuzzle, 0);
        break;

    case 1:
        generalSearch(customPuzzle, 1);
        break;
    
    case 2:
        generalSearch(customPuzzle, 2);
        break;
    
    default:
        break;
    }
    cout << "\nDone." << endl;
}

void mainMenu(){    
    int menuIn = -1;
    while (menuIn){
        cout << "\n8 Puzzle Solver- idelc\n" << endl;
        cout << "Main Menu" << endl;
        cout << "1. Use Test Cases\n";
        cout << "2. Custom Input String\n";
        cout << "0. Exit\n" << endl;
        cin >> menuIn;
        cout << endl;

        switch (menuIn){
            case 0:
                break;

            case 1:
                testCaseManager();
                break;

            case 2:
                customTest();
                break;
            
            default:
                cout << "Unrecognized input, please try again" << endl;
                menuIn = -1;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
        }
    }
    cout << "Goodbye!\n" << endl;
    return;
}

#endif