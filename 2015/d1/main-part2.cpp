#include <iostream>
#include <fstream>

int main() {
    std::ifstream crypt("../floor_level_crypted.txt");
    std::string c {""};
    std::getline(crypt, c);
    crypt.close();
    int counter = 0;
    bool entered = false;

    for(int i = 0; i < c.size(); i++) {
        if(c[i] == ')')
        {
            if(counter == -1 && entered == false) {
                std::cout << "Santa entered the basement at position: " << i << '\n';
                entered = true;
            }
            counter--;
        }
        else counter++;
    }
    std::cout << "Floor: " << counter << '\n';
    return 0;
}
