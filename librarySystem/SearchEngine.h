#ifndef _SEARCHENGINE_H
#define _SEARCHENGINE_H

#include <string>
#include "Media.h"
#include <vector>

class SearchEngine {

	public:
        SearchEngine();
        ~SearchEngine();
		const vector<Media *> searchByCallNum(const string &callNumber) const;
		const vector<Media *> searchByTitle(const string &title) const;
		const vector<Media *> searchBySubject(const string &subject) const;
		const vector<Media *> searchByOther(const string &other) const;

	private:
		vector<Media *> cardCatalog;

};

#endif
