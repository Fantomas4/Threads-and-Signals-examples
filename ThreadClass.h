//
// Created by Sierra Kilo on 30-Sep-19.
//

#ifndef SIGNALS_TEST_THREADCLASS_H
#define SIGNALS_TEST_THREADCLASS_H


#include <thread>
#include <functional>
#include "ThreadClass2.h"

class ThreadClass {

private:

    ThreadClass2 threadClass2;

    void startWorkerThread();

    std::thread localThreadHandler;

    std::thread workerThreadHandler;

public:

    ThreadClass(int limit);

    void count_numbers(int limit);

    //Delete the copy constructor
    ThreadClass(const ThreadClass&) = delete;

    //Delete the Assignment operator
    ThreadClass& operator=(const ThreadClass&) = delete;

    // Move Constructor
    ThreadClass(ThreadClass && obj);

    //Move Assignment Operator
    ThreadClass & operator=(ThreadClass && obj);

    //Destructor
    ~ThreadClass();

};


#endif //SIGNALS_TEST_THREADCLASS_H
