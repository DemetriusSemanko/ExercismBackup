pub fn build_proverb(list: &[&str]) -> String {
    let mut output = String::from("");
    if list.len() >= 1 {
        if list.len() > 1 {
            for x in list.windows(2) {
                output.push_str(
                    &("For want of a ".to_owned() + x[0] +
                    " the " + x[1] + " was lost.\n")
                );
            }
        }
        output.push_str(
            &("And all for the want of a ".to_owned() + list[0] + ".")
        );
    }
    output
}
