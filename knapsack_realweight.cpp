#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double price[101];
double weight[101];
double combi[101];
double m = 0;

void ks(int step, int total, double sumw, double sump, double allw) {
    if (sumw > allw) return ;
    if (sump + combi[step] < m) return ;
    if (step <= total) {
        //select this one
        ks(step + 1, total, sumw + weight[step], sump + price[step], allw);
        // not select
        ks(step + 1, total, sumw, sump, allw);
    }
    else {
        if (sump > m) m = sump;
    }
}

int main() {
    int n;
    double w;
    cin >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    combi[n] = price[n];
    for (int i = n - 1; i >= 1; i--) {
        combi[i] = combi[i + 1] + price[i];
    }

    m = price[1];
    ks(1, n, 0, 0, w);
    cout << fixed << setprecision(4) << m;
}