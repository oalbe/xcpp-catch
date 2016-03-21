#ifndef RNA_TRANSCRIPTION_H
#define RNA_TRANSCRIPTION_H
#include <map>
#include <string>


namespace transcription {
    std::map<char, char> dna_to_rna = {
        {'G', 'C'},
        {'C', 'G'},
        {'T', 'A'},
        {'A', 'U'}
    };
    
    char to_rna(const char dna_nucleotide) {
        return dna_to_rna[dna_nucleotide];
    }
    
    std::string to_rna(const std::string& dna_strand) {
        std::string rna;
        for (const char nucleotide : dna_strand) {
            rna += dna_to_rna[nucleotide];
        }
        
        return rna;
    }
}


#endif // RNA_TRANSCRIPTION_H