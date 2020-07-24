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
    
    void add_block(int from, int to, int amount) {
        entry in(from, to, amount, time);
        ++time;
        blockchain.add_node(in);
        
        //Update the balance sheet
        balances[from] -= amount;
        balances[to] += amount;
    }
    
public:
    
    void transfer(int from, int to, int amount) {
        add_block(from, to, amount);
    }
    
    void deposit(int to, int amount) {
        add_block(0, to, amount);
    }
    
    void withdrawal(int from, int amount) {
        add_block(from, 0, amount);
    }
    
    void create(int num) {
        //if num is taken, print error and return
        auto hold = balances.find(num);
        if (hold != balances.end())
            cout << "num already in use" << endl;
        else balances[num] = 0;
    }
    
    void print() {
        for (auto x:balances) {
            cout << x.first << " " << x.second << endl;
        }
    }
};

//take the public key and hash it to get the index into the central ledger
//in a real blockchain the central ledger is distrubuted among all the nodes but I cannot do this in this case

#endif /* ledger_hpp */
