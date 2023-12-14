#pragma once

// Before including <global_macro_functions.h>
#if defined(spec_context)
    #define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME spec_context
#elif defined(spec_file)
    #define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME spec_file
#elif defined(spec_name)
    #define _GLOBAL_MACRO_FUNCTIONS_COMPILATION_UNIT_NAME spec_name
#endif

#include <Specs/GlobalSpecFunctionDefinitionBlocks.h>
#include <Specs/GlobalSpecGroup.h>
#include <Specs/SpecDone.h>
#include <global_macro_functions.h>

// (global) Spec Group

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_SPEC_GROUP_BODY(symbol, specGroupDescription, count) \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)();       \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){[](  \
                                                                                              ) {  \
        SpecsCpp::GlobalSpecGroup::instance().register_group_fn(                                   \
            specGroupDescription,                                                                  \
            _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)              \
        );                                                                                         \
    }};                                                                                            \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)()

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_SPEC_GROUP(symbol, specGroupDescription) \
    _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_SPEC_GROUP_BODY(symbol, specGroupDescription, __COUNTER__)

// (global) Spec

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_SPEC_BODY(symbol, specDescription, count)           \
    inline void                                                                                   \
        _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(SpecsCpp::      \
                                                                                      ISpec*);    \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){[]( \
                                                                                              ) { \
        SpecsCpp::GlobalSpecGroup::instance().register_spec_fn(                                   \
            specDescription,                                                                      \
            _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)             \
        );                                                                                        \
    }};                                                                                           \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(        \
        SpecsCpp::ISpec * current_spec                                                            \
    )

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_SPEC(symbol, specDescription) \
    _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_SPEC_BODY(symbol, specDescription, __COUNTER__)

// (global) Async Spec

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_ASYNC_SPEC_BODY(symbol, specDescription, count)     \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(        \
        SpecsCpp::SpecDone                                                                        \
    );                                                                                            \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){[]( \
                                                                                              ) { \
        SpecsCpp::GlobalSpecGroup::instance().register_spec_fn(                                   \
            specDescription,                                                                      \
            _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)             \
        );                                                                                        \
    }};                                                                                           \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(        \
        SpecsCpp::SpecDone done                                                                   \
    )

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_ASYNC_SPEC(symbol, specDescription) \
    _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_ASYNC_SPEC_BODY(symbol, specDescription, __COUNTER__)

// (global) Setup

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_SETUP_BODY(symbol, count)                                                                                \
    inline void                                                                                                                                        \
        _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(SpecsCpp::ISpecGroup*, SpecsCpp::ISpecComponent*, SpecsCpp::ISpec*); \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){[](                                                      \
                                                                                              ) {                                                      \
        SpecsCpp::GlobalSpecGroup::instance().register_setup_fn(                                                                                       \
            _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)                                                                  \
        );                                                                                                                                             \
    }};                                                                                                                                                \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(                                                             \
        SpecsCpp::ISpecGroup * current_group, SpecsCpp::ISpecComponent * current_setup,                                                                \
        SpecsCpp::ISpec * current_spec                                                                                                                 \
    )

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_SETUP(symbol) \
    _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_SETUP_BODY(symbol, __COUNTER__)

// (global) Async Setup

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_ASYNC_SETUP_BODY(symbol, count)                     \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(        \
        SpecsCpp::ISpecGroup*, SpecsCpp::ISpecComponent*, SpecsCpp::ISpec*, SpecsCpp::SpecDone    \
    );                                                                                            \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){[]( \
                                                                                              ) { \
        SpecsCpp::GlobalSpecGroup::instance().register_setup_fn(                                  \
            _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)             \
        );                                                                                        \
    }};                                                                                           \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(        \
        SpecsCpp::ISpecGroup * current_group, SpecsCpp::ISpecComponent * current_setup,           \
        SpecsCpp::ISpec * current_spec, SpecsCpp::SpecDone done                                   \
    )

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_ASYNC_SETUP(symbol) \
    _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_ASYNC_SETUP_BODY(symbol, __COUNTER__)

