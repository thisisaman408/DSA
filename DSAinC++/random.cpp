#include <iostream>
#include <string>

int main() {
    std::string helloWorld = "hello world";

    for (int i = 0; i < helloWorld.length(); ++i) {
        for (char letter = 'a'; letter <= helloWorld[i]; ++letter) {
            for (int j = 0; j <= i; ++j) {
                std::cout << (char)(letter + j);
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
