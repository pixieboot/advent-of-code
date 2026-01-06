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

    short turn {0};

    std::pair<int, int> santaPos = std::make_pair(0, 0);
    std::pair<int, int> roboSantaPos = std::make_pair(0, 0);
    houses.push_back(santaPos);

    if(file.is_open()) {
        while(std::getline(file, c)) {
            for(char c : c) {
                if(turn == 0) {
                    turn = 1;
                    if(c == '^') santaPos.second += 1;
                    if(c == '>') santaPos.first += 1;
                    if(c == 'v') santaPos.second -= 1;
                    if(c == '<') santaPos.first -= 1;

                    if(std::find(houses.begin(), houses.end(), santaPos) != houses.end()) {
                        continue;
                    } else {
                        houses.push_back(santaPos);
                    }
                } else {
                    turn = 0;
                    if(c == '^') roboSantaPos.second += 1;
                    if(c == '>') roboSantaPos.first += 1;
                    if(c == 'v') roboSantaPos.second -= 1;
                    if(c == '<') roboSantaPos.first -= 1;

                    if(std::find(houses.begin(), houses.end(), roboSantaPos) != houses.end()) {
                        continue;
                    } else {
                        houses.push_back(roboSantaPos);
                    }
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
