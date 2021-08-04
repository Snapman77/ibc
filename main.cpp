#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
#define int long long
//#define double long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fileio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

vector<int> tsp4_solve(int distances[4][4]) {
    int n = 4;
    vector<int> minimalPath = {0, 1, 2, 3};
    int distanceOfMinimalPath = 1e10;
    int firstCity = 0;
    for (int secondCity = 1; secondCity < n; ++secondCity) {
        for (int thirdCity = 1; thirdCity < n; ++thirdCity) {
            for (int fourthCity = 1; fourthCity < n; ++fourthCity) {
                bool allCitiesAreDifferent = true;
                vector<int> orderInThisPath = {firstCity, secondCity, thirdCity, fourthCity};
                for (int firstIndex = 0; firstIndex < n; ++firstIndex) {
                    for (int secondIndex = firstIndex + 1; secondIndex < n; ++secondIndex) {
                        if (orderInThisPath[firstIndex] == orderInThisPath[secondIndex]) {
                            allCitiesAreDifferent = false;
                            break;
                        }
                    }
                }
                if (!allCitiesAreDifferent) continue;
                int currentDistance = 0;
                for (int i = 0; i < n; ++i) {
                    currentDistance += distances[orderInThisPath[i]][orderInThisPath[(i + 1) % n]];
                }
                if (currentDistance < distanceOfMinimalPath) {
                    distanceOfMinimalPath = currentDistance;
                    minimalPath = orderInThisPath;
                }
            }
        }
    }
    return minimalPath;
}



vector<int> tsp5_solve(int distances[5][5]) {
    int n = 5;
    vector<int> minimalPath = {0, 1, 2, 3, 4};
    int distanceOfMinimalPath = 1e10;
    int firstCity = 0;
    for (int secondCity = 1; secondCity < n; ++secondCity) {
        for (int thirdCity = 1; thirdCity < n; ++thirdCity) {
            for (int fourthCity = 1; fourthCity < n; ++fourthCity) {
                for (int fifthCity = 1; fifthCity < n; ++fifthCity) {
                    bool allCitiesAreDifferent = true;
                    vector<int> orderInThisPath = {firstCity, secondCity, thirdCity, fourthCity};
                    for (int firstIndex = 0; firstIndex < n; ++firstIndex) {
                        for (int secondIndex = firstIndex + 1; secondIndex < n; ++secondIndex) {
                            if (orderInThisPath[firstIndex] == orderInThisPath[secondIndex]) {
                                allCitiesAreDifferent = false;
                                break;
                            }
                        }
                    }
                    if (!allCitiesAreDifferent) continue;
                    int currentDistance = 0;
                    for (int i = 0; i < n; ++i) {
                        currentDistance += distances[orderInThisPath[i]][orderInThisPath[(i + 1) % n]];
                    }
                    if (currentDistance < distanceOfMinimalPath) {
                        distanceOfMinimalPath = currentDistance;
                        minimalPath = orderInThisPath;
                    }
                }
            }
        }
    }
    return minimalPath;
}



vector<int> tsp6_solve(int distances[6][6]) {
    int n = 6;
    vector<int> minimalPath = {0, 1, 2, 3, 4, 5};
    int distanceOfMinimalPath = 1e10;
    int firstCity = 0;
    for (int secondCity = 1; secondCity < n; ++secondCity) {
        for (int thirdCity = 1; thirdCity < n; ++thirdCity) {
            for (int fourthCity = 1; fourthCity < n; ++fourthCity) {
                for (int fifthCity = 1; fifthCity < n; ++fifthCity) {
                    bool allCitiesAreDifferent = true;
                    vector<int> orderInThisPath = {firstCity, secondCity, thirdCity, fourthCity};
                    for (int firstIndex = 0; firstIndex < n; ++firstIndex) {
                        for (int secondIndex = firstIndex + 1; secondIndex < n; ++secondIndex) {
                            if (orderInThisPath[firstIndex] == orderInThisPath[secondIndex]) {
                                allCitiesAreDifferent = false;
                                break;
                            }
                        }
                    }
                    if (!allCitiesAreDifferent) continue;
                    int currentDistance = 0;
                    for (int i = 0; i < n; ++i) {
                        currentDistance += distances[orderInThisPath[i]][orderInThisPath[(i + 1) % n]];
                    }
                    if (currentDistance < distanceOfMinimalPath) {
                        distanceOfMinimalPath = currentDistance;
                        minimalPath = orderInThisPath;
                    }
                }
            }
        }
    }
    return minimalPath;
}

