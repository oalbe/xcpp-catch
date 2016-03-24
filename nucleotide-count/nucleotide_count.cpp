#include "nucleotide_count.h"


std::map<char, int> dna::counter::nucleotide_counts() const {
    return nucleotides_occurrences;
}

int dna::counter::count(const char nucleotide) const {
    std::string legals = "ATCG";
    if (std::find(legals.begin(), legals.end(), nucleotide) == legals.end()) {
        throw std::invalid_argument("Strands lengths are different.");
    }
    
    return nucleotide_counts().at(nucleotide);
}

std::map<char, int> dna::counter::map_nucleotides_helper() const {
    std::map<char, int> occurrences_map = {{'A', 0}, {'T', 0}, {'C', 0}, {'G', 0}};
    
    for (const char nucleotide : dna_sequence) {
        occurrences_map[nucleotide] += 1;
    }
    
    return occurrences_map;
}