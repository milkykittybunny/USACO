#include <bits/stdc++.h>
using namespace std;
/*
Given a set of non-negative integers,
 and a value sum, determine if there
 is a subset of the given set with sum
 equal to given sum.
 https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
 */

bool find_subset(int size, vector<int> mySet, int sum) {
    // base case
    if (size == 0) {
        if (sum == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    // two cases
    else {
        // with last element
        return (find_subset(size - 1, mySet, sum - mySet[size - 1])
        // without
        || find_subset(size - 1, mySet, sum));
    }
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vector<int> myNotASet(x);
        int sum = 0;
        for (int j = 0; j < x; j++) {
            cin >> myNotASet[j];
            sum += myNotASet[j];
        }
        if (sum % 2 != 0) {
            cout << "NO" << endl;
        }
        else if (find_subset(myNotASet.size(), myNotASet, sum/2)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}