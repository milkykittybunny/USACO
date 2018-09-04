#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <fstream>

using namespace std;

struct block {
    string front;
    string back;
};



/*
int current = -1;
string make_combinations(vector<block> blocks, vector<string> &combinations, int &numofblocks) {
    current++;
    if (current == numofblocks) {
        return "";
    }
    int x = combinations.size();
    for (int i = 0; i < x; i++) {
        combinations.push_back(combinations[i] + blocks[current].front);
        combinations[i] += blocks[current].back;
    }
    make_combinations(blocks, combinations, numofblocks);
    return "";
}
*/

// generates a complete set using binary for loops
// generate alphabet
void create_alphabet(vector<block> blocks, vector<int> &alphabet) {
    int length = blocks.size();

    for (int i = 0; i < pow(2, length); i++) {
        string temp;
        int meow = i;
        for (int j = 0; j < length; j++) {
            if (meow & 1 == 1) {
                temp += blocks[j].front;
            }
            else {
                temp += blocks[j].back;
            }
            meow >>= 1;
        }
        vector<int> tempAlphabet(26, 0);
        for(unsigned int j = 0; j<temp.length(); j++) {
            char c = temp[j];
            tempAlphabet[c - 'a']++;
            if (alphabet[c - 'a'] < tempAlphabet[c - 'a']) {
                alphabet[c - 'a']++;
            }
        }
    }
}

int main() {
    ifstream fIn("blocks.in");
    vector<int> alphabet(26, 0);
    int numofblocks;
    fIn >> numofblocks;
    vector<block> blocks(numofblocks);
    for (int i = 0; i < numofblocks; i++) {
        fIn >> blocks[i].front >> blocks[i].back;
    }
    create_alphabet(blocks, alphabet);
    ofstream fOut("blocks.out");
    for (int i = 0; i < 26; i++) {
        fOut << alphabet[i] << endl;
    }
}