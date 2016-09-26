# include "Queue.hpp"
# include "AVLTree.hpp"

template< class type>
type Max ( type first , type second )
{
	if ( first > second )
	{
		return first ;
	}
	return second ;
}

template <class type>
AVLTree <type> :: AVLTree ()
{
	Root = nullptr ;
}

template <class type>
AVLTree <type> :: AVLTree ( const AVLTree &rhs ) 
{
	Root = nullptr ;
	*this = rhs ;
}

template <class type>
AVLTree <type> :: ~AVLTree()
{
	DeleteAll( Root ) ;
}

template <class type>
const AVLTree<type> & AVLTree<type>::operator = ( const AVLTree &rhs )
{
	DeleteAll( Root ) ;
	Root = Clone( rhs.Root ) ;

	return *this ;
}

template <class type>
typename AVLTree <type>::AVLNode* AVLTree <type> :: Clone ( const AVLNode *node )
{
	if ( node == nullptr )
	{
		return nullptr ;
	}
	else
	{
		return new AVLNode( node->data , Clone(node->left) , Clone(node->right ) ) ;
	}
}

template <class type>
void AVLTree <type> :: Delete ( const type input )
{
	Delete( input , Root ) ;
}
template <class type>
void AVLTree <type> :: Delete ( const type input , AVLNode *& node )
{
	if( node == nullptr )
	{
		return;
	}
	if( input < node->data )
	{
		Delete( input, node->left ) ;
	}
	else if( node->data < input )
	{
		Delete( input, node->right ) ;
	}
	else if( node->left != nullptr && node->right != nullptr )
	{
		node->data = FindMinElement() ; ;
		Delete( node->data, node->right ) ;
	}
	else
	{
		AVLNode *oldNode = node ;

		if ( node->left != nullptr )
		{
			node = node->left ;
		}
		else if ( node->right != nullptr )
		{
			node = node->right ;
		}
		if ( node != oldNode )
		{
			delete oldNode;
		}
		else
		{
			delete oldNode ;
			node = nullptr ;
		}
	}

	Balance( node ) ;
}

template <class type>
void AVLTree <type> :: DeleteAll ( AVLNode *node )
{
	if ( node != nullptr )
	{
		if ( node->left != nullptr )
		{
			DeleteAll( node->left ) ;
		}
		if ( node->right != nullptr )
		{
			DeleteAll( node->right ) ;
		}
		delete node ;
	}
	node = nullptr ;
}

template <class type>
void AVLTree <type> :: SetNodeR ( type input )
{
	SetNodeR( Root , input ) ;
}

template <class type>
void AVLTree <type> :: SetNodeR ( AVLNode *&Root , const type &input )
{
	if ( Root == nullptr )
	{
		Root = new AVLNode (input) ;
	}
	else if ( input < Root->data )
	{
		SetNodeR ( Root->left , input ) ;
	}
	else
	{
		SetNodeR ( Root->right , input ) ;
	}

	Balance( Root ) ;
}

template <class type>
void AVLTree <type> :: Balance ( AVLNode *& node )
{
	if ( node == nullptr )
	{
		return ;
	}
	if ( Height( node->left ) - Height( node->right ) > 1 )
	{
		if ( Height( node->left->left ) >= Height( node->left->right ) )
		{
			RotateWithLeftChild( node ) ;
		}
		else
		{
			DoubleRotateWithLeftChild( node ) ;
		}
	}
	else if ( Height( node->right ) - Height( node->left ) > 1 )
	{
		if ( Height( node->right->right ) >= Height( node->right->left ) )
		{
			RotateWithRightChild( node ) ;
		}
		else
		{
			DoubleRotateWithRightChild( node ) ;
		}
	}

	node->height = Max( Height( node->left ) , Height( node->right ) ) + 1 ;
}

template <class type>
typename AVLTree <type>::AVLNode* AVLTree <type> :: FindNode ( const type &input ) const
{
	return FindNode ( Root , input ) ;
}

