//
//  LL.cpp
//  P1_160
//
//  Created by Joe D'Agostino on 9/5/22.
//

#include <stdio.h>
#include "LL.h"
#include <chrono>


//BEGIN MTFlist Default constructor, creates header, trailer, and sets size = 0
MTFlist::MTFlist()
{
    header = new Node;
    trailer = new Node;
    
    header->next = trailer;
    trailer->next = trailer;
    
    current = header;
    
    size = 0;
    totalTrans = 0;
}

//BEGIN MTFlist default destructor
MTFlist::~MTFlist()
{
    cout << "MTFlist::~MTFlist() Entering destructor for class MTFlist\n";
    
    unsigned currentI = 0;
    Node *thisNode = header->next;
    //loops through the list, deleting each node
    while (currentI < getSize())
    {
        Node *next = thisNode->next;
        delete thisNode;
        thisNode = next;
        currentI += 1;
        
    }
    size = 0;
    cout << "MTFlist::~MTFlist() Exiting destructor for class MTFlist\n";
}

//BEGIN MTFlist loadFile() function definitions
void MTFlist::loadFile(string fileName)
{
    std::string errLoadData = "ERROR: in MTFlist class LoadFile operator<<\n";
    errLoadData += "the output stream is in a failed state, no processing can take place...\n";
    
    ifstream inFile;
    inFile.open(fileName.c_str());
    
    if (!inFile)
    {
        // file failed to open, cannot do any processing
        throw std::invalid_argument(errLoadData);
        
    } // END if (!inFile)
    
    string getNumAdds;
    getline(inFile, getNumAdds);
    int numAdds = stoi(getNumAdds);
    
    char delim = ' ';
    string thisStr;
    int thisAdd = 0;
    while (thisAdd < numAdds)
    {
        getline(inFile, thisStr, delim);
        int thisInt = stoi(thisStr);
        add(thisInt);
        thisAdd += 1;
    }
    size = numAdds;
    
    string strNumQ;
    getline(inFile, strNumQ);
    getline(inFile, strNumQ);
    int numQ = stoi(strNumQ);
    
    int i = 0;
    string strThisQ;
    
    auto start = chrono::steady_clock::now();
    while (i < numQ)
    {
        getline(inFile, strThisQ, delim);
        int thisQ = stoi(strThisQ);
        int searchCount = search(thisQ);
        totalTrans += searchCount;
        i += 1;
    }
    auto end = chrono::steady_clock::now();
    
    time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    
}

//BEGIN MTFlist add() function definition
void MTFlist::add(int val)
{
    Node *newNode = new Node();

    newNode->info = val;
    newNode->next = trailer;
    
    current->next = newNode;
    current = newNode;
    
    size = size + 1;
}

//BEGIN MTFlist search() function definition
int MTFlist::search(int val)
{

    Node *tmp = new Node;
    tmp = header->next;
    
    for (unsigned i = 1; i < size; i++)
    {
        if (tmp->next->info == val)
        {
            Node *found = tmp->next;
            tmp->next = found->next;
            
            found->next = header->next;
            header->next = found;
            return i;
        }
        tmp = tmp->next;
    }
    return 0;
}

//BEGIN MTFlist print() function definition
void MTFlist::print() const
{
    if (header->next == trailer) {
        cout << "List is empty, nothing to display." << endl << endl;
        return;
    }
    Node *tmp = new Node;
    tmp = header->next;
    while(tmp != trailer)
    {
        cout << tmp->info << "  ";
        tmp = tmp->next;
    }
    cout << endl;
}


//#############################################################################################
//#############################################################################################


//BEGIN OrderedList default constructor, creates header, trailer, and sets size = 0
orderedList::orderedList()
{
    header = new Node;
    trailer = new Node;
    
    header->next = trailer;
    trailer->next = trailer;
    
    current = header;
    
    size = 0;
    totalTrans = 0;
}

//BEGIN OrderedList default destructor
orderedList::~orderedList()
{
    cout << "orderedList::~orderedList() Entering destructor for class orderedList\n";
    
    unsigned currentI = 0;
    Node *thisNode = header->next;
    //loops through the list, deleting each node
    while (currentI < getSize())
    {
        Node *next = thisNode->next;
        delete thisNode;
        thisNode = next;
        currentI += 1;
    }
    size = 0;
    cout << "orderedList::~orderedList() Exiting destructor for class orderedList\n";
}

//BEGIN orderedList loadFile() function definition
void orderedList::loadFile(string fileName)
{
    std::string errLoadData = "ERROR: in orderedList class LoadFile operator<<\n";
    errLoadData += "the output stream is in a failed state, no processing can take place...\n";
    
    ifstream inFile;
    inFile.open(fileName.c_str());
    
    if (!inFile)
    {
        // file failed to open, cannot do any processing
        throw std::invalid_argument(errLoadData);
        
    } // END if (!inFile)

    string getNumAdds;
    getline(inFile, getNumAdds);
    int numAdds = stoi(getNumAdds);
    
    char delim = ' ';
    string thisStr;
    int thisAdd = 0;
    while (thisAdd < numAdds)
    {
        getline(inFile, thisStr, delim);
        int thisInt = stoi(thisStr);
        add(thisInt);
        thisAdd += 1;
    }
    size = numAdds;
    
    string strNumQ;
    getline(inFile, strNumQ);
    getline(inFile, strNumQ);
    int numQ = stoi(strNumQ);
    
    int i = 0;
    string strThisQ;
    
    auto start = chrono::steady_clock::now();
    while (i < numQ)
    {
        getline(inFile, strThisQ, delim);
        int thisQ = stoi(strThisQ);
        int searchCount = search(thisQ);
        totalTrans += searchCount;
        cout << totalTrans << endl;
        i += 1;
    }
    auto end = chrono::steady_clock::now();
    
    time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

//BEGIN orderedList add() function definition
void orderedList::add(int val)
{
    Node *newNode = new Node();

    newNode->info = val;
    newNode->next = trailer;
    
    current->next = newNode;
    current = newNode;
}

//BEGIN orderedList search() function definition
int orderedList::search(int val)
{

    Node *tmp = new Node;
    tmp = header->next;
    
    for (int i = 1; i < size; i++)
    {
        if (tmp->info == val)
        {
            return i;
        }
        tmp = tmp->next;
    }
    return size;
}

//BEGIN orderedList print() function definition
void orderedList::print() const
{
    if (header->next == trailer) {
        cout << "List is empty, nothing to display." << endl << endl;
        return;
    }
    Node *tmp = new Node;
    tmp = header->next;
    while(tmp != trailer)
    {
        cout << tmp->info << "  ";
        tmp = tmp->next;
    }
    cout << endl;
}
