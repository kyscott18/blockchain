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

class transaction {
public:
    transaction();
    
    transaction(int from, int to, int amount, int time, int condition);
    
    int hash();
    
    void print();
    
    int get_from();

    int get_to();
    
    int get_amount();
    
    int get_time();
    
    int get_condition(); 
    
    bool get_status();
    
    void set_status(bool status);
    
private:
    int from;
    int to;
    int amount;
    int time;
    int condition;
    bool status = false;
};

class block;

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
    
    void validate();
    
    void print();
    
    class Iterator {
    public:
        Iterator() : block_ptr(nullptr) {}
        
        Iterator& operator++() {
            block_ptr = block_ptr->prev.ptr;
            return *this;
        }
        
        bool operator !=(const Iterator &rhs) const {
            return block_ptr != rhs.block_ptr;
        }
        
        transaction & operator*() {
            return block_ptr->t;
        }
        
    private:
        Iterator(hashpoint h) {
            block_ptr = h.ptr;
        }
        
        block* block_ptr;
        friend class Blockchain;
    };
    
    Iterator back() const {
        return Iterator(end);
    }
    
    Iterator front() const {
        return Iterator();
    }
};


//This blockchain needs a real hashing function, proof of work, public and private keys, digitial signatures, saving ledger in a database, distributing the ledger to be a real functioning blockchain
//I add features intermittenly as I see fit, the main point is to show the applications of blockchain (decentralized gambling, free stock market)
//need a smart contract to save bets 
