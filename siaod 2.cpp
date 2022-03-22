#define ROWS 3
#define COLS 5
#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <set>
#include <algorithm>

// Задания 1, 2
// Дана матрица размером n*m. Операция сглаживания матрицы дает новую матрицу того же размера, 
// каждый элемент которой получается, как среднее арифметическое соседей соответствующего элемента 
// исходной матрицы. Построить результат сглаживания заданной матрицы.
// Задание 3. Найти решение системы линейных алгебраических уравнений методом Гаусса.

void print_matrix(const int m[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++) {
            std::cout << std::setw(5) << m[i][j];

            if (j != ROWS)
                std::cout << " ";
        }
        if (i != COLS)
            std::cout << std::endl;
    }
}

void print_matrix(int** m, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(5) << m[i][j];

            if (j != rows)
                std::cout << " ";
        }
        if (i != cols)
            std::cout << std::endl;
    }
}

void gen_matrix(int m[ROWS][COLS], int min = -25, int max = 25)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(min, max);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            m[i][j] = uniform_dist(e1);
    }
}

int** gen_matrix(int rows, int cols, int min = -25, int max = 25)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(min, max);

    int** m = (int**)malloc(sizeof(int) * rows);

    for (int i = 0; i < rows; i++)
    {
        m[i] = (int*)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++)
            m[i][j] = uniform_dist(e1);
    }

    return m;
}

// реализация для статического массива (для динамического массива реализация аналогична)
void fill_matrix(int m[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            std::cin >> m[i][j];
    }
}

void smooth_matrixes(const int m1[ROWS][COLS], int result[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
        {
            if (i == 0) // верхняя строка
            {
                if (j == 0)
                    result[i][j] = (m1[i + 1][j] + m1[i][j + 1]) / 2;
                else if (j == COLS - 1)
                    result[i][j] = (m1[i + 1][j] + m1[i][j - 1]) / 2;
                else
                    result[i][j] = (m1[i + 1][j] + m1[i][j + 1] + m1[i][j - 1]) / 2;
            }
            else if (i == ROWS - 1) // нижняя строка
            {
                if (j == 0)
                    result[i][j] = (m1[i - 1][j] + m1[i][j + 1]) / 2;
                else if (j == COLS - 1)
                    result[i][j] = (m1[i - 1][j] + m1[i][j - 1]) / 2;
                else
                    result[i][j] = (m1[i - 1][j] + m1[i][j + 1] + m1[i][j - 1]) / 2;
            }
            else
            {
                if (j == 0)
                    result[i][j] = (m1[i - 1][j] + m1[i][j + 1] + m1[i + 1][j]) / 2;
                else if (j == COLS - 1)
                    result[i][j] = (m1[i - 1][j] + m1[i][j - 1] + m1[i + 1][j]) / 2;
                else
                    result[i][j] = (m1[i - 1][j] + m1[i + 1][j] + m1[i][j + 1] + m1[i][j - 1]) / 2;
            }
        }
}

int** smooth_matrixes(int** m1, int rows, int cols)
{
    int** result = (int**)malloc(sizeof(int) * rows);

    for (int i = 0; i < rows; i++)
    {
        result[i] = (int*)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++)
        {
            if (i == 0) // верхняя строка
            {
                if (j == 0)
                    result[i][j] = (m1[i + 1][j] + m1[i][j + 1]) / 2;
                else if (j == cols - 1)
                    result[i][j] = (m1[i + 1][j] + m1[i][j - 1]) / 2;
                else
                    result[i][j] = (m1[i + 1][j] + m1[i][j + 1] + m1[i][j - 1]) / 2;
            }
            else if (i == rows - 1) // нижняя строка
            {
                if (j == 0)
                    result[i][j] = (m1[i - 1][j] + m1[i][j + 1]) / 2;
                else if (j == cols - 1)
                    result[i][j] = (m1[i - 1][j] + m1[i][j - 1]) / 2;
                else
                    result[i][j] = (m1[i - 1][j] + m1[i][j + 1] + m1[i][j - 1]) / 2;
            }
            else // любая другая строка
            {
                if (j == 0)
                    result[i][j] = (m1[i - 1][j] + m1[i][j + 1] + m1[i + 1][j]) / 2;
                else if (j == cols - 1)
                    result[i][j] = (m1[i - 1][j] + m1[i][j - 1] + m1[i + 1][j]) / 2;
                else
                    result[i][j] = (m1[i - 1][j] + m1[i + 1][j] + m1[i][j + 1] + m1[i][j - 1]) / 2;
            }
        }

    }
    return result;
}
/* 
(реализовал по-другому)
void print_matrix(const std::vector<std::vector<int> >& vec, int numvar = NUMVAR)
{
    for (int i = 0; i < NUMVAR; i++)
    {
        for (int j = 0; j < NUMVAR; j++)
            std::cout << std::setw(5) << vec[i][j];
        std::cout << std::endl;
    }
}

void fill_matrix(std::vector<std::vector<int>> & vec, int numvar = NUMVAR)
{
    int a;
    for (int r = 0; r < numvar; r++)
    {
        std::vector<int> row;
        for (int c = 0; c < numvar; c++)
        {
            std::cin >> a;
            row.push_back(a);
        }
        vec.push_back(row);
    }
}
*/
void gauss_slau() 
{
    int num, d, s;
    srand(time(0));
    std::cout << "Input num of vars:" << std::endl;
    std::cin >> num;
    std::vector < std::vector<double>> a(num, std::vector <double>(num + 1));
    double* x = new double[num];
    for (int i = 0; i < num; i++) 
    {
        for (int j = 0; j < num + 1; j++) 
        {
            a[i][j] = (-1000 + rand() % 100000) / 100.0;
            if (j == num) 
                std::cout << std::setw(10) << "= " << a[i][j];
            else 
                std::cout << std::setw(10) << a[i][j] << "x[" << j + 1 << "] ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < num; i++) 
    { 
        for (int j = i + 1; j < num; j++) 
        {
            d = a[j][i] / a[i][i];
            for (int k = i; k < num; k++)
                a[j][k] = a[j][k] - d * a[i][k];
            a[j][num] = a[j][num] - d * a[i][num];
        }
    }
    x[0] = a[num - 1][num] / a[num - 1][num - 1];

    for (int i = num - 1; i >= 0; i--) 
    { 
        d = 0;
        for (int j = i + 1; j < num; j++) 
        {
            s = a[i][j] * x[j];
            d += s;
        }
        x[i] = (a[i][num] - d) / a[i][i];
    }

    std::cout << "Roots: " << std::endl;

    for (int i = 0; i < num; i++)
        std::cout << "x[" << i + 1 << "] = " << x[i] << " " << std::endl;
}

int main()
{
    // 1.
    /*
    int m1[ROWS][COLS];
    int result[ROWS][COLS];

    gen_matrix(m1, 0, 20);

    print_matrix(m1);

    std::cout << std::endl;

    smooth_matrixes(m1, result);

    print_matrix(result);
    */

    // 2.
    /*
    int rows = 3;
    int cols = 5;
    int** m1 = gen_matrix(rows, cols, 1, 10);

    print_matrix(m1, rows, cols);
    std::cout << std::endl;

    int** result = smooth_matrixes(m1, rows, cols);
    print_matrix(result, rows, cols);
    */
    /*
    std::vector < std::vector<int>> matrix;

    fill_matrix(matrix, NUMVAR);
    print_matrix(matrix);
    */
    gauss_slau();
}