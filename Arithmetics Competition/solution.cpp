#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<long long> a(n), b(m);

        // vadim's card
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // kostya's cards
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        // prefix sums for efficient range sum queries
        vector<long long> prefixA(n + 1, 0), prefixB(m + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixA[i + 1] = prefixA[i] + a[i];
        }

        for (int i = 0; i < m; i++) {
           prefixB[i + 1] = prefixB[i] + b[i];
        }

        auto f =[&](int k, int z) -> long long {
            if (k < 0 || k > n) return LLONG_MIN / 4;
            int bk = z - k;
            if (bk < 0 || bk > m) return LLONG_MIN / 4;
            return prefixA[k] + prefixB[bk];

        }; 
        
        while (q--) {
            int x, y, z;
            cin >> x >> y >> z;
            if (z == 0) { cout << 0 << endl; continue; }

            int lo = max(0, z - y);
            int hi = min(x, z);
            if (lo > hi) { cout << 0 << endl; continue; }

            int L = lo, H = hi;
            while (H - L > 5) {
                int m1 = L + (H - L) / 3;
                int m2 = H - (H - L) / 3;

                long long v1 = f(m1, z);
                long long v2 = f(m2 ,z);
                if (v1 < v2) L = m1;
                else H = m2;
            }

            long long best = LLONG_MIN;
            for (int k = L; k <= H; k++) best = max(best, f(k, z));
            cout << best << endl;
        }
    }
    return 0;
}

