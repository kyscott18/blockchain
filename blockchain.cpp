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

transaction::transaction() : from(0), to(1), amount(12), time(1), condition(0), status(false)  {
    cout << "Creating genesis block" << endl;
}
    
transaction::transaction(int from, int to, int amount, int time, int condition) : from(from), to(to), amount(amount), time(time), condition(condition) {}
    
int transaction::hash() {
    return from + to + amount + time;
}
    
void transaction::print() {
    cout << from << to << amount << time << endl;
}

int transaction::get_from() {
    return from;
}

int transaction::get_to() {
    return to;
}

int transaction::get_amount() {
    return amount;
}

int transaction::get_condition() {
    return condition; 
}

bool transaction::get_status() {
    return status;
}

void transaction::set_status(bool status) {
    status = status;
}

hashpoint::hashpoint(block* block_ptr) {
    ptr = block_ptr;
    if (block_ptr == nullptr) hash = 0;
    else hash = ptr->t.hash();
}
    
hashpoint::hashpoint() {
    ptr = nullptr;
    hash = -1;
}

block::block(transaction in, hashpoint prev) : t(in), prev(hashpoint(prev.ptr)) {}
    
block::block() : t(transaction()), prev(hashpoint()) {}


Blockchain::Blockchain() {
    hashpoint next = hashpoint(new block());
    end = next;
        //create a genesis block that contains no data
        //make end point to the genesis block
}
    
void Blockchain::add_node(transaction in) {
    hashpoint next = hashpoint(new block(in, end));
    end = next;
    validate(); 
}
    
void Blockchain::validate(){
    hashpoint move = end;
    while (move.ptr != nullptr) {
        if (move.hash != move.ptr->t.hash()) {
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
        move.ptr->t.print();
        move = move.ptr->prev;
    }
}
