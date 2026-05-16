#include "mini-lib/argumentparser.hpp"
#include <optional>

ArgumentParser::ArgumentParser(std::string_view name,
                               std::string_view description)
    : name_{name}, description_{description} {}

std::optional<ParseResult> ArgumentParser::parse(std::string_view arguments) {
    return std::nullopt;
}

void ArgumentParser::add_argument(const std::string &short_name, const std::string &long_name, const std::string &help) {

}

void ArgumentParser::add_argument(const std::string &positional_name, const std::string &help) {

}

void ArgumentParser::help() const {

}
