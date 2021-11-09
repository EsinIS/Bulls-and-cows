#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;
bool ch_in_st(string s, char a) {
	return s.find(a) != string::npos;
}
int main() {
	setlocale(0, "");
	srand(time(0));
	int x = rand() % 10000 + 1000, bulls = 0, cows = 0, y, flag = 0;
	if (x > 9999) {
		x -= 1000;
	}
	string s, s1;
	s = to_string(x);
	cout << s << endl;
	while (bulls != 4) {
		cout << "Введите новое четырехзначное число.\nПлюсы - кол-во точно угаданных цифр.\nМинусы - кол-во цифр, находящихся не на своём месте." << endl;
		cin >> s1;
		for (int i = 0; i < s1.size(); i++) {
			if ((int)s1[i] < 48 || (int)s1[i] > 57) {
				flag = 1;
			}
		}
		if (flag == 1 || s1.size() != 4) {
			cout << "Введите ровно четыре цифры без пробелов." << endl;
		}
		else {
			for (int i = 0; i < s1.size(); i++) {
				if (ch_in_st(s, s1[i]) && s[i] == s1[i]) {
					bulls += 1;
				}
				else if (ch_in_st(s, s1[i]) && s[i] != s1[i]) {
					cows += 1;
				}
			}
		}
		if (bulls != 0) {
			for (int i = 0; i < bulls; i++) {
				cout << "+ ";
			}
			cout << endl;
		}
		if (cows != 0) {
			for (int i = 0; i < cows; i++) {
				cout << "- ";
			}
			cout << endl;
		}
		
		flag = 0;
		if (bulls != 4) {
			bulls = 0;
			cows = 0;
		}
	}
	cout << "Поздравляем! Вы угадали загаданное число!";
}

	
