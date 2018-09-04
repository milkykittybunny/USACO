#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct cow {
    int start;
    int passed;
};

bool sortfunc(const cow &a, const cow &b) {
    return a.start < b.start;
}

int main() {
    int amountOfCows;
    ifstream fIn("cowqueue.in");
    fIn >> amountOfCows;
    vector<cow> info(amountOfCows);
    for (int i = 0; i < amountOfCows; i++) {
        fIn >> info[i].start >> info[i].passed;
    }
    sort(info.begin(), info.end(), sortfunc);
    int timepassed = 0;
    int ctime = 0;
    for (int i = 0; i < amountOfCows; i++) {
        if (i == 0) {
            timepassed += info[i].passed;
            ctime += info[i].passed + info[i].start;
        }
        else {
            if (info[i].start > ctime) {
                timepassed += (info[i].start - ctime) + info[i].passed;
                ctime += (info[i].start - ctime) + info[i].passed;
            }
            else {
                timepassed += info[i].passed;
                ctime += info[i].passed;
            }
        }
    }
    ofstream fOut("cowqueue.out");
    fOut << ctime;
    fIn.close();
    fOut.close();
    return 0;
}