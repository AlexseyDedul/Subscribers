#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;


struct Account
{
	string login;
	string password;
	int role;          // 0-пользователь, 1-администратор
};

struct Lists
{
	string FIO;
	int mounth;
	int year;
	int days;
	int pay;
};

void menu();
void menuAdmin();
void menuAccounts();
void menuList();
void menuListbyAdmin();
void useMenu();
void useMenuAdmin();
void useMenuAccounts();
void useMenuList();
void useMenuTwo();
void useMenuListbyAdmin();
void optionList();
void useMenuOptionList();
void useMenuOptionListbyAdmin();

void menuAutorization(Account *arr_of_accounts, int &number_of_accounts);

void writeFileAccounts(Account *arr_of_accounts, int number_of_accounts);
void writeEndFileAccounts(Account new_account);
void readFileAccounts(Account *arr_of_accounts, int &number_of_accounts);

void readFileLists(Lists *arr_of_lists, int &number_of_lists);
void writeEndFileLists(Lists new_list);
void writeFileLists(Lists *arr_of_lists, int number_of_lists);

void showAccounts(Account *arr_of_accounts, int number_of_accounts);
void addAccount(Account *arr_of_accounts, int &number_of_accounts);
void delAccount(Account *arr_of_accounts, int &number_of_accounts);
void updateAccount(Account *arr_of_accounts, int number_of_accounts);

void showLists(Lists *arr_of_lists, int number_of_lists);
void showFoundLists(Lists *arr_of_lists, int number_of_lists);
void addLists(Lists *arr_of_lists, int &number_of_lists);
void delLists(Lists *arr_of_lists, int &number_of_lists);
void updateLists(Lists *arr_of_lists, int number_of_lists);

void foundList(Lists *arr_of_lists, int number_of_lists);
void foundPay(Lists *arr_of_lists, int number_of_lists);
void foundForFIO(Lists *arr_of_lists, int number_of_lists);
void foundForMounth(Lists *arr_of_lists, int number_of_lists);
void foundForYear(Lists *arr_of_lists, int number_of_lists);
void foundForDay(Lists *arr_of_lists, int number_of_lists);
void foundForPay(Lists *arr_of_lists, int number_of_lists);

void SortByFIO(Lists *arr_of_lists, int number_of_lists);
void SortByMounth(Lists *arr_of_lists, int number_of_lists);
void SortByPay(Lists *arr_of_lists, int number_of_lists);

const int SIZE_ARR_OF__ACCOUNTS = 100;
string const FILE_OF_ACCOUNTS = "Accounts.txt"; //Путь к файлу
const int SIZE_ARR_OF__LISTS = 100;
string const FILE_OF_LISTS = "Lists.txt";

void main()
{
	setlocale(LC_ALL, "rus");
	
	useMenu();
	system("pause");
}

void useMenu()
{
	Account arr_of_accounts[SIZE_ARR_OF__ACCOUNTS];
	int number_of_accounts = 0;

	readFileAccounts(arr_of_accounts, number_of_accounts);
	menuAutorization(arr_of_accounts, number_of_accounts);
		bool flag_exit = true;

		while (flag_exit)
		{
			menu();
			int item;
			cin >> item;

			switch (item)
			{
			case 0: useMenu();
				break;
			case 1: useMenuList();
				break;
			case 2: useMenuAccounts();
				break;
			}
		}
		writeFileAccounts(arr_of_accounts, number_of_accounts);
}

void useMenuTwo()
{
	Account arr_of_accounts[SIZE_ARR_OF__ACCOUNTS];
	int number_of_accounts = 0;

	readFileAccounts(arr_of_accounts, number_of_accounts);
	bool flag_exit = true;

	while (flag_exit)
	{
		menu();
		int item;
		cin >> item;

		switch (item)
		{
		case 0: useMenu();
			break;
		case 1: useMenuList();
			break;
		case 2: useMenuAccounts();
			break;
		}
	}
	writeFileAccounts(arr_of_accounts, number_of_accounts);
}

