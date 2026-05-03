#include <bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int> &books, int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + books[i] <= maxPages) {
            pages += books[i];
        } else {
            students++;
            pages = books[i];
        }

        if (students > m) return false;
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canAllocate(books, n, m, mid)) {
            ans = mid;        // possible
            high = mid - 1;   // try smaller
        } else {
            low = mid + 1;    // increase limit
        }
    }

    cout << ans;
    return 0;
}
