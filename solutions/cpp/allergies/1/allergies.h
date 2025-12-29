#pragma once
#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

namespace allergies {
    class allergy_test {
        private:
            int score;
        public:
            allergy_test(int);
            bool is_allergic_to(std::string);
            std::unordered_set<std::string> get_allergies();
    };
}  // namespace allergies
