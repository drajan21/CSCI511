#ifndef _PERIODICAL_H
#define _PERIODICAL_H

#include <string>
#include "Media.h"

using namespace std;

class Periodical: public Media 
{

	public:
		Periodical(string &cno, string &titl, string &sub, string &auth, string &desc, string &publ, string &publishingHist
			, string &ser, string &note, string &relatedTit, string &otherTitles, string &govDocNum);
        ~Periodical();
		void display() const;
		bool compare_other(const string &other) const;

	private:
		string author;
		string description;
		string publisher;
		string publishingHistory;
		string series;
		string relatedTitles;
		string otherFormsOfTitle;
		string govtDocNumber;
};

#endif
