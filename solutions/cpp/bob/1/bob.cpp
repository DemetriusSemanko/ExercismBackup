#include "bob.h"

namespace bob {

    std::string hey(std::string msg) {
        bool is_question = false;
        if (msg.size() > 0) { is_question = msg.back() == '?'; }
        bool is_yelling = true;
        bool is_silence = true;
        int alpha_count = 0;
        for (size_t i = 0; i < msg.size(); ++i) {
            char c = msg.at(i);

            if (std::isalpha(c)) {
                if (is_yelling) { is_yelling = std::isupper(c); }
                ++alpha_count;
            }
            if (is_silence) { is_silence = std::isspace(c); }
        }

        if (alpha_count == 0) {
            is_yelling = false;
        }

        if (!is_silence) {
            bool done = false;
            for (size_t i = msg.size() - 1; i > 0 && !done; --i) {
                char c = msg.at(i);
                if (!std::isspace(c)) {
                    is_question = (c == '?');
                    done = true;
                }
            }
        }

        if (is_silence) {
            return "Fine. Be that way!";
        } else if (is_question && is_yelling) {
            return "Calm down, I know what I'm doing!";
        } else if (is_question) {
            return "Sure.";
        } else if (is_yelling) {
            return "Whoa, chill out!";
        } else {
            return "Whatever.";
        }
    }

}  // namespace bob
