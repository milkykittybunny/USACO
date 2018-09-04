#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct shift {
    int start;
    int end;
};

bool compare_by_start(const shift &a, const shift &b)
{
    return a.start < b.start;
}

int lstfunc(vector<shift> lst, int amount, int ignoredIndex) {
    int returnsum = 0;
    if (ignoredIndex == amount - 1) {
        amount = ignoredIndex;
    }
    for (int i = 0; i < amount-1; i++) {
        if (i == ignoredIndex - 1) {
            if (lst[i+2].start < lst[i].end) {
                returnsum += (lst[i+2].start) - (lst[i].start);
            }
            else {
                returnsum += lst[i].end - lst[i].start;
            }
        }
        else if (i != ignoredIndex) {
            if (lst[i+1].start < lst[i].end) {
                returnsum += (lst[i+1].start) - (lst[i].start);
            }
            else {
                returnsum += lst[i].end - lst[i].start;
            }
        }

    }
    int x =  lst[amount - 1].end - lst[amount - 1].start;
    return returnsum + x;
}

int main() {
    int amount;
    ifstream fIn;
    fIn.open("lifeguards.in");
    fIn >> amount;
    vector<shift> lst(amount);
    for (int i = 0; i < amount; i++) {
        fIn >> lst[i].start >> lst[i].end;
    }
    sort(lst.begin(), lst.end(), compare_by_start);
    int maxsum = 0;
    vector<shift> tlst = lst;
    int ignoredIndex = -1;
    for (int i = 0; i < amount; i++) {
        ignoredIndex ++;
        int sum = lstfunc(tlst, amount, ignoredIndex);
        if (sum > maxsum) {
            maxsum = sum;
        }
    }
    ofstream fOut;
    fOut.open("lifeguards.out");
    fOut << maxsum;
    fIn.close();
    fOut.close();
    return 0;
}