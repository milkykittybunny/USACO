#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    int cowlength;
    ifstream fIn;
    fIn.open("shuffle.in");
    fIn >> cowlength;
    vector<int> newplaces(cowlength);
    for (int i = 0; i < cowlength; i++) {
        fIn >> newplaces[i];
    }
    vector<int> cows(cowlength);
    for (int i = 0; i < cowlength; i++) {
        fIn >> cows[i];
    }
    vector<int> newcows(cowlength);
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < cowlength; i++) {
            if (j % 2 == 0) {
                newcows[i] = cows[newplaces[i] - 1];
            }
            else {
                cows[i] = newcows[newplaces[i] - 1];
            }
        }
    }
    ofstream fOut;
    fOut.open("shuffle.out");
    for (int i = 0; i < cowlength; i++) {
        fOut << newcows[i] << endl;
    }
}