#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        unordered_set<int> seen;
        bool hasDuplicate = false;

        for (int i = 0; i < n; i++) {
            int teeth; 
            cin >> teeth;

            if (seen.count(teeth)) {
                hasDuplicate = true;
            }
            seen.insert(teeth);
        }

        cout << (hasDuplicate ? "YES" : "NO") << endl;
    }

    return 0;
}
