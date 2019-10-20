#ifndef __Singer_Type__
#define __Singer_Type__


#include <iostream>
#include <string>
#define MAXSIZE 1024
using namespace std;


class SingerType { 
private: 
	string name; 
	string birth_year_month_day; 
	int mainGenre; 
	string PrimaryKey; 



public:
	SingerType() {
		name = "";
		string birth_year_month_day = "000000";
		int mainGenre = 0;

	}
	~SingerType() {}
};


#endif