#include "rotational_cipher.h"

namespace rotational_cipher {

    std::string rotate(std::string plain_text, int key) {
        std::string cipher_text = { "" };
        
        key %= 26;
        if (key == 0) { return plain_text; }
        
        
        for (size_t i = 0; i < plain_text.size(); ++i) {
            char c = plain_text.at(i);
            if (isalpha(c)) {
                bool lower = islower(c);
    
                c = static_cast<char>(toupper(c) + key);
                if (c > 'Z') {
                    c = static_cast<char>('A' + (c - 'Z') - 1);
                }
                if (lower) { c = tolower(c); }
                cipher_text += c;
            } else {
                cipher_text += c;
            }
        }
    
        return cipher_text;
}

}  // namespace rotational_cipher
