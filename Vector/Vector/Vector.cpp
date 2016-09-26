#include "Vector.h"

template <class Object>
Vector<Object>::Vector()
{
	size = 0 ;
	capacity = 0 ;
}

template <class Object>
Vector<Object>::Vector( const int &size, const Object &value )
{
	this->size = size ;
	int i = 1 ;
	while ( size >= (pow(2,i) ) )
	{
		i++ ;
	}
	this->capacity = pow(2,i) ;
	arr = new Object[this->capacity] ;
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = value ;
	}
}

template <class Object>
Vector<Object>::Vector( const int &size, Object &&value )
{
	this->size = size ;
	int i = 1 ;
	while ( size >= (pow(2,i) ) )
	{
		i++ ;
	}
	this->capacity = pow(2,i) ;
	arr = new Object[this->capacity] ;
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = std::move( value ) ;
	}
}

template <class Object>
Vector<Object>::~Vector()
{
	delete []arr ;
	size = capacity = 0 ;
}

template <class Object>
void Vector<Object>::Reserve( const int &size, const Object& value )
{
	int i = 1 ;
	while (size >= ( pow(2, i) ) )
	{
		i++ ;
	}
	this->capacity = pow(2,i) ;
	Object *arr = new Object[this->capacity] ;
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = this->arr[i] ;
	}
	for (int i = this->size; i < this->capacity; i++)
	{
		arr[i] = value ;
	}
	delete []this->arr ;
	/*this->size = size ;*/
	this->arr = arr ;
}

template <class Object>
void Vector<Object>::Resize(const int &size, const Object& value)
{
	if ( size != this->size )
	{
		if ( size < this->size )
		{
			this->size = size ;
		}
		else if ( size > this->capacity )
		{
			Reserve(size, value) ;
			this->size = size ;
		}
		else
		{
			for (int i = this->size; i < size; i++)
			{
				arr[i] = value ;
			}
			this->size = size ;
		}
	}
}

template <class Object>
void Vector<Object>::Shrink_to_fit()
{
	int i = 0 ;
	while (size >= pow(2, i))
	{
		i++ ;
	}
	this->capacity = pow(2, i) ;
	Object *arr = new Object[this->capacity] ;
	this->size = size ;
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = this->arr[i] ;
	}
	delete[]this->arr ;
	this->arr = arr ;
}

template <class Object>
void Vector<Object>::InsertValue(const Object &value )
{
	if ( size == capacity )
	{
		Reserve ( size+1 ) ;
	}
	arr[size++] = value ;
}

template <class Object>
void Vector<Object>::Display()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl ;
	}
}

template <class Object>
Object & Vector<Object>::operator [] (const int &index)
{
	if ( index < 0 || index >= size )
	{
		throw -1 ;
	}
	return arr[index] ;
}

template <class Object>
const Object Vector<Object>::operator [] (const int &index) const
{
	if (index < 0 || index >= size)
	{
		throw - 1 ;
	}
	return arr[index] ;
}

template <class temp>
ostream & operator << (ostream & out , const Vector<temp> &arr)
{
	for (int i = 0; i < arr.size; i++)
	{
		out << arr[i] ;
	}
	return out ;
}