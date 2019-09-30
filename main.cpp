#include <iostream>
#include <csignal>
#include <thread>
#include "ThreadClass.h"

void signal_handler(int signal) {
    std::cout << "Signal handler activated" << std::endl;
}

int main() {
    int limit = 4000;

    std::signal(SIGTERM, signal_handler);

    ThreadClass threadClass = ThreadClass(limit);

    std::cout<< "Program initialized" << std::endl;

    return 0;
}