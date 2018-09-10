#include <bits/stdc++.h>
using namespace std;

int base_changer(int number, int base) {
    int total = number/100*(base*base);
    number = number%100;
    total += number/10*(base);
    return total + number % 10;
}

int main() {
    ifstream fIn("whatbase.in");
    ofstream fOut("whatbase.out");
    int n;
    fIn >> n;
    vector<pair<int, int> > testcases(n);
    for (int i = 0; i < n; i++) {
        fIn >> testcases[i].first >> testcases[i].second;
    }
 
    for (int i = 0; i < n; i++) {
        int onebase = 10, twobase = 10;
        int one = base_changer(testcases[i].first, onebase);
        int two = base_changer(testcases[i].second, twobase);

        while (one != two) {
            if (one < two) {
                onebase++;
                one = base_changer(testcases[i].first, onebase);
            }
            else {
                twobase++;
                two = base_changer(testcases[i].second, twobase);
            }
        }
        fOut << onebase << " " << twobase << endl;
    }

    fIn.close();
    fOut.close();
}