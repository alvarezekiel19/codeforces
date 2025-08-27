#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        string a, b;
        cin >> a >> b;
 
        char last_a = a.back(), last_b = b.back();
 
        if (last_a != last_b) {
            cout << (last_a < last_b ? '>' : '<') << '\n';
        } else if (a == b) {
            cout << "=\n";
        } else {
            bool a_shorter = a.size() < b.size();
            cout << ((a_shorter ^ (last_a == 'S')) ? '<' : '>') << '\n';
        }
    }
    return 0;
}
