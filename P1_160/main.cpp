//
//  main.cpp
//  P1_160
//
//  Created by Joe D'Agostino on 9/5/22.
//

#include <iostream>
#include "LL.h"

int main(int argc, const char * argv[]) {
    
    string fileName;
    if (argv[1] == NULL) {
        cout << "NO FILE PATH PASSED WHEN CALLING EXECUTABLE" << endl;
        cout << "Please enter file path: ";
        cin >> fileName;
        cout << endl;
    }
    else {
        fileName = argv[1];
    }

    
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
