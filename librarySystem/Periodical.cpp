#include <iostream>
#include "Periodical.h"
#include "Periodical.h"
#include <sstream>

using namespace std;

Periodical::Periodical(string &cno, string &titl, string &sub, string &auth, string &desc, string &publ, string &publishingHist
    , string &ser, string &note, string &relatedTit, string &otherTitles, string &govDocNum) :
    Media(cno, titl, sub, note), author(auth), description(desc), publisher(publ), publishingHistory(publishingHist),
    series(ser), relatedTitles(relatedTit), otherFormsOfTitle(otherTitles), govtDocNumber(govDocNum)
{
}

Periodical::~Periodical()
{
}

void Periodical::display() const
{
	cout<<"----------------------Periodical Details-------------------------"<<endl;
	Media::display();
	cout<<"Author-----------------"<<this->author<<endl;
	cout<<"Description------------"<<this->description<<endl;
	cout<<"Publisher--------------"<<this->publisher<<endl;
	cout<<"Publishing History-----"<<this->publishingHistory<<endl;
	cout<<"Series-----------------"<<this->series<<endl;
	cout<<"Notes------------------"<<this->notes<<endl;
	cout<<"Related Titles---------"<<this->relatedTitles<<endl;
	cout<<"Other Forms of Title---"<<this->otherFormsOfTitle<<endl;
	cout<<"Govt. Doc Number-------"<<this->govtDocNumber<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
}

bool Periodical::compare_other(const string &other) const
{
	if((this->description.find(other) != std::string::npos) ||
		(this->notes.find(other) != std::string::npos) ||
		(this->series.find(other) != std::string::npos) ||
		(this->relatedTitles.find(other) != std::string::npos))
	{
		return true;
	}
	else
		return false;
}



