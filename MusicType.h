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
	string PrimaryKey_for_seperate_song; // Music �������� �����ϱ� ���� primary_key -> ������ �Է¾��� ���� ������Ʈ ��¥�� ���� string���� �ڵ������ȴ�.
	string PrimaryKey_for_Singer; // Music�� �������� ���� ���� primary_key -> ������� ������ ������� ������ ���� string���� �ڵ������Ѵ�.
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
	~MusicType() {

	}
	void playmusicOneTime(); // ������ �ѹ� ����Ѵ�.
	void SetUpdateDayFrKB(); // ������Ʈ ���̸� Ű����� �Է¹޴´�.
	void Display(); // Music ������ ǥ��
	string GetPrimaryKey_Singer(); // ���� ������ ���� primary_key�� return �Ѵ�.
	string GetName(); // �̸��� ��ȯ�Ѵ�.
	int GetGenre(); // �帣�� ��ȯ�Ѵ�.
	string GetSinger(); // ������ ��ȯ�Ѵ�.
	string GetPrimaryKey(); // Music ������ ������ ���� primary_key�� ��ȯ�Ѵ�.
	void SetRecordFromKB(); // Music�� ��� ������ kb�� �Է¹޴´�.
	void SetNameFromKB(); // Music�� �̸��� Ű����� ���� �Է¹޴´�.
	int GetPlayTime() { // playȽ���� return �Ѵ�.
		return playTime;
	}

	bool operator < (MusicType& music) {
		if (this->GetPlayTime() < music.GetPlayTime()) {
			return true;
		}
		else
			false;
	}

	bool operator == (const MusicType& music) {
		if (this->PrimaryKey_for_seperate_song == music.PrimaryKey_for_seperate_song) {
			return true;
		}
		else
			return false;
	}

	bool operator > (MusicType& music) {
		if (this->GetPlayTime() > music.GetPlayTime()) {
			return true;
		}
		else
			false;
	}
	

};

#endif

