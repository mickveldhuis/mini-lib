add_executable(testthreadpool test.cpp threadpool.cpp)
target_link_libraries(testthreadpool PRIVATE Catch2::Catch2WithMain)

# The following two lines are includes such that VS Code intellisense properly picks up Catch2!

include(Catch)
catch_discover_tests(testthreadpool)
