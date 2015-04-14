#include <iostream>
#include "Video.h"
#include <sstream>

using namespace std;

 Video::Video(string &cno, string &titl, string &sub, string &desc, string &dist, string &note, string &ser, string &lbl)
        : Media(cno, titl, sub, note), description(desc), distributor(dist), series(ser), label(lbl)
 {
 }


Video::~Video()
{
}

void Video::display() const
{
	cout<<"--------------Video Details---------------"<<endl;
	Media::display();
	cout<<"Description------------"<<this->description<<endl;
	cout<<"Distributor------------"<<this->distributor<<endl;
	cout<<"Notes------------------"<<this->notes<<endl;
	cout<<"Series-----------------"<<this->series<<endl;
	cout<<"Label------------------"<<this->label<<endl;
	cout<<"------------------------------------------"<<endl;
}

bool Video::compare_other(const string &other) const
{
	if((this->description.find(other) != std::string::npos) ||
		(this->notes.find(other) != std::string::npos) ||
		(this->distributor.find(other) != std::string::npos))
	{
		return true;
	}
	else
		return false;
}
