#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<double> a;
double cache [1001][10001] = {0};

double calc_prob(int i, int j) { //
    if ( i == 0) { //array out of bounds (starts at 1)
        return 0;
    }
    if ( j == 0) { //array out of bounds (starts at 1)
        return 1;
    }

    if (i == 1 && j == 1) { //edge case: first kid and first barrier
        return a[1]; //a[1] is the probability for the first barrier
    }
    if (cache[i][j] > 0) {
        return cache[i][j];
    }


    auto res = calc_prob(i, j-1) * a[j] + (1 - a[j]) * calc_prob(i-1, j);

    cache[i][j] = res;
    return res;
}

int main() {
    cin >> n >> k;
    a.push_back(0);
    for (int i= 0; i < k; i++) {
        double p;
        cin >> p;
        a.push_back(p);
    }
    double best = 0;
    for (int i= 1; i <= n; i++) {
        double cur = calc_prob(i, k) - calc_prob(i-1, k);

        best = max(best, cur);
        if (best == 0.0000000000) {
            break;
        }
    }
    cout << fixed << setprecision(10) << best <<endl;
}