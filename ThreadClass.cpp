//
// Created by Sierra Kilo on 30-Sep-19.
//

#include <iostream>
#include "ThreadClass.h"

ThreadClass::ThreadClass(int limit) {
    std::cout << "Mpika constructor ThreadClass" << std::endl;
    threadClass2 = ThreadClass2();
    localThreadHandler = std::thread(&ThreadClass::count_numbers, this, limit);
    startWorkerThread();

}



void ThreadClass::startWorkerThread() {
    workerThreadHandler = std::thread(&ThreadClass2::worker, &threadClass2);
}

void ThreadClass::count_numbers(int limit) {

    for (int i=0; i<limit; i++) {
        std::cout << "Current number is: " << i << std::endl;
    }

    raise(SIGTERM);
}

ThreadClass::ThreadClass(ThreadClass &&obj) : workerThreadHandler(std::move(obj.workerThreadHandler)) {
    std::cout << "Move Constructor is called" << std::endl;
}

ThreadClass &ThreadClass::operator=(ThreadClass &&obj) {
    std::cout << "Move Assignment is called" << std::endl;
    if (workerThreadHandler.joinable())
        workerThreadHandler.join();
    workerThreadHandler = std::move(obj.workerThreadHandler);

    if (localThreadHandler.joinable())
        localThreadHandler.join();
    localThreadHandler = std::move(obj.localThreadHandler);

    return *this;
}

ThreadClass::~ThreadClass() {
    if (workerThreadHandler.joinable())
        workerThreadHandler.join();

    if (localThreadHandler.joinable())
        localThreadHandler.join();

    std::cout << "After join - inside destructor" << std::endl;
}




