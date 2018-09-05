/*
git commands to upload code to github after finishing a new question

cd USACO

git add .
git commit -m "added a new solution!"
git push -u origin master

*/

//C++ template for all USACO codes
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn(".in");
    ofstream fOut(".out");

    // solution comes here
    int n;
    fIn >> n;



    fIn.close();
    fOut.close();
}


//STL examples
//vector
vector<int> v;
v.push_back(3); // [3]
v.push_back(2); // [3,2]
cout << v.size();
vector<int> v.resize(10);

//vector insert
std::vector<int>::iterator it;
for (int i=1; i<=3; i++) myvector.push_back(i);
myvector.insert (myvector.begin() + 2 , 200 );

//vector erase
std::vector<int> myvector;
// set some values (from 1 to 10)
for (int i=1; i<=10; i++) myvector.push_back(i);
// erase the 6th element
myvector.erase (myvector.begin()+5);
// erase the first 3 elements:
myvector.erase (myvector.begin(),myvector.begin()+3);

//vector iteration
for (auto it = myvector.begin() ; it != myvector.end(); ++it)
  cout << ' ' << *it;
//vector reverse iteration
for (auto rit = myvector.rbegin() ; rit != myvector.rend(); ++rit)
  cout << ' ' << *rit;




//set
set<int> s;
set<int> s{2,5,6,8};
s.insert(3);
s.insert(2);
s.erase(3);
s.size()

//set iterate
for (auto it = s.begin(); it != s.end(); it++) {
  cout << *it << "\n";
}

//set search
auto it = s.find(x);
if (it == s.end()) {
// x is not found
}

//set find the largest/maximum member
if(!s.empty())
    cout << *s.rbegin(); //pay attention to the "*"
else
    //the set is empty




//std::map<key, value> map;
map<string,int> m;
m["monkey"] = 4;
m["banana"] = 3;
m["harpsichord"] = 9;

if (m.count("aybabtu")) {
   // key exists
}

//map iterate
for (auto x : m) {
  cout << x.first << " " << x.second << "\n";
}

//sort vector , list
sort(v.begin(), v.end());

//reverse
reverse(v.begin(), v.end());

//random shuffle
random_shuffle(v.begin(), v.end());
