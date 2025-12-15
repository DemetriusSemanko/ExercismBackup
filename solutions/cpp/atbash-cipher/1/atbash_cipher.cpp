#include "atbash_cipher.h"
#include <string>
#include <cctype>

namespace atbash_cipher {

    std::string encode(std::string raw) {
        std::string cipher_table = {"zyxwvutsrqponmlkjihgfedcba"};
        std::string ciphered = {};
        int counter = 0;
        for (size_t i = 0; i < raw.size(); ++i) {
            if (isalnum(raw.at(i))) {
                if (counter % 5 == 0 && counter > 0) { ciphered += " "; }
                ++counter;
                if (isalpha(raw.at(i))) {
                    int pos = tolower(raw.at(i)) - 'a';
                    ciphered += (cipher_table.at(pos));
                } else {
                    ciphered += raw.at(i);
                }
            }
        }
    
        return ciphered;
    }

    std::string decode(std::string cipher_text) {
        std::string decoded_filtered = { "" };
        std::string decoded = encode(cipher_text);
        for (size_t i = 0; i < decoded.size(); ++i) {
            if (isalnum(decoded.at(i))) {
                decoded_filtered += (decoded.at(i));
            }
        }
        return decoded_filtered;
    }

}  // namespace atbash_cipher
