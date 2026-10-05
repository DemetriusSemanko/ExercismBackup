use std::collections::HashSet;

#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    let a = first_list.iter().collect::<HashSet<_>>();
    let b = second_list.iter().collect::<HashSet<_>>();
    
    if a == b {
        if first_list == second_list {
            return Comparison::Equal
        }   
    } else if a.is_superset(&b) {
        if b.is_empty() || first_list.windows(second_list.len()).any(|window| window == second_list) {
            return Comparison::Superlist
        }
    } else if a.is_subset(&b) {
        if a.is_empty() || second_list.windows(first_list.len()).any(|window| window == first_list) {
            return Comparison::Sublist
        }
    }
    Comparison::Unequal
}
