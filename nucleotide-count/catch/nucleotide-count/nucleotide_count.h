#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H
#include <string>
#include <map>
#include <algorithm>


namespace dna {
    class counter {
        std::string dna_sequence;
        std::map<char, int> nucleotides_occurrences;
        
        std::map<char, int> map_nucleotides_helper() const;
    public:
        counter(const std::string input_sequence): 
            dna_sequence(input_sequence), 
            nucleotides_occurrences(map_nucleotides_helper()) {}
        
        std::map<char, int> nucleotide_counts() const;
        int count(const char nucleotide) const;
    };
}

#endif // NUCLEOTIDE_COUNT_H