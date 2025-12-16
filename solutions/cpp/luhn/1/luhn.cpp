#include "luhn.h"

namespace luhn {

    bool valid(std::string ident) {
        std::string temp = {};
        for (size_t i = 0; i < ident.size(); ++i) {
            if (!isspace(ident.at(i))) { temp += ident.at(i); }
        }
        ident = {temp};
        int checksum = {0};
        int counter = {0};
        if (ident.size() < 2) { return false; }
        for (int i = {static_cast<int>(ident.size() - 1)}; i >= 0; --i) {
            char ident_c = ident.at(i);
            if (!std::isdigit(ident_c) && !std::isspace(ident_c)) {
                return false;
            } else {
                if (std::isdigit(ident_c)) {
                    int ident_int = {ident_c - '0'};
                    if (counter % 2 == 1) {
                        ident_int *= 2;
                        if (ident_int > 9) {
                            ident_int -= 9;
                        }
                    }
                    checksum += ident_int;
                    ++counter;
                }
            }
        }
        return (checksum % 10 == 0);
    }

}  // namespace luhn
