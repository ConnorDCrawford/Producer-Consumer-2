//
//  Consumer.cpp
//  Producer-Consumer 2
//
//  Created by Connor Crawford on 3/10/16.
//  Copyright © 2016 Connor Crawford. All rights reserved.
//

#include "Consumer.hpp"

// Consumer function definition

void Consumer::consume() {
    
    while (logger_.getElapsedTime() < RUNTIME || buffer_.size() != 0) {
        int value = buffer_.get();
        logger_.logValue(value, threadNo_, false);
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // sleep for 10 milliseconds so log isn't too crazy
    }
    
}

// End Consumer