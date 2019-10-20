#ifndef _MusicType_
#define _MusicType_

#include <iostream>
#include <fstream>
#include <string>
# define FILESIZE 1024
using namespace std;


class MusicType {
private:
	string Name;
	string Singer;
	string Singer_birth;
	string update_day;
	int Genre; 
	string PrimaryKey_for_seperate_song;
	string PrimaryKey_for_Singer;
	int playTime;
public:
	MusicType() {
		Name = "";
		update_day = "000000";
		Genre = 0;
		playTime = 0;
		PrimaryKey_for_seperate_song = Name + update_day;
		PrimaryKey_for_Singer = Singer + Singer_birth;
	};
	~MusicType();
	string GetName();
	int GetGenre();
	string GetSinger();
	string GetPrimaryKey();
	void SetRecordFromKB();
};

#endif

