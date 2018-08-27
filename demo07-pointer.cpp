#include <iostream>
using namespace std;
void change(int *p)
{
	*p = 100;
}
void change(int **p ,int **p2)
{
	*p = *p2;
}
int main(int arg, char *args[])
{
	int t = 0;
	change(&t);
	std::cout << t << std::endl;
	int tt = 0;
	int *p1 = &tt;
	int ttm = 100;
	int *p2 = &ttm;
	change(&p1,&p2);
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	std::cout << "hello" << std::endl;
	std::cin.get();
	return 1;
}