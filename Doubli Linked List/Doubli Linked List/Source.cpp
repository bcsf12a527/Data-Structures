# include "DoubliLinkedList.hpp"

void main ()
{
	DoubliLinkedList<int> list ;

	list.Push_back(1) ;
	list.Push_back(2) ;
	list.Push_back(3) ;
	list.Push_back(4) ;
	list.Push_back(5) ;
	list.Push_back(6) ;

	list.Erase( ++(list.RBegin()) , --(list.REnd()) ) ;

	DoubliLinkedList<int>::iterator itr = list.Begin() ;
	while ( itr++ != list.End() )
	{
		cout << *itr ;
	}
}
