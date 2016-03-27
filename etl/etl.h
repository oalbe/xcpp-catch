#ifndef ETL_H
#define ETL_H
#include <map>
#include <vector>


namespace etl {

std::map<char, int> transform(std::map<int, std::vector<char>> old_data) {
    std::map<char, int> new_data;
    
    for (auto& old_map_element : old_data) {
        for (auto vector_element : old_map_element.second) {
            new_data[char(vector_element + 32)] = old_map_element.first;
        }
    }
    
    return new_data;
}

} // namespace etl

#endif // ETL_H