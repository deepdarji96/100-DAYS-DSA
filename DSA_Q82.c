#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size(); // default if not found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1; // move left
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int lb = lowerBound(arr, x);
    int ub = upperBound(arr, x);

    cout << lb << " " << ub;

    return 0;
}
