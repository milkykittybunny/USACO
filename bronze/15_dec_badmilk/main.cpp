#include <bits/stdc++.h>
using namespace std;

struct cow{
    vector<pair<int, int> > drank;
    bool sick;
    int sicktime;
};

int main() {
    ifstream fIn("badmilk.in");
    ofstream fOut("badmilk.out");

    // solution comes here
    int friends, milk, drink, sick;
    fIn >> friends >> milk >> drink >> sick;

    vector<cow> cows(friends);

    for (int i = 0; i < drink; i++) {
        int f, m, time;
        fIn >> f >> m >> time;
        cows[f-1].drank.push_back(make_pair(m, time));
        cows[f-1].sick = false;
        cows[f-1].sicktime = -1;
    }

    for (int i = 0; i < sick; i++) {
        int cowsick, stime;
        fIn >> cowsick >> stime;
        cows[cowsick-1].sick = true;
        cows[cowsick-1].sicktime = stime;
    }

    int greatestMed = 0;
    for (int cMilk = 1; cMilk <= milk; cMilk++) {
        int currentMed = 0;
        bool sick_drank = true;
        for (int cow = 0; cow < friends; cow++) {
            bool ttrue = false;

            bool drank = false;
            for (int i = 0; i < cows[cow].drank.size(); i++) {
                if (cows[cow].drank[i].first == cMilk) {
                    drank = true;
                    if (cows[cow].sick) {
                        if (cows[cow].sicktime > cows[cow].drank[i].second) {
                            ttrue = true;
                        }
                        else {
                            sick_drank = false;
                        }
                    }
                    else {
                        ttrue = true;
                    }
                }
            }

            if (! drank && cows[cow].sick) {
                sick_drank = false;
            }

            if (ttrue) {
                currentMed++;
            }

        }

        if (sick_drank && currentMed > greatestMed) {
            greatestMed = currentMed;
        }
    }

    fOut << greatestMed;

    fIn.close();
    fOut.close();
}