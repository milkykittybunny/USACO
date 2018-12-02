#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("family.in");
    ofstream fOut("family.out");

    // solution comes here
    int n;
    fIn >> n;
    string a, b;
    fIn >> a >> b;

    map<string, vector<string> > daughters;
    map<string, string> mother;

    for (int i = 0; i < n; i++) {
        string cMother, cDaughter;
        fIn >> cMother >> cDaughter;
        if (daughters.count(cMother) == 0) {
            // key does not exist
            vector<string> temp;
            temp.push_back(cDaughter);
            daughters[cMother] = temp;
        }
        else {
            daughters[cMother].push_back(cDaughter);
        }
        mother[cDaughter] = cMother;
    }
    vector<string> aTree;
    vector<string> bTree;

    string currentCow = a;
    aTree.push_back(currentCow);
    while (mother.count(currentCow) != 0) {
        aTree.push_back(mother[currentCow]);
        currentCow = mother[currentCow];
    }

    currentCow = b;
    bTree.push_back(currentCow);
    while (mother.count(currentCow) != 0) {
        bTree.push_back(mother[currentCow]);
        currentCow = mother[currentCow];
    }

    bool flag = false;
    int diff, iB, iA;
    for (int i = 0; i < aTree.size(); i++) {
        for (int j = 0; j < bTree.size(); j++) {
            if (aTree[i] == bTree[j]) {
                diff = i - j;
                iB = j;
                flag = true;
                iA = i;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    if (! flag) {
        fOut << "NOT RELATED";
        return 0;
    }


    bool isMother = find(aTree.begin(), aTree.end(), b) != aTree.end();
    isMother = isMother || (find(bTree.begin(), bTree.end(), a) != bTree.end());

    if (iA >= 3 && iB >= 3) {
        fOut << "COUSINS";
        return 0;
    }
    if (diff == 0) {
        if (iA == 1) {
            fOut << "SIBLINGS";
        }
        else {
            fOut << "COUSINS";
        }
    }
    else if (diff == 1) {
        // aunt
        if (! isMother) {
            fOut << b << " is the aunt of " << a;
        }
        // mother
        else {
            fOut << b << " is the mother of " << a;
        }
    }
    else if (diff > 1) {
        // aunt

        if (! isMother) {
            fOut << b << " is the ";
            for (int i = 0; i < diff - 1; i++) {
                fOut << "great-";
            }
            fOut << "aunt of " << a;
        }

        // mother
        else {
            fOut << b << " is the ";
            for (int i = 0; i < diff - 2; i++) {
                fOut << "great-";
            }
            fOut << "grand-mother of " << a;
        }
    }

    else if (diff == -1) {
        // aunt
        if (! isMother) {
            fOut << a << " is the aunt of " << b;
        }
            // mother
        else {
            fOut << a << " is the mother of " << b;
        }
    }
    else if (diff < -1) {
        // aunt
        if (! isMother) {
            fOut << a << " is the ";
            for (int i = 0; i < abs(diff) - 1; i++) {
                fOut << "great-";
            }
            fOut << "aunt of " << b;
        }
            // mother
        else {
            fOut << a << " is the ";
            for (int i = 0; i < abs(diff) - 2; i++) {
                fOut << "great-";
            }
            fOut << "grand-mother of " << b;
        }
    }




    fIn.close();
    fOut.close();
}