void useMenuAdmin()
{
	Account arr_of_accounts[SIZE_ARR_OF__ACCOUNTS];
	int number_of_accounts = 0;

	readFileAccounts(arr_of_accounts, number_of_accounts);
	bool flag_exit = true;

	while (flag_exit)
	{
		menuAdmin();
		int item;
		cin >> item;

		switch (item)
		{
		case 0: useMenu();
			break;
		case 1: useMenuListbyAdmin();
			break;
		case 2: useMenuAccounts();
			break;
		}
	}
	writeFileAccounts(arr_of_accounts, number_of_accounts);
}

void useMenuAccounts()
{
	Account arr_of_accounts[SIZE_ARR_OF__ACCOUNTS];
	int number_of_accounts = 0;

	readFileAccounts(arr_of_accounts, number_of_accounts);
	bool flag_exit = true;

	while (flag_exit)
	{
		menuAccounts();
		int item;
		cin >> item;

		switch (item)
		{
		case 0: flag_exit = false;
			break;
		case 1: showAccounts(arr_of_accounts, number_of_accounts);
			break;
		case 2: addAccount(arr_of_accounts, number_of_accounts);
			break;
		case 3: delAccount(arr_of_accounts, number_of_accounts);
			break;
		case 4: updateAccount(arr_of_accounts, number_of_accounts);
			break;
		}
	}

	writeFileAccounts(arr_of_accounts, number_of_accounts);

}

void useMenuOptionList()
{
	Lists arr_of_lists[SIZE_ARR_OF__LISTS];
	int number_of_lists = 0;

	readFileLists(arr_of_lists, number_of_lists);
	bool flag_exit = true;

	while (flag_exit)
	{
		optionList();
		int item;
		cin >> item;

		switch (item)
		{
		case 0: useMenuList();
			break;
		case 1: foundForFIO(arr_of_lists, number_of_lists);
			break;
		case 2: foundForYear(arr_of_lists, number_of_lists);
			break;
		case 3: foundForMounth(arr_of_lists, number_of_lists);
			break;
		case 4: foundForDay(arr_of_lists, number_of_lists);
			break;
		case 5: foundForPay(arr_of_lists, number_of_lists);
			break;
		case 6: SortByFIO(arr_of_lists, number_of_lists);
			break;
		case 7: SortByMounth(arr_of_lists, number_of_lists);
			break;
		case 8: SortByPay(arr_of_lists, number_of_lists);
			break;
		}
	}

	writeFileLists(arr_of_lists, number_of_lists);

}

void useMenuOptionListbyAdmin()
{
	Lists arr_of_lists[SIZE_ARR_OF__LISTS];
	int number_of_lists = 0;

	readFileLists(arr_of_lists, number_of_lists);
	bool flag_exit = true;

	while (flag_exit)
	{
		optionList();
		int item;
		cin >> item;

		switch (item)
		{
		case 0: useMenuListbyAdmin();
			break;
		case 1: foundForFIO(arr_of_lists, number_of_lists);
			break;
		case 2: foundForYear(arr_of_lists, number_of_lists);
			break;
		case 3: foundForMounth(arr_of_lists, number_of_lists);
			break;
		case 4: foundForDay(arr_of_lists, number_of_lists);
			break;
		case 5: foundForPay(arr_of_lists, number_of_lists);
			break;
		case 6: SortByFIO(arr_of_lists, number_of_lists);
			break;
		case 7: SortByMounth(arr_of_lists, number_of_lists);
			break;
		case 8: SortByPay(arr_of_lists, number_of_lists);
			break;
		}
	}

	writeFileLists(arr_of_lists, number_of_lists);

}

