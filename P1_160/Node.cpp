//
//  Node.cpp
//  P1_160
//
//  Created by Joe D'Agostino on 9/5/22.
//

#include <stdio.h>
#include "Node.h"

Node::Node()
{
    info = 0;
    next = NULL;
    prev = NULL;
}



Node* Node::getNext(){
    return next;
}
Node* Node::getPrev(){
    return prev;
}

int Node::getInfo(){
    return info;
}

void Node::setInfo(int val){
    info = val;
}
