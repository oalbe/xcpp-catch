#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <string>
#include <map>


namespace word_count {
    std::map<std::string, int> words(std::string const &input);
}

#endif // WORD_COUNT_H