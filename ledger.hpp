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
    
    void transfer(int from, int to, int amount);
    
    void deposit(int to, int amount);
    
    void withdrawal(int from, int amount);
    
    void create(int num);
    
    void print();
};

#endif /* ledger_hpp */
