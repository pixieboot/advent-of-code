#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <cerrno>
#include <cstring>

/*
 * Splits string line by the given delimiter
 *
 * @param reference s        : string line
 * @param reference delimiter: delimiter which the string line will be split by
 * @param reference tokens   : string container vector for element manipulation from 'std::string s'
 *
 * @return: void
 */
void split(std::string& s, const std::string& delimiter, std::vector<std::string>& tokens) {
    size_t pos = 0;
    std::string token;
    while((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);
};

/*
 * Sums total value from the given formula for surface area of the present box
 *
 * @param l: length of the box
 * @param w: width of the box
 * @param h: height of the box
 *
 * @return: total sum from the given formula
 */
int surfaceAreaSum(std::string& l, std::string& w, std::string& h) {
    int lenght { std::stoi(l) };
    int width { std::stoi(w) };
    int height { std::stoi(h) };

    int lw { 2 * lenght * width };
    int wh { 2 * width * height };
    int hl { 2 * height * lenght };

    std::array<int, 3> box = { lw, wh, hl };
    int* minElem { std::min_element(box.begin(), box.end()) };

    int totalSum { (lw + wh + hl + (*minElem / 2)) };
    return totalSum;
}

int main() {
    std::ifstream paper("../paper_dimensions_list.txt");
    std::string line;
    std::vector<std::string> data;
    int totalSum { 0 };

    if(paper.is_open()) {
        while(std::getline(paper, line)) {
            split(line, "x", data);
            for(int i = 0; i < data.size(); i++) {
                int surfaceArea = surfaceAreaSum(data[0], data[1], data[2]);
                totalSum += surfaceArea;
                std::cout << surfaceArea << '\n';
                std::vector<std::string>().swap(data);
            }
        }
        std::cout << "Total sum for square feet of wrapping paper is: " << totalSum << '\n';
    } else {
        std::cerr << "Error: Could not open \"" << std::strerror(errno) << "\"!" << '\n';
    }
    paper.close();

    return 0;
}
