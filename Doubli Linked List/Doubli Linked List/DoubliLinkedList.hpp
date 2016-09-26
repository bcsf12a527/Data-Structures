# include <iostream>
using namespace std;

template <class Object>
class DoubliLinkedList
{
private:

	class ListNode
	{
	public:

		Object data ;
		ListNode *next ;
		ListNode *previous ;

		ListNode( const Object &value = Object() , ListNode *previous = NULL , ListNode *next = NULL )
		{
			this->data = value ;
			this->previous = previous ;
			this->next = next ;
		}

		ListNode(Object &&value = Object() , ListNode *previous = NULL, ListNode *next = NULL)
		{
			this->data = std::move(value) ;
			this->next = next ;
			this->previous = previous ;
		}
	};
	int size ;
	ListNode *head ;					//Node actual objects,only header nodes
	ListNode *tail ;

	void Initialization();
public:
	class const_iterator;
	class const_reverse_iterator;
	class iterator;
	class reverse_iterator;
	class const_iterator
	{
	protected:
		ListNode *current ;

		const_iterator ( ListNode *node )				//Constructor Protected?
		{
			current = node ;
		}

		Object & Retrive () const						//Data Retrival Function
		{
			return current->data ;
		}

	public:

		const_iterator ()
		{
			current = NULL ;
		}

		const Object & operator * () const
		{
			return Retrive() ;
		}
		const DoubliLinkedList & operator -> () const
		{
			return Retrive() ;
		}

		const_iterator & operator = ( const const_reverse_iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}

		const_iterator & operator = ( const_reverse_iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}

		const_iterator & operator = ( const const_iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}
		const_iterator & operator = ( const_iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}

		const_iterator & operator ++ ()
		{
			current = current->next ;
			return *this ;
		}
		const_iterator operator ++ (int)
		{
			const_iterator old = *this ;
			++(*this) ;
			return old ;
		}
		const_iterator operator + ( const int &num )
		{
			for ( int i = 0 ; i < num ; i++ )
			{
				(*this)++ ;
			}

			return *this ;
		}

		const_iterator & operator -- ()
		{
			this->current = this->current->previous ;
			return *this ;
		}
		const_iterator operator -- (int)
		{
			const_iterator old = *this ;
			--(*this) ;
			return old ;
		}
		const_iterator operator - ( const int &num )
		{
			for ( int i = 0 ; i < num ; i++ )
			{
				(*this)-- ;
			}

			return *this ;
		}

		bool operator == ( const const_iterator &rhs )
		{
			return ( this->current == rhs.current ) ;
		}
		bool operator != (const const_iterator &rhs)
		{
			return (this->current != rhs.current) ;
		}

		friend class DoubliLinkedList<Object>;
	};

	class const_reverse_iterator
	{
	protected:
		ListNode *current ;

		const_reverse_iterator ( ListNode *node )				//Constructor Protected?
		{
			current = node ;
		}

		Object & Retrive () const						//Data Retrival Function
		{
			return current->data ;
		}

	public:

		const_reverse_iterator ()
		{
			current = NULL ;
		}

		const_reverse_iterator & operator = ( const const_iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}
		const_reverse_iterator & operator = ( const_iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}
		const_reverse_iterator & operator = ( const const_reverse_iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}
		const_reverse_iterator & operator = ( const_reverse_iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}

		const Object & operator * () const
		{
			return Retrive() ;
		}

		const_reverse_iterator & operator ++ ()
		{
			current = current->next ;
			return *this ;
		}
		const_reverse_iterator operator ++ (int)
		{
			const_reverse_iterator old = *this ;
			++(*this) ;
			return old ;
		}
		const_reverse_iterator operator + ( const int &num )
		{
			for ( int i = 0 ; i < num ; i++ )
			{
				(*this)++ ;
			}

			return *this ;
		}

		const_reverse_iterator & operator -- ()
		{
			this->current = this->current->previous ;
			return *this ;
		}
		const_reverse_iterator operator -- (int)
		{
			const_reverse_iterator old = *this ;
			--(*this) ;
			return old ;
		}
		const_reverse_iterator operator - ( const int &num )
		{
			for ( int i = 0 ; i < num ; i++ )
			{
				(*this)-- ;
			}

			return *this ;
		}

