#include <iostream>
#include <cstdlib>

const int MAX_ROWS = 100; // Максимальное количество строк
const int MAX_COLS = 100; // Максимальное количество столбцов

// Функция для подсчета количества строк с нулевым элементом
int countRowsWithZero(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
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
int findLongestSeriesColumn(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    int longestSeriesColumn = -1;
    int longestSeriesLength = 0;

    for (int j = 0; j < cols; j++)
    {
        int currentSeriesLength = 1;
        for (int i = 1; i < rows; i++)
        {
            if (matrix[i][j] == matrix[i - 1][j])
            {
                currentSeriesLength++;
            }
            else
            {
                if (currentSeriesLength > longestSeriesLength)
                {
                    longestSeriesLength = currentSeriesLength;
                    longestSeriesColumn = j;
                }
                currentSeriesLength = 1;
            }
        }

        if (currentSeriesLength > longestSeriesLength)
        {
            longestSeriesLength = currentSeriesLength;
            longestSeriesColumn = j;
        }
    }

    return longestSeriesColumn;
}

int main()
{
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    std::cout << "Введите количество строк матрицы: ";
    std::cin >> rows;

    std::cout << "Введите количество столбцов матрицы: ";
    std::cin >> cols;

    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    int rowsWithZero = countRowsWithZero(matrix, rows, cols);
    std::cout << "Количество строк, содержащих хотя бы один нулевой элемент: " << rowsWithZero << std::endl;

    int longestSeriesColumn = findLongestSeriesColumn(matrix, rows, cols);
    std::cout << "Номер столбца с самой длинной серией одинаковых элементов: " << longestSeriesColumn << std::endl;

    return 0;
}