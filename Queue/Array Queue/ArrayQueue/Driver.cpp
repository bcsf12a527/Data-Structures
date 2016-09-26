# include "Queue.cpp"
# include <string>
# include <iostream>
using namespace std ;

void main ()
{
	Queue<int> queue(50) ;

	for (size_t i = 0; i < 49; i++)
	{
		queue.Enqueue(1) ;
	}

	try
	{
		queue.Enqueue(1) ;
	}
	catch (char *name)
	{
		cout << name ;
	}
}