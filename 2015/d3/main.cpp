#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <vector>
#include <algorithm>

struct Hash_pair {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const
    {
        size_t hash1 = std::hash<T1>{}(p.first);
        size_t hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
    }
};

int main() {
    auto const filename { std::string {"../directions.txt"} };
    auto file { std::fstream{filename} };
    std::string c;
    std::vector<std::pair<int, int>> houses {};
    std::pair<int, int> santaPos = std::make_pair(0, 0);
    houses.push_back(santaPos);

    if(file.is_open()) {
        while(std::getline(file, c)) {
            for(char c : c) {
                if(c == '^') santaPos.second += 1;
                if(c == '>') santaPos.first += 1;
                if(c == 'v') santaPos.second -= 1;
                if(c == '<') santaPos.first -= 1;

                if(std::find(houses.begin(), houses.end(), santaPos) != houses.end()) {
                    continue;
                } else {
                    houses.push_back(santaPos);
                }
            }
        }
        std::cout << houses.size() << std::endl;
    } else {
        std::cerr << "Error: Could not open \"" << filename << "\" - " << std::strerror(errno) << "!" << '\n';
    }
    file.close();
    return 0;
}
