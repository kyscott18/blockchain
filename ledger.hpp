//
//  ledger.hpp
//  blockchain
//
//  Created by Kyle Scott on 7/1/20.
//  Copyright © 2020 Kyle Scott. All rights reserved.
//

#ifndef ledger_hpp
#define ledger_hpp

#include <stdio.h>

class ledger {
    void add_block(); 
public:
    void transfer();
    void deposit();
    void withdrawal();
};

#endif /* ledger_hpp */
