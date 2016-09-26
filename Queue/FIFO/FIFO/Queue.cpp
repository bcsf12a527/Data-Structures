# include "Queue.h"

template <class Object>
Queue<Object>::Queue()
{
	front = rear = NULL ;
	size = 0 ;
}

template <class Object>
Queue<Object>::~Queue()
{
	ListNode *temp = rear ;
	while ( temp != NULL )
	{
		rear = rear->next ;
		delete temp ;
		size-- ;
		temp = rear ;
	}
}

template <class Object>
void Queue<Object>::Enque(const Object value)
{
	if ( isEmpty() )
	{
		rear = front = new ListNode(value) ;
		size++ ;
	}
	else
	{
		front->next = new ListNode(value) ;
		front = front->next ;
		size++ ;
	}
}

template <class Object>
Object Queue<Object>::Deque()
{
	Object value = Peek() ;
	ListNode *temp = rear ;
	rear = rear->next ;
	delete temp ;
	size-- ;
	return value ;
}

template <class Object>
Object Queue<Object>::Peek() const
{
	if ( !isEmpty() )
	{
		return rear->data ;
	}
	else
	{
		throw -1 ;
	}
}

template <class Object>
bool Queue<Object>::isEmpty() const
{
	return size == 0 ;
}