void useMenuList()
{
	Lists arr_of_lists[SIZE_ARR_OF__LISTS];
	int number_of_lists = 0;

	readFileLists(arr_of_lists, number_of_lists);
	bool flag_exit = true;

	while (flag_exit)
	{
		menuList();
		int item;
		cin >> item;

		switch (item)
		{
		case 0: useMenuTwo();
			break;
		case 1: showLists(arr_of_lists, number_of_lists);
			useMenuOptionList();
			break;
		case 2: foundList(arr_of_lists, number_of_lists);
			break;
		case 3: foundPay(arr_of_lists, number_of_lists);
			break;
		}
	}

	writeFileLists(arr_of_lists, number_of_lists);
}

void useMenuListbyAdmin()
{
	Lists arr_of_lists[SIZE_ARR_OF__LISTS];
	int number_of_lists = 0;

	readFileLists(arr_of_lists, number_of_lists);
	bool flag_exit = true;

	while (flag_exit)
	{
		menuListbyAdmin();
		int item;
		cin >> item;

		switch (item)
		{
		case 0: useMenuAdmin();
			break;
		case 1: showLists(arr_of_lists, number_of_lists);
			useMenuOptionListbyAdmin();
			break;
		case 2: addLists(arr_of_lists, number_of_lists);
			break;
		case 3: delLists(arr_of_lists, number_of_lists);
			break;
		case 4: updateLists(arr_of_lists, number_of_lists);
			break;
		case 5: foundList(arr_of_lists, number_of_lists);
			break;
		case 6: foundPay(arr_of_lists, number_of_lists);
			break;
		}
	}

	writeFileLists(arr_of_lists, number_of_lists);
}

void menuAutorization(Account *arr_of_accounts, int &number_of_accounts)
{
	bool flag = true;
	
	do
	{
		system("cls");
		string alogin;
		string apassword;
		cout << "|============================================|" << endl;
		cout << " Login" << endl;
		cin >> alogin;
		cout << "|--------------------------------------------|" << endl;
		cout << " Password" << endl;
		cin >> apassword;
		cout << "|============================================|" << endl;

		ifstream fin(FILE_OF_ACCOUNTS, ios::in); //Открыли файл для чтения
		
		if (fin.is_open())
		{
			for (int i = 0; i < number_of_accounts; i++)
			{
				if ((arr_of_accounts[i].login == alogin) && (arr_of_accounts[i].password == apassword))
				{
					system("cls");
					if (arr_of_accounts[i].role == 1)
					{
						cout << "Вы успешно авторизировались!" << endl;
						system("pause");
						system("cls");
						useMenuAdmin();
					}
					else
					{
						flag = false;
					}
				}
			}
		}
	} while (flag == true);
			cout << endl;
			cout << "Вы успешно авторизировались!" << endl;
			system("pause");
			system("cls");
}

void menuAdmin()
{
	cout << "|============================================|" << endl;
	cout << "|-----------МЕНЮ АДМИНИСТРАТОРА--------------|" << endl;
	cout << "1 - Лист подписчиков на печатную продукцию" << endl;
	cout << "2 - Аккаунты " << endl;
	cout << "0 - Выход" << endl;
	cout << "|--------------------------------------------|" << endl;
	cout << endl;
}

void menu()
{
	cout << "|============================================|" << endl;
	cout << "|-------------------МЕНЮ---------------------|" << endl;
	cout << "1 - Лист подписчиков на печатную продукцию" << endl;
	cout << "2 - Аккаунты " << endl;
	cout << "0 - Выход" << endl;
	cout << "|--------------------------------------------|" << endl;
	cout << endl;
}

void menuList()
{
	cout << "|============================================|" << endl;
	cout << "|-------РАБОТА С БОЛЬНИЧНЫМИ ЛИСТАМИ---------|" << endl;
	cout << "1 - Просмотреть лист подписчиков" << endl;
	cout << "2 - Вывести список подписчиков за период" << endl;
	cout << "3 - Вывести сумму выплат за период" << endl;
	cout << "0 - Выход" << endl;
	cout << "|--------------------------------------------|" << endl;
	cout << endl;
}