template <class type>
typename AVLTree <type>::AVLNode* AVLTree <type> :: FindNode ( const AVLNode *Root , const type &input ) const
{
										// Return true if item is one of the items in the binary
										// sort tree to which root points.   Return false if not.
	AVLNode* temp = nullptr ;
	if ( Root == nullptr )
	{
										// Tree is empty, so it certainly doesn't contain item.
		return nullptr ;
	}
	else if ( input == Root->data )
	{
										// Yes, the item has been found in the root node.
		return Root ;
	}
	else if ( input < Root->data )
	{
										// If the item occurs, it must be in the left subtree.
		temp = FindNode ( Root->left , input ) ;
	}
	else
	{
										// If the item occurs, it must be in the right subtree.
		temp = FindNode ( Root->right , input ) ;
	}
	return temp ;
}

template <class type>
bool AVLTree <type> :: Search ( const type &input ) const
{
	return Search ( Root , input ) ;
}

template <class type>
bool AVLTree <type> :: Search (  const AVLNode *Root , const type &input ) const
{
										// Return true if item is one of the items in the binary
										// sort tree to which root points.   Return false if not.
	bool found = false ;
	if ( Root == nullptr )
	{
		return false ;								// Tree is empty, so it certainly doesn't contain item.
	}
	else if ( input == Root->data )
	{
										// Yes, the item has been found in the root node.
		return true ;
	}
	else if ( input < Root->data )
	{
										// If the item occurs, it must be in the left subtree.
		found = Search ( Root->left , input ) ;
	}
	else
	{
										// If the item occurs, it must be in the right subtree.
		found = Search ( Root->right , input ) ;
	}
	return found ;
}

template <class type>
type AVLTree <type> :: FindMaxElementR() const
{
	return FindMaxElementR( Root ) ;
}

template <class type>
type AVLTree <type> :: FindMaxElementR( const AVLNode* node ) const
{
	if ( node == nullptr )
	{
		return nullptr ;
	}
	if ( node->right == nullptr )
	{
		return node->data ;
	}
	
	FindMaxElementR ( node->right ) ;
}

template <class type>
type AVLTree <type> :: FindMaxElement() const
{
	AVLNode* node = Root ;
	while ( node->right != nullptr )
	{
		node = node->right ;
	}
	return node->data ;
}

template <class type>
type AVLTree <type> :: FindMinElementR() const
{
	return FindMinElementR( Root ) ;
}

template <class type>
type AVLTree <type> :: FindMinElementR( const AVLNode* node ) const
{
	if ( node == nullptr )
	{
		return nullptr ;
	}
	if ( node->left == nullptr )
	{
		return node->data ;
	}
	
	FindMinElementR ( node->left ) ;
}

template <class type>
type AVLTree <type> :: FindMinElement() const
{
	AVLNode* node = Root ;
	while ( node->left != nullptr )
	{
		node = node->left ;
	}
	return node->data ;
}

template <class type>
typename AVLTree <type>::AVLNode* AVLTree <type> :: FindMaxNodeR() const
{
	return FindMaxNodeR( Root ) ;
}
template <class type>
typename AVLTree <type>::AVLNode* AVLTree <type> :: FindMaxNodeR( AVLNode* node ) const
{
	if ( node == nullptr )
	{
		return nullptr ;
	}
	if ( node->right == nullptr )
	{
		return node ;
	}
	
	FindMaxNodeR ( node->right ) ;
}
template <class type>
typename AVLTree <type>::AVLNode* AVLTree <type> :: FindMaxNode() const
{
	AVLNode* node = Root ;
	while ( node->right != nullptr )
	{
		node = node->right ;
	}
	return node ;
}

template <class type>
typename AVLTree <type>::AVLNode* AVLTree <type> :: FindMinNodeR() const
{
	return FindMinNodeR( Root ) ;
}
template <class type>
typename AVLTree <type>::AVLNode* AVLTree <type> :: FindMinNodeR( AVLNode* node ) const
{
	if ( node == nullptr )
	{
		return nullptr ;
	}
	if ( node->left == nullptr )
	{
		return node ;
	}
	
	FindMinNodeR ( node->left ) ;
}
template <class type>
typename AVLTree <type>::AVLNode* AVLTree <type> :: FindMinNode() const
{
	AVLNode* node = Root ;
	while ( node->left != nullptr )
	{
		node = node->left ;
	}
	return node ;
}

template <class type>
void AVLTree <type> :: Post_Order_Print() const
{
	Post_Order_Print( Root ) ;
}

