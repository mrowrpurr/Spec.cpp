#pragma once

#include <Specs/DSLs.h>  // IWYU pragma: keep
#include <Specs/ExceptionHandlers/CStringExceptionHandler.h>
#include <Specs/ExceptionHandlers/StdExceptionExceptionHandler.h>

#include "DLL/Entrypoint.h"  // IWYU pragma: keep

namespace _Specs_DLL_Configuration {
    inline static auto cStringExceptionHandler =
        SpecsCpp::ExceptionHandlers::CStringExceptionHandler();
    inline static auto stdExceptionExceptionHandler =
        SpecsCpp::ExceptionHandlers::StdExceptionExceptionHandler();
}

Configure(_Specs_DLL_ExceptionHandlers_Config_) {
    if (auto* specsEnv = SpecsCpp::global_spec_environment().get()) {
        specsEnv->local_exception_handlers()->register_exception_handler(
            &_Specs_DLL_Configuration::cStringExceptionHandler
        );
        specsEnv->local_exception_handlers()->register_exception_handler(
            &_Specs_DLL_Configuration::stdExceptionExceptionHandler
        );
    }
}