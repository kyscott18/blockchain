//
//  ledger.hpp
//  blockchain
//
//  Created by Kyle Scott on 7/1/20.
//  Copyright © 2020 Kyle Scott. All rights reserved.
//

#ifndef ledger_hpp
#define ledger_hpp

#include "blockchain.hpp"
#include <unordered_map>

#include <stdio.h>



class Ledger {
    int time = 1;
    Blockchain blockchain;
    unordered_map<int, int> balances;
    
    void add_block(int from, int to, int amount);
    
public:
    
    void write_contract(int from, int to, int amount, int condition);
    
    void validate_contracts(int condition); 
    
    void transfer(int from, int to, int amount);
    
    void deposit(int to, int amount);
    
    void withdrawal(int from, int amount);
    
    void create(int num);
    
    void print();
};

// to add a smart contract, create a new type that can be added on the blockchain
//when an event is published, go through all the blocks and check if the result validates a smart contract
//if a contract is valid, add the transaction onto the blockchain as a transaction

#endif /* ledger_hpp */
