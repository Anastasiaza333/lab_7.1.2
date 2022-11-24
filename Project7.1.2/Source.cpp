// Lab_7_1.cpp 
// < Заяць Анастасія> 
// Лабораторна робота № 7.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці. 
// Варіант 8 
#include <iostream> 
#include <iomanip> 
#include <time.h> 
using namespace std;
void Create(int** R, const int rowCount, const int colCount, const int Low,
    const int High, int i, int j);
void Print(int** R, const int rowCount, const int colCount, int i, int j);
void Sort(int** R, const int rowCount, const int colCount, int i0, int i1);
void Change(int** R, const int row1, const int row2, const int colCount, int j);
void Calc(int** R, const int rowCount, const int colCount, int& S, int& k, int i, int j);
int main()
{
    srand((unsigned)time(NULL));
    int Low = -12;
    int High = 37;
    int rowCount = 7;
    int colCount = 9;
    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];
    Create(R, rowCount, colCount, Low, High, 0, 0);
    Print(R, rowCount, colCount, 0, 0);
    Sort(R, rowCount, colCount, 0, 0);
    Change(R, rowCount, colCount, 0, 0);
    Print(R, rowCount, colCount, 0, 0);
   
    int S = 0;
    int k = 0;
    Calc(R, rowCount, colCount, S, k, 0, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(R, rowCount, colCount, 0, 0);
    for (int i = 0; i < rowCount; i++)
        delete [] R[i];
    delete [] R;

    return 0;
}
void Create(int** R, const int rowCount, const int colCount, const int Low,
    const int High, int i, int j)
{
    if (i < rowCount) {
        if (j < colCount) {
            R[i][j] = Low + rand() % (High - Low + 1);
            Create(R, rowCount, colCount, Low, High, i, j + 1);
        }
        Create(R, rowCount, colCount, Low, High, i + 1, j);
    }
}
void Print(int** R, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << R[i][j];
    if (j < colCount - 1)
        Print(R, rowCount, colCount, i, j + 1);
    else
        if (i < rowCount - 1)
        {
            cout << endl;
            Print(R, rowCount, colCount, i + 1, 0);
        }
        else
            cout << endl<< endl;
}
void Sort(int** R, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 < rowCount - 1) {
        if (i1 < rowCount - i0 - 1) {
            if ((R[i1][0] > R[i1 + 1][0])
                ||
                (R[i1][0] == R[i1 + 1][0] &&
                    R[i1][1] > R[i1 + 1][1])
                ||
                (R[i1][0] == R[i1 + 1][0] &&
                    R[i1][1] == R[i1 + 1][1] &&
                    R[i1][2] > R[i1 + 1][2]))
                Change(R, i1, i1 + 1, rowCount, 0);
            Sort(R, rowCount, colCount, i0, i1 + 1);
        }
        Sort(R, rowCount, colCount, i0 + 1, i1);
    }

}
void Change(int** R, const int col1, const int col2, const int rowCount, int j)
{
    int tmp;
    if (j < rowCount)
    {
        tmp = R[j][col1];
        R[j][col1] = R[j][col2];
        R[j][col2] = tmp;
        Change(R, col1, col2, rowCount, j + 1);
    }
}
void Calc(int** R, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
  
    if (i < rowCount)
        if (j < colCount) {
            if (R[i][j] > 0 || !(R[i][j] % 3 == 0))
            {
                S += R[i][j];
                k++;
                R[i][j] = 0;
                Calc(R, rowCount, colCount, S, k, i, j + 1);

            }
       
            Calc(R, rowCount, colCount, S, k, i + 1, j);

        }
}