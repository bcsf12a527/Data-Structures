#pragma once
template <class Object>
class Queue
{
	Object *data ;
	const int size ;
	int front ;
	int rear ;
public:
	Queue( const int & size = 20 );
	~Queue();

	void Enqueue ( const Object & ) ;
	Object Dequeue () ;
	Object Peek () ;

	bool isFull() ;
	bool isEmpty() ;
};

