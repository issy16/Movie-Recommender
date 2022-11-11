#include "movieList.hpp"
#include <string>
#include <vector>
#include "json/json.hpp"
#include "movie.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include <iostream>

using namespace std;
using json = nlohmann::json;

movieList::movieList(){}


void movieList::readMovieListFiles(){

	//read json file.
	fstream f("data/MovieDatabase.json");
    json moviedata = json::parse(f);

    int countMovies = 0;
	for (countMovies = 0; countMovies < moviedata.size(); ++countMovies){

		if (moviedata[countMovies]["genres"]!="(no genres listed)"){
		movie Movie1 (moviedata[countMovies]["title"], moviedata[countMovies]["directedBy"], 
					  moviedata[countMovies]["starring"], moviedata[countMovies]["avgRating"],
					  moviedata[countMovies]["imdbId"], moviedata[countMovies]["item_id"], moviedata[countMovies]["year"], moviedata[countMovies]["genres"]);
		Movie1.generateGenreList();
		list.push_back(Movie1);
		}
	
	}

	
    json newdata;
    vector<movie>::iterator i;
    std::ofstream out("data/newdata.json");
    for( i = list.begin();i < list.end(); i++){
       newdata["title"]=i->getTitle();
       newdata["directedBy"]=i->getDirector();
       newdata["starring"]=i->getCast();
       newdata["avgRating"]=i->getRating();
       newdata["imdbId"]=i->getImdbId();
       newdata["item_id"]=i->getItemId();
	   newdata["genres"]=i->getGenre();
       newdata["year"]=i->getYear();
       newdata["genresList"]=i->return_genreList();

       out << setw(4) << newdata << endl;
    }
}





//sorts movies by rating in descending order
void movieList::sortByRating() {
	sortedlist = list;
	int maxIdx;

	for (unsigned i = 0; i + 1 < sortedlist.size(); ++i) {
		maxIdx = i;

		for (unsigned j = i + 1; j < sortedlist.size(); ++j) {
			if (sortedlist.at(j).getRating() > sortedlist.at(maxIdx).getRating()) {
				maxIdx = j;
			}
		}

		swap(sortedlist.at(i), sortedlist.at(maxIdx));
	}
}

void movieList::printMovies(const vector<movie>& m){
	//temporarily changed m.size() to a fixed vector size
	for (int i =0; i < m.size(); ++i){
		cout << "------------------" << endl;
		cout<<"title: "<< m.at(i).getTitle()<<endl;
		cout<<"year: "<< m.at(i).getYear()<<endl;
		cout<<"director: "<<m.at(i).getDirector()<<endl;
		cout<<"casting: "<<m.at(i).getCast()<<endl;
		cout<<"rating: "<<m.at(i).getRating()<<endl;
		cout<<"IMDB ID: "<<m.at(i).getImdbId()<<endl;
		cout<<"item: "<<m.at(i).getItemId()<<endl;
		cout<<"Genre: "<<m.at(i).getGenre()<<endl;
	}
}

void movieList::sortYear(vector<movie>& newList) {

	//can try to replace newList.size() to a fixed number to see the first movies in the list
	//i've tried it and it seems to work in the lower end of the list as well
	//note: last movie has an incorrect year and is in the wrong spot because of it
	
	int temp;
	for (int j = 0; j < newList.size() - 1; ++j){
		int min = newList.at(j).getYear();
		temp = j;
		for (int i = j+1; i < newList.size(); ++i) {
			if (min > newList.at(i).getYear()) {
				min = newList.at(i).getYear();
				temp = i;
			}
		}
		std::swap(newList.at(j), newList.at(temp));
	}
	printMovies(newList);
}
 vector<movie>& movieList::returnList(){
	return list;
}

vector<movie>& movieList::returnSortedList() {
	return sortedlist;
}