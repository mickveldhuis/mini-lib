include(CTest)
include(Catch)

# Define test sources
set(TESTS
    tthreadpool
    targumentparser
)

foreach(target ${TESTS})
    add_executable(${target} "${target}.cpp")
    target_link_libraries(${target} PRIVATE mini-lib Catch2::Catch2WithMain)

    catch_discover_tests(${target})
endforeach()
