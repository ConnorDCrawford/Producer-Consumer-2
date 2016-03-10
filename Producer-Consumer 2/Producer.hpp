//
//  Producer.hpp
//  Producer-Consumer 2
//
//  Created by Connor Crawford on 3/10/16.
//  Copyright © 2016 Connor Crawford. All rights reserved.
//

#ifndef Producer_hpp
#define Producer_hpp

#include "Constants.h"
#include "Buffer.hpp"
#include "Logger.hpp"

/**
 * Asynchronously produces values and inserts them into a shared Buffer.
 * The Producer will not insert values if the Buffer is full.
 * It will block any Consumers while it inserts data into the Buffer.
 */
class Producer {
    
public:
    
    // Constructor
    Producer(Buffer& buffer, Logger& logger, int threadNo):
    buffer_(buffer),
    logger_(logger),
    threadNo_(threadNo)
    {}
    
    void produce();
    int threadNo() const { return threadNo_; }
    
private:
    Buffer& buffer_; // Reference to shared Buffer object
    Logger& logger_; // Reference to share Logger object
    int threadNo_; // The thread's ID
    
};

#endif /* Producer_hpp */
