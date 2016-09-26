# pragma once
# include "HashTable.h"

template <typename HashedObj>	
void HashTable<HashedObj>::makeEmpty()
{
	vector< list<HashedObj> >::iterator itr = theLists.begin() ;
	for (; itr != theLists.end() ; itr++)
	{
		(*itr).clear() ;										//Remove all the lists one by one
	}
}

template <typename HashedObj>
bool HashTable<HashedObj>::contains( const HashedObj & x ) const
{
	list<HashedObj> whichlist = theLists[ myhash( x ) ] ;
	list<HashedObj>::iterator itr = whichlist.begin() ;
	for ( ; itr != whichlist.end() ; itr++)
	{
		if ( *itr == x )
		{
			return true ;										//Object is found in the list
		}
	}
	return false ;												//Itrator has traversed through the list and did not find object
}

template <typename HashedObj>
bool HashTable<HashedObj>::remove( const HashedObj & x )
{
	list<HashedObj> whichList = theLists[ myhash( x ) ] ;
	list<HashedObj>::iterator itr = whichlist.begin() ;
	for ( ; itr != whichlist.end() ; itr++)
	{
		if ( *itr == x )
		{
			break ;										//Object is found in the list
		}
	}
	if ( itr == whichlist.end() )
	{
		return false ;									//Object was not found in the list
	}
	whichList.erase( itr ) ;							//Position of where the object was found in the list
	--currentSize;
	return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert( const HashedObj & x )
{
	list<HashedObj> whichList = theLists[ myhash( x ) ] ;
	list<HashedObj>::iterator itr = whichlist.begin() ;
	for ( ; itr != whichlist.end() ; itr++)
	{
		if ( *itr == x )
		{
			return false ;										//Object is already in the list
		}
	}
	whichList.push_back( x ) ;
	if( ++currentSize > theLists.size( ) )						//Objects have increased the Universe size. We could go on adding the objects to linked-list. But it would be better to increase the hash table size.
	{
		rehash() ;
	}
	return true ;
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert( HashedObj && x )
{
	list<HashedObj> whichlist = theLists[ myhash( x ) ] ;
	list<HashedObj>::iterator itr = whichlist.begin() ;
	for ( ; itr != whichlist.end() ; itr++)
	{
		if ( *itr == x )
		{
			return false ;										//Object is already in the list
		}
	}
	whichlist.push_back( x ) ;
	if( ++currentSize > theLists.size() )						//Objects have increased the Universe size. We could go on adding the objects to linked-list. But it would be better to increase the hash table size.
	{
		rehash() ;
	}
	return true ;
}

template <typename HashedObj>
void HashTable<HashedObj>::rehash()
{
	theLists.resize( theLists.size() + 5 ) ;
}

template <typename HashedObj>
int HashTable<HashedObj>::myhash( const HashedObj & x ) const
{
	static Hash<HashedObj> Hashfunction;
	return Hashfunction( x ) % theLists.size();
}