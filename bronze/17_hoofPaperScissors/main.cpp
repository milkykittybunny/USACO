#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct days {
    int one;
    int two;
};

int main() {
    int daysamount;
    ifstream fIn;
    fIn.open("hps.in");
    fIn >> daysamount;
    vector<days> cows(daysamount);
    for (int i = 0; i < daysamount; i++) {
        fIn >> cows[i].one >> cows[i].two;
    }
    vector<int> amounts = {0, 0, 0, 0, 0, 0};
    int royalty[6][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    // through possibilities
    for (int i = 0; i < 6; i++) {
        // through days
        for (int j = 0; j < daysamount; j++) {
            if (distance(royalty[i], find(royalty[i], royalty[i] + 4, cows[j].one))
            == 1 + distance(royalty[i], find(royalty[i], royalty[i] + 4, cows[j].two))) {
                amounts[i] ++;
            }
            else if (distance(royalty[i], find(royalty[i], royalty[i] + 4, cows[j].one)) == 0
            && distance(royalty[i], find(royalty[i], royalty[i] + 4, cows[j].two)) == 2) {
                amounts[i]++;
            }
        }
    }
    int greatest = 0;
    for (int i = 0; i < 6; i++) {
        if (amounts[i] > greatest) {
            greatest = amounts[i];
        };
    }
    ofstream fOut;
    fOut.open("hps.out");
    fOut << greatest;
    return 0;
}