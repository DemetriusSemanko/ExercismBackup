#include "hexadecimal.h"

namespace hexadecimal {

    int convert(std::string hex) {
        int pow = {0};
        int decimal = {0};
        for (int i = static_cast<int>(hex.size() - 1); i >= 0; --i) {
            int factor = {0};
            int c = std::tolower(hex.at(i));
            if (!std::isdigit(c) && (c < 'a' || c > 'f')) {
                return 0;
            } else {
                if (std::isdigit(c)) {
                    factor = {c - '0'};
                } else {
                    factor = {c - 'a' + 10};
                }
                decimal += factor * (static_cast<int>(std::pow(16, pow)));
            }
            ++pow;
        }
        return decimal;
    }

}  // namespace hexadecimal
