#include "raindrops.h"
#include <string>

namespace raindrops {

    std::string convert(int n) {
        std::string out = {""};
        if (n % 3 == 0) { out += "Pling"; }
        if (n % 5 == 0) { out += "Plang"; }
        if (n % 7 == 0) { out += "Plong"; }
        if (out == "") { out += std::to_string(n); }

        return out;
    }

}  // namespace raindrops
