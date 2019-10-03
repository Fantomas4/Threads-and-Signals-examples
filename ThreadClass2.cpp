//
// Created by Sierra Kilo on 30-Sep-19.
//

#include <iostream>
#include "ThreadClass2.h"

void ThreadClass2::worker() {

    for (int i=0; i<200; i++) {
        std::cout << "*** Thread 2 Worker spamming! ***" << std::endl;
    }

}
