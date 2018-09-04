#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct cow {
    int side;
    int count;
};

int main() {
    int crosstotals;
    ifstream fIn("crossroad.in");
    fIn >> crosstotals;
    vector<cow> cows(10);
    for (int i = 0; i < 10; i++) {
        cows[i].side = -1;
        cows[i].count = 0;
    }
    for (int i = 0; i < crosstotals; i++) {
        int id, side;
        fIn >> id >> side;
        if (side == 1) {
            if (cows[id - 1].side != 1) {
                cows[id-1].count++;
            }
            cows[id-1].side = 1;
        }
        else {
            if (cows[id - 1].side != 0) {
                cows[id-1].count++;
            }
            cows[id-1].side = 0;
        }
    }
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (cows[i].count == 2) {
            count ++;
        }
        if (cows[i].count > 2) {
            count += (cows[i].count) - 1;
        }
    }
    ofstream fOut("crossroad.out");
    fOut << count;
    fIn.close();
    fOut.close();
    return 0;
}