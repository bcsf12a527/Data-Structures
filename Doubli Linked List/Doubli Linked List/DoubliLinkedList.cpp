# include "DoubliLinkedList.hpp"

// Initializing List

template <class Object>
void DoubliLinkedList<Object>::Initialization()
{
	size = 0 ;
	head = new ListNode ;
	tail = new ListNode ;
	head->next = tail ;
	tail->previous = head ;
}

// Copy and Move Constructors, as well as Default Constructor

template <class Object>
DoubliLinkedList<Object>::DoubliLinkedList()
{
	Initialization() ;
}

template <class Object>
DoubliLinkedList<Object>::DoubliLinkedList( const DoubliLinkedList &rhs )
{
	Initialization();
	for( DoubliLinkedList<Object>::const_iterator itr = rhs.Begin() ; itr != rhs.End() ; itr++ )
	{
		Push_back( *itr ) ;
	}
}

template <class Object>
DoubliLinkedList<Object>::DoubliLinkedList(DoubliLinkedList &&rhs) : size(rhs.size) , head(rhs.head) , tail(rhs.tail)
{
	rhs.size = 0 ;
	rhs.head = NULL ;
	rhs.tail = NULL ;
}

//Destructor
template <class Object>
DoubliLinkedList<Object>::~DoubliLinkedList()
{
	Clear() ;
	delete head ;
	delete tail ;
}

//Copy and Move Assignment Operators

template <class Object>
DoubliLinkedList<Object> & DoubliLinkedList<Object>::operator = ( const DoubliLinkedList &rhs )
{
	DoubliLinkedList copy = rhs ;
	std::swap( *this , copy ) ;
	return *this ;
}

template <class Object>
DoubliLinkedList<Object> & DoubliLinkedList<Object>::operator = ( DoubliLinkedList &&rhs )
{
	std::swap( size , rhs.size ) ;
	std::swap( head , rhs.head ) ;
	std::swap( tail , rhs.tail ) ;

	return *this ;
}
