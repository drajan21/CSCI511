#ifndef _VIDEO_H
#define _VIDEO_H

#include <string>
#include "Media.h"

using namespace std;

class Video: public Media 
{

	public:
		Video(string &cno, string &titl, string &sub, string &desc, string &dist, string &note, string &ser, string &lbl);
        ~Video();
		void display() const;
		bool compare_other(const string &other) const;

	private:
		string description;
		string distributor;
		string series;
		string label;
};

#endif
