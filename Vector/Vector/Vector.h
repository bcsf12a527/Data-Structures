#include <iostream>
using namespace std ;

template <class Object>
class Vector
{
	Object *arr ;
	int size ;
	int capacity ;

	void Reserve( const int &, const Object & value = -999 ) ;

public:

	Vector() ;
	Vector( const int & , const Object & value = -999);
	Vector( const int & , Object && value = -999);
	~Vector();

	void Resize(const int &, const Object& value = -999) ;
	void Shrink_to_fit() ;

	void InsertValue( const Object& ) ;
	void Display() ;

	Object & operator [] ( const int & ) ;
	const Object operator [] (const int &) const ;

	template<class temp>
	friend ostream & operator << ( ostream & , const Vector<temp> &) ;
};

