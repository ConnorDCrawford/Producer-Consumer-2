//
//  main.cpp
//  Producer-Consumer 2
//
//  Created by Connor Crawford on 3/7/16.
//  Copyright © 2016 Connor Crawford. All rights reserved.
//

#include "Constants.h"
#include "Buffer.hpp"
#include "Logger.hpp"
#include "Producer.hpp"
#include "Consumer.hpp"

// Main
int main(int argc, const char * argv[]) {
    auto const startTime = std::chrono::high_resolution_clock::now(); // Get the program launch time
    
    std::thread producerThreads[NUM_P_THREADS];
    std::thread consumerThreads[NUM_C_THREADS];
    
    Buffer buffer;
    Logger logger(startTime);
    int threadNo = 2;
    std::vector<Producer> producers;
    std::vector<Consumer> consumers;
    for (int i = 0; i < NUM_P_THREADS; i++) {
        producers.push_back(Producer(buffer, logger, threadNo++));
    }
    for (int i = 0; i < NUM_C_THREADS; i++) {
        consumers.push_back(Consumer(buffer, logger, threadNo++));
    }
    
    // Create threads
    for (int i = 0; i < NUM_P_THREADS; i++) {
        producerThreads[i] = std::thread(&Producer::produce, &producers[i]);
        logger.logThreadCreate(producers[i].threadNo(), true);
    }
    for (int i = 0; i < NUM_C_THREADS; i++) {
        consumerThreads[i] = std::thread(&Consumer::consume, &consumers[i]);
        logger.logThreadCreate(consumers[i].threadNo(), false);
    }
    
    // Join threads
    for (int i = 0; i < NUM_P_THREADS; i++) {
        logger.logThreadJoin(i, true);
        producerThreads[i].join();
    }
    for (int i = 0; i < NUM_C_THREADS; i++) {
        logger.logThreadJoin(i, false);
        consumerThreads[i].join();
    }
    
    return 0;
}

// End Main