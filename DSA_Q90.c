#include <bits/stdc++.h>
using namespace std;

bool canPaint(vector<int> &boards, int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (time + boards[i] <= maxTime) {
            time += boards[i];
        } else {
            painters++;
            time = boards[i];
        }

        if (painters > k) return false;
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> boards(n);
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;        // possible
            high = mid - 1;   // try smaller
        } else {
            low = mid + 1;    // increase time
        }
    }

    cout << ans;
    return 0;
}
