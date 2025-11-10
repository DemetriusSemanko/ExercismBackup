pub fn is_armstrong_number(num: u32) -> bool {
    let length = count_digits(num);
    let mut x = num;
    let mut acc = 0;
    while x > 0 {
        acc += u32::pow(x % 10, length);
        x = x / 10;
    }
    acc == num
}

pub fn count_digits(num: u32) -> u32 {
    let mut count = 0;
    let mut x = num;
    if num == 0 { 1 } else {
        while x > 0 {
            count += 1;
            x /= 10;
        }
        count
    }
}
