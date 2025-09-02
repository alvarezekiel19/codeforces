#include <iostream>
#include <string>

using namespace std;

long long digitSum(int n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long solve(long long k) {
    if (k <= 9) return k * (k + 1) / 2;

    long long total = 45;
    long long pos = 9;
    int len = 2;
    
    while (pos < k) {
        long long count = 9;
        for (int i = 1; i < len; i++) {
            count *= 10;
        }

        long long totalDigits = count * len;

        if (pos + totalDigits <= k) {
            long long groupSum = 0;
            groupSum += 45 * (count / 9);

            for (int i = 1; i < len; i++) {
                groupSum += 45 * (count / 10);
            }

            total += groupSum;
            pos += totalDigits;
        } else {
            long long remaining = k - pos;
            long long start = 1;

            for (int i = 1; i < len; i++) {
                start += 10;
            }

            long long num = start;
            while (remaining > 0) {
                string s = to_string(num);
                for (char c : s) {
                    if (remaining-- <= 0) break;
                    total += c - '0';
                }
                num++;
            }
            break;
        }
        len++;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long k;
        cin >> k;
        cout << solve(k) << endl;
    }
    return 0;
}
