#include <iostream>

void move (char const* f, char const* t)
{
    std::cout << "Move from " << f << " to " << t << '\n';
}

void hanoi (int n, char const* f, char const* h, char const* t)
{
    if (n == 0) return;
    hanoi(n-1, f, t, h);
    move(f, t);
    hanoi(n-1, h, f, t);
}

int main (int argc, char const** argv)
{
    hanoi(4, "A", "B", "C");
    return 0;
}
