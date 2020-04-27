//
// Created by andrey on 4/27/20.
//

#include <iostream>
#include <vector>
#include "MultithreadingExample.h"
#include "future"
#include "Logger.h"

void MultithreadingExample::run() {
    Logger logger;
    logger.info("start");

    auto f1 = std::async(std::launch::async, [&logger]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        logger.info("1 sec action complete");
    });

    auto f2 = std::async(std::launch::async, [&logger]() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        logger.info("3 sec action complete");
    });

    // 1st option:
    // f1.get();
    // f2.get();

    // 2nd option:
    std::vector<std::future<void>> vector;
    vector.push_back(move(f1));
    vector.push_back(move(f2));

    for (const auto &future : vector) {
        if (future.valid()) {
            future.wait();
        }
    }

    logger.info("end");
}

