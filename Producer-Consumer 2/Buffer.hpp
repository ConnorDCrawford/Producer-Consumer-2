//
//  Buffer.hpp
//  Producer-Consumer 2
//
//  Created by Connor Crawford on 3/10/16.
//  Copyright © 2016 Connor Crawford. All rights reserved.
//

#ifndef Buffer_hpp
#define Buffer_hpp

#include "Constants.h"

/**
 * A shared FIFO buffer that a producer write into and a consumer reads from.
 */
class Buffer {
    
public:
    void put(int value);
    int get(void);
    unsigned long size();
    
private:
    std::mutex mutex_;
    std::condition_variable conditionVar_;
    std::queue<int> buffer_;
    const int size_ = 128;
};

#endif /* Buffer_hpp */
