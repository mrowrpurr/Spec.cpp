#pragma once

namespace Specs {

    //! Interface for reporters of test suite results (SpecTestCaseResult and SpecTestGroupResult).
    class ISpecReporter {
    public:
        // virtual BeginTestCase(std::shared_ptr<SpecTestCaseRun> testCaseRun) = 0;
    };
}