		bool operator == ( const const_reverse_iterator &rhs )
		{
			return ( this->current == rhs.current ) ;
		}
		bool operator != (const const_reverse_iterator &rhs)
		{
			return (this->current != rhs.current) ;
		}

		friend class DoubliLinkedList<Object>;
	};

	class iterator : public const_iterator
	{
	protected:
		ListNode *current ;
		iterator(ListNode *node) : const_iterator(node)				//Const_Iterator Constructor Called
		{
		}

	public:

		iterator()
		{
			current = NULL;
		}

		iterator & operator = ( const const_iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}
		iterator & operator = ( const_iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}
		iterator & operator = ( const const_reverse_iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}
		iterator & operator = ( const_reverse_iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}
		iterator & operator = ( const reverse_iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}

		iterator & operator = ( reverse_iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}
		iterator & operator = ( const iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}
		iterator & operator = ( iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}

		Object & operator * ()
		{
			return const_iterator::Retrive() ;
		}
		const Object & operator * () const
		{
			return const_iterator::operator*() ;
		}

		iterator & operator ++ ()
		{
			this->current = this->current->next ;
			return *this ;
		}
		iterator operator ++ (int)
		{
			iterator old = *this ;
			++(*this) ;
			return old ;
		}
		iterator operator + ( const int &num )
		{
			for ( int i = 0 ; i < num ; i++ )
			{
				(*this)++ ;
			}

			return *this ;
		}

		iterator & operator -- ()
		{
			this->current = this->current->previous ;
			return *this ;
		}
		iterator operator -- (int)
		{
			iterator old = *this ;
			--(*this) ;
			return old ;
		}
		iterator operator - ( const int &num )
		{
			for ( int i = 0 ; i < num ; i++ )
			{
				(*this)-- ;
			}

			return *this ;
		}

		friend class DoubliLinkedList<Object>;
	};

	class reverse_iterator : public const_reverse_iterator
	{
	protected:
		ListNode *current ;
		reverse_iterator(ListNode *node) : const_reverse_iterator(node)				//Const_Iterator Constructor Called
		{
		}

	public:

		reverse_iterator()
		{
		}

		reverse_iterator & operator = ( const iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}
		reverse_iterator & operator = ( iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}
		reverse_iterator & operator = ( const const_iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}
		reverse_iterator & operator = ( const_iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}
		reverse_iterator & operator = ( const reverse_iterator &rhs )
		{
			current = rhs.current ;
			return *this ;
		}
		reverse_iterator & operator = ( reverse_iterator &&rhs )
		{
			current = std::move(rhs.current) ;
			return *this ;
		}

		Object & operator * ()
		{
			return const_reverse_iterator::Retrive() ;
		}
		const Object & operator * () const
		{
			return const_reverse_iterator::operator*() ;
		}

		reverse_iterator & operator ++ ()
		{
			this->current = this->current->previous ;
			return *this ;
		}
		reverse_iterator operator ++ (int)
		{
			reverse_iterator old = *this ;
			++(*this) ;
			return old ;
		}
		reverse_iterator operator + ( const int &num )
		{
			for ( int i = 0 ; i < num ; i++ )
			{
				(*this)++ ;
			}

			return *this ;
		}

		reverse_iterator & operator -- ()
		{
			this->current = this->current->next ;
			return *this ;
		}
		reverse_iterator operator -- (int)
		{
			reverse_iterator old = *this ;
			--(*this) ;
			return old ;
		}
		reverse_iterator operator - ( const int &num )
		{
			for ( int i = 0 ; i < num ; i++ )
			{
				(*this)-- ;
			}

			return *this ;
		}

		friend class DoubliLinkedList<Object>;
	};

	iterator Begin()
	{
		return head->next ;
	}
	const_iterator Begin() const
	{
		return head->next ;
	}
	reverse_iterator RBegin()
	{
		return tail->previous ;
	}
	const_reverse_iterator RBegin() const
	{
		return tail->previous ;
	}

	iterator End()
	{
		return tail ;
	}
	const_iterator End() const
	{
		return tail ;
	}
	reverse_iterator REnd()
	{
		return head ;
	}
	const_reverse_iterator REnd() const
	{
		return head ;
	}

