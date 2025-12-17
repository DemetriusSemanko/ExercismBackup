#include "darts.h"

namespace darts {

    int score(float x, float y) {
        float dist_from_center = std::sqrt( std::pow(x, 2) + std::pow(y, 2) );
        if (dist_from_center > 10.0f) {
            return 0;
        } else if (dist_from_center > 5.0f && dist_from_center <= 10.0f) {
            return 1;
        } else if (dist_from_center > 1.0f && dist_from_center <= 5.0f) {
            return 5;
        } else {
            return 10;
        }
    }

}  // namespace darts
