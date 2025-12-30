#include "kindergarten_garden.h"

namespace kindergarten_garden {
   std::array<Plants, 4> plants(std::string plant_rows, std::string name) {
        std::string front_row = plant_rows.substr(0, plant_rows.find("\n"));
        std::string back_row = plant_rows.substr(plant_rows.find("\n") + 1);
        std::array<Plants, 4> owned = {};
        int factor = {name.at(0) - 'A'};
        int atomic = {0};
        for (int i = 0; i < 2; ++i) {
            std::string row = {};
            if (i == 0) {
                row = {front_row};
            } else {
                row = {back_row};
            }
            
            for (int j = 2 * factor; j < (2 * factor) + 2; ++j) {
                char plant = row.at(j);
                Plants p = {};
                if (plant == 'G') {
                    p = Plants::grass;
                } else if (plant == 'C') {
                    p = Plants::clover;
                } else if (plant == 'R') {
                    p = Plants::radishes;
                } else { // plant == 'V'
                    p = Plants::violets;
                }
                
                owned.at(atomic) = p;
                ++atomic;
            }
        }
        return owned;
    }

}  // namespace kindergarten_garden
