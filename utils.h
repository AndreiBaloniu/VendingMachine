
#ifndef LAB9_10_UTILS_H
#define LAB9_10_UTILS_H
#include <fstream>

using namespace std;

void clear_file(const char* filename);

bool file_is_empty(std::ifstream& pFile);


inline void clear_file(const char* filename) {
    std::ofstream f;
    f.open(filename, std::ofstream::out | std::ofstream::trunc);
    f.close();
}

inline bool file_is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}
#endif //LAB9_10_UTILS_H
