//
//  Logger.hpp
//  Producer-Consumer 2
//
//  Created by Connor Crawford on 3/10/16.
//  Copyright © 2016 Connor Crawford. All rights reserved.
//

#ifndef Logger_hpp
#define Logger_hpp

#include "Constants.h"

/**
 * Logs values as they are inserted and removed from the buffer,
 * along with the elapsed time (in nanoseconds) from launch that the event occurred.
 */
class Logger {
    
public:
    //Constructor
    Logger(std::chrono::high_resolution_clock::time_point startTime):
    startTime_(startTime)
    {}
    
    void logThreadCreate(int threadNo, bool isProducer);
    void logThreadJoin(int threadNo, bool isProducer);
    void logValue(int value, int threadNo, bool isProducer);
    long long getElapsedTime();
    
private:
    std::mutex mutex_; // Mutex for writing to the log (cannot have multiple threads writing at same time)
    std::chrono::high_resolution_clock::time_point startTime_; // Program start time
    
};

#endif /* Logger_hpp */
