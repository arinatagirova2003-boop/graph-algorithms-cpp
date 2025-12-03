#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Enter n (2000..6000): ";
    cin >> n;

    if (n < 2 || n > 6000) {
        cout << "Invalid n\n";
        return 0;
    }


    vector<vector<double>> A(n, vector<double>(n, 0.0));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            A[i][j] = (rand() % 9 + 1);
        }
    }

    vector<double> G(n);

    int repeats = 50;

    for (int test = 1; test <= 5; test++) {
        clock_t t1 = clock();

        for (int r = 0; r < repeats; r++) {

            for (int col = 0; col < n; col++) {

                double sum_log = 0.0;
                int count = 0;

                for (int row = col; row < n; row++) {
                    sum_log += log(A[row][col]);
                    count++;
                }

                G[col] = exp(sum_log / count);
            }
        }

        clock_t t2 = clock();

        double dt = (double)(t2 - t1) / CLOCKS_PER_SEC;

        cout << "Measurement " << test
            << ": time = " << fixed << setprecision(6) << dt
            << " seconds\n";
    }

    cout << "\nVector of geometric means (first 10 values):\n";
    for (int i = 0; i < min(n, 10); i++)
        cout << G[i] << " ";

    cout << "\nDone.\n";
    return 0;
}
