#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct information {
    int day;
    string name;
    int increased;
};

bool sortfunc(const information &a, const information &b) {
    return a.day < b.day;
}

int main() {
    int totaldays;
    ifstream fIn("measurement.in");
    fIn >> totaldays;
    vector<information> info(totaldays);
    int bessie = 7, elsie = 7, mildred = 7;
    for (int i = 0; i < totaldays; i++) {
        fIn >> info[i].day >> info[i].name >> info[i].increased;
    }
    sort(info.begin(), info.end(), sortfunc);
    string currentcow = "n/a";
    int changes = 0;
    for (int i = 0; i < totaldays; i++) {
        if (info[i].name == "Bessie") {
            bessie += info[i].increased;
        }
        else if (info[i].name == "Mildred") {
            mildred += info[i].increased;
        }
        else if (info[i].name == "Elsie") {
            elsie += info[i].increased;
        }
        if (bessie > mildred && bessie > elsie) {
            if ("Bessie" != currentcow) {
                currentcow = "Bessie";
                changes++;
            }
        }
        else if (bessie < elsie && mildred < elsie) {
            if ("Elsie" != currentcow) {
                currentcow = "Elsie";
                changes++;
            }
        }
        else if (elsie < mildred && bessie < mildred) {
            if ("Mildred" != currentcow) {
                currentcow = "Mildred";
                changes++;
            }
        }
        // bessie and mildred
        else if (bessie == mildred && bessie > elsie) {
            if ("Bessie Mildred" != currentcow) {
                currentcow = "Bessie Mildred";
                changes++;
            }
        }

        // bessie and elsie
        else if (bessie == elsie && bessie > mildred) {
            if ("Bessie Elsie" != currentcow) {
                currentcow = "Bessie Elsie";
                changes++;
            }
        }

        // elsie and mildred
        else if (elsie == mildred && elsie > bessie) {
            if ("Elsie Mildred" != currentcow) {
                currentcow = "Elsie Mildred";
                changes++;
            }
        }

        // we're all in dis togetha
        else if (elsie == mildred && mildred == bessie) {
            if ("Elsie Mildred Bessie" != currentcow) {
                currentcow = "Elsie Mildred Bessie";
                changes++;
            }
        }
    }
    ofstream fOut("measurement.out");
    fOut << changes;
    fIn.close();
    fOut.close();
    return 0;
}