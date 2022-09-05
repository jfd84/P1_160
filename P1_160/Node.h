//
//  Node.h
//  P1_160
//
//  Created by Joe D'Agostino on 9/5/22.
//

#ifndef Node_h
#define Node_h

class Node {
public:
    Node();
    
    Node* getNext();
    Node* getPrev();
    int getInfo();
    
    
    void setInfo(int val);
    
    Node* next;
    Node* prev;
    int info;
    
};

#endif /* Node_h */
