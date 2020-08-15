//
//  blockchain.hpp
//  blockchain
//
//  Created by Kyle Scott on 7/1/20.
//  Copyright © 2020 Kyle Scott. All rights reserved.
//
//
//#ifndef blockchain_hpp
//#define blockchain_hpp

#include <stdio.h>
//
//#endif /* blockchain_hpp */

#include <iostream>
using namespace std;

class transaction {
public:
    transaction() : from(0), to(1), amount(12), time(1), condition(0), status(false)  {
        cout << "Creating genesis block" << endl;
    }
        
    transaction(int from, int to, int amount, int time, int condition) : from(from), to(to), amount(amount), time(time), condition(condition), status(false) {}
        
    int hash() {
        return from + to + amount + time;
    }
        
    void print() {
        cout << from << to << amount << time << endl;
    }

    int get_from() {
        return from;
    }

    int get_to() {
        return to;
    }

    int get_amount() {
        return amount;
    }

    int get_condition() {
        return condition;
    }

    bool get_status() {
        return status;
    }

    void set_status(bool status) {
        status = status;
    }
    
private:
    int from;
    int to;
    int amount;
    int time;
    int condition;
    bool status;
};

class block;

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
    block(transaction in, hashpoint prev) : t(in), prev(hashpoint(prev.ptr)) {}
        
    block() : t(transaction()), prev(hashpoint()) {}
    
    //has data and a hashpointer to the previous block
    transaction t;
    hashpoint prev;
};

hashpoint::hashpoint(block* block_ptr) {
    ptr = block_ptr;
    if (block_ptr == nullptr) hash = 0;
    else hash = ptr->t.hash();
}

class Blockchain {
public:
    
   Blockchain() {
        hashpoint next = hashpoint(new block());
        end = next;
            //create a genesis block that contains no data
            //make end point to the genesis block
    }
    
    hashpoint end;
    
    void add_node(transaction in) {
        hashpoint next = hashpoint(new block(in, end));
        end = next;
        validate();
    }
        
    void validate(){
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
        
        
    void print() {
        hashpoint move = end;
        while (move.ptr != nullptr) {
            move.ptr->t.print();
            move = move.ptr->prev;
        }
    }
    
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
