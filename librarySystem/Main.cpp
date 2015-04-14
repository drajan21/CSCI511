#include <iostream>
#include "Media.h"
#include "SearchEngine.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char * argv[])
{
	SearchEngine search;
	vector<Media* > results;
	char option;
	string callNumber;
	string title;
	string subject;
	string other;
    int resultSize = 0;

	while(true)
	{
		cout<<"----------Library Search------------"<<endl;
		cout<<"Choose from below options"<<endl;
		cout<<"1. Search By Call No."<<endl;
		cout<<"2. Search By Title"<<endl;
		cout<<"3. Search By Subject"<<endl;
		cout<<"4. Search By Other"<<endl;
		cout<<"5. Exit"<<endl;

		cin.clear();
		cin.sync();
		cin>>option;
		switch(option)
		{
			case '1':
					cout<<"Enter the Call No:";
					cin.clear();
					cin>>callNumber;
                    results.clear();
                    //Search the card catalog for the input call number
					results = search.searchByCallNum(callNumber);
                    resultSize = results.size();
                    if(resultSize > 0)
                    {  
                        //For each item found display the details
					    for(int i=0; i<resultSize; ++i)
					    {
						    Media *media;
						    media = results[i];
						    media->display();
					    }
                    }
                    else
                        cout<<"No matching Media Objects Found!!!"<<endl<<endl;
					break;
	
			case '2':
					cout<<"Enter the Title:";
					cin.clear();
					cin>>title;
                    results.clear();
                    //Search the card catalog for the input title
					results = search.searchByTitle(title);
                    resultSize = results.size();
                    if(resultSize > 0)
                    {
                    //For each item found display the details
					    for(int i=0; i<resultSize; ++i)
					    {
						    Media *media;
						    media = results[i];
						    media->display();
					    }
                    }
                    else
                        cout<<"No matching Media Objects Found!!!"<<endl<<endl;
					break;

			case '3':
					cout<<"Enter the Subject:";
					cin.clear();
					cin>>subject;
                    results.clear();
                    //Search through card catalog for input subject
					results = search.searchBySubject(subject);
                    resultSize = results.size();
                    if(resultSize > 0)
                    {
                        //For each item found display the details
					    for(int i=0; i<resultSize; ++i)
					    {
						    Media *media;
						    media = results[i];
						    media->display();
					    }
                    }
                    else
                        cout<<"No matching Media Objects Found!!!"<<endl<<endl;
					break;

			case '4':
					cout<<"Enter the String:";
					cin.clear();
					cin>>other;
                    results.clear();
                    //Search through the card catalog for any other input string
					results = search.searchByOther(other);
                    resultSize = results.size();
                    if(resultSize > 0)
                    {
                        //For each item found display the details
					    for(int i=0; i<resultSize; ++i)
					    {
						    Media *media;
						    media = results[i];
						    media->display();
					    }
                    }
                    else
                        cout<<"No matching Media Objects Found!!!"<<endl<<endl;
					break;

			case '5': exit(0);
					break;

			default: cout<<"No such option exists"<<endl;
					 break;
		}
	}
	return 0;
}
