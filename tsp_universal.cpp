#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
#define int long long
//#define double long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fileio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

vector<int> tsp_solve(int n, vector<vector<int>> distances) {
    vector<int> orderInPath;
    for (int i = 0; i < n; ++i) {
        orderInPath.push_back(i);
    }
    vector<int> minimalPath;
    int minimalDistance = 1e10;
    do {
        if (orderInPath[0] != 0) continue;
        int currentDistance = 0;
        for (int i = 0; i < n; ++i) {
            currentDistance += distances[orderInPath[i]][orderInPath[(i + 1) % n]];
        }
        if (currentDistance < minimalDistance) {
            minimalDistance = currentDistance;
            minimalPath = orderInPath;
        }
    } while (next_permutation(orderInPath.begin(), orderInPath.end()));
    return minimalPath;
}

signed main() {
    fastio
//    fileio
    int n;
    cout << "Input the size of graph: ";
    cin >> n;
    while (true) {
        if (n < 0) {
            cout << "Inappropriate size\n";
            cout << "Input the size of graph: ";
            cin >> n;
            continue;
        }
        cout << "Input the array of distances:\n";
        vector<vector<int>> distances(n, vector<int> (n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> distances[i][j];
            }
        }
        bool ifArrayIsGood = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i == j && distances[i][j] != 0) {
                    ifArrayIsGood = false;
                    break;
                }
                if (i != j && distances[i][j] != distances[j][i]) {
                    ifArrayIsGood = false;
                    break;
                }
            }
        }
        if (!ifArrayIsGood) {
            cout << "Inappropriate array\n";
            continue;
        }
        vector<int> minimalPath = tsp_solve(n, distances);
        int currentDistanceOfThePath = 0;
        for (int i = 0; i < n; ++i) {
            currentDistanceOfThePath += distances[minimalPath[i]][minimalPath[(i + 1) % n]];
        }
        cout << "Minimal distance: " << currentDistanceOfThePath << '\n';
        cout << "Path to get this distance:\n";
        for (int i = 0; i < n; ++i) {
            cout << minimalPath[i] << ' ';
        }
        cout << minimalPath[0];
        break;
    }
}
