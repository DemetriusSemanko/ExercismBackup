#include "reverse_string.h"
#include <string>

namespace reverse_string {

    std::string reverse_string(std::string s) {
        std::string c;
        std::copy(s.crbegin(), s.crend(), std::back_inserter(c));

        return c;
    }

}  // namespace reverse_string
