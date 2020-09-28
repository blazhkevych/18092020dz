/*
Написати програму «Автоматизована інформаційна система залізничного вокзалу».
Система містить: відомості про відправлення поїздів далекого прямування.
Для кожного поїзда вказуємо: номер, час відправлення, станцію призначення. забезпечити:
■■ Введення даних в систему;
■■ Виведення інформації про всіх поїздах;
■■ Виведення інформації про запитуваний поїзд.
Використовувати контейнерний клас vector
*/
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Poezd
{
protected:
	int nomer;
	string vrem_otpravl, mesto_nazn;
public:
	Poezd() :nomer(0), vrem_otpravl(0), mesto_nazn(0) {}
	Poezd(const Poezd& copy) :nomer(copy.nomer), vrem_otpravl(copy.vrem_otpravl), mesto_nazn(copy.mesto_nazn) {}
	Poezd(int _nomer, string _vrem_otpravl, string _mesto_nazn) {
		nomer = _nomer; //номер поезда
		vrem_otpravl = _vrem_otpravl; //время отправления
		mesto_nazn = _mesto_nazn; //место назначения
	}
	int getNomer() {
		return nomer;
	}
	string getVrem_otpravl() {
		return vrem_otpravl;
	}
	string getMesto_nazn() {
		return mesto_nazn;
	}
	void operator = (Poezd other) {
		nomer = other.nomer;
		vrem_otpravl = other.vrem_otpravl;
		mesto_nazn = other.mesto_nazn;
	}
};

void addPoezd(vector <Poezd>& a) {//добавление поезда
	int nom;
	string stantsiya, vremya;
	cout << "Введите номер поезда: " << endl;
	cin >> nom;
	cin.ignore();
	cout << "Введите место назначения: " << endl;
	cin >> stantsiya;
	cin.ignore();
	cout << "Введите время отправления: " << endl;
	cin >> vremya;
	cin.ignore();
	a.push_back(Poezd(nom, vremya, stantsiya));
}

void allInfo(vector <Poezd>& a) { //вывод информации о всех поездах
	if (a.empty()) {
		cout << "Список пуст! " << endl; return;
	}
	vector <Poezd>::iterator it = a.begin();
	cout << "Номер поезда  " << '\t' << " Время отправления " << '\t' << " Место назначения " << endl;
	while (it != a.end()) {
		cout << it->getNomer() << setw(25) << it->getVrem_otpravl() << setw(25) << it->getMesto_nazn() << '\n';
		it++;
	}
}
void infoZaprashPoezd(vector<Poezd>a) { //информация о запрашиваемом поезде
	int nomerPoezda;
	vector <Poezd>::iterator it = a.begin();
	cout << "Введите номер поезда: " << endl;
	cin >> nomerPoezda;
	cin.ignore();
	if (it->getNomer() == nomerPoezda) {
		cout << it->getMesto_nazn() << '\t' << it->getVrem_otpravl() << endl;
	}
	else {
		cout << "Поезд не найден! " << endl;
	}
}
int main() {
	setlocale(LC_ALL, ""); //працює тільки з потоком виведення
	SetConsoleCP(1251); //встановлює потрібну кодову таблицю, на потік введення
	SetConsoleOutputCP(1251); //встановлює потрібну кодову таблицю, на потік виводу.
	vector <Poezd> dataBase;
	for (int i = 0; i < 2; i++) {
		addPoezd(dataBase);
	}
	allInfo(dataBase);
	infoZaprashPoezd(dataBase);
}