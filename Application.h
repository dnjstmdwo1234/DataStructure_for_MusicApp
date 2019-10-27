#ifndef _Application
#define _Application

#include "MusicType.h"
#include "SingerType.h"
#include "UnSortedList.h"
#include "LinkedList.h"
#include "SortedList.h"
#include "CircularQueue.h"
#include "DoublyIterator.h"
#include "DoublySortedLinkedList.h"
#include "TOP10_music.h"

class Application {

private:
	int m_Command;
	ifstream m_InFile; 
	ofstream m_OutFile;
	TOPMUSIC topmusicList; // 실시간 TOP10 구현을 위한 Application 멤버변수 
	LinkedList<SingerType> SingerList; // Singer의 데이터저장을 위한 멤버변수
	CircularQueueType<MusicType> playList; // PlayList 데이터저장을 위한 멤버변수
	LinkedList<MusicType> MusicList; // Music 데이터 저장을 위한 멤버변수
	//UnsortedList<MusicType> MusicList;
	//LinkedList<> SongList;
	//DoublySortedLinkedList<PlayItem> PlayList;
	//DoublySortedLinkedList<SingerList> Singer_List;
public:
	   Application();
	   ~Application();
	   void Run(); // Application 실행
	   void SongData_edit(); // Song 기능 선택
	   void SingerData_edit(); // Singer 기능 선택
	   void PlayListData_edit(); // PlayList 데이터 선택
	   int GetCommand_main(); // 메인화면 기능선택
	   int GetCommand_Singer();// Singer화면 기능선택
	   int GetCommand_Song();// Song 화면 기능선택
	   int GetCommand_PlayList();// PlayList 화면 기능선택
	   int AddSong(); // 새로운 Music 추가
	   int DeleteSong(); // Music 삭제
	   int RetrieveSong(); // Music 검색
	   //int SearchBySong_SequenS(); 
	   //int SearchBySong_BinaryS();
	   int AddSinger(); // 새로운 Music 추가
	   int DeleteSinger(); // Singer 삭제
	   int RetrieveSinger(); // Singer 검색
	   //int SearchBySinger_SequenS();
	   //int SearchBySinger_BinaryS();
	   int Add_Top10(); // TOP10 Music에 추가 시도
	   void Top10_Display(); // 현재 TOP10 Music Display 
	   int GetCommand_top10(); // top10 화면 기능선택
	   void Top10_edit(); // top10 기능 선택
	   int AddToPlayList(); // PlayList 추가
	   void PlayAllMusic(); // PlayList의 모든 MUSIC 1회씩 재생
	   int DeleteFrPlayList(); // PlayList 삭제
	   void PlayOneMusic(); // PlayList의 특정 곡 1회 재생
	   void ShowAllMusic_from_singer(); // 해당 가수의 모든 Music 재생
};











#endif 
