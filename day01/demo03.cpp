#include <iostream>
#include <stack>

using namespace std;
int getF(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return getF(n - 1) + getF(n - 2);
    }
}

int GetFF(int n)
{
    int *p = new int[n];
    p[0] = p[1] = 1;
    for (int i = 2; i < n; i++)
    {
        p[i] = p[i - 1] + p[i - 2];
    }
    return p[n - 1];
}
int GetFFF(int n)
{
    int f1, f2, f3;
    f1 = f2 = 1;
    for (int i = 2; i < n; i++)
    {
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}
int GetFFFF(int n)
{
    stack<int> mstack;
    int f1, f2, f3;
    f1 = f2 = 1;
    int i = 2;
ABC: if (i < n)
    {
        f3 = 0;
        mstack.push(f1);
        mstack.push(f2);
        while (!mstack.empty())
        {
            f3 += mstack.top();
            mstack.pop();
        }
        f1 = f2;
        f2 = f3;
        i++;
        goto ABC;
    }
    return f3;
}
int main(int arg, char *args[])
{
    std::cout << getF(10) << std::endl;
    std::cout << GetFF(10) << std::endl;
    std::cout << GetFFF(10) << std::endl;
    std::cout << GetFFFF(10) << std::endl;
    std::cin.get();
    return 1;
}