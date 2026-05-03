#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &stalls, int n, int k, int dist) {
    int count = 1; // first cow at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= k) return true;
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;       // possible
            low = mid + 1;   // try bigger
        } else {
            high = mid - 1;  // reduce distance
        }
    }

    cout << ans;
    return 0;
}