void menuListbyAdmin()
{
	cout << "|============================================|" << endl;
	cout << "|-------РАБОТА С ЛИСТОМ ПОДПИСЧИКОВ---------|" << endl;
	cout << "1 - Просмотреть лист подписчиков" << endl;
	cout << "2 - Добавить подписчика" << endl;
	cout << "3 - Удалить подписчика" << endl;
	cout << "4 - Редактировать подписчика" << endl;
	cout << "5 - Вывести список подписчиков за период" << endl;
	cout << "6 - Вывести сумму выплат за период" << endl;
	cout << "0 - Выход" << endl;
	cout << "|--------------------------------------------|" << endl;
	cout << endl;
}

void menuAccounts()
{
	cout << "|============================================|" << endl;
	cout << "|--------РАБОТА С УЧЁТНЫМИ ЗАПИСЯМИ----------|" << endl;
	cout << "1 - Просмотреть все учетные записи" << endl;
	cout << "2 - Добавить учетную запись" << endl;
	cout << "3 - Удалить учетную запись" << endl;
	cout << "4 - Редактировать учетную запись" << endl;
	cout << "0 - Выход" << endl;
	cout << "|--------------------------------------------|" << endl;
	cout << endl;
}

void optionList()
{
	cout << "|============================================|" << endl;
	cout << "|-----ОПЦИИ РАБОТЫ С ЛИСТОМ ПОДПИСЧИКОВ-----|" << endl;
	cout << "1 - Поиск по ФИО" << endl;
	cout << "2 - Поиск по году" << endl;
	cout << "3 - Поиск по месяцу" << endl;
	cout << "4 - Поиск по дням" << endl;
	cout << "5 - Поиск по сумме оплаты" << endl;
	cout << "6 - Сортировка по ФИО" << endl;
	cout << "7 - Сортировка по месяцу" << endl;
	cout << "8 - Сортировка по сумме оплаты" << endl;
	cout << "0 - Выход" << endl;
	cout << "|--------------------------------------------|" << endl;
	cout << endl;
}

void readFileAccounts(Account *arr_of_accounts, int &number_of_accounts)
{
	ifstream fin(FILE_OF_ACCOUNTS, ios::in); //Открыли файл для чтения

	if (!fin.is_open())
	{
		arr_of_accounts[0].login = "admin";
		arr_of_accounts[0].password = "admin";
		arr_of_accounts[0].role = 1;
		number_of_accounts = 1;
		writeEndFileAccounts(arr_of_accounts[0]);
	}
	else
	{
		number_of_accounts = 0;
		while (!fin.eof())
		{
			fin >> arr_of_accounts[number_of_accounts].login >> arr_of_accounts[number_of_accounts].password >> arr_of_accounts[number_of_accounts].role;
			number_of_accounts++;
		}
	}
	fin.close();  //Закрыли открытый файл
}


void readFileLists(Lists *arr_of_lists, int &number_of_lists)
{
	ifstream fin(FILE_OF_LISTS, ios::in); //Открыли файл для чтения
	number_of_lists = 0;
	while (!fin.eof())
	{
		fin >> arr_of_lists[number_of_lists].FIO >> arr_of_lists[number_of_lists].mounth >> arr_of_lists[number_of_lists].year >> arr_of_lists[number_of_lists].days >> arr_of_lists[number_of_lists].pay;
		number_of_lists++;
	}
	fin.close();  //Закрыли открытый файл
}

void writeFileAccounts(Account *arr_of_accounts, int number_of_accounts)
{
	ofstream fout(FILE_OF_ACCOUNTS, ios::out);  //Открыли файл для записи

	for (int i = 0; i < number_of_accounts; i++)
	{
		if (i < number_of_accounts - 1)
			fout << arr_of_accounts[i].login << " " << arr_of_accounts[i].password << " " << arr_of_accounts[i].role << endl;
		else
			fout << arr_of_accounts[i].login << " " << arr_of_accounts[i].password << " " << arr_of_accounts[i].role;
	}

	fout.close();
}

