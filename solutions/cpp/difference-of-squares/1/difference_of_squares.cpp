#include "difference_of_squares.h"

namespace difference_of_squares {

    int difference(int n) {
        return (square_of_sum(n) - (sum_of_squares(n)));
    }

    int square_of_sum(int n) {
        int sum_1_to_n = (n * (n + 1)) / 2;
        int square_sum_1_to_n = static_cast<int>(std::pow(static_cast<double>(sum_1_to_n), 2));

        return square_sum_1_to_n;
    }

    int sum_of_squares(int n) {
        return (n * (n + 1) * (2 * n + 1)) / 6;
    }

}  // namespace difference_of_squares
