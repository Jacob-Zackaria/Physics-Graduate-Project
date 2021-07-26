// ABStack
// Andre Berthiaume, May 2017

#ifndef _ABStack
#define _ABStack


class GameObject2D;

// Storage for ABEntities to be recycled
class LinkNode
{
public:
	LinkNode()
		:pEnt(nullptr), pNext(nullptr)
	{ }

	LinkNode* pNext;
	GameObject2D* pEnt;
};

class ABStack
{
private:
	LinkNode* pHead;
	int count;

public:
	ABStack();
	virtual ~ABStack();
	ABStack(const ABStack&) = delete;
	ABStack& operator=(const ABStack&) = delete;

	int Size() const { return count; };
	bool IsEmpty() const { return count == 0; };

	void push(LinkNode* pEnt);
	LinkNode* Pop();


};


#endif _ABStack
