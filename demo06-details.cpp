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
//中序遍历
void zhong(MyNode *pRoot)
{
	if (pRoot != nullptr)
	{
		if (pRoot->pLeft != nullptr)
		{
			zhong(pRoot->pLeft);
		}
		std::cout << " " << pRoot->nodeData << std::endl;
		if (pRoot->pRight != nullptr)
		{
			zhong(pRoot->pRight);
		}
	}
}
/**
 * @brief      use array made
 *
 * @param      proot  The proot
 */
void stackzhong(MyNode *proot)
{
	MyNode *pcur = proot;
	MyNode *mystack[100];
	int top = 0;
	while (pcur != nullptr || top != 0)
	{
		while (pcur != nullptr)
		{
			mystack[top++] = pcur;
			pcur = pcur->pLeft;
		}
		if (top > 0)
		{
			top--;
			pcur = mystack[top];
			std::cout << " " << pcur->nodeData << std::endl;
			pcur = pcur->pRight;
		}
	}
}
/**
 * @brief      use stack
 *
 * @param      proot  The proot
 */
void mystackzhong(MyNode *proot)
{
	MyNode *pcur = proot;
	stack<MyNode *> mystack;
	while (pcur != nullptr || !mystack.empty())
	{
		while (pcur != nullptr)
		{
			mystack.push(pcur);
			pcur = pcur->pLeft;
		}
		if (!mystack.empty())
		{
			pcur = mystack.top();
			std::cout << " " << pcur->nodeData << std::endl;
			mystack.pop();
			pcur = pcur->pRight;
		}
	}
}
/**
 * @brief      Shows the tree.
 *
 * @param      pRoot  The root
 * @param[in]  n     degree
 */
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
			std::cout << "....";
		}
		std::cout << pRoot->nodeData << std::endl;
		showTree(pRoot->pLeft, n + 1);
	}

}
int getFather(MyNode *proot, int num)
{
	if (proot == nullptr)
	{
		return -1;
	}
	if (proot->pLeft != nullptr && proot->pLeft->nodeData == num)
	{
		return proot->nodeData;
	}
	if (proot->pRight != nullptr && proot->pRight->nodeData == num)
	{
		return proot->nodeData;
	}
	getFather(proot->pLeft, num);
	getFather(proot->pRight, num);
}
int getLeft(MyNode *proot, int num)
{
	if (proot == nullptr)
	{
		return -1;
	}
	if (proot->pRight != nullptr && proot->pRight->nodeData == num)
	{
		if (proot->pLeft != nullptr)
		{
			return proot->pLeft->nodeData;
		}

	}
	getLeft(proot->pLeft, num);
	getLeft(proot->pRight, num);
}
int getFather2(MyNode *proot, int num, int *ret)
{
	if (proot == nullptr)
	{
		*ret =  -1;
		return 100;
	}
	if (proot->pLeft != nullptr && proot->pLeft->nodeData == num)
	{
		*ret =  proot->nodeData;
		return 100;
	}
	if (proot->pRight != nullptr && proot->pRight->nodeData == num)
	{
		*ret = proot->nodeData;
		return 100;
	}
	getFather2(proot->pLeft, num, ret);
	getFather2(proot->pRight, num, ret);
	return 0;
}
int main(int arg, char *args[])
{
	MyNode *pRoot = nullptr;
	MyNode s1;
	MyNode s2;
	MyNode s3;
	MyNode s4;
	MyNode s5;
	MyNode s6;
	MyNode s7;
	pRoot = &s1;
	s1.nodeData = 1;
	s2.nodeData = 2;
	s3.nodeData = 3;
	s4.nodeData = 4;
	s5.nodeData = 5;
	s6.nodeData = 6;
	s7.nodeData = 7;

	s1.pLeft = &s2;
	s1.pRight = &s3;

	s2.pLeft = &s4;
	s2.pRight = &s5;

	s3.pLeft = &s6;
	s3.pRight = &s7;

	//showTree(pRoot, 1);
	/*
	zhong(pRoot);
	std::cout<<"use stack "<<std::endl;
	stackzhong(pRoot);
	std::cout<<"use stack "<<std::endl;
	mystackzhong(pRoot);
	*/
	std::cout << getFather(pRoot, 3) << std::endl;
	int m = 0;
	getFather2(pRoot, 3, &m);
	std::cout << m << std::endl;
	std::cout << getLeft(pRoot, 7) << std::endl;

	std::cout << "hello" << std::endl;
	std::cin.get();
	return 1;
}