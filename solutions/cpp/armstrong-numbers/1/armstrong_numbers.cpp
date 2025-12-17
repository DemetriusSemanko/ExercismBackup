#include "armstrong_numbers.h"

namespace armstrong_numbers {

    bool is_armstrong_number(int n) {
        // Count digits
        int digits = {0};
        if (n >= 0 && n < 10) { return true; }
        
        int n_copy = {n};
        while (n_copy > 0) {
            ++digits;
            n_copy /= 10;
        }

        // Start Armstronging
        int acc = {0};
        n_copy = {n};
        while (n_copy > 0) {
            int digit = n_copy % 10;
            acc += static_cast<int>(std::pow(digit, digits));
            n_copy /= 10;
        }

        return (acc == n);
    }

}  // namespace armstrong_numbers
