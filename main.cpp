#include <iostream>
#include <csignal>
#include <thread>
#include "ThreadClass.h"

void signal_handler(int signal) {
    std::cout << "Signal handler activated" << std::endl;
}

int main() {
    int limit = 100;

    std::signal(SIGTERM, signal_handler);

    std::cout<< "Program initialized" << std::endl;

    ThreadClass threadClass = ThreadClass(limit);

    std::cout<< "Returned from ThreadClass in main..." << std::endl;




    return 0;
}