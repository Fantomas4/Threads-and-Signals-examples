//
// Created by Sierra Kilo on 30-Sep-19.
//

#include <iostream>
#include "ThreadClass.h"

ThreadClass::ThreadClass(int limit) {
    std::cout << "Mpika constructor ThreadClass" << std::endl;
    threadClass2 = ThreadClass2();
    count_numbers(limit);

}

void ThreadClass::startWorkerThread() {
    threadHandler = std::thread(&ThreadClass2::worker, threadClass2);
}

void ThreadClass::count_numbers(int limit) {
    startWorkerThread();
    for (int i=0; i<limit; i++) {
        std::cout << "Current number is: " << i << std::endl;
    }

    raise(SIGTERM);
}

ThreadClass::ThreadClass(ThreadClass &&obj) : threadHandler(std::move(obj.threadHandler)) {
    std::cout << "Move Constructor is called" << std::endl;
}

ThreadClass &ThreadClass::operator=(ThreadClass &&obj) {
    std::cout << "Move Assignment is called" << std::endl;
    if (threadHandler.joinable())
        threadHandler.join();
    threadHandler = std::move(obj.threadHandler);
    return *this;
}

ThreadClass::~ThreadClass() {
    if (threadHandler.joinable())
        threadHandler.join();
    std::cout << "After join - inside destructor" << std::endl;
}



