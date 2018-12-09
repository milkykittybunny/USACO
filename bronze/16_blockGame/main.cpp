//C++ template for all USACO codes
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("blocks.in");
    ofstream fOut("blocks.out");

    // solution comes here
    int n;
    fIn >> n;
    vector<pair<string, string> > boards(n);
    map<char, int> letters;

    for (int i = 0; i < n; i++) {
        fIn >> boards[i].first >> boards[i].second;
        map<char, int> firstDict;
        for (int j = 0; j < boards[i].first.size(); j++) {
            char key = boards[i].first[j];
            if (firstDict.count(key) == 0) {
                firstDict[key] = 1;
            }
            else {
                firstDict[key]++;
            }
        }
        map<char,int> secondDict;
        for (int j = 0; j < boards[i].second.size(); j++) {
            char key = boards[i].second[j];
            if (secondDict.count(key) == 0) {
                secondDict[key] = 1;
            }
            else {
                secondDict[key]++;
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            int first = firstDict.count(c);
            int second = secondDict.count(c);
            if (first != 0) {
                first = firstDict[c];
            }
            if (second != 0) {
                second = secondDict[c];
            }
            if (letters.count(c) != 0) {
                letters[c] += max(first, second);
            }
            else {
                letters[c] = max(first,second);
            }
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        fOut << letters[c] << endl;
    }



    fIn.close();
    fOut.close();
}



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
/*
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

*/