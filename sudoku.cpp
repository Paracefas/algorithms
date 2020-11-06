#include <iostream>
#include <vector>

// Print matrix
template<typename T>
std::ostream& operator<< (std::ostream& os, std::vector<T> v)
{
    os << "[ ";
    for(int i = 0; i < v.size()-1; ++i)
        os << v[i] << ", ";
    os << v[v.size()-1] << " ]\n";
    return os;
}

bool possible (std::vector<std::vector<int>> const& matrix, int y, int x, int n)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        if (matrix[y][i] == n) return false;
        if (matrix[i][x] == n) return false;
    }
    // Check region
    int xr = static_cast<int>(x/3)*3;
    int yr = static_cast<int>(y/3)*3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (matrix[yr+i][xr+i] == n) return false;
    return true;
}

void sudoku (std::vector<std::vector<int>>& m)
{
    for (int y = 0; y < m.size(); ++y)
        for (int x = 0; x < m.size(); ++x)
            if (m[y][x] == 0)
            {
                for (int n = 1; n <= 9; ++n)
                    if (possible(m, y, x, n))
                    {
                        m[y][x] = n;
                        sudoku(m);
                        m[y][x] = 0;
                    }
                return;
            }
    std::cout << m << '\n';
    std::cin.get();
}

int main (int argc, char const** argv)
{
    std::vector<std::vector<int>> matrix =
    {
        { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
        { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
        { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
        { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
        { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
        { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
        { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
        { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
        { 0, 0, 0, 0, 8, 0, 0, 0, 9 }
    };

    std::cout << matrix << '\n';
    sudoku(matrix);
}
