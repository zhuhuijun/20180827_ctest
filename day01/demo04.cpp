/**
 * 栈模拟递归函数
 */

#include <iostream>
#include <stack>
using namespace std;

struct datas
{
	int n;
	//函数指针
	void (*p)(int);
};
//打印
void print (int n)
{
	std::cout << n << std::endl;
}
void printN(int n)
{
	stack<int> ms;
AAA: if (n > 0)
	{
		ms.push(n);
		while (!ms.empty())
		{
			std::cout << ms.top() << std::endl;
			ms.pop();
		}
		n -= 1;
		goto AAA;
	}
}
void printN2(int n)
{
	stack<datas> ms;
AAA: if (n > 0)
	{
		datas s1;
		s1.n = n;
		s1.p = print;
		ms.push(s1);
		while (!ms.empty())
		{
			datas tmp = ms.top();
			tmp.p(tmp.n);
			ms.pop();
		}
		n -= 1;
		goto AAA;
	}
}
//主函数
int main(int arg, char *args[])
{
	printN(10);
	std::cout<<"printN2..........."<<std::endl;
	printN2(10);
	std::cout << "hello" << std::endl;
	std::cin.get();
	return 1;
}