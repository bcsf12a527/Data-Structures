# include "HashTable.cpp"
# include "Employee.cpp"
# include "StudentClass.cpp"

void main ()
{
	HashTable<Employee> hashtable ;
	string name ;

	for (int i = 0; i < 10; i++)
	{
		cout << endl << "Enter name : " ;
		getline( cin , name ) ;
		hashtable.insert( Employee( name ) ) ;
	}


	for (int i = 0; i < 10; i++)
	{
		cout << endl << "Enter name : " ;
		getline( cin , name ) ;
		if ( hashtable.contains( Employee( name ) ) )
		{
			cout << "HashTable contains the Employee named " << name << endl ;
		}
	}
}