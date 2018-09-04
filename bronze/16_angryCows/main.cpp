#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

bool around(list<int> &c, int t, vector<int> lst) {
    bool flag = false;
    for (int i = 0; i < lst.size(); i++)   {
        if (abs(lst[i] - c.front()) <= t
        || abs(lst[i] - c.back()) <= t) {
            if (find(c.begin(), c.end(), lst[i]) == c.end()) {
                for (auto it = c.begin(); it != c.end(); it++) {
                    if (*it > lst[i]) {
                        c.insert(it, lst[i]);
                        flag = true;
                        break;
                    }
                    else {
                        c.push_back(lst[i]);
                        flag = true;
                        break;
                    }
                }
            }
        }
    }
    return flag;
}

int main() {
    int n;
    ifstream fIn("angry.in");
    fIn >> n;
    vector<int> bales(n);
    for (int i = 0; i < n; i++) {
        fIn >> bales[i];

    }
    sort(bales.begin(),bales.end());
    int largest = 0;
    for (int i = 0; i < n; i++) {
        int t = 1;
        list<int> c;
        c.push_back(bales[i]);
        bool flag = true;
        while (flag) {
            flag = around(c, t, bales);
            t++;
        }
        if (c.size() > largest) {
            largest = c.size();
        }
        cout << c.size() << endl;

    }
    ofstream fOut("angry.out");
    fOut << largest;
    return 0;
}