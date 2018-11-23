#include <bits/stdc++.h>
using namespace std;

void find_partners(vector<int> cowslst, vector<int> &closest, set<int> &hasPass) {
    for (int i = 0; i < closest.size(); i++) {
        int diff = 10001, diff2 = 10001;
        if (i != 0) {
            diff = cowslst[i] - cowslst[i - 1];
        }
        if (i != closest.size() - 1) {
            diff2 = cowslst[i + 1] - cowslst[i];
        }
        if (diff <= diff2) {
            closest[i] = i - 1;
            hasPass.insert(i - 1);
        }
        else {
            closest[i] = i + 1;
            hasPass.insert(i + 1);
        }
    }
}

int find_ball(vector<int> &cowslst, vector<int> &closest, set<int> &noPass) {
    int n = cowslst.size();
    int balls = 0;
    vector<int> parallel(n);
    for (auto it = noPass.begin(); it != noPass.end(); it++) {
        int current = *it;
        int last = *it;
        parallel[*it] = 1;
        // while not continued loop
        while (last != closest[current]) {
            // make a pass, current to last and
            // next to current (next is closest[i])
            last = current;
            // since last is rn current, actually saying closest[current]
            current = closest[last];
            parallel[current] = 1;
        }
        balls++;
    }
    int remaining = 0;
    for (int i = 0; i < parallel.size(); i++) {
        if (parallel[i] == 0) {
            remaining++;
        }
    }
    balls += remaining/2;
    return balls;
    /*int n = cowslst.size();
    int leastBallsGiven = 1000000;
    for (auto it = noPass.begin(); it != noPass.end(); it++) {
        vector<int> parallel(n);
        int counter = 0;
        int balls = 0;
        int ballGiven = *it;
        while (counter < n) {
            parallel[ballGiven] = 1;
            counter++;
            int current = ballGiven;
            int last = ballGiven;
            // while not continued loop
            while (last != closest[current] && counter < n) {
                // make a pass, current to last and
                // next to current (next is closest[i])
                last = current;
                // since last is rn current, actually saying closest[current]
                current = closest[last];
                parallel[current] = 1;
                counter++;
            }
            balls++;
            //find the next candidate
            for (int j = 0; j < parallel.size(); j++) {
                if (parallel[j] == 0 && noPass.find(j) != noPass.end()) {
                    ballGiven = j;
                    break;
                }
            }
        }
        if (balls < leastBallsGiven) {
            leastBallsGiven = balls;
        }
    }
    return leastBallsGiven;*/
}

int main() {
    ifstream fIn("hoofball.in");
    ofstream fOut("hoofball.out");

    // solution comes here
    int n;
    fIn >> n;

    vector<int> cowslst(n);
    vector<int> closest(n);

    for (int i = 0; i < n; i++) {
        fIn >> cowslst[i];
    }

    sort(cowslst.begin(), cowslst.end());

    set<int> hasPass;
    set<int> noPass;
    find_partners(cowslst, closest, hasPass);

    for (int i = 0; i < n; i++) {
        if (hasPass.find(i) == hasPass.end()) {
            noPass.insert(i);
        }
    }

    fOut << find_ball(cowslst, closest, noPass);

    fIn.close();
    fOut.close();
}