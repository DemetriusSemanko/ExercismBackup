#include "protein_translation.h"

namespace protein_translation {

    std::vector<std::string> proteins(std::string codons) {
        std::vector<std::string> proteins_vec = {};
        
        if (codons.size() < 3) { return proteins_vec; } // If invalid codons string

        std::string builder = {};
        for (size_t i = 0; i < codons.size(); ++i) {
            builder += codons.at(i);
            if (builder.size() == 3) {
                std::string translation = translate(builder);
                if (translation == "STOP") {
                    return proteins_vec;
                } else {
                    proteins_vec.emplace_back(translation);
                    builder = "";
                }
            }
        }
        return proteins_vec;
    }

    std::string translate(std::string codon_triple) {
        if (codon_triple == "AUG") {
                return "Methionine";
        } else if (codon_triple == "UUU" || codon_triple == "UUC") {
                return "Phenylalanine";
        } else if (codon_triple == "UUA" || codon_triple == "UUG") {
                return "Leucine";
        } else if (codon_triple == "UCU" || codon_triple == "UCC"
                        || codon_triple == "UCA" || codon_triple == "UCG") {
                return "Serine";
        } else if (codon_triple == "UAU" || codon_triple == "UAC") {
            return "Tyrosine";
        } else if (codon_triple == "UGU" || codon_triple == "UGC") {
            return "Cysteine";
        } else if (codon_triple == "UGG") {
            return "Tryptophan";
        } else if (codon_triple == "UAA" || codon_triple == "UAG" 
                        || codon_triple == "UGA") {
            return "STOP";
        } else {
            return "";
        }
    }

}  // namespace protein_translation
