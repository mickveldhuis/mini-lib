#pragma once

#include <charconv>
#include <optional>
#include <string>
#include <string_view>
#include <map>
#include <system_error>

struct Argument {
    std::string_view value;

    template<typename NumericType>
    std::optional<NumericType> as_number() {
        int result{};
        auto [ptr, error_code] = std::from_chars(value.data(), value.data() + value.size(), result);

        if (error_code == std::errc{}) {
            return result;
        }

        return std::nullopt;
    }


};

struct ParseResult {
    std::map<std::string_view, Argument> arguments;
};

/// Basic CLI argument parser.
/// Usage:
/// ArgumentParser parser;
/// parser.add_argument("v", "verbose", "Increase verbosity", ArgumentParser::Type::Bool);
/// parser.add_argument("d" "duration", "Time duration", ArgumentParser::Type::Float);
/// parser.add_argument("file", "File name", ArgumentParser::Type::String);
/// parser.parse(argv);
/// Limitations:
/// - No groups (e.g. subcmd would not be valid in 'prog subcmd -v a.txt')
/// Choices: utilise modern C++ features, e.g.
/// - std::string_view
/// - std::from_chars
/// Because we're using string_view, we might need
/// to keep a copy of the original string around to
/// guarantee no dangling pointers...(alt. string pooling?)
class ArgumentParser {
public:
  ArgumentParser(std::string_view name, std::string_view description);

  std::optional<ParseResult> parse(std::string_view arguments);

  void add_argument(const std::string& short_name, const std::string& long_name, const std::string& help);
  void add_argument(const std::string& positional_name, const std::string& help);

  void help() const;

private:
  void consume_arguments();
  void consume_argument();

  std::string name_{};
  std::string description_{};
  std::string arguments_{};
};