signed main() {
    fastio
//    fileio
    int n;
    cout << "Input the size of graph: ";
    cin >> n;
    while (true) {
        if (n < 4 || n > 6) {
            cout << "Inappropriate size\n";
            cout << "Input the size of graph: ";
            cin >> n;
            continue;
        }
        if (n == 4) {
            cout << "Input the array of distances:\n";
            int distances[4][4];
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
                    } else if (i != j && distances[i][j] != distances[j][i]) {
                        ifArrayIsGood = false;
                        break;
                    }
                }
            }
            if (!ifArrayIsGood) {
                cout << "Inappropriate array\n";
                continue;
            }
            vector<int> answerPath = tsp4_solve(distances);
            int distanceOfAnswerPath = 0;
            distanceOfAnswerPath += distances[answerPath[0]][answerPath[1]];
            distanceOfAnswerPath += distances[answerPath[1]][answerPath[2]];
            distanceOfAnswerPath += distances[answerPath[2]][answerPath[3]];
            distanceOfAnswerPath += distances[answerPath[3]][answerPath[0]];
            cout << "Minimal distance: " << distanceOfAnswerPath << '\n';
            cout << "Path for the answer:\n";
            for (int i = 0; i < 4; ++i) {
                cout << answerPath[i] << ' ';
            }
            cout << answerPath[0];
        }
        if (n == 5) {
            cout << "Input the array of distances:\n";
            int distances[5][5];
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
                    } else if (i != j && distances[i][j] != distances[j][i]) {
                        ifArrayIsGood = false;
                        break;
                    }
                }
            }
            if (!ifArrayIsGood) {
                cout << "Inappropriate array\n";
                continue;
            }
            vector<int> answerPath = tsp5_solve(distances);
            int distanceOfAnswerPath = 0;
            distanceOfAnswerPath += distances[answerPath[0]][answerPath[1]];
            distanceOfAnswerPath += distances[answerPath[1]][answerPath[2]];
            distanceOfAnswerPath += distances[answerPath[2]][answerPath[3]];
            distanceOfAnswerPath += distances[answerPath[3]][answerPath[4]];
            distanceOfAnswerPath += distances[answerPath[4]][answerPath[0]];
            cout << "Minimal distance: " << distanceOfAnswerPath << '\n';
            cout << "Path for the answer:\n";
            for (int i = 0; i < 5; ++i) {
                cout << answerPath[i] << ' ';
            }
            cout << answerPath[0];
        }

        if (n == 6) {
            cout << "Input the array of distances:\n";
            int distances[6][6];
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
                    } else if (i != j && distances[i][j] != distances[j][i]) {
                        ifArrayIsGood = false;
                        break;
                    }
                }
            }
            if (!ifArrayIsGood) {
                cout << "Inappropriate array\n";
                continue;
            }
            vector<int> answerPath = tsp6_solve(distances);
            int distanceOfAnswerPath = 0;
            distanceOfAnswerPath += distances[answerPath[0]][answerPath[1]];
            distanceOfAnswerPath += distances[answerPath[1]][answerPath[2]];
            distanceOfAnswerPath += distances[answerPath[2]][answerPath[3]];
            distanceOfAnswerPath += distances[answerPath[3]][answerPath[4]];
            distanceOfAnswerPath += distances[answerPath[4]][answerPath[5]];
            distanceOfAnswerPath += distances[answerPath[5]][answerPath[0]];
            cout << "Minimal distance: " << distanceOfAnswerPath << '\n';
            cout << "Path for the answer:\n";
            for (int i = 0; i < 6; ++i) {
                cout << answerPath[i] << ' ';
            }
            cout << answerPath[0];
        }
        break;
    }
    //
}
