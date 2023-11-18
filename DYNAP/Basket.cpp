#include <iostream>
#include <vector>

using namespace std;

double calcularProbabilidad(int n, double P) {
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1.0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = P * dp[i - 1][j] + (1.0 - P) * dp[i][j - 1];
        }
    }

    return dp[n][n];
}

double calcularProbabilidadConVentaja(int n, double PL, double PV) {
    double p1 = PL;
    double p2 = PV;

    double totalProbabilidad = (p1 * calcularProbabilidad(n - 1, p1)) +
                               ((1.0 - p2) * calcularProbabilidad(n - 1, p1));

    return totalProbabilidad;
}

int main() {
    int n = 3;

    double P = 0.5;
    double probabilidadA = calcularProbabilidad(n, P);
    cout << "a. Probabilidad de que Informáticos CB gane el playoff: " << probabilidadA << endl;

    double PL = 0.6;
    double PV = 0.4;
    double probabilidadB = calcularProbabilidadConVentaja(n, PL, PV);
    cout << "b. Probabilidad de ganar con ventaja de campo: " << probabilidadB << endl;
    return 0;
}