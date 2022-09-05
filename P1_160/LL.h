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
    
    int getCount() const { return count; }
    
    void loadFile(std::string fileName);
    
    void add(int val);
    
    int search(int val);
    
    void print() const;
    
    int totalTrans;
    int time;
    
private:
    Node* header;
    Node* trailer;
    int count;
}; //END MTFList Declaration



//Declaration of orderedList
class orderedList {
public:
    orderedList();
    virtual ~orderedList();
    
    int getCount() const { return count; }
    
    void loadFile(std::string fileName);
    
    void add(int val);
    
    int search(int val);
    
    void print() const;
    
    int totalTrans;
    int time;
    
private:
    Node* header;
    Node* trailer;
    int count;
 
}; //END orderedList Declaration



#endif /* LL_h */
