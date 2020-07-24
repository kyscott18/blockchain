//
//  ledger.cpp
//  blockchain
//
//  Created by Kyle Scott on 7/1/20.
//  Copyright © 2020 Kyle Scott. All rights reserved.
//

#include "ledger.hpp"


int main(int argc, char** argv) {
    Ledger ledger;
    //initialize users
    ledger.create(0);
    ledger.create(1);
    ledger.create(1);
    ledger.create(109);
    //deposit money into users accounts
    ledger.deposit(1, 10);
    ledger.deposit(109, 20);
    //transfer money between users
    ledger.transfer(1, 109, 3);
    //withdrawal money from users accounts
    ledger.withdrawal(109, 7);
    //print the remaining balances
    ledger.print(); 
}
