#include <iostream>
#include <vector>
using namespace std;

void mergesort(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    if (m <= 0 || n <= 0) {
        cout << "Invalid input. Size of arrays should be positive." << endl;
        return;
    }

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else if (nums1[i] < nums2[j]) {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

void display(vector<int> &nums1, int m) {
    for (int i = 0; i < m; i++) {
        cout << nums1[i] << " "; 
    }
    cout << endl;
}

int main() {
    vector<int> nums1;
    vector<int> nums2;
    int m = 0;
    int n = 0;

    cout << "Enter size of the first array: " << endl;
    cin >> m;

    if (m <= 0) {
        cout << "Invalid input. Size of the first array should be positive." << endl;
        return 1; 
    }

    cout << "Enter size of the second array: " << endl;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Size of the second array should be positive." << endl;
        return 1; 
    }

    cout << "Enter elements of the first array: ";
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        nums1.push_back(x);
    }

    cout << "Enter elements of the second array: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums2.push_back(x);
    }

    mergesort(nums1, m, nums2, n);
    display(nums1, m);
}
