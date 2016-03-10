//
//  Logger.cpp
//  Producer-Consumer 2
//
//  Created by Connor Crawford on 3/10/16.
//  Copyright © 2016 Connor Crawford. All rights reserved.
//

#include "Logger.hpp"

// Logger function definitions

void Logger::logThreadCreate(int threadNo, bool isProducer) {
    std::lock_guard<std::mutex> lock(mutex_); // Lock, lock_guard will automatically unlock when out of scope
    std::cout << "Creating " << (isProducer ? "Producer " : "Consumer ") << "thread " << threadNo << "\n";
}

void Logger::logThreadJoin(int threadNo, bool isProducer) {
    std::lock_guard<std::mutex> lock(mutex_); // Lock, lock_guard will automatically unlock when out of scope
    std::cout << "Joining " << (isProducer ? "Producer " : "Consumer ") << "thread " << threadNo << "\n";
}

void Logger::logValue(int value, int threadNo, bool isProducer) {
    auto elapsed = getElapsedTime();
    std::lock_guard<std::mutex> lock(mutex_); // Lock, lock_guard will automatically unlock when out of scope
    if (value == TIMEOUT) std::cout << "\nConsumer thread no: " << threadNo << " Timeout\nTimestamp: " << elapsed << "\n";
    else std::cout << (isProducer ? "\nProducer " : "\nConsumer ") << "thread no:" << threadNo << " Value: " << value << "\nTimestamp: " << elapsed << "\n";
}

long long Logger::getElapsedTime() {
    auto elapsed = std::chrono::high_resolution_clock::now() - startTime_;
    return std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
}

// End Logger