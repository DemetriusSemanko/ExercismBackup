#include "eliuds_eggs.h"

namespace chicken_coop {

    int positions_to_quantity(int val) {
        if (val == 0) { return 0; }
        int eggs = {0};
        while (val > 0) {
            if (val % 2 == 1) { ++eggs; }
            val /= 2;
        }

        return eggs;
    }

}  // namespace chicken_coop
