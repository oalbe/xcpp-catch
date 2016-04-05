#ifndef FOOD_CHAIN_H
#define FOOD_CHAIN_H
#include <string>


namespace food_chain {

namespace {

using swallowed_things_t = std::vector<std::string>;

swallowed_things_t swallowed_things = {
    "fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"
};

std::string beginning = "I know an old lady who swallowed a ";

std::map<std::string, std::string> swallowed_events = {
    {"fly", "I don't know why she swallowed the fly. Perhaps she'll die.\n"},
    {"spider", "It wriggled and jiggled and tickled inside her.\n"},
    {"bird", "How absurd to swallow a bird!\n"},
    {"cat", "Imagine that, to swallow a cat!\n"},
    {"dog", "What a hog, to swallow a dog!\n"},
    {"goat", "Just opened her throat and swallowed a goat!\n"},
    {"cow", "I don't know how she swallowed a cow!\n"},
    {"horse", "She's dead, of course!\n"}
};

std::string verse_helper(std::size_t thing, swallowed_things_t things) {
    // 0 = fly | 7 = horse
    if ((0 == thing) || (7 == thing)) {
        return "";
    }

    // 2 = bird
    if (2 == thing) {
        return "She swallowed the " + things[thing] + " to catch the " + 
            things[thing - 1] + " that wriggled and jiggled and tickled inside her.\n";
    }

    return "She swallowed the " + things[thing] + " to catch the " + things[thing - 1] + ".\n";
}

} // unnamed namespace

std::string verse(std::size_t index) {
    std::string common = beginning +
        swallowed_things[index - 1] + ".\n" +
        swallowed_events[swallowed_things[index - 1]];

    if ((1 == index) || (8 == index)) {
        return common;
    }

    std::string specific;
    for (std::size_t i = 2; i <= index; ++i) {
        std::size_t things_index = index - i;
        std::string events_index = swallowed_things[things_index];

        specific += verse_helper(things_index + 1, swallowed_things);

        if (i == index) {
            specific += swallowed_events[events_index];
        }
    }

    return common + specific;
}

std::string verses(std::size_t begin, std::size_t end) {
    std::string bunch;
    for (std::size_t i = begin; i <= end; ++i) {
        bunch += verse(i) + '\n';
    }

    return bunch;
}

std::string sing() {
    return verses(1, 8);
}

} // namespace food_chain

#endif // FOOD_CHAIN_H