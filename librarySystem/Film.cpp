#include <iostream>
#include "Film.h"
#include "Media.h"
#include <sstream>

using namespace std;

Film::Film(string &cno, string &titl, string &sub, string &dir, string &note, string &yr)
  : Media(cno, titl, sub, note), director(dir), year(yr)
{
}

Film::~Film()
{
}

void Film::display() const
{
	cout<<"--------------Film Details----------------------------------------"<<endl;
	Media::display();
	cout<<"Director---------------"<<this->director<<endl;
	cout<<"Notes------------------"<<this->notes<<endl;
	cout<<"Year-------------------"<<this->year<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
}

bool Film::compare_other(const string &other) const
{
	if((this->director.find(other) != std::string::npos) ||
		(this->notes.find(other) != std::string::npos) ||
		(this->year.find(other) != std::string::npos))
	{
		return true;
	}
	else
		return false;
}
