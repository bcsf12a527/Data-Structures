# include "Queue.cpp"

void main ()
{
	Queue<int> queue ;

	queue.Enque(15) ;
	queue.Enque(10) ;
	queue.Enque(9) ;

	if ( !queue.isEmpty() )
	{
		cout << queue.Peek() << endl ;
	}
	queue.Deque() ;
	queue.Deque() ;
	queue.Deque() ;
	if ( !queue.isEmpty() )
	{
		cout << queue.Peek() << endl ;
	}
}