void writeFileLists(Lists *arr_of_lists, int number_of_lists)
{
	ofstream fout(FILE_OF_LISTS, ios::out);  //Открыли файл для записи

	for (int i = 0; i < number_of_lists; i++)
	{
		if (i < number_of_lists - 1)
			fout << arr_of_lists[i].FIO << " " << arr_of_lists[i].mounth << " " << arr_of_lists[i].year << " " << arr_of_lists[i].days << " " << arr_of_lists[i].pay << endl;
		else
			fout << arr_of_lists[i].FIO << " " << arr_of_lists[i].mounth << " " << arr_of_lists[i].year << " " << arr_of_lists[i].days << " " << arr_of_lists[i].pay;
	}

	fout.close();
}

void writeEndFileAccounts(Account new_account)
{
	ofstream fout(FILE_OF_ACCOUNTS, ios::app);  //Открыли файл для ДОзаписи
	fout << endl;
	fout << new_account.login << " " << new_account.password << " " << new_account.role;

	fout.close();
}

void writeEndFileLists(Lists new_lists)
{
	ofstream fout(FILE_OF_LISTS, ios::app);  //Открыли файл для ДОзаписи
	fout << endl;
	fout << new_lists.FIO << " " << new_lists.mounth << " " << new_lists.year << " " << new_lists.days << " " << new_lists.pay;

	fout.close();
}

void showAccounts(Account *arr_of_accounts, int number_of_accounts)
{
	cout << "ТАБЛИЦА УЧЕТНЫХ ЗАПИСЕЙ ПОЛЬЗОВАТЕЛЕЙ" << endl;
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "№ " << setw(15) << left << "Логин" << setw(15) << left << "Пароль" << setw(3) << left << "Роль" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_accounts; i++)
		cout << setw(4) << left << i + 1 <<
		setw(15) << left << arr_of_accounts[i].login <<
		setw(15) << left << arr_of_accounts[i].password <<
		setw(3) << left << arr_of_accounts[i].role << endl;
	cout << setw(37) << "--------------------------------------" << endl;
}

void showLists(Lists *arr_of_lists, int number_of_lists)
{
	cout << "ТАБЛИЦА ПОДПИСЧИКОВ" << endl;
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "|№ " << setw(15) << left << "|ФИО" << setw(15) << left << "|Месяц" << setw(15) << left << "|Кол-во дней" << setw(15) << left << "|Год" << setw(15) << left << "|Сумма оплаты" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_lists; i++)
		cout << setw(4) << left << i + 1 <<
		setw(15) << left << arr_of_lists[i].FIO <<
		setw(15) << left << arr_of_lists[i].mounth <<
		setw(15) << left << arr_of_lists[i].days << 
		setw(15) << left << arr_of_lists[i].year << 
		setw(15) << left << arr_of_lists[i].pay << endl;
	cout << setw(37) << "--------------------------------------" << endl;
}

void showFoundLists(Lists *arr_of_lists, int number_of_lists)
{
	
		cout << setw(4) << left << number_of_lists + 1 <<
		setw(15) << left << arr_of_lists[number_of_lists].FIO <<
		setw(15) << left << arr_of_lists[number_of_lists].mounth <<
		setw(15) << left << arr_of_lists[number_of_lists].days <<
		setw(15) << left << arr_of_lists[number_of_lists].year <<
		setw(15) << left << arr_of_lists[number_of_lists].pay << endl;
	cout << setw(37) << "--------------------------------------" << endl;
}

