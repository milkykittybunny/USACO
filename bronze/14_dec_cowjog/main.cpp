#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("cowjog.in");
    ofstream fOut("cowjog.out");
    int n;
    fIn >> n;
    vector<pair<int, int> > cowj(n);
    for (int i = 0; i < n; i++) {
        fIn >> cowj[i].first >> cowj[i].second;
    }

    int least = cowj[n-1].second;
    int groups = 0;
    for (int i = n-2; i >= 0; i--) {
        if (cowj[i].second <= least) {
            least = cowj[i].second;
            groups++;
        }
    }

    fOut << groups+1;
    fIn.close();
    fOut.close();
}
    /*
    while(1) {
        double simstep = 1000000;
        for (int i = 1; i < n; i++) {
            if (cowj[i-1].second > cowj[i].second) {
                double time = abs(cowj[i].first - cowj[i-1].first)/
                        abs(cowj[i].second - cowj[i-1].second);
                if (time < simstep){
                    simstep = time;
                }
            }
        }
        for (int i = n-1; i > 0; i--) {
            cowj[i].first += cowj[i].second * simstep;
            if (i != 0 && cowj[i].first <= cowj[i + 1].first) {
                cowj.erase(cowj.begin() + i - 1);
            }
        }
        bool leastamount = true;
        for (int i = 1; i < cowj.size(); i++) {
            if (cowj[i].second > cowj[i-1].second) {
                leastamount = false;
                break;
            }
        }
        if (leastamount == true) {
            break;
        }
    }
*/