#ifndef _Application
#define _Application

#include "MusicType.h"
#include "SingerType.h"
#include "PlayType.h"
#include "UnSortedList.h"
#include "LinkedList.h"
#include "SortedList.h"
#include "CircularQueue.h"
#include "DoublyIterator.h"
#include "DoublySortedLinkedList.h"

class Application {

private:
	int m_Command;
	ifstream m_InFile;
	ofstream m_OutFile;
	SortedList<SingerType> SingerList;
	UnsortedList<MusicType> MusicList;
	CircularQueueType<PlayType> playList;
	//LinkedList<> SongList;
	//DoublySortedLinkedList<PlayItem> PlayList;
	//DoublySortedLinkedList<SingerList> Singer_List;
public:
	   Application();
	   ~Application();
	   void Run(); // Application 실행
	   void SongData_edit();
	   void SingerData_edit();
	   void PlayListData_edit();
	   int GetCommand_main();
	   int GetCommand_Singer();// m_Command 값 반환
	   int GetCommand_Song();// m_Command 값 반환
	   int GetCommand_PlayList();// m_Command 값 반환
	   int AddSong(); // 새로운 Music 추가
	   int DeleteSong();
	   int RetrieveSong();
	   int SearchBySong_SequenS();
	   int SearchBySong_BinaryS();
	   int AddSinger(); // 새로운 Music 추가
	   int DeleteSinger();
	   int RetrieveSinger();
	   int SearchBySinger_SequenS();
	   int SearchBySinger_BinaryS();








	  
};











#endif 