	int Size() const
	{
		return size ;
	}
	bool Empty() const
	{
		return size == 0 ;
	}
	void Clear()
	{
		while ( !Empty() )
		{
			Pop_front() ;
		}
	}

	Object & Front()
	{
		return *Begin() ;
	}
	const Object & Front() const
	{
		return *Begin() ;
	}
	Object & Back()
	{
		return *--End() ;
	}
	const Object & Back() const
	{
		return *--End() ;
	}

	void Push_front( const Object &value )
	{
		Insert( Begin() , value ) ;
	}
	void Push_front( const Object &&value )
	{
		Insert( Begin(), std::move(value) ) ;
	}
	void Push_back( const Object &value )
	{
		Insert( End() , value ) ;
	}
	void Push_back(const Object &&value)
	{
		Insert( End(), std::move(value) ) ;
	}

	void Pop_front()
	{
		Erase( Begin() ) ;
	}
	void Pop_back()
	{
		Erase( --End() ) ;
	}

	iterator Insert ( iterator itr , const Object &value )
	{
		ListNode *node = itr.current ;
		size++ ;
		return ( node->previous = node->previous->next = new ListNode ( value , node->previous , node ) );
	}
	reverse_iterator Insert ( reverse_iterator itr , const Object &value )
	{
		ListNode *node = itr.current ;
		size++ ;
		return ( node->next = node->next->previous = new ListNode ( value , node , node->next ) );
	}
	iterator Insert ( iterator itr , Object &&value )
	{
		ListNode *node = itr.current ;
		size++ ;
		return ( node->previous = node->previous->next = new ListNode ( std::move(value) , node->previous , node ) );
	}
	reverse_iterator Insert ( reverse_iterator itr , Object &&value )
	{
		ListNode *node = itr.current ;
		size++ ;
		return ( node->next = node->next->previous = new ListNode ( std::move(value) , node , node->next ) );
	}

	void Insert_Sorted ( const Object &value )
	{
		iterator itr = Begin() ;
		while ( itr != End() && *itr >= value )
		{
			itr++ ;
		}
		Insert( itr , value ) ;
	}
	void Insert_Sorted ( Object &&value )
	{
		iterator itr = Begin() ;
		while ( itr != End() && *itr >= value )
		{
			itr++ ;
		}
		Insert( itr , std::move(value) ) ;
	}
	
	iterator Erase ( iterator itr )
	{
		ListNode *node = itr.current ;
		iterator retVal ( node->next ) ;
		node->previous->next = node->next ;
		node->next->previous = node->previous ;
		delete node ;
		size-- ;

		return retVal ;
	}
	reverse_iterator Erase ( reverse_iterator itr )
	{
		ListNode *node = itr.current ;
		reverse_iterator retVal ( node->previous ) ;
		node->next->previous = node->previous ;
		node->previous->next = node->next ;
		delete node ;
		size-- ;

		return retVal ;
	}
	iterator Erase ( iterator from , iterator to )
	{
		iterator itr = from ;
		while ( itr != to )
		{
			itr =  Erase( itr ) ;
		}
		return to ;
	}
	reverse_iterator Erase ( reverse_iterator from , reverse_iterator to )
	{
		reverse_iterator itr = from ;
		while ( itr != to )
		{
			itr = Erase( itr ) ;
		}
		return to ;
	}

	void Erase ( const Object &value )
	{
		iterator itr = Begin() ;
		while ( *itr != value )
		{
			itr++ ;
			if ( itr == End() )
			{
				return ;
			}
		}
		Erase( itr ) ;
	}
	void Erase ( Object &&value )
	{
		iterator itr = Begin() ;
		while ( *itr != value )
		{
			itr++ ;
			if ( itr == End() )
			{
				return ;
			}
		}
		Erase( itr ) ;
	}

	DoubliLinkedList();
	DoubliLinkedList( const DoubliLinkedList & );
	DoubliLinkedList( DoubliLinkedList && );

	~DoubliLinkedList();

	DoubliLinkedList & operator = ( const DoubliLinkedList & );
	DoubliLinkedList & operator = ( DoubliLinkedList && );
};
