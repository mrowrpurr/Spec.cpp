#pragma once

#include <any>
#include <unordered_map>

#include "Spec/AsyncSpec.h"
#include "Spec/Types/SpecDiscovery.h"

namespace Specs {

    // TODO: xit() for all variations of it()

    void it(const std::string& description) {
        Spec::Types::SpecDiscovery::GetGlobalInstance().DiscoverTest(description
        );
    }

    void it(
        const std::string&                         description,
        std::function<void(std::function<void()>)> body
    ) {
        Spec::Types::SpecDiscovery::GetGlobalInstance().DiscoverTest(
            description,
            [body](SpecTest& test) { body([&]() { test.Pass(); }); }, true
        );
    }

    void it(
        const std::string& description, std::function<void(SpecTest&)> body
    ) {
        Spec::Types::SpecDiscovery::GetGlobalInstance().DiscoverTest(
            description, body
        );
    }

    void it(
        const std::string& description, std::function<void(AsyncSpec&)> body
    ) {
        Spec::Types::SpecDiscovery::GetGlobalInstance().DiscoverTest(
            description, body
        );
    }

    void it(
        const std::string&                              description,
        std::function<void(std::shared_ptr<AsyncSpec>)> body
    ) {
        Spec::Types::SpecDiscovery::GetGlobalInstance().DiscoverTest(
            description, body
        );
    }

    void it(const std::string& description, std::function<void()> body) {
        Spec::Types::SpecDiscovery::GetGlobalInstance().DiscoverTest(
            description, body
        );
    }

    void it(
        const std::string& description,
        std::unordered_map<std::string, std::any>, std::function<void()> body
    ) {
        Spec::Types::SpecDiscovery::GetGlobalInstance().DiscoverTest(
            description, body
        );
    }
}