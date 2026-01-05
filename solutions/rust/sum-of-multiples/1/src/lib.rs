pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    let mut fac_list: Vec<u32> = Vec::new();

    for fac in factors {
        let mut x: u32 = *fac;
        while x < limit && *fac != 0 {
            if !fac_list.contains(&x) {
                fac_list.push(x);
            }
            x = x + fac;
        }
    }
    fac_list.into_iter().sum()
}
