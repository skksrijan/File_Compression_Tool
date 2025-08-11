#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <string>

// ------------------ RLE FUNCTIONS ------------------
using u8  = uint8_t;
using u16 = uint16_t;

void compressRLE(const std::vector<u8> &in, std::vector<u8> &out) {
    size_t i = 0;
    while (i < in.size()) {
        u8 value = in[i];
        size_t run = 1;

        while (i + run < in.size() && in[i + run] == value && run < 65535) {
            run++;
        }

        out.push_back(value);
        u16 count = static_cast<u16>(run);
        out.push_back(static_cast<u8>((count >> 8) & 0xFF));
        out.push_back(static_cast<u8>(count & 0xFF));

        i += run;
    }
}

bool decompressRLE(const std::vector<u8> &in, std::vector<u8> &out) {
    if (in.size() % 3 != 0) return false; // corrupted format
    for (size_t i = 0; i < in.size(); i += 3) {
        u8 value = in[i];
        u16 high = in[i + 1];
        u16 low  = in[i + 2];
        u16 count = (high << 8) | low;
        for (u16 k = 0; k < count; ++k) {
            out.push_back(value);
        }
    }
    return true;
}

// ------------------ FILE HELPERS ------------------
bool readFile(const std::string &filename, std::vector<u8> &data) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) return false;
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    data.resize(size);
    file.read(reinterpret_cast<char*>(data.data()), size);
    return true;
}

bool writeFile(const std::string &filename, const std::vector<u8> &data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) return false;
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
    return true;
}

// ------------------ MAIN CLI ------------------
int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage:\n"
                  << argv[0] << " compress <input> <output>\n"
                  << argv[0] << " decompress <input> <output>\n";
        return 1;
    }

    std::string mode = argv[1];
    std::string inFile = argv[2];
    std::string outFile = argv[3];

    std::vector<u8> inputData, outputData;

    if (!readFile(inFile, inputData)) {
        std::cerr << "Error: Cannot open input file.\n";
        return 1;
    }

    if (mode == "compress") {
        compressRLE(inputData, outputData);
    } else if (mode == "decompress") {
        if (!decompressRLE(inputData, outputData)) {
            std::cerr << "Error: Corrupted RLE data.\n";
            return 1;
        }
    } else {
        std::cerr << "Unknown mode: " << mode << "\n";
        return 1;
    }

    if (!writeFile(outFile, outputData)) {
        std::cerr << "Error: Cannot write output file.\n";
        return 1;
    }

    std::cout << "Done! " << mode << "ion complete.\n";
    return 0;
}