void addAccount(Account *arr_of_accounts, int &number_of_accounts)
{
	number_of_accounts++;
		cout << endl;
		cout << "=====================================================================" << endl;
		cout << "Введите данные новой учетной записи:" << endl;

		cout << "Логин: ";
		cin >> arr_of_accounts[number_of_accounts - 1].login;

		cout << "Пароль: ";
		cin >> arr_of_accounts[number_of_accounts - 1].password;

		cout << "Роль: ";
		cin >> arr_of_accounts[number_of_accounts - 1].role;
		if ((arr_of_accounts[number_of_accounts - 1].role == 0) || (arr_of_accounts[number_of_accounts - 1].role == 1))
		{
			writeEndFileAccounts(arr_of_accounts[number_of_accounts - 1]);

			system("cls");
			cout << "Новая учетная запись добавлена!" << endl;
			cout << endl;
		}
		else
		{
			arr_of_accounts[number_of_accounts - 1].login = "";
			arr_of_accounts[number_of_accounts - 1].password = "";
			arr_of_accounts[number_of_accounts - 1].role = NULL;
			cout << "Неправильно выбрана роль!" << endl;
		}
}

void addLists(Lists *arr_of_lists, int &number_of_lists)
{
	int i;
	bool FLAG = true;
	number_of_lists++;

	cout << endl;
	cout << "=====================================================================" << endl;
	cout << "Введите данные нового подписчика:" << endl;

	cout << "ФИО: ";
	cin >> arr_of_lists[number_of_lists - 1].FIO;

	cout << "Месяц: ";
	cin >> arr_of_lists[number_of_lists - 1].mounth;
	
	cout << "Год: ";
	cin >> arr_of_lists[number_of_lists - 1].year;

	cout << "День: ";
	cin >> arr_of_lists[number_of_lists - 1].days;

	cout << "Сумма оплаты: ";
	cin >> arr_of_lists[number_of_lists - 1].pay;

	writeEndFileLists(arr_of_lists[number_of_lists - 1]);

	system("cls");
	cout << "Подписчик добавлен!" << endl;
	cout << endl;
}

void delAccount(Account *arr_of_accounts, int &number_of_accounts)
{
	cout << endl;
	cout << "=====================================================================" << endl;
	cout << "Введите номер удаляемой учетной записи: ";

	int del_item;
	cin >> del_item;
	for (int i = del_item - 1; i < number_of_accounts - 1; i++)
		arr_of_accounts[i] = arr_of_accounts[i + 1];

	number_of_accounts--;

	system("cls");
	cout << "Учетная запись удалена!" << endl;
	cout << endl;
}

void delLists(Lists *arr_of_lists, int &number_of_lists)
{
	cout << endl;
	cout << "=====================================================================" << endl;
	cout << "Введите номер удаляемого подписчика!: ";

	int del_item;
	cin >> del_item;
	for (int i = del_item - 1; i < number_of_lists - 1; i++)
		arr_of_lists[i] = arr_of_lists[i + 1];

	number_of_lists--;

	system("cls");
	cout << "Учетная запись удалена!" << endl;
	cout << endl;
}

void updateAccount(Account *arr_of_accounts, int number_of_accounts)
{
	cout << endl;
	cout << "=====================================================================" << endl;
	cout << "Введите номер редактируемой учетной записи: ";

	int update_item;
	cin >> update_item;

	cout << "Отредактируйте данные учетной записи:" << endl;

	cout << "Логин: ";
	cin >> arr_of_accounts[update_item - 1].login;

	cout << "Пароль: ";
	cin >> arr_of_accounts[update_item - 1].password;

	cout << "Роль: ";
	cin >> arr_of_accounts[update_item - 1].role;

	system("cls");
	cout << "Изменения успешно внесены!" << endl;
	cout << endl;
}

void updateLists(Lists *arr_of_lists, int number_of_lists)
{
	cout << endl;
	cout << "=====================================================================" << endl;
	cout << "Введите номер редактируемой учетной записи: ";

	int update_item;
	cin >> update_item;

	cout << "Отредактируйте данные подписчика:" << endl;

	cout << "ФИО: ";
	cin >> arr_of_lists[number_of_lists - 1].FIO;

	cout << "Месяц: ";
	cin >> arr_of_lists[number_of_lists - 1].mounth;

	cout << "Год: ";
	cin >> arr_of_lists[number_of_lists - 1].days;

	cout << "День: ";
	cin >> arr_of_lists[number_of_lists - 1].mounth;

	cout << "Сумма оплаты: ";
	cin >> arr_of_lists[number_of_lists - 1].days;

	system("cls");
	cout << "Изменения успешно внесены!" << endl;
	cout << endl;
}

