#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            Q[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** Q, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(5) << Q[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Change(int** Q, const int col1, const int col2, const int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        int tmp = Q[i][col1];
        Q[i][col1] = Q[i][col2];
        Q[i][col2] = tmp;
    }
}

void Sort(int** Q, const int rowCount, const int colCount) {
    for (int j0 = 0; j0 < colCount - 1; j0++) {
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++) {
            if ((Q[0][j1] > Q[0][j1 + 1]) ||
                (Q[0][j1] == Q[0][j1 + 1] && Q[1][j1] < Q[1][j1 + 1]) ||
                (Q[0][j1] == Q[0][j1 + 1] && Q[1][j1] == Q[1][j1 + 1] && Q[2][j1] > Q[2][j1 + 1])) {
                Change(Q, j1, j1 + 1, rowCount);
            }
        }
    }
}

void Calc(int** Q, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            // Критерій: всі елементи, КРІМ додатних парних
            if (!(Q[i][j] > 0 && Q[i][j] % 2 == 0)) {
                S += Q[i][j];
                k++;
                Q[i][j] = 0;
            }
        }
    }
}

int main() {
    srand((unsigned)time(NULL));

    const int Low = -26;
    const int High = 23;
    const int rowCount = 8;
    const int colCount = 6;

    int** Q = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        Q[i] = new int[colCount];
    }

    // 1. Формування та виведення початкової матриці
    Create(Q, rowCount, colCount, Low, High);
    cout << "Initial matrix:";
    Print(Q, rowCount, colCount);

    // 2. Впорядкування стовпчиків та виведення
    Sort(Q, rowCount, colCount);
    cout << "Sorted matrix:";
    Print(Q, rowCount, colCount);

    // 3. Обчислення суми, кількості та заміна елементів
    int S = 0;
    int k = 0;
    Calc(Q, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << "Modified matrix:";
    Print(Q, rowCount, colCount);

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++) {
        delete[] Q[i];
    }
    delete[] Q;

    return 0;
}