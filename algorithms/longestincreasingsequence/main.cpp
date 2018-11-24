#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<int> lst(m);
        vector<int> diff(lst.size());

        for (int j = 0; j < m; j++) {
            cin >> lst[j];
        }
        diff[0] = 1;
        for (int i = 0; i < lst.size() - 1; i++) {
            if (lst[i] < lst[i + 1]) {
                diff[i + 1] = diff[i] + 1;
            }
            else {
                diff[i + 1] = 1;
            }
        }

        cout << *max_element(diff.begin(), diff.end()) << endl;
    }
}