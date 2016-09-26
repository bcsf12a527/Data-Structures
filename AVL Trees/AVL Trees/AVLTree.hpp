#pragma once
#include <iostream>
using namespace std;

template <class type>
class AVLTree
{
private:

	class AVLNode
	{
	public:

		type data ;
		AVLNode *left ;
		AVLNode *right ;

		int height ;

		AVLNode ( const type & data = type() , AVLNode *left = nullptr , AVLNode *right = nullptr , int height = 0 )
		{
			this->data = data ;
			this->left = left ;
			this->right = right ;

			this->height = height ;
		}
		AVLNode ( type && data = type() , AVLNode *left = nullptr , AVLNode *right = nullptr , int height = 0 )
		{
			this->data = std::move(data) ;
			this->left = left ;
			this->right = right ;

			this->height = height ;
		}
	};

	AVLNode *Root ;

	void Delete ( const type , AVLNode *& );
	void SetNodeR ( AVLNode *& , const type & ) ;

	AVLNode* FindNode ( const AVLNode * , const type & ) const ;
	bool Search ( const AVLNode * , const type & ) const ;

	type FindMaxElementR( const AVLNode* ) const ;
	type FindMinElementR( const AVLNode* ) const ;
	AVLNode* FindMaxNodeR( AVLNode* ) const ;
	AVLNode* FindMinNodeR( AVLNode* ) const ;

	int Height( const AVLNode *) const ;

	void Post_Order_Print ( const AVLNode * ) const ;
	void In_Order_Print ( const AVLNode * ) const ;
	void Pre_Order_Print ( const AVLNode * ) const ;

public:

	AVLTree () ;
	AVLTree ( const AVLTree & ) ;
	~AVLTree() ;

	const AVLTree & operator = ( const AVLTree & ) ;
	AVLNode* Clone ( const AVLNode * ) ;

	void DeleteAll ( AVLNode *);
	void Delete ( const type );
		
	AVLNode* FindNode ( const type & ) const ;
	bool Search ( const type & ) const ;
	void SetNodeR ( type ) ;

	type FindMaxElementR() const ;
	type FindMaxElement() const ;
	type FindMinElementR() const ;
	type FindMinElement() const ;

	AVLNode* FindMaxNodeR() const ;
	AVLNode* FindMaxNode() const ;
	AVLNode* FindMinNodeR() const ;
	AVLNode* FindMinNode() const ;

	void Post_Order_Print () const ;
	void In_Order_Print () const ;
	void Pre_Order_Print () const ;
	void Level_Order_Print () const ;

	void Balance ( AVLNode *& ) ;

	int Height( const type &) ;
	int Level( const type &) ;
	void ShowMaxPath() const ;

	void RotateWithLeftChild( AVLNode *& ) ;
	void DoubleRotateWithLeftChild( AVLNode *& ) ;
	void RotateWithRightChild( AVLNode *& ) ;
	void DoubleRotateWithRightChild( AVLNode *& ) ;
};
