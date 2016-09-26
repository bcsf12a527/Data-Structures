# pragma once
# include "HashTable.cpp"
# include <fstream>

class Student
{
	int id ;						//store the id of a student
	char rollno[11] ;				//store rollno of student
	char name[20] ;					//store the name of a student
	float marks ;					//store the marks of a student

public:

	//constructor
	Student(int id = 0 , char *rollno = NULL , char *name = NULL, float marks = 0.0f)
	{
		this->id = id ;
		strcpy_s ( this->rollno , rollno ) ;
		strcpy_s ( this->name , name ) ;
		this->marks = marks ;
	}

	char* getRollNo ()
	{
		return rollno ;
	}

	//overload stream extraction operator to get data of a student from user
	friend istream & operator >> (istream &in, Student &obj)
	{
		cout << "Enter Student's id : " ;
		in >> obj.id ;

		cout << "Enter Student's name : " ;
		in.getline ( obj.rollno , 11 , '\n' ) ;

		cout << "Enter Student's name : " ;
		in.getline ( obj.name , 20 , '\n' ) ;

		cout << "Enter Student's marks : " ;
		in >> obj.marks ;

		return in ;
	}

	//overload stream insertion operator to display the data of a student
	friend ostream & operator << (ostream &out, const Student &obj)
	{
		out << endl << "The id of Student : " << obj.id ;
		out << endl << "The name of Student : " << obj.name ;
		out << endl << "The marks of Student : " << obj.marks << endl ;

		return out ;
	}

	void addStudent ( ofstream &fout )
	{
		fout.seekp ( 0 , ios::end ) ;
		fout.write( reinterpret_cast<char *>(this) , sizeof(Student) ) ;
	}

	bool findStudent ( ifstream &fin )
	{
		bool flag = false ;
		Student temp ;

		fin.read( reinterpret_cast<char *>(&temp) , sizeof(Student) ) ;

		while ( !fin.eof() )
		{
			flag = temp.id == id ;
			fin.read( reinterpret_cast<char *>(&temp) , sizeof(Student) ) ;
		}

		return flag ;
	}

	void updateMarks ( fstream &fio , float new_marks )
	{
		int count = 1 ;
		Student temp ;
		this->marks = new_marks ;

		fio.open ("student.dat" , ios::in | ios::out | ios::binary ) ;
		fio.seekg( 0 , ios::beg ) ;

		fio.read( reinterpret_cast<char *>(&temp) , sizeof(Student) ) ;
		while ( !fio.eof() )
		{
			if ( temp.id != id )
			{
				int size = sizeof(Student) ;
				fio.seekg( -(size) , ios::cur ) ;
				fio.write ( reinterpret_cast<char *>(this) , sizeof(Student) ) ;
			}
			fio.read( reinterpret_cast<char *>(&temp) , sizeof(Student) ) ;
			count = count + 1 ;
		}

		if ( count <= 1 )
		{
			cout << endl << "File is empty. No data exits." << endl ;
		}
	}

	void deleteStudent ( ifstream &fin )
	{
		int count = 1 ;
		Student temp ;
		ofstream fout ( "student1.dat" , ios::binary ) ; 
		fin.open ("student.dat" , ios::binary ) ;

		fin.read( reinterpret_cast<char *>(&temp) , sizeof(Student) ) ;

		while ( !fin.eof() )
		{
			if ( temp.id != id )
			{
				fout.write ( reinterpret_cast<char *>(&temp) , sizeof(Student) ) ;
			}
			fin.read( reinterpret_cast<char *>(&temp) , sizeof(Student) ) ;
		}

		if ( count <= 1 )
		{
			cout << endl << "File is empty. No data exits." << endl ;
			return ;
		}

		remove("student.dat" ) ;
		rename ( "student1.dat" , "student.dat" ) ;
	}



	//Static Functions
	static void displayAllStudents ( ifstream & ) ;

	
}; 


	

void Student::displayAllStudents ( ifstream &fin )
{
	int count = 1 ;
	Student temp ;

	fin.open ("student.dat" , ios::binary ) ;

	fin.read( reinterpret_cast<char *>(&temp) , sizeof(Student) ) ;

	while ( !fin.eof() )
	{
		cout << "The id of Student " << count << " : " << temp.id << endl ;
		cout << "The rollno of Student" << count << " : " << temp.rollno << endl ;
		cout << "The name of Student" << count << " : " << temp.name << endl ;
		cout << "The marks of Student " << count << " : " << temp.marks << endl << endl ;
		fin.read( reinterpret_cast<char *>(&temp) , sizeof(Student) ) ;
		count = count + 1 ;
	}

	if ( count <= 1 )
	{
		cout << endl << "File is empty. No data exits." << endl ;
	}
}

template<>
class Hash<Student>
{
public:

	int operator() ( Student & student )
	{
		int hashvalue = 0 ;
		char* rollno = student.getRollNo() ;
		if ( rollno[4] == '3' )
		{
			hashvalue = hashvalue + 120 ;
		}
		if ( rollno[5] == 'M' || rollno[6] == 'm' )
		{
			hashvalue = hashvalue + 60 ;
		}

		char* context = NULL ;
		char* ch = strtok_s(rollno , "5\n" , &context ) ;
		ch = strtok_s(NULL , "5\n" , &context  ) ;
		hashvalue = hashvalue + std::atoi( ch ) ;
	}
};