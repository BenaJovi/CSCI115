#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

const int HASHSIZE = 4001; // Change this value as needed

class HashTable {
private:
    struct Entry {
        std::string key;
        int value;
        Entry(const std::string& k, int v) : key(k), value(v) {} // Constructor
    };

    Entry* hashTable[HASHSIZE];
    int updates[HASHSIZE];
    int cost[HASHSIZE];
    int totalProbes;

    int hashFunction(const std::string& key) const {
        int hash = 0;
        for (size_t i = 0; i < key.length(); ++i) {
            hash += static_cast<int>(key[i]);
        }
        return hash % HASHSIZE;
    }

public:
    HashTable() : totalProbes(0) {
        for (int i = 0; i < HASHSIZE; i++) {
            hashTable[i] = nullptr;
            updates[i] = 0;
            cost[i] = 0;
        }
    }

    void update(const std::string& key) {
        int index = hashFunction(key);
        int probeCount = 1;
        
        while (hashTable[index] != nullptr && hashTable[index]->key != key) {
            index = (index + 1) % HASHSIZE; // Linear probing
            probeCount++;
        }

        if (hashTable[index] == nullptr) { // Key not found, insert new entry
            hashTable[index] = new Entry(key, 1); // Explicit constructor call
            updates[getSize()]++;
        } else { // Key found, increment value
            hashTable[index]->value++;
        }

        cost[getSize()] += probeCount;
        totalProbes += probeCount;
    }

    int size() const {
        int count = 0;
        for (int i = 0; i < HASHSIZE; i++) {
            if (hashTable[i] != nullptr) {
                count++;
            }
        }
        return count;
    }

    int probes(const std::string& key) const {
        int index = hashFunction(key);
        int probeCount = 1;
        
        while (hashTable[index] != nullptr && hashTable[index]->key != key) {
            index = (index + 1) % HASHSIZE; // Linear probing
            probeCount++;
        }

        return probeCount;
    }

    int getSize() const {
        return size() - 1; // Adjust for 0-based indexing
    }

    void printStatistics() const {
        std::cout << "Number of unique words: " << size() << std::endl;
        for (int i = 1; i < getSize(); i++) {
            double ratio = (updates[i] != 0) ? static_cast<double>(cost[i]) / updates[i] : 0.0;
            std::cout << std::fixed << std::setprecision(2) << ratio;
            if (i < getSize() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    ~HashTable() {
        for (int i = 0; i < HASHSIZE; i++) {
            delete hashTable[i];
        }
    }
};

int main() {
    std::ifstream inputFile("RomeoAndJuliet.txt"); // Change the file name as needed
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    HashTable hashTable;

    std::string word;
    while (inputFile >> word) {
        hashTable.update(word);
    }

    hashTable.printStatistics();

    return 0;
}
