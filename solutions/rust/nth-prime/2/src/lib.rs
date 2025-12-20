pub fn nth(n: u32) -> u32 {
    (2 .. ).filter(
        |e| is_prime(*e)
    ).nth(n as usize).expect("Last item is nth prime")
}

pub fn is_prime(n: u32) -> bool {
    ! ((2 .. (n.isqrt() + 1)).any( |e| n % e == 0))
}