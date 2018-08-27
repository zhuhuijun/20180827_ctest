#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct MyNode
{
	int nodeData = 0;
	MyNode *pLeft = nullptr;
	MyNode *pRight = nullptr;
} BTree, *pBTree;

void showTree(MyNode *pRoot, int n)
{
	if (pRoot == nullptr)
	{
		return;
	}
	else
	{
		showTree(pRoot->pRight, n + 1);
		for (int i = 0; i < n; i++)
		{
			std::cout << "  ";
		}
		std::cout << pRoot->nodeData << std::endl;
		showTree(pRoot->pLeft, n + 1);
	}

}
int main(int arg,char *args[])
{
	MyNode *pRoot = nullptr;
	MyNode sarry[100];
	pRoot = sarry;
	for (int i = 0; i < 100; i++)
	{
		sarry[i].nodeData = i;
	}
	for (int i = 0; i <= 50 ; i++)
	{
		if (i < (99-1)/2)
		{
			sarry[i].pLeft = &sarry[2*i+1];
		}
		if(i < (99-2)/2)
		{
			sarry[i].pRight = &sarry[2*i+2];
		}
	}
	showTree(pRoot,1);
	std::cout<<"hello"<<std::endl;
	std::cin.get();
	return 1;
}