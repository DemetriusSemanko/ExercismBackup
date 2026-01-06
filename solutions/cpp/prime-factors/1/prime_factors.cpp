#include "prime_factors.h"

namespace prime_factors {

    std::vector<long long> of(long long n) {
        std::vector<long long> factors = {};
        long long fac = {2};
        while (n > 1) {
            if (n % fac == 0) {
                factors.emplace_back(fac);
                n /= fac;
            } else {
                fac += 1;
            }
        }

        return factors;
    }
}  // namespace prime_factors
