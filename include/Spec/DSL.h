#pragma once

#include <format>
#include <functional>
#include <iostream>
#include <string>

#include "Spec/Macros.h"

namespace Spec {

    void describe(const std::string& groupDescription, std::function<void()> bodyFunction) {
        std::cout << std::format("DESCRIBE: '{}'", groupDescription) << std::endl;
        bodyFunction();
    }

    void it(const std::string& testDescription, std::function<void()>) {
        std::cout << std::format("it test: '{}'", testDescription) << std::endl;
    }

    void test(const std::string& testDescription, std::function<void()>) {
        std::cout << std::format("test: '{}'", testDescription) << std::endl;
    }
}
