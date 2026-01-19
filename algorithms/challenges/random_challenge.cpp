#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <sstream>

// Simple JSON parser for our specific use case
std::vector<int> parseEasyChallenges(const std::string& filename) {
    std::vector<int> challenges;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return challenges;
    }
    
    std::string line;
    bool inEasyArray = false;
    
    while (std::getline(file, line)) {
        // Check if we're in the "easy" array
        if (line.find("\"easy\"") != std::string::npos) {
            inEasyArray = true;
            continue;
        }
        
        if (inEasyArray) {
            // Extract numbers from the line
            std::stringstream ss(line);
            std::string token;
            
            while (std::getline(ss, token, ',')) {
                // Remove whitespace and extract number
                size_t start = token.find_first_of("0123456789");
                if (start != std::string::npos) {
                    size_t end = token.find_last_of("0123456789");
                    std::string numStr = token.substr(start, end - start + 1);
                    challenges.push_back(std::stoi(numStr));
                }
            }
            
            // Stop when we reach the end of the array
            if (line.find("]") != std::string::npos) {
                break;
            }
        }
    }
    
    file.close();
    return challenges;
}

int getRandomChallenge(const std::vector<int>& challenges) {
    if (challenges.empty()) {
        return -1;
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, challenges.size() - 1);
    
    return challenges[dist(gen)];
}

int main() {
    std::vector<int> easyChallenges = parseEasyChallenges("challenges.json");
    
    if (easyChallenges.empty()) {
        std::cerr << "No challenges found!" << std::endl;
        return 1;
    }
    
    int randomChallenge = getRandomChallenge(easyChallenges);
    std::cout << "Random challenge: " << randomChallenge << std::endl;
    
    return 0;
}
