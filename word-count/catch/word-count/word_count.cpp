#include "word_count.h"
#include "split.h"
#include <regex>
#include <iostream>


std::map<std::string, int> word_count::words(std::string const &input) {
    // First, replaces punctuation and other symbols with spaces.
    std::regex symbols_re("[,\.!&@$%\^:]+", std::regex::ECMAScript);
    std::string no_symbols = std::regex_replace(input, symbols_re, " ");
    
    // Second, replaces freestanding apostrophes and quotes with spaces.
    std::regex freestanding_apostrophes_re("(\ '+|'$)", std::regex::ECMAScript);
    std::string no_freestanding = std::regex_replace(no_symbols, freestanding_apostrophes_re, " ");
    
    // Finally, replaces sequences of more than one space with a single one.
    std::regex spaces_re("[[:space:]]+", std::regex::ECMAScript);
    std::string clean_input = std::regex_replace(no_freestanding, spaces_re, " ");
    
    std::transform(clean_input.begin(), clean_input.end(), clean_input.begin(), ::tolower);
    
	std::vector<std::string> single_words = split(clean_input, ' ');
	
	std::map<std::string, int> counts;
	for (std::size_t i = 0; i < single_words.size(); ++i) {
  		if(counts.count(single_words[i])) {
            counts[single_words[i]] += 1;
		} else {
            counts[single_words[i]] = 1;
		}
	}

	return counts;
}