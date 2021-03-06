#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include <locale>

#include "algorithms.h"
#include "puzzleMaker.h"

// runs all three algorithms on a precoded version of the test cases
void testCaseManager(){
    cout << "Which test would you like to do?\n\n 0, 2, 4, 8, 12, 16, 20, 24\n" << endl;
    unsigned choice = 32;
    cin >> choice;
    switch (choice){ // interpret choice
        case 0:
            {
            unsigned depthZeroInit [9] = {1,2,3,4,5,6,7,8,0}; // array that can be read into puzzle
            // cout << pzlTest << endl << pzlTest.zeroPos[0] << ", " << pzlTest.zeroPos[1] << endl;
            {
                Puzzle pzlToUse(depthZeroInit);
                cout << endl << pzlToUse << "Zero at: " << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 0 using: Uniform Cost Search\n" << endl;
                generalSearch(pzlToUse, 2, false);
            }
            {
                Puzzle pzlToUse(depthZeroInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 0 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0, false);
            }
            {
                Puzzle pzlToUse(depthZeroInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 0 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1, false);
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
                generalSearch(pzlToUse, 2, false);
            }
            {
                Puzzle pzlToUse(depthTwoInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 2 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0, false);
            }
            {
                Puzzle pzlToUse(depthTwoInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 2 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1, false);
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
                generalSearch(pzlToUse, 2, false);
            }
            {
                Puzzle pzlToUse(depthFourInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 4 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0, false);
            }
            {
                Puzzle pzlToUse(depthFourInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 4 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1, false);
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
                generalSearch(pzlToUse, 2, false);
            }
            {
                Puzzle pzlToUse(depthEightInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 8 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0, false);
            }
            {
                Puzzle pzlToUse(depthEightInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 8 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1, false);
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
                generalSearch(pzlToUse, 2, false);
            }
            {
                Puzzle pzlToUse(depthTwelveInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 12 using: A* Misplaced Tile\n" << endl;
                generalSearch(pzlToUse, 0, false);
            }
            {
                Puzzle pzlToUse(depthTwelveInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 12 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1, false);
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
                generalSearch(pzlToUse, 0, false);
            }
            {
                Puzzle pzlToUse(depthSixteenInit);
                cout << endl << pzlToUse << pzlToUse.zeroPos[0] << ", " << pzlToUse.zeroPos[1]<< endl;
                cout << "Testing Depth 16 using: A* Manhattan\n" << endl;
                generalSearch(pzlToUse, 1, false);
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
                generalSearch(pzlToUse, 1, false);
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
                generalSearch(pzlToUse, 1, false);
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

// allows a string with no spaces to be put in and made initial state
void customTest(bool printOut){
    cout << "Please enter a string of 9 values, from 0 to 8.\nIncorrect configurations will be discarded\n" << endl;
    char n = 'a';
    unsigned initArr[9];
    for(unsigned i = 0; i < 9; i++){ // read 9 times
        cin >> n; // read 1 char
        // cout << static_cast<unsigned>(n) - 48;
        if(!isalpha(n) && (static_cast<unsigned>(n) > 47) && (static_cast<unsigned>(n) < 57)){ // valid number?
            initArr[i] = static_cast<unsigned>(n) - 48; // push into array
        }
        else{
            cout << "\nYour input was impropper. Please only include numbers with no spaces (ex: 012345678)\n" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }
    }

    Puzzle customPuzzle(initArr); // make puzzle using array, display it
    cout << "\n\n8 puzzle you have made:\n" << customPuzzle;
    cout << "Zero is at: " << customPuzzle.zeroPos[0] << ", " << customPuzzle.zeroPos[1] << endl;
    cout << "\nWhich method would you like to use to solve?\n0.Misplaced Tile\n1.Manhattan\n2.Uniform Cost Search\n" << endl; 
    int type = 4;
    cin >> type;
    cin.clear();
    cin.ignore(10000, '\n');
    switch (type){ // allow for choice of algorithm
    case 0:
        generalSearch(customPuzzle, 0, printOut);
        break;

    case 1:
        generalSearch(customPuzzle, 1, printOut);
        break;
    
    case 2:
        generalSearch(customPuzzle, 2, printOut);
        break;
    
    default:
        break;
    }
    cout << "\nDone." << endl;
}

void reportData(){ // not used
    // ofstream wrt;
    // wrt.open("reportData.txt");
    // if(!wrt.is_open()){
    //     cout << "error opening file" << endl;
    //     exit(1);
    // }



    // wrt.close();
}

void mainMenu(){   // loop to output main options 
    int menuIn = -1;
    while (menuIn){
        // main output
        cout << "\n8 Puzzle Solver- idelc\n" << endl;
        cout << "Main Menu" << endl;
        cout << "1. Use Test Cases\n";
        cout << "2. Custom Input String\n";
        cout << "3. Custom Input String, with printout to Trace.txt\n";
        //cout << "4. Simulate data generation for report\n";
        cout << "0. Exit\n" << endl;
        cin >> menuIn;
        cout << endl;
        // read option from user, call appropriate function
        switch (menuIn){
            case 0:
                break;

            case 1:
                testCaseManager();
                break;

            case 2:
                customTest(false);
                break;

            case 3:
                customTest(true);
                break;

            case 4:
                reportData();
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