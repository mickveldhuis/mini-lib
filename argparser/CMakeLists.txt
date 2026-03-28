add_executable(testargparser test.cpp argumentparser.cpp)
target_link_libraries(testargparser PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(testargparser)
