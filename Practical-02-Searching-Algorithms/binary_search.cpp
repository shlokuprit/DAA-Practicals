// Practical 2(b) : Binary Search

#include <iostream>
#include <vector>
using namespace std;

// Iterative binary search, the array must be sorted in ascending order
int binarySearch(const vector<int> &a, int key) {
    int low = 0;
    int high = a.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int pos = binarySearch(a, key);

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
