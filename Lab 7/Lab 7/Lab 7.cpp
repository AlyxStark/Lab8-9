#include <iostream>
#include <fstream> //file
#include <windows.h> //SYSTEMTIME
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	ofstream file;
	file.open("C:\\Users\\Lyx\\Desktop\\Проекты\\Lab 7\\log.txt", ios::app);
	SYSTEMTIME st;
	GetLocalTime(&st);// инициализ времени
	file << "Программа запущенна в " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;

	int a, b, c, d, s;
	cout << "а) Являются ли поля одинакового цвета?" << endl << "Введите координаты первой фигуры (числа от 1 до 8): " << endl << "k = ";
	cin >> a;
	if (a > 8 || a < 1) {
		cout << "Введите число от 1 до 8" << endl;
		file << "Программа закрыта т.к. введено неверное значение" << endl;
		return 0;
	}
	cout << "l= ";
	cin >> b;
	if (b > 8 || b < 1) {
		cout << "Введите число от 1 до 8" << endl;
		file << "Программа закрыта т.к. введено неверное значение " << endl;
		return 0;
	}
	cout << "Введите координаты второй фигуры (числа от 1 до 8): " << endl;
	cout << "m= ";
	cin >> c;
	if (c > 8 || c < 1) {
		cout << "Введите число от 1 до 8" << endl;
		file << "Программа закрыта т.к. введено неверное значение " << endl;
		return 0;
	}
	cout << "n= ";
	cin >> d;
	if (d > 8 || d < 1) {
		cout << "Введите число от 1 до 8" << endl;
		file << "Программа закрыта т.к. введено неверное значение " << endl;
		return 0;
	}
	s = a + b + c + d;
	if (s % 2 == 0) {
		cout << "Эти поля одного цвета" << endl;
	}
	else {
		cout << "Эти поля разного цвета" << endl;
	}//готова буква а
	cout << endl << "б) Угрожает ли фигура полю m,n?" << endl << "Какая фигура стоит на поле? " << endl << "1-ферзь" << endl << "2-ладья" << endl << "3-слон" << endl << "4-конь" << endl;
	int f;
	while (1) {
		cin >> f;
		if ((f < 5 && f > 0)) {
			break;
		}
		cout << "Введите число от 1 до 4" << endl;
		file << "Введено значение не в интервале от 1 до 4" << endl;
	}
	if (f == 1) {
		if (!(a == c && b == d) && (a == c || b == d || abs(a - c) == abs(b - d))) {
			cout << "Угрожает" << endl;
		}
		else {
			cout << "Не угрожает" << endl;
		}
	}
	if (f == 2) {
		if (a == c || b == d) {
			cout << "Угрожает" << endl;
		}
		else {
			cout << "Не угрожает" << endl;
		}
	}
	if (f == 3) {
		if (abs(a - c) == abs(b - d)) {
			cout << "Угрожает" << endl;
		}
		else {
			cout << "Не угрожает" << endl;
		}
	}
	if (f == 4) {
		if (abs(a - c) * abs(b - d) == 2) {
			cout << "Угрожает" << endl;
		}
		else {
			cout << "Не угрожает" << endl;
		}
	}//готова буква б
	cout << endl << "в) Можно ли попасть на поле m,n?" << endl << "Какая фигура стоит на поле? " << endl << "1-ферзь" << endl << "2-ладья" << endl << "3-слон" << endl;
	int h;
	while (1) {
		cin >> h;
		if ((h < 4 && h > 0)) {
			break;
		}
		cout << "Введите число от 1 до 3 " << endl;
		file << "Введено значенние не в интервале от 1 до 3" << endl;
	}
	if (f == h) {
		cout << "Можно за 1 ход" << endl;
	}
	if (h == 1) {
		if (!(a == c && b == d) && (a == c || b == d || abs(a - c) == abs(b - d))) {
			cout << "Можно за 1 ход" << endl;
		}
		else {
			cout << "Можно за 2 хода. Если 1 ход сделан на клетку a= " << a << ", b= " << d << endl;
		}

	}
	if (h == 2) {
		if (a == c || b == d) {
			cout << "Можно за 1 ход" << endl;
		}
		else {
			cout << "Можно за 2 хода. Если 1 ход сделан на клетку a= " << a << ", b= " << d << endl;
		}
	}
	int x, y;
	if (h == 3) {
		if (s % 2 == 0) {
			if (abs(a - c) == abs(b - d)) {
				cout << "Можно за 1 ход" << endl;
			}
			else {
				x = (a + b + c - d) / 2;
				y = (a + b - c + d) / 2;
				if ((x > 8) || (x < 1) || (y > 8) || (y < 1)) {
					x = (c + d + a - b) / 2;
					y = (c + d - a + b) / 2;
				}
				cout << "Можно за 2 хода. Если 1 ход сделан на клетку a= " << x << ", b= " << y << endl;
			}
		}
		else {
			cout << "Нельзя, поля разного цвета" << endl;
		}//рисуем доску
	}
	int z = 0;
	cout << "Нарисовать доску с фигурами?" << endl << "1-да" << endl << "2-нет" << endl;
	while (1) {
		cin >> z;
		if ((z < 3 && z > 0)) {
			break;
		}
		cout << "Введите число 1 или 2" << endl;
		file << "Введено значенние не в интервале от 1 до 2" << endl;
	}
	if (z == 1) {
		a = (a - 1) * 5;
		b = (8 - b) * 5;
		c = (c - 1) * 5;
		d = (8 - d) * 5;
		for (int column = 0; column < 40; column++) {
			for (int line = 0; line < 40; line++) {
				if ((line / 5 + column / 5) & 1) {
					if ((line == a || line == a + 1 || line == a + 2 || line == a + 3 || line == a + 4) && (column == b || column == b + 1 || column == b + 2 || column == b + 3 || column == b + 4) || ((line == c || line == c + 1 || line == c + 2 || line == c + 3 || line == c + 4) && (column == d || column == d + 1 || column == d + 2 || column == d + 3 || column == d + 4))) {
						cout << "#";
					}
					else {
						std::cout << "*";
					}
				}
				else if ((line == a || line == a + 1 || line == a + 2 || line == a + 3 || line == a + 4) && (column == b || column == b + 1 || column == b + 2 || column == b + 3 || column == b + 4) || ((line == c || line == c + 1 || line == c + 2 || line == c + 3 || line == c + 4) && (column == d || column == d + 1 || column == d + 2 || column == d + 3 || column == d + 4))) {
					cout << "#";
				}
				else {
					std::cout << " ";
				}
			}
			cout << endl;
		}
	}
	GetLocalTime(&st);
	file << "Программа закрыта в " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
	file.close();
	system("pause");
}

