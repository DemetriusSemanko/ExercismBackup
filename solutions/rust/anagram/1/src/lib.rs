use std::collections::{HashSet, HashMap};

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let thm = count_letters(word.to_lowercase().as_str());

    possible_anagrams.into_iter().copied().filter(|x| word.to_lowercase() != x.to_lowercase() && is_anagram(&thm, x.to_lowercase().as_str())).collect()
}

pub fn is_anagram(target: &HashMap<char, u32>, current: &str) -> bool {
    *target == count_letters(current)
} 

pub fn count_letters(word: &str) -> HashMap<char, u32> {
    let mut hm = HashMap::with_capacity(26);

    let x = word.chars();
    
    for c in x {
        let opt = hm.get_mut(&c);
        if let Some(v) = opt { *v += 1; } else { hm.insert(c, 1); }
    }

    hm
}