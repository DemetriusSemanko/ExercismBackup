pub fn factors(n: u64) -> Vec<u64> {
    let mut factors: Vec<u64> = Vec::new();
    let mut x = n;

    let mut fac = 2;
    while x > 1 {
        if x % fac == 0 {
            factors.push(fac);
            x /= fac;
        } else {
            fac += 1;
        }
    }

    factors
}