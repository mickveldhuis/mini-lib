#include <cstdint>
#include <string>
#include <print>

#include <catch2/catch_test_macros.hpp>
#include <string_view>
#include <utility>
#include <vector>
#include <iostream>
#include <typeinfo>

#include "argumentparser.hpp"

namespace {
    enum class ArgumentType {
        OptionValuePair,
        Boolean,
        Positional
    };

    void consume_arguments(std::string_view arguments, std::vector<ArgumentType> specification) {
        std::size_t position = 0;
        while (position <= arguments.size()) {
            // std::println("current = {} / position = {}", arguments[position], position);
            if (arguments[position] == '-' && arguments[position + 1] == '-') {
                const std::size_t start = position + 2;
                const std::size_t end = arguments.find(' ', position);
                const std::size_t length = end - start;

                std::string_view argument = arguments.substr(start, length);
                std::println("found arg: {} ({}; {})", argument, length, position);

                position = end;
            } else if (arguments[position] == ' ') {
                ++position;
            } else {
                const std::size_t end = arguments.find(' ', position);
                const std::size_t length = end != arguments.npos ? end - position : arguments.size() - position + 1;

                std::string_view value = arguments.substr(position, length);
                std::println("found val: {} ({}; {})", value, length, position);

                position = end;
            }
        }


    }
} // namespace

TEST_CASE("Test tokenization", "[argparser]") {
    std::string arguments{"--option value --action positional"};
    std::vector<ArgumentType> arguments_spec = {ArgumentType::OptionValuePair, ArgumentType::Boolean, ArgumentType::Positional};

    consume_arguments(arguments, arguments_spec);
}

TEST_CASE("Test initialization", "[argparser]") {
    ArgumentParser parser("prog", "this is a test program");
}

TEST_CASE("Test argument", "[argument]") {
    Argument arg{"1"};

    std::println("val = {};", arg.value);

    int int_val = *arg.as_number<int>();
    std::print("Type of val = {};", typeid(int_val).name());

    float float_val = *arg.as_number<float>();
    std::print("Type of val = {};", typeid(float_val).name());
}
