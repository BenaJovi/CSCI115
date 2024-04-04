/*  Author: Jovani Benavides
 *  Course: CSCI-115
 *  
 *  
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int HASHSIZE = 4001; // Adjust this as needed

class HashTable {
private:
    struct Item {
        string key;
        int count;
    };

    Item table[HASHSIZE] = {};
    int counter = 0;
    int updates[HASHSIZE] = {};
    int costs[HASHSIZE] = {};

public:
    void update(const string& key) {
        int index = hashFunction(key);
        while (!table[index].key.empty() && table[index].key != key) {
            index = (index + 1) % HASHSIZE;
            counter++;
        }
        if (table[index].key.empty()) {
            table[index].key = key;
        }
        table[index].count++;
        updates[size()]++;
        costs[size()] += probes();
        counter++;
    }

    int size() const {
        int count = 0;
        for (int i = 0; i < HASHSIZE; ++i) {
            if (!table[i].key.empty()) {
                count++;
            }
        }
        return count;
    }

    int probes() const {
        return counter;
    }
   
    void printStatistics() {
        cout << "Unique words count: " << size() << endl;
        cout << "Cost ratios:" << endl;

        for (int i = 1; i <= size(); i++) {
            double ratio = (updates[i] != 0) ? static_cast<double>((costs[i]) / updates[i]) : 0.0;
            cout << "[" << i << "]: " << fixed << setprecision(2) << ratio;  
            
            if (i != size()) {
                cout << ", ";
            }
            else {
                cout << endl;
            }
            if (i % 10 == 0) {
                cout << endl;
            }
        }
    }
    

    int hashFunction(const string& key) const {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % HASHSIZE;
        }
        return hash;
    }

    void readFromFile(const string& filename) {
        ifstream file(filename);
        string word;
        while (file >> word) {
            update(word);
        }
    }
};

int main() {
    HashTable hashTable;
    hashTable.readFromFile("RomeoAndJuliet.txt"); // Change input file name as needed
    hashTable.printStatistics();

    
    return 0;
}
