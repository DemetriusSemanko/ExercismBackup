pub fn nth(n: u32) -> u32 {
    (2 .. ).filter(
        | e | is_prime(*e)
    ).nth(n.try_into().unwrap()).expect("Last item is nth prime")
}

pub fn is_prime(n: u32) -> bool {
    (2 .. (n.isqrt() + 1)).filter( |e| n % e == 0).count() == 0_usize
}