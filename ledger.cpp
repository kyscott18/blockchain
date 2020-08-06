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

void Ledger::add_block(int from, int to, int amount, int condition) {
    transaction in(from, to, amount, time, condition);
    ++time;
    
    if (condition == 0) process_payment(&in);
    
    blockchain.add_node(in);
}

void Ledger::process_payment(transaction *t) {
    balances[t->get_from()] -= t->get_amount();
    balances[t->get_to()] += t->get_amount();
    t->set_status(true);
}

void Ledger::write_contract(int from, int to, int amount, int condition) {
    add_block(from, to, amount, condition); 
}

void Ledger::validate_contracts(int condition) {
    Blockchain::Iterator it = blockchain.back();
    while(it != blockchain.front()) {
        if ((*it).get_condition() == condition && !(*it).get_status()) {
            process_payment(&(*it)); 
            (*it).set_status(true);
            
        }
        ++it;
    }
    return;
    //parse the blockchain, if the condition matches and the transaction is unprocessed, process the transaction
}

void Ledger::transfer(int from, int to, int amount) {
    add_block(from, to, amount, 0);
}
    
void Ledger::deposit(int to, int amount) {
    add_block(0, to, amount, 0);
}
    
void Ledger::withdrawal(int from, int amount) {
    add_block(from, 0, amount, 0);
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
