/*
7-2 一元多项式的乘法与加法运算
    使用单链表实现
https://pintia.cn/problem-sets/15/problems/710
 */

#include <iostream>
#include <tuple>

typedef int Coefficient;
typedef int Index;
using ElementType=std::tuple<Coefficient, Index>;

class LNode {
	typedef typedef struct LNode *PtrToLNode;
	typedef PtrToLNode Position;
	typedef PtrToLNode List;
private:
    ElementType Data;
    PtrToLNode Next;
public:
	Position Find(ElementType X);
	List Insert(ElementType X, Position P);
	List Delete(Position P);
};

int main(int argc, char* argv[]) {

	return 0;
}