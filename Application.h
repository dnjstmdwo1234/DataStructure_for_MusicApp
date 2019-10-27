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
	TOPMUSIC topmusicList; // �ǽð� TOP10 ������ ���� Application ������� 
	LinkedList<SingerType> SingerList; // Singer�� ������������ ���� �������
	CircularQueueType<MusicType> playList; // PlayList ������������ ���� �������
	LinkedList<MusicType> MusicList; // Music ������ ������ ���� �������
	//UnsortedList<MusicType> MusicList;
	//LinkedList<> SongList;
	//DoublySortedLinkedList<PlayItem> PlayList;
	//DoublySortedLinkedList<SingerList> Singer_List;
public:
	   Application();
	   ~Application();
	   void Run(); // Application ����
	   void SongData_edit(); // Song ��� ����
	   void SingerData_edit(); // Singer ��� ����
	   void PlayListData_edit(); // PlayList ������ ����
	   int GetCommand_main(); // ����ȭ�� ��ɼ���
	   int GetCommand_Singer();// Singerȭ�� ��ɼ���
	   int GetCommand_Song();// Song ȭ�� ��ɼ���
	   int GetCommand_PlayList();// PlayList ȭ�� ��ɼ���
	   int AddSong(); // ���ο� Music �߰�
	   int DeleteSong(); // Music ����
	   int RetrieveSong(); // Music �˻�
	   //int SearchBySong_SequenS(); 
	   //int SearchBySong_BinaryS();
	   int AddSinger(); // ���ο� Music �߰�
	   int DeleteSinger(); // Singer ����
	   int RetrieveSinger(); // Singer �˻�
	   //int SearchBySinger_SequenS();
	   //int SearchBySinger_BinaryS();
	   int Add_Top10(); // TOP10 Music�� �߰� �õ�
	   void Top10_Display(); // ���� TOP10 Music Display 
	   int GetCommand_top10(); // top10 ȭ�� ��ɼ���
	   void Top10_edit(); // top10 ��� ����
	   int AddToPlayList(); // PlayList �߰�
	   void PlayAllMusic(); // PlayList�� ��� MUSIC 1ȸ�� ���
	   int DeleteFrPlayList(); // PlayList ����
	   void PlayOneMusic(); // PlayList�� Ư�� �� 1ȸ ���
	   void ShowAllMusic_from_singer(); // �ش� ������ ��� Music ���
};











#endif 
