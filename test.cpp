#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <string> 
using namespace std;
#include "Linux_perm.h"

int main() {
//to compose full path to "user.txt" in home directiry
string path_u = getenv("HOME");
string doc_path_u = path_u + "/user.txt";
//cast to const char* for chmod()
const char* user_path = doc_path_u.c_str();

	fstream user_file  = fstream(doc_path_u, ios::in | ios::out);   
    if (!user_file.is_open())
		// Для создания файла используем параметр ios::trunc
		user_file = fstream(doc_path_u, ios::in | ios::out | ios::trunc);

	if (user_file) {
		User user("Alex", "qwerty", "12345");
		// Запишем данные по в файл
		user_file << user << endl;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		user_file.seekg(0, ios_base::beg);
		// Считываем данные из файла
		user_file >> user;
		user_file.seekg(0, ios_base::beg);
		string u_temp;
		
		user_file >> u_temp;			
		cout << "Name: ";
		cout << u_temp << endl;
		user_file >> u_temp;
		cout << "Login: ";
		cout << u_temp << endl;
		user_file >> u_temp;
		cout << "Password: ";
		cout << u_temp << endl;			
		
	}
	else
	{
		cout << "Could not open file user.txt !" << '\n';
		return 0;
	}
chmod (user_path,  S_IRWXU);
user_file.close();

string doc_path_m = path_u + "/message.txt";
//cast to const char* for chmod()
const char* mes_path = doc_path_m.c_str();
 
	fstream message_file = fstream(mes_path, ios::in | ios::out | ios::app);
	if (!message_file)		
		message_file = fstream(mes_path, ios::in | ios::out | ios::trunc | ios::app);

	if (message_file) {
		Message mes("Hello friend of mine!", "Alex", "Anton");
		// Запишем данные по в файл
		message_file << mes << endl;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		message_file.seekg(0, ios_base::beg);
		// Считываем данные из файла		
		message_file >> mes;
		message_file.seekg(0, ios_base::beg);		
		string m_temp;		
		while (!message_file.eof())
		{
			m_temp = "";
			message_file >> m_temp;
			if (m_temp == "") break;
			cout << "Sender: ";
			cout << m_temp << endl;
			message_file >> m_temp;
			cout << "Receiver: ";
			cout << m_temp << endl;
			getline (message_file, m_temp);
			cout << "Text: ";
			cout << m_temp << endl;
		}	
		
    }	
	
	else
	{
		cout << "Could not open file message.txt !" << '\n';
		return 0;
	}
	
	chmod (mes_path,  S_IRWXU);	
	message_file.close();
	return 0;

}
