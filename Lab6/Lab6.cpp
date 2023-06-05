#include <iostream>
#include <cstdlib>

const int MAX_ROWS = 100; // Максимальное количество строк
const int MAX_COLS = 100; // Максимальное количество столбцов
using namespace std;
// Функция для подсчета количества строк с нулевым элементом
int countZero(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        bool hasZero = false;
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                hasZero = true;
                break;
            }
        }
        if (hasZero)
            count++;
    }
    return count;
}

// Функция для нахождения номера столбца с самой длинной серией одинаковых элементов
int findColumn(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    int longestColumn = -1;
    int longestLength = 0;

    for (int j = 0; j < cols; j++)
    {
        int currentLength = 1;
        for (int i = 1; i < rows; i++)
        {
            if (matrix[i][j] == matrix[i - 1][j])
            {
                currentLength++;
            }
            else
            {
                if (currentLength > longestLength)
                {
                    longestLength = currentLength;
                    longestColumn = j;
                }
                currentLength = 1;
            }
        }

        if (currentLength > longestLength)
        {
            longestLength = currentLength;
            longestColumn = j;
        }
    }

    return longestColumn;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;
    auto input_int = [](const string& prompt, int& val)
    {
        while (true)
        {

            cout << prompt;
            if (cin >> val)
            {
                if (val > 0) {
                    break;

                }/*
                break;*/
            }
            
            cout << "Ошибка: введено некорректное значение! Повторите ввод.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
    };

    input_int("Введите количество строк матрицы : ", rows);
    input_int("Введите количество столбцов матрицы : ", cols);
    

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int rowsZero = countZero(matrix, rows, cols);
    cout << "Количество строк, содержащих хотя бы один нулевой элемент: " << rowsZero << endl;

    int longestColumn = findColumn(matrix, rows, cols);
    cout << "Номер столбца с самой длинной серией одинаковых элементов: " << longestColumn << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int q = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 10)
                q++;
        }
    }
    return 0;
}