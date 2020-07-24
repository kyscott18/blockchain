//
//  blockchain.cpp
//  blockchain
//
//  Created by Kyle Scott on 7/1/20.
//  Copyright © 2020 Kyle Scott. All rights reserved.
//

#include "blockchain.hpp"

#include <iostream>
using namespace std;

entry::entry() : from(0), to(1), amount(12), time(1) {
    cout << "Creating genesis block" << endl;
}
    
entry::entry(int from, int to, int amount, int time) : from(from), to(to), amount(amount), time(time) {}
    
int entry::hash() {
    return from + to + amount + time;
}
    
void entry::print() {
    cout << from << to << amount << time << endl;
}

hashpoint::hashpoint(block* block_ptr) {
    ptr = block_ptr;
    if (block_ptr == nullptr) hash = 0;
    else hash = ptr->data.hash();
}
    
hashpoint::hashpoint() {
    ptr = nullptr;
    hash = -1;
}

block::block(entry in, hashpoint prev) : data(in), prev(hashpoint(prev.ptr)) {}
    
block::block() : data(entry()), prev(hashpoint()) {}


Blockchain::Blockchain() {
    hashpoint next = hashpoint(new block());
    end = next;
        //create a genesis block that contains no data
        //make end point to the genesis block
}
    
void Blockchain::add_node(entry in) {
    hashpoint next = hashpoint(new block(in, end));
    end = next;
    validate(); 
}
    
void Blockchain::validate(){
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
    
    
void Blockchain::print() {
    hashpoint move = end;
    while (move.ptr != nullptr) {
        move.ptr->data.print();
        move = move.ptr->prev;
    }
}
