#include <iostream>
#include "Media.h"
#include "Book.h"

using namespace std;


Media::Media(string &cNo, string & titl, string &sub, string &note)
{
	this->callNo = cNo;
	this->title = titl;
	this->subjects = sub;
	this->notes = note;
}

Media::~Media()
{
}

bool Media::compare_callNumber(const string &callNum) const
{
	if(this->callNo.find(callNum) != std::string::npos)
	{
		return true;
	}
	else
		return false;
}

bool Media::compare_title(const string &title) const
{
	if(this->title.find(title) != std::string::npos)
	{
		return true;
	}
	else
		return false;
}

bool Media::compare_subject(const string &subject) const
{
	if(this->subjects.find(subject) != std::string::npos)
	{
		return true;
	}
	else
		return false;
}


void Media::display() const
{
	cout<<"Call Number------------"<<this->callNo<<endl;
	cout<<"Title------------------"<<this->title<<endl;
	cout<<"Subject----------------"<<this->subjects<<endl;
}
