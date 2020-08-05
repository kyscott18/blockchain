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

class transaction {
public:
    transaction();
    
    transaction(int from, int to, int amount, int time);
    
    int hash();
    
    void print();
    
private:
    int from;
    int to;
    int amount;
    int time;
};

class sc {
public:
    sc();
    sc(int from, int to, int amount, int time, int condition);
    int hash();
    void print();
    
private:
    int from;
    int to;
    int amount;
    int time;
    int condition;
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
    block(transaction in, hashpoint prev);
    
    block(sc in, hashpoint prev);
    
    block();
    
    //has data and a hashpointer to the previous block
    transaction t;
    hashpoint prev;
};

class Blockchain {
public:
    
    Blockchain();
    
    hashpoint end;
    
    void add_node(transaction in);
    
    void add_node(sc in);
    
    void validate();
    
    void print();
};

//This blockchain needs a real hashing function, proof of work, public and private keys, digitial signatures, saving ledger in a database, distributing the ledger to be a real functioning blockchain
//I add features intermittenly as I see fit, the main point is to show the applications of blockchain (decentralized gambling, free stock market)
//need a smart contract to save bets 
