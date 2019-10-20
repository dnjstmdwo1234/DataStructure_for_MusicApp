#include "Application.h"

Application::Application() {
	m_Command = 0;
}

Application::~Application() {

}

void Application::Run() // Application ����
{
	while (1)
	{
		m_Command = GetCommand_main();

		switch (m_Command)
		{
		case 1:		// �� ������ �Է� �޾� ����Ʈ�� �߰�					
			SongData_edit(); break;
		case 2:		// ���� ������ȣ�� �Է� �޾� ����Ʈ���� ����					
			SingerData_edit(); break;
		case 3:		// �� ������ �Է� �޾Ƽ� ����Ʈ���� �ش� �� ������ ����			
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
		case 1:		// �� ������ �Է� �޾� ����Ʈ�� �߰�					
			AddSong(); break;
		case 2:		// ���� ������ȣ�� �Է� �޾� ����Ʈ���� ����					
			DeleteSong(); break;
		case 3:		// �� ������ �Է� �޾Ƽ� ����Ʈ���� �ش� �� ������ ����			
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
	case 1:		// �� ������ �Է� �޾� ����Ʈ�� �߰�					
		AddSinger(); break;
	case 2:		// ���� ������ȣ�� �Է� �޾� ����Ʈ���� ����					
		DeleteSinger(); break;
	case 3:		// �� ������ �Է� �޾Ƽ� ����Ʈ���� �ش� �� ������ ����			
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
	int command; // command ���� ����
	cout << endl << endl;
	cout << "\t 1 : Song Data edit" << endl;
	cout << "\t 2 : Singer Data edit" << endl;
	cout << "\t 3 : PlayList Data edit" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // ���ϴ� �۾��� ����
	cout << endl;

	return command;
}

int GetCommand_Song() {
	int command; // command ���� ����
	cout << endl << endl;
	cout << "\t 1 : Song Data edit" << endl;
	cout << "\t 2 : Singer Data edit" << endl;
	cout << "\t 3 : PlayList Data edit" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // ���ϴ� �۾��� ����
	cout << endl;

	return command;
}

int GetCommand_PlayList() {
	int command; // command ���� ����
	cout << endl << endl;
	cout << "\t 1 : Add PlayList" << endl;
	cout << "\t 2 : Delete PlayList" << endl;
	cout << "\t 3 : abcd" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // ���ϴ� �۾��� ����
	cout << endl;

	return command;
}

int Application::GetCommand_main() {  // m_Command �� ��ȯ
	int command; // command ���� ����
	cout << endl << endl;
	cout << "\t 1 : Song Data edit" << endl;
	cout << "\t 2 : Singer Data edit" << endl;
	cout << "\t 3 : PlayList Data edit" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // ���ϴ� �۾��� ����
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
