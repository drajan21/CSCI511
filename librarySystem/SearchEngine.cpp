#include <iostream>
#include <string>
#include "SearchEngine.h"
#include "Book.h"
#include "Video.h"
#include "Film.h"
#include "Periodical.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>

using namespace std;

SearchEngine::SearchEngine()
{
	string callnumber;
	string title;
	string subjects;
	string author;
	string description;
	string publisher;
	string city;
	string year;
	string series;
	string notes;

	fstream fsBook;

	//Reading the Books 
	fsBook.open("book.txt");
	if(fsBook==NULL)
		cout<<"Error while reading book.txt"<<endl;
	//Read book.txt line by line
	while(!getline(fsBook, callnumber, '|').eof() )
	{
		getline(fsBook, title,'|');
		getline(fsBook, subjects,'|');
		getline(fsBook, author,'|');
		getline(fsBook, description,'|');
		getline(fsBook, publisher,'|');
		getline(fsBook, city,'|');
		getline(fsBook, year,'|');
		getline(fsBook, series,'|');
		getline(fsBook, notes);

		Book *book = new Book(callnumber, title, subjects, author, description, publisher, city, year, series, notes);
		cardCatalog.push_back(book);
		
	}
	fsBook.close();

	//Reading the Video file
	string distributor;
	string label;
	fstream fsVideo;

	fsVideo.open("video.txt");

	if(fsVideo==NULL)
		cout<<"Error while reading video.txt"<<endl;
    //Read video.txt line by line
	while(!getline(fsVideo, callnumber, '|').eof() )
	{
		getline(fsVideo, title,'|');
		getline(fsVideo, subjects,'|');
		getline(fsVideo, description,'|');
		getline(fsVideo, distributor,'|');
		getline(fsVideo, notes,'|');
		getline(fsVideo, series,'|');
		getline(fsVideo, label);

		Video *video = new Video(callnumber, title, subjects, description, distributor, notes, series, label);
		cardCatalog.push_back(video);
		
	}
	fsVideo.close();

	//Reading the Film file
	string director;
	fstream fsFilm;
	fsFilm.open("film.txt");

	if(fsFilm==NULL)
		cout<<"Error while reading film.txt"<<endl;
	
    //Read the Film file line by line
	while(!getline(fsFilm, callnumber, '|').eof() )
	{
		getline(fsFilm, title,'|');
		getline(fsFilm, subjects,'|');
		getline(fsFilm, director,'|');
		getline(fsFilm, notes,'|');
		getline(fsFilm, year);

		Film *film = new Film(callnumber, title, subjects, director, notes, year);
		cardCatalog.push_back(film);
		
	}
	fsFilm.close();

	//Reading the Periodical file
	string publishingHistory;
	string relatedTitl;
	string otherTitles;
	string govDocNum;
	fstream fsPeriodical;
	fsPeriodical.open("periodic.txt");

	if(fsPeriodical==NULL)
		cout<<"Error while reading periodical.txt"<<endl;

	while(!getline(fsPeriodical, callnumber, '|').eof() )
	{
		getline(fsPeriodical, title,'|');
		getline(fsPeriodical, subjects,'|');
		getline(fsPeriodical, author,'|');
		getline(fsPeriodical, description,'|');
		getline(fsPeriodical, publisher,'|');
		getline(fsPeriodical, publishingHistory,'|');
		getline(fsPeriodical, series,'|');
		getline(fsPeriodical, notes,'|');
		getline(fsPeriodical, relatedTitl,'|');
		getline(fsPeriodical, otherTitles,'|');
		getline(fsPeriodical, govDocNum);

		Periodical *periodical = new Periodical(callnumber, title, subjects, author, description, publisher, publishingHistory,
			series, notes, relatedTitl, otherTitles, govDocNum);
		cardCatalog.push_back(periodical);
		
	}
	fsPeriodical.close();
}

SearchEngine::~SearchEngine()
{
    //release memory allocated while pushing in records
    for(unsigned int i=0; i < cardCatalog.size(); ++i)
    {
        delete cardCatalog[i];
    }
}

const vector<Media* > SearchEngine::searchByCallNum(const string &callNumber) const
{
	unsigned int i=0;
    vector <Media *> searchResult;
	bool found;

	for(i=0; i < cardCatalog.size(); i++)
	{
        //compare the input callnumber with every record
		found = cardCatalog[i]->compare_callNumber(callNumber);
		if(found)
		{
			searchResult.push_back(cardCatalog[i]);
		}
	}
	return searchResult;
}

const vector<Media *> SearchEngine::searchByTitle(const string &title) const
{
	unsigned int i=0;
	bool found;
    vector <Media *> searchResult;

	for(i=0; i < cardCatalog.size(); i++)
	{
		found = cardCatalog[i]->compare_title(title);
		if(found)
		{
			searchResult.push_back(cardCatalog[i]);
		}
	}
	return searchResult;
}

const vector<Media *> SearchEngine::searchBySubject(const string &subject) const
{
	unsigned int i=0;
	bool found;
    vector <Media *> searchResult;

	for(i=0; i < cardCatalog.size(); i++)
	{
		found = cardCatalog[i]->compare_subject(subject);
		if(found)
		{
			searchResult.push_back(cardCatalog[i]);
		}
	}
	return searchResult;
}

const vector<Media *> SearchEngine::searchByOther(const string &other) const
{
	unsigned int i=0;
	bool found;
    vector <Media *> searchResult;

	for(i=0; i < cardCatalog.size(); i++)
	{
		found = cardCatalog[i]->compare_other(other);
		if(found)
		{
			searchResult.push_back(cardCatalog[i]);
		}
	}
	return searchResult;
}
