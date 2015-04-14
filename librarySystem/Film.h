#ifndef _FILM_H
#define _FILM_H

#include <string>
#include "Media.h"

using namespace std;

class Film: public Media 
{

	public:
		Film(string &cno, string &titl, string &sub, string &dir, string &note, string &yr);
        ~Film();
		void display() const;
		bool compare_other(const string &other) const;

	private:
		string director;
		string year;
};

#endif