void foundList(Lists *arr_of_lists, int number_of_lists)
{
	int FoundYear = 0;
	int FoundMounth = 0;
	cout << "Введите год по которому будете искать: ";
	(cin >> FoundYear).get();
	cout << "Введите месяц по которому будете искать: ";
	(cin >> FoundMounth).get();
	if (cin.fail())
	{
		cout << "Год и месяц должны быть указаны цифрами" << endl;
		system("pause");
	}
	cout << "ТАБЛИЦА ПОДПИСЧИКОВ" << endl;
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "|№ " << setw(15) << left << "|ФИО" << setw(15) << left << "|Месяц" << setw(15) << left << "|Кол-во дней" << setw(15) << left << "|Год" << setw(15) << left << "|Сумма оплаты" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_lists; i++)
	{
		if ((arr_of_lists[i].mounth == FoundMounth) && (arr_of_lists[i].year == FoundYear)) 
		{
			showFoundLists(arr_of_lists, i);
		}
	}
	
}

void foundPay(Lists *arr_of_lists, int number_of_lists)
{
	int sum = 0;
	int FoundYear = 0;
	int FoundMounth = 0;
	cout << "Введите год по которому будете искать: ";
	(cin >> FoundYear).get();
	cout << "Введите месяц по которому будете искать: ";
	(cin >> FoundMounth).get();
	if (cin.fail())
	{
		cout << "Год и месяц должны быть указаны цифрами" << endl;
		system("pause");
	}

	for (int i = 0; i < number_of_lists; i++)
	{
		if ((arr_of_lists[i].mounth == FoundMounth) && (arr_of_lists[i].year == FoundYear))
		{
			sum = sum + arr_of_lists[i].pay;
		}
	}
	cout << "Сумма за выбранный период равна - " << sum << endl;
}

void foundForFIO(Lists *arr_of_lists, int number_of_lists)
{
	string FIO;
	cout << "Введите ФИО: ";
	(cin >> FIO).get();
	
	cout << "ТАБЛИЦА ПОДПИСЧИКОВ" << endl;
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "|№ " << setw(15) << left << "|ФИО" << setw(15) << left << "|Месяц" << setw(15) << left << "|Кол-во дней" << setw(15) << left << "|Год" << setw(15) << left << "|Сумма оплаты" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_lists; i++)
	{
		if (arr_of_lists[i].FIO == FIO)
		{
			showFoundLists(arr_of_lists, i);
		}
	}
}

void foundForMounth(Lists *arr_of_lists, int number_of_lists)
{
	int mounth;
	cout << "Введите месяц: ";
	(cin >> mounth).get();

	cout << "ТАБЛИЦА ПОДПИСЧИКОВ" << endl;
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "|№ " << setw(15) << left << "|ФИО" << setw(15) << left << "|Месяц" << setw(15) << left << "|Кол-во дней" << setw(15) << left << "|Год" << setw(15) << left << "|Сумма оплаты" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_lists; i++)
	{
		if (arr_of_lists[i].mounth == mounth)
		{
			showFoundLists(arr_of_lists, i);
		}
	}
}

void foundForDay(Lists *arr_of_lists, int number_of_lists)
{
	int days;
	cout << "Введите количество дней: ";
	(cin >> days).get();

	cout << "ТАБЛИЦА ПОДПИСЧИКОВ" << endl;
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "|№ " << setw(15) << left << "|ФИО" << setw(15) << left << "|Месяц" << setw(15) << left << "|Кол-во дней" << setw(15) << left << "|Год" << setw(15) << left << "|Сумма оплаты" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_lists; i++)
	{
		if (arr_of_lists[i].days == days)
		{
			showFoundLists(arr_of_lists, i);
		}
	}
}

