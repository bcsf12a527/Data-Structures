# pragma once
# include <iostream>
# include <string>
# include <vector>
# include <list>
using namespace std ;

template <typename HashedObj>
class HashTable
{
public:

	explicit HashTable( int size = 101 );
	void makeEmpty();
	bool contains( const HashedObj & ) const;
	bool remove( const HashedObj & );

	bool insert( const HashedObj & );
	bool insert( HashedObj && );

private:

	vector< list<HashedObj> > theLists;							// The array of Lists
	size_t currentSize;											// Not the hash table size. That one is stored in "theLists.size()"
	void rehash();
	int myhash( const HashedObj & ) const;

};

template <class Key>
class Hash
{
public:
	int operator() ( const Key & key ) const ;
};

template <>
class Hash<string>
{
public:
	int operator() ( const string & key )
	{
		int hashVal = 0 ;
		for( char ch : key )
		{
			hashVal = 37 * hashVal + ch ;
		}
		return hashVal ;
	}
};