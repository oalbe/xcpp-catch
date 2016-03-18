#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <vector>
#include <string>
#include <algorithm>


namespace anagram {
    class anagram {
        std::string word;
        
        std::string lower(const std::string&) const;
    public:
        anagram(const std::string input): word(lower(input)) {}

        std::vector<std::string> matches(const std::vector<std::string>& candidates) const;
    };
}

#endif // ANAGRAM_H