void foundForYear(Lists *arr_of_lists, int number_of_lists)
{
	int year;
	cout << "Введите год: ";
	(cin >> year).get();

	cout << "ТАБЛИЦА ПОДПИСЧИКОВ" << endl;
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "|№ " << setw(15) << left << "|ФИО" << setw(15) << left << "|Месяц" << setw(15) << left << "|Кол-во дней" << setw(15) << left << "|Год" << setw(15) << left << "|Сумма оплаты" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_lists; i++)
	{
		if (arr_of_lists[i].year == year)
		{
			showFoundLists(arr_of_lists, i);
		}
	}
}

void foundForPay(Lists *arr_of_lists, int number_of_lists)
{
	int pay;
	cout << "Введите сумму выплаты: ";
	(cin >> pay).get();

	cout << "ТАБЛИЦА ПОДПИСЧИКОВ" << endl;
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "|№ " << setw(15) << left << "|ФИО" << setw(15) << left << "|Месяц" << setw(15) << left << "|Кол-во дней" << setw(15) << left << "|Год" << setw(15) << left << "|Сумма оплаты" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_lists; i++)
	{
		if (arr_of_lists[i].pay == pay)
		{
			showFoundLists(arr_of_lists, i);
		}
	}
}

void SortByFIO(Lists *arr_of_lists, int number_of_lists)
{
	Lists tmp;
	system("cls");
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "|№ " << setw(15) << left << "|ФИО" << setw(15) << left << "|Месяц" << setw(15) << left << "|Кол-во дней" << setw(15) << left << "|Год" << setw(15) << left << "|Сумма оплаты" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_lists; i++)
	{
		for (int j = 0; j < number_of_lists - 1; j++)
		{
			if (arr_of_lists[j].FIO > arr_of_lists[j + 1].FIO)
			{
				tmp = arr_of_lists[j + 1];
				arr_of_lists[j + 1] = arr_of_lists[j];
				arr_of_lists[j] = tmp;
			}
		}
		showFoundLists(arr_of_lists, i);
	}	
}

void SortByMounth(Lists *arr_of_lists, int number_of_lists)
{
	Lists tmp;
	system("cls");
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "|№ " << setw(15) << left << "|ФИО" << setw(15) << left << "|Месяц" << setw(15) << left << "|Кол-во дней" << setw(15) << left << "|Год" << setw(15) << left << "|Сумма оплаты" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_lists; i++)
	{
		for (int j = 0; j < number_of_lists - 1; j++)
		{
			if (arr_of_lists[j].mounth > arr_of_lists[j + 1].mounth)
			{
				tmp = arr_of_lists[j + 1];
				arr_of_lists[j + 1] = arr_of_lists[j];
				arr_of_lists[j] = tmp;
			}
		}
		showFoundLists(arr_of_lists, i);
	}
}

void SortByPay(Lists *arr_of_lists, int number_of_lists)
{
	Lists tmp;
	system("cls");
	cout << setw(37) << "======================================" << endl;
	cout << setw(4) << left << "|№ " << setw(15) << left << "|ФИО" << setw(15) << left << "|Месяц" << setw(15) << left << "|Кол-во дней" << setw(15) << left << "|Год" << setw(15) << left << "|Сумма оплаты" << endl;
	cout << setw(37) << "======================================" << endl;
	for (int i = 0; i < number_of_lists; i++)
	{
		for (int j = 0; j < number_of_lists - 1; j++)
		{
			if (arr_of_lists[j].pay > arr_of_lists[j + 1].pay)
			{
				tmp = arr_of_lists[j + 1];
				arr_of_lists[j + 1] = arr_of_lists[j];
				arr_of_lists[j] = tmp;
			}
		}
		showFoundLists(arr_of_lists, i);
	}
}