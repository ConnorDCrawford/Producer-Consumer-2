//
//  Producer.cpp
//  Producer-Consumer 2
//
//  Created by Connor Crawford on 3/10/16.
//  Copyright © 2016 Connor Crawford. All rights reserved.
//

#include "Producer.hpp"

// Producer function definitions

void Producer::produce() {
    
    // Generate a random number between [0, 1000]
//    std::default_random_engine generator;
    std::random_device rd;
    std::mt19937 generator(rd()); // Cannot use default engine because time differential between calls is too small, generating the same numbers
    std::uniform_int_distribution<int> distribution(0,1000);
    
    while (logger_.getElapsedTime() < RUNTIME) {
        int value = distribution(generator);
        buffer_.put(value);
        logger_.logValue(value, threadNo_, true);
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // sleep for 10 milliseconds so log isn't too crazy
    }
}
// End Producer