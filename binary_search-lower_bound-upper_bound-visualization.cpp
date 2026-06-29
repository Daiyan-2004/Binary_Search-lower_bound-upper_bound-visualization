#include <bits/stdc++.h>
using namespace std;

vector<int> books;

bool _binary_search(int key) {
    int low = 0, high = books.size() - 1, mid;

    cout << "low\thigh\tmid\tmid_value\n";
    while(low <= high) {
        mid = low + (high - low)/2;
        cout << low << "\t" << high << "\t" << mid << "\t" << books[mid] << endl;

        if(books[mid] == key) return true;
        else if(books[mid] < key) low = mid + 1;
        else high = mid - 1;

    }

    return false;
}

int _lb(int key) {
    int low = 0, high = books.size() - 1, mid, lb = books.size();

    cout << "low\thigh\tmid\tmv\tclb\n";
    while(low <= high) {
        mid = low + (high - low)/2;
        cout << low << "\t" << high << "\t" << mid << "\t" << books[mid] << "\t" << lb << endl;
        if(books[mid] >= key) {
            high = mid - 1;
            lb = mid;
        }
        else low = mid + 1;
    }

    return lb;
}

int _ub(int key) {
    int low = 0, high = books.size() - 1, mid, ub = books.size();

    cout << "low\thigh\tmid\tmv\tcub\n";
    while(low <= high) {
        mid = low + (high - low)/2;
        cout << low << "\t" << high << "\t" << mid << "\t" << books[mid] << "\t" << ub << endl;
        if(books[mid] > key) {
            high = mid - 1;
            ub = mid;
        }
        else low = mid + 1;
    }

    return ub;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        books.push_back(a);
    }

    while(1) {
        int key;
        cout << "\nKey: ";
        cin >> key;

        if(key == -10) break;

        cout << "\nBinary Search: \n";
        if(_binary_search(key)) {
            cout << "Found!" << endl;
        } else {
            cout << "Not Found!" << endl;
        }


        cout << "\nlower bound: [mv -> mid value; clb -> current lower bound;]\n";
        int _lower_bound = _lb(key);

        cout << "\nUpper bound: [mv -> mid value; cub -> current upper bound;]\n";
        int _upper_bound = _ub(key);

        cout << "\nFinal lb: " << _lower_bound << endl;
        cout << "Final ub: " << _upper_bound << endl;
        cout << "Occurrences: " << _upper_bound - _lower_bound  << endl;

    }

    return true;
}

//15
//1 3 5 7 7 7 7 7 7 9 9 11 11 13 13
