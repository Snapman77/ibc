#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
#define int long long
//#define double long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fileio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

vector<int> c;

int rec(int n) {
    if (n <= 2) {
        return 1;
    }
    if (c[n] != -1) return c[n];
    return c[n] = rec(n - 1) + rec(n - 2);
}

signed main() {
    fastio
//    fileio
    int n;
    cin >> n;
    auto t1 = chrono::high_resolution_clock::now();
    c.resize(n + 1, -1);
    cout << rec(n) << '\n';
    auto t2 = chrono::high_resolution_clock::now();
    int a = 1, b = 1;
    for (int i = 3; i <= n; ++i) {
        int p = b;
        b = a + b;
        a = p;
    }
    cout << b << '\n';
    auto t3 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    auto duration2 = chrono::duration_cast<std::chrono::nanoseconds>(t3 - t2).count();
    cout << "Time taken to do iterative solution: " << duration2 << " nanoseconds\n";
    cout << "Time taken to do recursive solution: " << duration1 << " nanoseconds\n";

}
