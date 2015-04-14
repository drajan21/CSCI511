#ifndef _BOOK_H
#define _BOOK_H

#include <string>
#include "Media.h"

using namespace std;

class Book: public Media 
{

	public:
		Book(string &cno, string &titl, string &sub, string &auth, string &desc, string &publ, string &cit, string &yr, 
			string &ser, string &note);
        ~Book();
		void display() const;
		bool compare_other(const string &other) const;
	
	private:
		string author;
		string description;
		string publisher;
		string city;
		string year;
		string series;
};

#endif
