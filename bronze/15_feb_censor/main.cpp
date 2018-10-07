#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("censor.in");
    ofstream fOut("censor.out");

    string s, t;
    fIn >> s >> t;

    string output;
    for (int i = 0; i < s.size(); i++) {
        output += s[i];
        int subSize = output.size() - t.size();
        if (subSize > 0) {
            string sub = output.substr(subSize);
            if (sub == t) {
                output.erase(output.end() - t.size(), output.end());
            }
        }
    }

    fOut << output;

    fIn.close();
    fOut.close();
}
