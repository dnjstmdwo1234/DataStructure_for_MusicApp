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
		case 1:		// Song ��� ����				
			SongData_edit(); break;
		case 2:		// Singer ��ɼ���					
			SingerData_edit(); break;
		case 3:		// PlayList ��� ����			
			PlayListData_edit(); break;
		case 4:		// �ǽð� TOP10 ��ɼ���
			Top10_edit(); break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

void Application::Top10_edit() {
		m_Command = GetCommand_top10();

		switch (m_Command)
		{
		case 1:		// �� ������ �Է� �޾� top10�� �Է¿� �߰�
			Add_Top10(); break;
		case 2:		// �ǽð� TOP10 MUSIC ��Ȳ�� ���					
			Top10_Display(); break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
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
	case 1:		// ���� ������ �Է� �޾� ����Ʈ�� �߰�					
		AddSinger(); break;
	case 2:		// ������ ������ȣ�� �Է� �޾� ����Ʈ���� ����					
		DeleteSinger(); break;
	case 3:		// ���� ������ �Է� �޾Ƽ� ����Ʈ���� �ش� �� ������ ����			
		RetrieveSinger(); break;
	case 4:		// ������ ����� ��� Music�� Display 
		ShowAllMusic_from_singer();
	case 0:
		return;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}

void Application::ShowAllMusic_from_singer() {
	SingerType data;
	MusicType music1;
	data.SetNameFrKB();
	data.Setbirth_year_month_dayKB(); // keyboard�� ������ �̸��� ��������� �Է¹޴´�. -> name+birth_year_month_day = primary_key
	MusicList.ResetList();
	for (int i = 0; i < MusicList.GetLength(); i++) {
		MusicList.GetNextItem(music1); 
		if (music1.GetPrimaryKey_Singer() == data.GetPrimaryKey()) { // Music database���� ������ primary_key�� ������ ���� ����Ѵ�.
			music1.Display();
		}
	}
}


void Application::PlayListData_edit() {
	m_Command = GetCommand_PlayList();

	switch (m_Command)
	{
	case 1:		// �� ������ �Է� �޾� �÷��̸���Ʈ�� �߰�					
		AddToPlayList(); break;
	case 2:		// ���� �÷��̸���Ʈ���� ����					
		DeleteFrPlayList(); break;
	case 3:		// �÷��̸���Ʈ�� �ִ� ��� ���� 1ȸ �÷���		
		PlayAllMusic(); break;
	case 4:		// �÷��̸���Ʈ�� �ִ� Ư�� ���� 1ȸ �÷���
		PlayOneMusic();
	case 0:
		return;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}
}

int Application::GetCommand_Singer() {
	int command; // command ���� ����
	cout << endl << endl;
	cout << "\t 1 : Add Singer" << endl;
	cout << "\t 2 : Delete Singer" << endl;
	cout << "\t 3 : Retrieve Singer" << endl;
	cout << "\t 4 : Display All Song with Singer" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // ���ϴ� �۾��� ����
	cout << endl;

	return command;
}

int Application::GetCommand_top10() {
	int command; // command ���� ����
	cout << endl << endl;
	cout << "\t 1 : Add_top10" << endl;
	cout << "\t 2 : Display TOP10" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // ���ϴ� �۾��� ����
	cout << endl;

	return command;
}

int Application::GetCommand_Song() {
	int command; // command ���� ����
	cout << endl << endl;
	cout << "\t 1 : Add Song" << endl;
	cout << "\t 2 : Delete Song" << endl;
	cout << "\t 3 : Retrieve Song" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // ���ϴ� �۾��� ����
	cout << endl;

	return command;
}

int Application::GetCommand_PlayList() {
	int command; // command ���� ����
	cout << endl << endl;
	cout << "\t 1 : Add PlayList" << endl;
	cout << "\t 2 : Delete PlayList" << endl;
	cout << "\t 3 : Play All Music" << endl;
	cout << "\t 4 : Play One Music" << endl;
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
	cout << "\t 4 : top10 music challenge" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command-->";
	cin >> command; // ���ϴ� �۾��� ����
	cout << endl;
	
	return command;
}

int Application::AddSong() {
	MusicType music1;
	music1.SetRecordFromKB();
	
	if (MusicList.Get(music1) == 0) { // ������ ��ϵ� �������� Ȯ���� �� ��� �Ǿ����� ������ ���� �߰��Ѵ�.
		MusicList.Add(music1);
		cout << "������ �����Ͱ� �����ϴ�. ���ο� ������ �߰��մϴ�." << endl;
		
		return 1;
	}
	else {
		cout << "������ �����Ͱ� �����մϴ�." << endl;
		return 0;
	}
		
}

int Application::DeleteSong() {
	MusicType music1;
	music1.SetNameFromKB();
	music1.SetUpdateDayFrKB();
	cout << music1.GetPrimaryKey() << endl;
	if (MusicList.Get(music1) == 1) { // ������ ��ϵ� �������� Ȯ���� �� ��� �Ǿ����� ������ ���� �߰��Ѵ�.
		MusicList.Delete(music1);
		cout << "������ �����͸� �����߽��ϴ�." << endl;
		return 1;
	}
	else {
		cout << "������ �����Ͱ� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
}

int Application::RetrieveSong() {
	MusicType data;
	data.SetNameFromKB();
	data.SetUpdateDayFrKB();
	cout << data.GetPrimaryKey() << endl;
	if (MusicList.Get(data)) {
		data.Display();
		return 1;
	}
	else {
		cout << "�ش� ���� ã�� ���߽��ϴ�. " << endl;
		return 0;
	}
		
}


int Application::AddSinger() {
	SingerType singer1;
	singer1.SetRecordFrKB();

	if (SingerList.Get(singer1) == 0) { // ������ ��ϵ� �������� Ȯ���� �� ��� �Ǿ����� ������ ���� �߰��Ѵ�.
		SingerList.Add(singer1);
		cout << "������ �����Ͱ� �����ϴ�. ���ο� ������ �߰��մϴ�." << endl;

		return 1;
	}
	else {
		cout << "������ �����Ͱ� �����մϴ�." << endl;
		return 0;
	}

}

int Application::DeleteSinger() {
	SingerType singer1;
	singer1.SetNameFrKB();
	singer1.Setbirth_year_month_dayKB();
	cout << singer1.GetPrimaryKey() << endl;
	if (SingerList.Get(singer1) == 1) { // ������ ��ϵ� �������� Ȯ���� �� ��� �Ǿ����� ������ ���� �߰��Ѵ�.
		SingerList.Delete(singer1);
		cout << "������ �����͸� �����߽��ϴ�." << endl;
		return 1;
	}
	else {
		cout << "������ �����Ͱ� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
}

int Application::RetrieveSinger() {
	SingerType data;
	data.SetNameFrKB();
	data.Setbirth_year_month_dayKB();
	cout << data.GetPrimaryKey() << endl;
	if (SingerList.Get(data)) {
		data.Display();
		return 1;
	}
	else {
		cout << "�ش� ������ ã�� ���߽��ϴ�. " << endl;
		return 0;
	}

}


int Application::Add_Top10() {
	MusicType music1;
	music1.SetNameFromKB();
	music1.SetUpdateDayFrKB(); // Music ������ keybroad���� �Է¹޾� �ش� ���� �ڼ��� ������ MusicList���� ������ TOP10�� ����Ѵ�.
	if (MusicList.Get(music1)) {
		topmusicList.Add_new(music1); 
		return 1;
	}
	else {
		cout << "�ش� Music�� ã�� ���߽��ϴ�. " << endl;
		return 0;
	}
}

void Application::Top10_Display() {
	topmusicList.Display_top10(); // �ǽð� top10 music�� ����Ѵ�.
}


int Application::AddToPlayList() {
	MusicType music1;
	music1.SetNameFromKB();
	music1.SetUpdateDayFrKB(); // music�� Ű����� ���� �Է¹޾� playlist�� �߰��Ѵ�.
	if (MusicList.Get(music1)) //0�� �ƴϸ�(ã����)
	{
		playList.EnQueue(music1);
		cout << "PlayList�� �߰��Ϸ��߽��ϴ�." << endl;
		return 1;
	}
	else {
		cout << "�ش� ���� ã�� �� �����ϴ�. " << endl;
		return 0;	//����(0)�� ����
	}
	
}

void Application::PlayAllMusic() {
	MusicType data;
	playList.ResetPoint(); 
	while (playList.GetNextItem(data)) {
		if (MusicList.Get(data)) //0�� �ƴϸ�(ã����)
		{
			data.playmusicOneTime(); //playlist�� �ִ� ��� �뷡�� �ѹ��� �÷����Ѵ�.
			topmusicList.Add_new(data); // �÷��� �� �뷡�� �ڵ����� top10 music�� add �ɻ縦 �Ѵ�.
			MusicList.Replace(data); 
		}
	}
}

void Application::PlayOneMusic() {
	MusicType music1;
	music1.SetNameFromKB();
	music1.SetUpdateDayFrKB(); //music�� Ű����� ���� �Է¹޴´�.
	if (MusicList.Get(music1)) //0�� �ƴϸ�(ã����)
	{
		music1.playmusicOneTime(); //�ش� music�� �ѹ� �÷��� �Ѵ�.
		topmusicList.Add_new(music1); // �÷��̵� music�� �ǽð� top10�� ���� �� �ִ��� �ɻ��Ѵ�.
		MusicList.Replace(music1);
	}
}

int Application::DeleteFrPlayList() {
	MusicType music1;
	music1.SetNameFromKB();
	music1.SetUpdateDayFrKB(); //����ڷ� ���� �Է¹޾� �ش� ������ ������ playlist���� �����Ѵ�.
	if (MusicList.Get(music1)) //0�� �ƴϸ�(ã����)
	{
		playList.DeQueue(music1);
		cout << "PlayList���� ���ſϷ��߽��ϴ�." << endl;
		return 1;
	}
	else {
		cout << "�ش� ���� ã�� �� �����ϴ�. " << endl;
		return 0;	//����(0)�� ����
	}
}