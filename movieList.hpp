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
		void readMovieListFile();
		void getCriteria();
		void sortList();
		void sortByMovieTitle(string movieName);
		void sortByRating(double avgRating);
		void sortByGenre(string movieGenre);
		void sortByYear(int movieYear);
		void sortAlphabetical();

		void printMovie(const movie&);
};		


#endif