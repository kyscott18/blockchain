//
//  ledger.cpp
//  blockchain
//
//  Created by Kyle Scott on 7/1/20.
//  Copyright © 2020 Kyle Scott. All rights reserved.
//

#include "ledger.hpp"
#include <unordered_map>

#include <stdio.h>

void Ledger::add_block(int from, int to, int amount) {
    entry in(from, to, amount, time);
    ++time;
    blockchain.add_node(in);
    
    //Update the balance sheet
    balances[from] -= amount;
    balances[to] += amount;
}

void Ledger::transfer(int from, int to, int amount) {
    add_block(from, to, amount);
}
    
void Ledger::deposit(int to, int amount) {
    add_block(0, to, amount);
}
    
void Ledger::withdrawal(int from, int amount) {
    add_block(from, 0, amount);
}
    
void Ledger::create(int num) {
    //if num is taken, print error and return
    auto hold = balances.find(num);
    if (hold != balances.end())
        cout << "num already in use" << endl;
    else balances[num] = 0;
}
    
void Ledger::print() {
    for (auto x:balances) {
        cout << x.first << " " << x.second << endl;
    }
}
