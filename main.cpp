#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

int main(int argc, char** argv) {
    // check if inpnuts file names
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <input> <output>\n";
        return 1;
    }

    std::ifstream in(argv[1], std::ios::binary);
    std::ofstream out(argv[2], std::ios::binary);
    if (!in || !out) {
        std::cerr << "failed to open file\n";
        return 1;
    }

    std::string line;                     // (1) why is this HERE and not inside the loop?

    while (std::getline(in, line)) {
        ______________________________;   // (2) reverse it, in place
        ______________________________;   // (3) write the bytes
        ______________________________;   // (4) write the newline
    }

    return 0;
}
