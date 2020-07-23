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
    entry() : from(0), to(1), amount(12), time(1) {}
    
    entry(int from, int to, int amount, int time) : from(from), to(to), amount(amount), time(time) {}
    
    int hash() {
        return from + to + amount + time;
    }
    
    void print() {
        cout << from << to << amount << time << endl;
    }
    
private:
    int from;
    int to;
    int amount;
    int time;
};

class hashpoint {
public:
    hashpoint(block* block_ptr);
    
    hashpoint() {
        ptr = nullptr;
        hash = -1;
    }
    
    //has a pointer to the last block and a hash of its data
    block* ptr;
    int hash;
};

class block {
public:
    block(entry in, hashpoint prev) : data(in), prev(hashpoint(prev.ptr)) {}
    
    block() : data(entry()), prev(hashpoint()) {
        cout << "Genesis Block Created" << endl;
    }
    
    //TODO: make this a function of the type of data, block.data.hash
    //has data and a hashpointer to the previous block
    entry data;
    hashpoint prev;
};

class blockchain {
public:
    
    blockchain() {
        hashpoint next = hashpoint(new block());
        end = next;
        //create a genesis block that contains no data
        //make end point to the genesis block
    }
    
    hashpoint end;
    
    void add_node(entry in) {
        hashpoint next = hashpoint(new block(in, end));
        end = next;
    }
    
    void validate(){
        hashpoint move = end;
        while (move.ptr != nullptr) {
            if (move.hash != move.ptr->data.hash()) {
                cout << "not valid" << endl;
                return;
            }
            move = move.ptr->prev;
        }
        cout << "valid" << endl;
    }
    
    
    void print() {
        hashpoint move = end;
        while (move.ptr != nullptr) {
            move.ptr->data.print();
            move = move.ptr->prev;
        }
    }
    
};

hashpoint::hashpoint(block* block_ptr) {
    ptr = block_ptr;
    if (block_ptr == nullptr) hash = 0;
    else hash = ptr->data.hash();
}


//each templated type needs a hash function and a genesis block creator
