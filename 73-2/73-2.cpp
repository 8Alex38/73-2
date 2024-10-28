#include <iostream>
#include <iomanip>
using namespace std;

void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
bool CountPositiveAfterZero(int** a, const int rowCount, const int colCount, int& count);
int CountPositiveAfterZeroInColumn(int** a, const int rowCount, int col, int index, bool& foundZero);
int CountPositiveInRow(int** a, const int rowCount, int col, int row, bool& foundZero);

void FindSaddlePoints(int** a, const int rowCount, const int colCount);
bool IsMaxInRow(int** a, const int n, const int k, const int colCount);
bool IsMinInCol(int** a, const int n, const int k, const int rowCount);

int main() {
    int rowCount, colCount;

    cout << "k = "; cin >> rowCount;
    cout << "n = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int count = 0;
    if (CountPositiveAfterZero(a, rowCount, colCount, count))
        cout << "Count of positive elements after zeroes = " << count << endl;
    else
        cout << "There are no zero elements" << endl;

    cout << endl;
    FindSaddlePoints(a, rowCount, colCount);
    cout << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Input(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool CountPositiveAfterZero(int** a, const int rowCount, const int colCount, int& count) {
    bool hasZero = false;

    for (int j = 0; j < colCount; j++) {
        bool foundZero = false;
        int columnCount = CountPositiveAfterZeroInColumn(a, rowCount, j, 0, foundZero);
        count += columnCount;
        if (foundZero) {
            hasZero = true;
        }
    }

    return hasZero;
}

int CountPositiveAfterZeroInColumn(int** a, const int rowCount, int col, int index, bool& foundZero) {
    if (index >= rowCount) {
        return 0;
    }

    if (a[index][col] == 0) {
        foundZero = true;
    }

    int count = (foundZero && a[index][col] > 0) ? 1 : 0;
    return count + CountPositiveAfterZeroInColumn(a, rowCount, col, index + 1, foundZero);
}

int CountPositiveInRow(int** a, const int rowCount, int col, int row, bool& foundZero) {
    if (row >= rowCount) {
        return 0;
    }

    if (a[row][col] == 0) {
        foundZero = true;
    }

    int count = (foundZero && a[row][col] > 0) ? 1 : 0;
    return count + CountPositiveInRow(a, rowCount, col, row + 1, foundZero);
}

bool IsMaxInRow(int** a, const int n, const int k, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        if (a[n][j] > a[n][k]) {
            return false;
        }
    }
    return true;
}

bool IsMinInCol(int** a, const int n, const int k, const int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        if (a[i][k] < a[n][k]) {
            return false;
        }
    }
    return true;
}

void FindSaddlePoints(int** a, const int rowCount, const int colCount) {
    cout << "Saddle points: max in row & min in col" << endl;
    cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
    int No = 0;

    for (int n = 0; n < rowCount; n++) {
        for (int k = 0; k < colCount; k++) {
            if (IsMaxInRow(a, n, k, colCount) && IsMinInCol(a, n, k, rowCount)) {
                cout << setw(4) << ++No << setw(6) << n << setw(6) << k << endl;
            }
        }
    }
}
