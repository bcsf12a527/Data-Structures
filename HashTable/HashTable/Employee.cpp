# pragma once
# include "HashTable.cpp"

// Example of an Employee class that can be hashed
class Employee
{
public:
	Employee ( const string & str )
	{
		name = str  ;
	}
	const string & getName() const
	{
		return name ;
	}
	const string & setName()
	{
		getline( cin , name ) ;
	}
	bool operator == ( const Employee & rhs ) const
	{
		return getName() == rhs.getName() ;
	}
	bool operator != ( const Employee & rhs ) const
	{
		return !( *this == rhs );
	}
	// Additional public members not shown
private:
	string name;
	double salary;
	int seniority;
	// Additional private members not shown
};

template<>
class Hash<Employee>
{
public:
	int operator() ( const Employee & item )
	{
		static Hash<string> Hashfunction;
		return Hashfunction( item.getName() );
	}
};