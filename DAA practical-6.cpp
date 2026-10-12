#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[100];
    cout << "Enter dimensions array (" << n + 1 << " values): ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    int m[100][100] = {};

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    cout << "Minimum multiplications: " << m[1][n] << endl;
    return 0;
}