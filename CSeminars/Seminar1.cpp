// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iomanip>
#include <iostream>

using namespace std;

int factorCycle(int num) {
    int res = 1;
    for (int i = 1; i <= num; i++ ) {
        res *= i;
    }
    return res;
}

int factorRec(int num) {
    if (num == 1) {
        return 1;
    }
    return num * factorRec(num - 1);
}

int maxNum(int* Mas, int len) {
    int res = Mas[0];

    for (int i = 0; i < len; i++) {
        if (Mas[i] > res) res = Mas[i];
    }
    return res;
}

int main()
{
    srand(time(0));
    //cout << factorCycle(10) << ' ' << factorRec(10);
    /*
    int len1, len2;

    cout << "len1: " << endl;
    cin >> len1;
    cout << "len2: " << endl;
    cin >> len2;

    int* Mas1 = new int[len1];
    cout << "Mas1: ";
    for (int i = 0; i < len1; i++) {
        cin >> Mas1[i];
    }

    int* Mas2 = new int[len2];
    cout << "Mas2: " << endl;
    for (int i = 0; i < len2; i++) {
        cin >> Mas2[i];
    }
    int max1 = maxNum(Mas1, len1);
    int max2 = maxNum(Mas2, len2);

    cout << "\nMas in 1: " << max1 << " Max in 2: " << max2 << endl;
    cout << max1 * max2 << endl;
    delete[] Mas1, Mas2;
    */
    int columns = 4;
    int rows = 10;

    int** Mas = new int*[rows];

    for (int i = 0; i < rows; i++) {
        Mas[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            Mas[i][j] = (rand() % 20) - 10;
        }
    }

   
    cout << "\n\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << setw(3) << Mas[i][j] << ' ';
        }
        cout << endl;
    }

    for (int i = 0; i++; i < rows) {
        delete[] Mas[i];
    }

    delete[] Mas;
}
