#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (mid * mid <= n) {
            ans = mid;       // store answer
            low = mid + 1;   // try bigger
        } else {
            high = mid - 1;  // go smaller
        }
    }

    cout << ans;
    return 0;
}
