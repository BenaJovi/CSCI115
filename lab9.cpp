/*  Author: Jovani Benavides
*  Course: CSCI-115
* 
* 
*/

#include <iostream>
using namespace std;

void printOptimalParenthesization(int bracket[100][100], int i, int j, char& matrixName) {
    if (i == j) {
        cout << matrixName++;
        return;
    }
    cout << "(";
    printOptimalParenthesization(bracket, i, bracket[i][j], matrixName);
    printOptimalParenthesization(bracket, bracket[i][j] + 1, j, matrixName);
    cout << ")";
}

void matrixChainOrder(int p[], int n) {
    int m[100][100] = {0}; // Minimum number of scalar multiplications
    int bracket[100][100] = {0}; // To store optimal k

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    char matrixName = 'A';
    cout << "Optimal Parenthesization is : ";
    printOptimalParenthesization(bracket, 0, n - 2, matrixName);
    cout << endl;
    cout << "Optimal Cost is : " << m[0][n - 2] << endl;
}

int main() {
    int p[] = {4, 10, 3, 12, 20, 7}; // Example array of matrix dimensions
    int n = sizeof(p) / sizeof(p[0]);
    matrixChainOrder(p, n);
    return 0;
}
