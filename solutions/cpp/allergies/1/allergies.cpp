#include "allergies.h"

namespace allergies {
    std::unordered_set<std::string> allergies = {};

    allergy_test::allergy_test(int score) {
        allergies = {};
        std::vector<std::string> allergy_list = {"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"};

        std::string bin = {""};
        while (score > 0) {
            if (score % 2 == 1) {
                bin = "1" + bin;
            } else {
                bin = "0" + bin;
            }
            score /= 2;
        }
        while (bin.size() < 8) {
            bin = "0" + bin;
        }
        if (bin.size() > 8) {
            bin = bin.substr(bin.size() - 8);
        }
        int counter = {7};
        while (counter >= 0) {
            if (bin.at(counter) == '1') {
                allergies.emplace(allergy_list.at(7 - counter));
            }
            --counter;
        }
    }

    std::unordered_set<std::string> allergy_test::get_allergies() {     
        return allergies;
    }

    bool allergy_test::is_allergic_to(std::string thing) {
        return allergy_test::get_allergies().count(thing) == 1;
    }
}  // namespace allergies
