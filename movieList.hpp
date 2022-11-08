#ifndef __MOVIELIST_H__
#define  __MOVIELIST_H__
#include "movie.hpp"
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;


class movieList{
	private:
		vector <movie> list;
		vector <movie> sortedlist;

	public:
		movieList();
		void readMovieListFiles();
		string parseStringFromCSV(const string &);
		void getCriteria();
		void sortList();
		void sortByMovieTitle(vector<movie>& movieList);
		void sortByRating(double avgRating);
		void sortByGenre(string movieGenre);
				void sortByYear(int movieYear);		//initial function, changed to below function
		void sortAlphabetical();

		void sortByAscendingTitle();
		void sortByDescendingTitle();
		void sortBySpecificTitle(vector<movie>& movieList, string movieName);
		//local testing sortByYear function
		void sortYear(vector<movie>&);

		vector<movie>& returnList();
		void printMovies(const vector<movie>&);
};		


#endif