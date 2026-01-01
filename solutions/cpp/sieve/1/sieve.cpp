#include "sieve.h"

namespace sieve {
    std::vector<int> primes(int n) {
        std::vector<int> solns = {};
        for (int i = 2; i <= n; ++i) {
            solns.emplace_back(i);
        }
        for (int i = 0; i < static_cast<int>(solns.size()); ++i) {
            int prime = solns.at(i);
            for (std::vector<int>::iterator it = solns.begin(); it != solns.end();) {
                if (*it != prime && *it % prime == 0) {
                    solns.erase(it);
                } else {
                    ++it;
                }
            }
        }
        
        return solns;
    }
}  // namespace sieve
