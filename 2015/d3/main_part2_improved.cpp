#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <vector>
#include <algorithm>

int main() {
    auto const filename { std::string {"../directions.txt"} };
    auto file { std::fstream{filename} };
    std::string c;
    std::vector<std::pair<int, int>> houses {};

    std::pair<int, int> santas[2] = {{0, 0}, {0, 0}};
    houses.push_back(santas[0]);

    if(file.is_open()) {
        while(std::getline(file, c)) {
            for(int i = 0; i < c.size(); i++) {
                if(c[i] == '^') {
                    santas[i % 2].second -= 1;
                }
                else if (c[i] == 'v') {
                    santas[i % 2].second += 1;
                }
                else if (c[i] == '>') {
                    santas[i % 2].first -= 1;
                }
                else {
                    santas[i % 2].first += 1;
                }
                if(std::find(houses.begin(), houses.end(), santas[i % 2]) != houses.end()) {
                    continue;
                } else {
                    houses.push_back(santas[i % 2]);
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
