#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H
#include <map>
#include <string>
#include <vector>
#include <algorithm>


namespace grade_school {

typedef std::vector<std::string> students_t;
typedef std::map<int, students_t> school_log_t;

class school {
    school_log_t __roster;
public:
    school() {}
    
    inline school_log_t roster() const {
        return __roster;
    }
    
    inline students_t grade(int mark) {
        return __roster[mark];
    }
    
    void add(std::string student, int mark) {
        __roster[mark].push_back(student);
        std::sort(__roster[mark].begin(), __roster[mark].end());
    }
};

} // namespace grade_school

#endif // GRADE_SCHOOL_H