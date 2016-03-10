//
//  Buffer.cpp
//  Producer-Consumer 2
//
//  Created by Connor Crawford on 3/10/16.
//  Copyright © 2016 Connor Crawford. All rights reserved.
//

#include "Buffer.hpp"

// Buffer function definitions

void Buffer::put(int value) {
    
    while (true) { // Repeat until able to enter critical section
        std::unique_lock<std::mutex> lock(mutex_);
        conditionVar_.wait(lock, [this](){return buffer_.size() < size_;}); // Block until the buffer is not in use and not full
        
        // Enter critical section
        buffer_.push(value); // Push value into the queue
        lock.unlock();
        conditionVar_.notify_one(); // Unblock next thread waiting for use of buffer
        // Leave critical section
        
        return;
    }
    
}

int Buffer::get() {
    
    while (true) { // Repeat until able to enter critical section
        std::unique_lock<std::mutex> lock(mutex_);
        //        conditionVar_.wait(lock, [this](){return buffer_.size() > 0;}); // Wait until buffer is not empty
        
        // Buffer should timeout after .1 seconds, because production has most likely stopped
        if (conditionVar_.wait_for(lock, std::chrono::milliseconds(100), [this](){return !buffer_.empty();})) {
            // Enter critical section
            int readValue = buffer_.front(); // Get the oldest value in queue
            buffer_.pop(); // Remove value from queue
            lock.unlock();
            conditionVar_.notify_one(); // Unblock next thread waiting for use of buffer
            // Leave critical section
            return readValue;
        } else {
            // Timeout
            return TIMEOUT;
        }
        
    }
    
    return 0;
}

unsigned long Buffer::size() {
    return buffer_.size();
}

// End Buffer