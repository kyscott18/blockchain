//
//  blockchain.hpp
//  blockchain
//
//  Created by Kyle Scott on 7/1/20.
//  Copyright © 2020 Kyle Scott. All rights reserved.
//

#ifndef blockchain_hpp
#define blockchain_hpp

#include <stdio.h>

#endif /* blockchain_hpp */

#include <iostream>
using namespace std;
class block;

class entry {
public:
    entry();
    
    entry(int from, int to, int amount, int time);
    
    int hash();
    
    void print();
    
private:
    int from;
    int to;
    int amount;
    int time;
};

class hashpoint {
public:
    hashpoint(block* block_ptr);
    
    hashpoint();
    
    //has a pointer to the last block and a hash of its data
    block* ptr;
    int hash;
};

class block {
public:
    block(entry in, hashpoint prev);
    
    block();
    
    //has data and a hashpointer to the previous block
    entry data;
    hashpoint prev;
};

class Blockchain {
public:
    
    Blockchain();
    
    hashpoint end;
    
    void add_node(entry in);
    
    void validate();
    
    void print();
};
