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



int main(int argc, const char * argv[]) {
    //template the blockchain class with the entry type so that the entry can be interchanged as long as it has a hash function
    blockchain block;
    entry one(1, 2, 3, 4);
    entry two(2, 1, 3, 5); 
    block.add_node(one);
    block.add_node(two);
    block.add_node(one);
    block.validate();
    block.print();
    block.validate();
    return 0;
}
