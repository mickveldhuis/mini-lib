add_executable(testthreadpool test.cpp threadpool.cpp)
target_link_libraries(testthreadpool PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(testthreadpool)