// (global) Teardown

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_TEARDOWN_BODY(symbol, count)                                                                             \
    inline void                                                                                                                                        \
        _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(SpecsCpp::ISpecGroup*, SpecsCpp::ISpecComponent*, SpecsCpp::ISpec*); \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){[](                                                      \
                                                                                              ) {                                                      \
        SpecsCpp::GlobalSpecGroup::instance().register_teardown_fn(                                                                                    \
            _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)                                                                  \
        );                                                                                                                                             \
    }};                                                                                                                                                \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(                                                             \
        SpecsCpp::ISpecGroup * current_group, SpecsCpp::ISpecComponent * current_teardown,                                                             \
        SpecsCpp::ISpec * current_spec                                                                                                                 \
    )

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_TEARDOWN(symbol) \
    _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_TEARDOWN_BODY(symbol, __COUNTER__)

// (global) Async Teardown

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_ASYNC_TEARDOWN_BODY(symbol, count)                  \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(        \
        SpecsCpp::ISpecGroup*, SpecsCpp::ISpecComponent*, SpecsCpp::ISpec*, SpecsCpp::SpecDone    \
    );                                                                                            \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){[]( \
                                                                                              ) { \
        SpecsCpp::GlobalSpecGroup::instance().register_teardown_fn(                               \
            _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)             \
        );                                                                                        \
    }};                                                                                           \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)(        \
        SpecsCpp::ISpecGroup * current_group, SpecsCpp::ISpecComponent * current_teardown,        \
        SpecsCpp::ISpec * current_spec, SpecsCpp::SpecDone done                                   \
    )

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_ASYNC_TEARDOWN(symbol) \
    _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_ASYNC_TEARDOWN_BODY(symbol, __COUNTER__)

// (global) Misc code blocks { ... }

#define _SPEC_MACRO_FUNCTIONS_REGISTER_GLOBAL_CODE_BLOCK(symbol) \
    _GLOBAL_MACRO_FUNCTIONS_REGISTER_NEW_NAMED_FUNCTION(                         \
        symbol, SpecsCpp::GlobalSpecFunctionDefinitionBlocks::instance().register_code_block \
    )()

// (global) Describe group (top-level with name, no block)

#define _SPEC_MACRO_DEFINE_TOP_LEVEL_GROUP(symbol, description)            \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME(symbol \
    ){[]() { SpecsCpp::GlobalSpecGroup::instance().register_top_level_group(description); }};

// (global) Top-level Template (top-level with name, no block)

#define _SPEC_MACRO_DEFINE_TOP_LEVEL_TEMPLATE(symbol, templateName)        \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME(symbol \
    ){[]() { SpecsCpp::GlobalSpecGroup::instance().register_top_level_template(templateName); }};

// (global) Unset Describe group (top-level with name, no block)

#define _SPEC_MACRO_UNSET_TOP_LEVEL_GROUP(symbol)                          \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME(symbol \
    ){[]() { SpecsCpp::GlobalSpecGroup::instance().clear_top_level_group(); }};

// (global) Define template

#define _SPEC_MACRO_FUNCTIONS_DEFINE_TEMPLATE_BODY(symbol, templateName, count)                   \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)();      \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME_FROM_COUNT(symbol, count){[]( \
                                                                                              ) { \
        SpecsCpp::GlobalSpecGroup::instance().register_template_fn(                               \
            templateName,                                                                         \
            _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)             \
        );                                                                                        \
    }};                                                                                           \
    inline void _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_NAME_FROM_COUNT(symbol, count)()

#define _SPEC_MACRO_FUNCTIONS_DEFINE_TEMPLATE(symbol, templateName) \
    _SPEC_MACRO_FUNCTIONS_DEFINE_TEMPLATE_BODY(symbol, templateName, __COUNTER__)

// (global) Use template

#define _SPEC_MACRO_USE_TEST_TEMPLATE(symbol, templateName)                \
    _GLOBAL_MACRO_FUNCTIONS_NEW_NAMED_FUNCTION_RUNNER_VARIABLE_NAME(symbol \
    ){[]() { SpecsCpp::GlobalSpecGroup::instance().use_template(templateName); }};
