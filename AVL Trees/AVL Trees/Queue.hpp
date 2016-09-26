# pragma once

template <class Object>
class Queue
{
private:

	class ListNode
	{
	public:
		Object data;
		ListNode *next;
		ListNode(Object d)
		{
			data = d;
			next = nullptr;
		}
		/*~ListNode()
		{
			if ( this->next )
			{
				delete this->next ;
			}
		}*/
	};
	
	ListNode *front;
	ListNode *rear;
	int size ;

public:
	Queue() ;
	~Queue() ;

	void Enque(const Object) ;
	Object Deque() ;
	Object Peek() const ;

	bool isEmpty () const ;
};
