#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fIn("promote.in");
    int diff[] = {0, 0, 0, 0};
    int promoted[] = {0, 0, 0};
    int a, b;
    for (int i = 0; i < 4; i++) {
        fIn >> a >> b;
        diff[i] = b - a;
    }
    for (int i = 0; i < 4; i++) {
        if(i >= 1) {
            promoted[0]+= diff[i];
        }
        if(i >= 2) {
            promoted[1]+= diff[i];
        }
        if(i >= 3) {
            promoted[2] += diff[i];
        }
    }
    ofstream fOut("promote.out");
    for (int i = 0; i < 3; i++) {
        fOut << promoted[i] << endl;
    }
    return 0;
}