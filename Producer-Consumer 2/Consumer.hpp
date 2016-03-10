//
//  Consumer.hpp
//  Producer-Consumer 2
//
//  Created by Connor Crawford on 3/10/16.
//  Copyright © 2016 Connor Crawford. All rights reserved.
//

#ifndef Consumer_hpp
#define Consumer_hpp

#include "Constants.h"
#include "Buffer.hpp"
#include "Logger.hpp"

/**
 * Asynchronously reads and processes values from a shared Buffer.
 * The Consumer will not read values if the Buffer is empty.
 * It will block any Producers while it reads data from the Buffer.
 */
class Consumer {
    
public:
    // Constructor
    Consumer(Buffer& buffer, Logger& logger, int threadNo):
    buffer_(buffer),
    logger_(logger),
    threadNo_(threadNo)
    {}
    
    void consume();
    int threadNo() const { return threadNo_; }
    
private:
    Buffer& buffer_; // Reference to shared Buffer object
    Logger& logger_; // Reference to share Logger object
    int threadNo_; // The thread's ID
    
};

#endif /* Consumer_hpp */
