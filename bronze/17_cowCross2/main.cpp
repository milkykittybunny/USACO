#include <iostream>
#include <fstream>

using namespace std;

struct letter {
    int start;
    int end;
};

int main() {
    letter path[26];
    ifstream fIn("circlecross.in");
    for (int i = 0; i < 26; i++) {
        path[i].start = -1;
    }
    for (int i = 0; i < 52; i++) {
        char temp;
        fIn >> temp;
        if (path[temp - 'A'].start == -1) {
            path[temp - 'A'].start = i;
        }
        else {
            path[temp - 'A'].end = i;
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i != j) {
                // i in j
                if (path[j].start < path[i].start && path[j].end > path[i].start
                && path[j].end < path[i].end) {
                    count++;
                }

                else if (path[j].start < path[i].end && path[j].end > path[i].end
                         && path[j].start > path[i].start) {
                    count++;
                }

            }
        }
    }
    ofstream fOut("circlecross.out");
    fOut << count/2;
    return 0;
}