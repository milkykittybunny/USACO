#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fIn("pails.in");
    int x, y, m;
    fIn >> x >> y >> m;
    int i = 0;
    int max = 0;
    while (x*i < m) {
        int temp = (m - x*i)/y;
        int current = (x*i + temp*y);
        if (current > max) {
            max = current;
        }
        i++;
    }
    ofstream fOut("pails.out");
    fOut << max;
}