#include <iostream>
#include "Book.h"
#include "Media.h"
#include <sstream>

using namespace std;

 Book::Book(string &cno, string &titl, string &sub, string &auth, string &desc, string &publ, string &cit, string &yr,
 string &ser, string &note) : Media(cno, titl, sub, note), author(auth), description(desc), publisher(publ),city(cit), year(yr), 
 series(ser)
 {
 }


Book::~Book()
{
}

void Book::display() const
{
	cout<<"--------------Book Details-------------------------------------"<<endl;
	Media::display();
	cout<<"Author-----------------"<<this->author<<endl;
	cout<<"Description------------"<<this->description<<endl;
	cout<<"Publisher--------------"<<this->publisher<<endl;
	cout<<"City-------------------"<<this->city<<endl;
	cout<<"Year-------------------"<<this->year	<<endl;
	cout<<"Series-----------------"<<this->series<<endl;
	cout<<"Notes------------------"<<this->notes<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
}

bool Book::compare_other(const string &other) const
{
	if((this->description.find(other) != std::string::npos) ||
		(this->notes.find(other) != std::string::npos) ||
		(this->year.find(other) != std::string::npos))
	{
		return true;
	}
	else
		return false;
}