template <class type>
void AVLTree <type> :: Post_Order_Print( const AVLNode *Root ) const
{
	if ( Root != nullptr )
	{											// (Otherwise, there's nothing to print.)
		Post_Order_Print ( Root->left ) ;		// Print items in left subtree.
		Post_Order_Print ( Root->right ) ;		// Print items in right subtree.
		cout << Root->data << " " << endl ;				// Print the root item.
	}
}

template <class type>
void AVLTree <type> :: In_Order_Print() const
{
	In_Order_Print( Root ) ;
}

template <class type>
void AVLTree <type> :: In_Order_Print( const AVLNode *Root ) const
{
	if ( Root != nullptr )
	{											// (Otherwise, there's nothing to print.)
		In_Order_Print ( Root->left ) ;			// Print items in left subtree.
		cout << Root->data << " " << endl ;				// Print the root item.
		In_Order_Print ( Root->right ) ;		// Print items in right subtree.
	}
}

template <class type>
void AVLTree <type> :: Pre_Order_Print() const
{
	Pre_Order_Print( Root ) ;
}

template <class type>
void AVLTree <type> :: Pre_Order_Print( const AVLNode *Root ) const
{
	if ( Root != nullptr )
	{											// (Otherwise, there's nothing to print.)
		cout << Root->data << " " << endl ;				// Print the root item.
		Pre_Order_Print ( Root->left ) ;		// Print items in left subtree.
		Pre_Order_Print ( Root->right ) ;		// Print items in right subtree.
	}
}

template <class type>
void AVLTree <type> :: Level_Order_Print() const
{
	Queue< AVLNode* > queue ;
	AVLNode* temp = nullptr ;

	queue.Enque( Root ) ;

	while ( !queue.isEmpty() )
	{
		temp = queue.Deque() ;

		cout << temp->data << endl ;
		if ( temp->left != nullptr )
		{
			queue.Enque( temp->left ) ;
		}
		if ( temp->right != nullptr )
		{
			queue.Enque( temp->right ) ;
		}
	}
}

template <class type>
int AVLTree <type> :: Height( const type &input )
{
	return FindNode( input )->height ;
}

template <class type>
int AVLTree <type> :: Height( const AVLNode* node ) const
{
	if ( node != nullptr )
	{
		return node->height ;
	}
	else
	{
		return -1 ;
	}
}

template <class type>
int AVLTree <type> :: Level( const type &input )
{
	AVLNode *node = FindNode( input ) ;
	AVLNode *temp = Root ;
	int Level = 0 ;

	while ( temp != node )
	{
		if ( node->data < temp->data )
		{
			temp = temp->left ;
		}
		else
		{
			temp = temp->right ;
		}
		Level++ ;
	}
	return Level ;
}

template <class type>
void AVLTree <type> :: ShowMaxPath() const
{
	AVLNode *node = Root ;
	cout << "Maximum path is : " ;
	if ( node != nullptr )
	{
		while ( node != nullptr )
		{
			cout << node->data << " " ;
			if ( Height ( node->left ) > Height( node->right ) )
			{
				node = node->left ;
			}
			else
			{
				node = node->right ;
			}
		}
	}
	cout << endl ;
}

template <class type>
void AVLTree <type> :: RotateWithLeftChild( AVLNode *& node )
{
	AVLNode *temp = node->left ;
	node->left = temp->right ;
	temp->right = node ;
	node->height = Max( Height( node->left ), Height( node->right ) ) + 1 ;
	temp->height = Max( Height( temp->left ), node->height ) + 1 ;
	node = temp ;
}
template <class type>
void AVLTree <type> :: DoubleRotateWithLeftChild( AVLNode *& node )
{
	RotateWithRightChild( node->left ) ;
	RotateWithLeftChild( node ) ;
}
template <class type>
void AVLTree <type> :: RotateWithRightChild( AVLNode *& node )
{
	AVLNode *temp = node->right ;
	node->right = temp->left ;
	temp->left = node ;
	node->height = Max( Height( node->left ), Height( node->right ) ) + 1 ;
	temp->height = Max( Height( temp->right ) , node->height ) + 1 ;
	node = temp ;
}
template <class type>
void AVLTree <type> :: DoubleRotateWithRightChild( AVLNode *& node )
{
	RotateWithLeftChild( node->right ) ;
	RotateWithRightChild( node ) ;
}
