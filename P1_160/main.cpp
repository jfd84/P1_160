//
//  main.cpp
//  P1_160
//
//  Created by Joe D'Agostino on 9/5/22.
//

#include <iostream>
#include "LL.h"
/*
 The first line of the input file will be an integer that is the number of integers that will be added to the two lists (i.e., their eventual lengths).
 
 This will be followed by a new line character.
 
 The second line will contain all the values (integers) to store; we will refer to this sequence of numbers as the “Additions”. This will be followed by a new line character.
 
 The next line will then contain an integer that is the number of queries, followed by a new line character.
 
 The final line is a sequence of values to retrieve from each of the lists; we will refer to this sequence as the “Queries”.
 
 */


int main(int argc, const char * argv[]) {

    cout << "GitHub TEST" << endl;
    string fileName = "/Users/jfd/Desktop/COSC 160/P1_160/P1_160/poisson_small.txt";
    
    MTFlist mtf;
    mtf.loadFile(fileName);
    
    orderedList ord;
    ord.loadFile(fileName);
    
    cout << "MTFList after Queries: ";
    mtf.print();
    
    cout << "orderedList after Queries: ";
    ord.print();

     
    cout << endl << "MTFList Traversal Count: " << mtf.totalTrans << endl;
    cout << "MTFList time: " << mtf.time << " nanoseconds" << endl;
     
    cout << endl << "orderedList Traversal Count: " << ord.totalTrans << endl;
    cout << "orderedList time: " << ord.time << " nanoseconds" << endl;
    
    if (mtf.time < ord.time) {
        cout << endl << "MTFlist is faster for this data." << endl << endl;
    }
    else {
        cout << endl << "orderedList is faster for this data." << endl << endl;
    }
    
    
    
    
    
    return 0;
}
