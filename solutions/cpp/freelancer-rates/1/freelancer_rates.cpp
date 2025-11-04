// INFO: Headers from the standard library should be inserted at the top via
#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return hourly_rate * 8;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return (1 - (discount / 100)) * before_discount;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    int rate = {static_cast<int>(std::ceil(apply_discount(22 * daily_rate(hourly_rate), discount)))};
    return rate;
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double daily_rate_value = {daily_rate(apply_discount(hourly_rate, discount))};
    int days_in_budget = {static_cast<int>(std::floor(budget / daily_rate_value))};
    return days_in_budget;
}
