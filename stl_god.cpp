#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

bool f (int x, int y) {
    return x > y;
}

void vectorDemo() {
    vector<int> A = {11, 2, 3, 14};

    cout << A[1] << endl;

    sort(A.begin(), A.end()); // O(NlogN)

    // {2, 3, 11, 14}
    bool present = binary_search(A.begin(), A.end(), 3); //true - O(logN)
    present = binary_search(A.begin(), A.end(), 4); // false - O(logN)

    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100); // true
    // {2, 3, 11, 14, 100}

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    // {2, 3, 11, 14, 100, 100, 100, 100, 123}

    // vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100); // returns first value >= 100
    // vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // returns first value > 100

    // new syntax in C++
    auto it = lower_bound(A.begin(), A.end(), 100); // returns first value >= 100
    auto it2 = upper_bound(A.begin(), A.end(), 100); // returns first value > 100

    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl;

    sort(A.begin(), A.end(), f);

    vector<int>::iterator it3;

    for (it3 = A.begin(); it3 != A.end(); it3++) {
        cout << *it3 << " ";
    }
    cout << endl;

    // new syntax in C++ for looping over vectors
    for  (int x: A) {
        cout << x << " ";
    }
    cout << endl;

    // reference
    for  (int &x: A) {
        x++;
    }

    for  (int x: A) {
        cout << x << " ";
    }
    cout << endl;
}

void setDemo() {
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    for (int x: S) cout << x << " ";
    cout << endl;
    
    // -10 -1 1 2
    auto it = S.find(-1);

    if (it == S.end()) {
        cout << "not present\n";
    } else {
        cout << "present\n";
        cout << *it << endl;
    }

    auto it2 = S.lower_bound(-1);
    auto it3 = S.upper_bound(0);
    cout << *it2 << " " << *it3 << endl;

    auto it4 = S.upper_bound(2);
    if (it4 == S.end()) {
        cout << "oops! sorry cant find something like that \n";
    }

}

void mapDemo() {
    map<int, int> A;
    A[1] = 100;
    A[2] = -1;
    A[1000000232] = 1;

    map<char, int> cnt;
    string x = "akinbowale akin-taylor";

    for (char c: x) {
        cnt[c]++;
    }

    cout << cnt['a'] << " " << cnt['o'] << endl;

}

void PowerOfStl() {
    set< pair<int, int> > S; 

    S.insert({{ 401, 450 }});
    S.insert({{ 10, 20 }});
    S.insert({{ 2, 3 }});
    S.insert({{ 30, 400}});

    // 2, 3
    // 10, 20
    // 30, 400
    // 401, 450

    int point = 2;

    auto it = S.upper_bound({ point, INT_MAX });


    if (it == S.begin()) {
        cout << "the given point is not lying in any interval..\n";
        return;
    }
    it--;
    pair<int, int> current = *it;
    if (current.first <= point && point <= current.second) {
        cout << "yes its present: " << current.first << " " << current.second << endl;
    } else {
        cout << "the given point is not lying in any interval..\n";
    }


}

int main() {
    // C++ STL
    // setDemo();
    // mapDemo();
    PowerOfStl();


    return 1;
}