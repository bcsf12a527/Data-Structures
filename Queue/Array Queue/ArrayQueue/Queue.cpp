#include "Queue.h"

template <class Object>
Queue<Object>::Queue(const int & size ) : size(size)
{
	data = new Object[this->size] ;
	rear = front = 0 ;
}

template <class Object>
Queue<Object>::~Queue()
{
	delete[] data ;
}

template <class Object>
void Queue<Object>::Enqueue (const Object & obj )
{
	if ( !isFull() )
	{
		data[rear] = obj ;
		rear = rear++ % size ;
	}
	else
	{
		throw "Exception thrown" ;
	}
}

template <class Object>
Object Queue<Object>::Dequeue()
{
	if ( !isEmpty() )
	{
		Object temp = data[front] ;
		front = front++ % size ;
		return temp ;
	}
	else
	{
		throw "Exception thrown" ;
	}
}

template <class Object>
Object Queue<Object>::Peek()
{
	if (!isEmpty())
	{
		return data[front] ;
	}
	else
	{
		throw "Exception thrown" ;
	}
}

template <class Object>
bool Queue<Object>::isFull()
{
	return front == ( (rear + 1) % size ) ;
}

template <class Object>
bool Queue<Object>::isEmpty()
{
	return front == rear ;
}
