#ifndef _MEDIA_H
#define _MEDIA_H

#include <string>

using namespace std;

class Media {

	public:
		Media(string &cNo, string &titl, string &sub, string &note);
        virtual ~Media();
		virtual void display() const;
		bool compare_callNumber(const string &callNumber) const;
		bool compare_title(const string &title) const;
		bool compare_subject(const string &subject) const;
		virtual bool compare_other(const string &other) const= 0;

	private:
		string callNo;
		string title;
		string subjects;

	protected:
		string notes;

};

#endif
