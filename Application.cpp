#include "Application.h"

Application::Application() {
	m_Command = 0;
}

Application::~Application() {

}

void Application::Run() // Application 실행
{
	while (1)
	{
		m_Command = GetCommand_main();

		switch (m_Command)
		{
		case 1:		// 곡 정보를 입력 받아 리스트에 추가					
			SongData_edit(); break;
		case 2:		// 곡의 고유번호를 입력 받아 리스트에서 삭제					
			SingerData_edit(); break;
		case 3:		// 곡 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신			
			PlayListData_edit(); break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

void Application::SongData_edit() {
		m_Command = GetCommand_Song();

		switch (m_Command)
		{
		case 1:		// 곡 정보를 입력 받아 리스트에 추가					
			AddSong(); break;
		case 2:		// 곡의 고유번호를 입력 받아 리스트에서 삭제					
			DeleteSong(); break;
		case 3:		// 곡 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신			
			RetrieveSong(); break;
		case 4:
			SearchBySong_SequenS();
		case 5:
			SearchBySong_BinaryS();
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
}

void Application::SingerData_edit() {
	m_Command = GetCommand_Singer();

	switch (m_Command)
	{
	case 1:		// 곡 정보를 입력 받아 리스트에 추가					
		AddSinger(); break;
	case 2:		// 곡의 고유번호를 입력 받아 리스트에서 삭제					
		DeleteSinger(); break;
	case 3:		// 곡 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신			
		RetrieveSinger(); break;
	case 4:
		SearchBySinger_SequenS();
	case 5:
		SearchBySinger_BinaryS();
	case 0:
		return;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}

void Application::PlayListData_edit() {

}

int GetCommand_Singer() {
	int command; // command 변수 생성
	cout << endl << endl;
	cout << "\t 1 : Song Data edit" << endl;
	cout << "\t 2 : Singer Data edit" << endl;
	cout << "\t 3 : PlayList Data edit" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // 원하는 작업을 선택
	cout << endl;

	return command;
}

int GetCommand_Song() {
	int command; // command 변수 생성
	cout << endl << endl;
	cout << "\t 1 : Song Data edit" << endl;
	cout << "\t 2 : Singer Data edit" << endl;
	cout << "\t 3 : PlayList Data edit" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // 원하는 작업을 선택
	cout << endl;

	return command;
}

int GetCommand_PlayList() {
	int command; // command 변수 생성
	cout << endl << endl;
	cout << "\t 1 : Add PlayList" << endl;
	cout << "\t 2 : Delete PlayList" << endl;
	cout << "\t 3 : abcd" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // 원하는 작업을 선택
	cout << endl;

	return command;
}

int Application::GetCommand_main() {  // m_Command 값 반환
	int command; // command 변수 생성
	cout << endl << endl;
	cout << "\t 1 : Song Data edit" << endl;
	cout << "\t 2 : Singer Data edit" << endl;
	cout << "\t 3 : PlayList Data edit" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // 원하는 작업을 선택
	cout << endl;
	
	return command;
}

int AddSong() {
	return 0;
}

int DeleteSong() {
	return 0;
}

int RetrieveSong() {
	return 0;
}

int SearchBySong_SequenS() {
	return 0;
}

int SearchBySong_BinaryS() {
	return 0;
}

int AddSinger() {
	return 0;
}

int DeleteSinger() {
	return 0;
}

int RetrieveSinger() {
	return 0;
}

int SearchBySinger_SequenS() {
	return 0;
}

int SearchBySinger_BinaryS() {
	return 0;
}
