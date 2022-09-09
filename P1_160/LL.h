//
//  LL.h
//  P1_160
//
//  Created by Joe D'Agostino on 9/5/22.
//

#ifndef LL_h
#define LL_h

using namespace std;

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Node.h"


//Declaration of MTFList
class MTFlist {
public:
    MTFlist();
    virtual ~MTFlist();
    
    int getSize() const { return size; }
    
    void loadFile(std::string fileName);
    
    void add(int val);
    
    int search(int val);
    
    void print() const;
    
    int totalTrans;
    int time;
    
private:
    Node* header;
    Node* trailer;
    Node* current;
    int size;
}; //END MTFList Declaration



//Declaration of orderedList
class orderedList {
public:
    orderedList();
    virtual ~orderedList();
    
    int getSize() const { return size; }
    
    void loadFile(std::string fileName);
    
    void add(int val);
    
    int search(int val);
    
    void print() const;
    
    int totalTrans;
    int time;
    
private:
    Node* header;
    Node* trailer;
    Node* current;
    int size;
 
}; //END orderedList Declaration

class orderedArray {
public:
    //Creates an array with the size specified in the first line of the file
    orderedArray();
    
    //Uses an instance of fstream to read file data and fill the array
    void loadFile(string fileName);
    
    //Call the existing array::end member function and fills the open index
    void add(int ndx, int val);
    
    //Iterates through array, returns index of the found element (returns size of list if not found)
    int search(int val);
    
    //Iterates through array, prints each element
    void print();
    
    int totalTrans;
    int time;
    int size;
    int *arr;
    
}; //END orderedArray Declaration



#endif /* LL_h */
