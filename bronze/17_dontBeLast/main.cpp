#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main() {
    map<string, int> info;
    info["Bessie"] = 0;
    info["Elsie"] = 0;
    info["Daisy"] = 0;
    info["Gertie"] = 0;
    info["Annabelle"] = 0;
    info["Maggie"] = 0;
    info["Henrietta"] = 0;
    int length;
    ifstream fIn("notlast.in");
    fIn >> length;
    for (int i = 0; i < length; i++) {
        string currentcow;
        int milk;
        fIn >> currentcow;
        fIn >> milk;
        info[currentcow] += milk;
    }
    int smallest = 100000001;
    int secondSmallest = 100000002;
    string s = "Tie";
    string second = "Tie";
    for (auto it = info.begin() ; it != info.end() ; ++it) {
        if (it->second > smallest && it->second < secondSmallest) {
            secondSmallest = it->second;
            second = it->first;
        }
        else if (it->second < smallest) {
            int temp = smallest;
            string tem = s;
            smallest = it->second;
            s = it->first;
            secondSmallest = temp;
            second = tem;
        }
        else if (it->second == secondSmallest) {
            second = "Tie";
        }
    }
    ofstream fOut("notlast.out");
    if (secondSmallest == 102) {
        fOut << "Tie" << endl;
    }

    else {
        fOut << second << endl;
    }
    fIn.close();
    fOut.close();
    return 0;
}