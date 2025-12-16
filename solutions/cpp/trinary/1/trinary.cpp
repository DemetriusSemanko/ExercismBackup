#include "trinary.h"

namespace trinary {

    int to_decimal(std::string trinary) {
        int pow = {0};
        int acc = {0};
        for (int i = static_cast<int>(trinary.size() - 1); i >= 0; --i) {
            char trin_c = trinary.at(i);
            int factor = {0};
            if (trin_c == '1') {
                factor = {1};
            } else if (trin_c == '2') {
                factor = {2};
            } else {
                if (trin_c != '0') {
                    return 0;    
                }
            }
            acc += factor * static_cast<int>((std::pow(3, pow)));
            ++pow;
        }

        return acc;
    }

}  // namespace trinary
