// Practical 2(a) : Linear Search

#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int> &a, int key) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int pos = linearSearch(a, key);

    if (pos != -1)
        cout << "Element " << key << " found at index " << pos
             << " (position " << pos + 1 << ")." << endl;
    else
        cout << "Element " << key << " is not present in the array." << endl;

    cout << "\n----------------------------------------\n";
    cout << "Name           : Shlok Uprit\n";
    cout << "Enrollment No. : 92460118211\n";

    return 0;
}
