#include <bits/stdc++.h>
using namespace std;



int main() {
    ifstream fIn("backforth.in");
    ofstream fOut("backforth.out");

    vector<int> firstSide(10);
    vector<int> secondSide(10);

    for (int i = 0; i < 10; i++) {
        fIn >> firstSide[i];
    }

    for (int i = 0; i < 10; i++) {
        fIn >> secondSide[i];
    }

    set<int> tanks;
    for (int i = 0; i < 10; i++) {
        vector<int> first1 = firstSide;
        vector<int> second1 = secondSide;
        int one = first1[i];
        second1.push_back(first1[i]);
        first1.erase(first1.begin() + i);

        for (int j = 0; j < second1.size(); j++) {
            vector<int> first2 = first1;
            vector<int> second2 = second1;
            int two = second2[j];
            first2.push_back(second2[j]);
            second2.erase(second2.begin() + j);

            for (int k = 0; k < first2.size(); k++) {
                vector<int> first3 = first2;
                vector<int> second3 = second2;
                int three = first3[k];
                second3.push_back(first3[k]);
                first3.erase(first3.begin() + k);

                for (int l = 0; l < second3.size(); l++) {
                    vector<int> first4 = first3;
                    vector<int> second4 = second3;
                    int four = second4[l];
                    first4.push_back(second4[l]);
                    second4.erase(second4.begin() + l);
                    tanks.insert(1000 + one - two + three - four);  
                }
            }
        }
    }

    fOut << tanks.size();

    fIn.close();
    fOut.close();
}