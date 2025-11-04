#include <string>

namespace log_line {
    std::string message(std::string line) {
        return line.substr(line.find(":") + 2);
    }

    std::string log_level(std::string line) {
        int closeBrackIndex = line.find("]");
        int messageLength = closeBrackIndex - 1;
        
        return (line.substr(1, messageLength));
    }

    std::string reformat(std::string line) {
        std::string message = {log_line::message(line)};
        std::string log_level = {log_line::log_level(line)};

        return message + " (" + log_level + ")";
    }
}  // namespace log_line
