#include <iostream>

#define BLANK 0
#define STAR 1

using namespace std;

void go(char **a, int x, int y, int n, int color);

int main(void)
{
	int n;
	cin >> n;
	char** a = new char*[n]; // in C, a = char(**)malloc(sizeof(char*)*n);
	for (int i = 0; i < n; ++i) {
		a[i] = new char[n + 1]; // in C, a = (char*)malloc(sizeof(char)*(n+1));
	}
	for (int i = 0; i < n; ++i) { // number of row
		for (int j = 0; j < n + 1; ++j) { // number of col (row + 1 by expected output)
			a[i][j] = 0; //default zero == all BLANK
		}
	}
	go(a, 0, 0, n, STAR);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << '\n';
	}
	return 0;
}

void go(char **a, int x, int y, int n, int color) { // x = row, y = col, n => divided by 3
	int newColor;
	if (color == BLANK) { // if color is BLANK(middle case), put whitespace ' '
		for (int i = x; i < x + n; ++i) {
			for (int j = y; j < y + n; ++j) {
				a[i][j] = ' ';
			}
		}
	}
	else {
		if (n == 1) {
			a[x][y] = '*';
		}
		else {
			newColor = STAR;
			int m = n / 3;
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					if (i == 1 && j == 1) {
						newColor = BLANK;
					}
					else {
						newColor = STAR;
					}
					go(a, x + m * i, y + m * j, m, newColor);
				}
			}
		}
	}
}