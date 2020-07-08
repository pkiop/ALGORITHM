#include <stdio.h>

void ft_putchar(char a) {
    printf()
}
void a(int row, int col, int x, int y) {

    if((row == 0 && col == 0) || (row == y - 1 && col == x-1))
        ft_putchar('/');
    else if((row == 0 && col == x-1) || (row == y-1 && col == 0))
        ft_putchar('\\');
    else if((row != 0 && row != y-1) && (col != 0 && col != x-1))
        ft_putchar(' ');
	else 
        ft_putchar('*');
}


int main(void) {
    for(int y=0;y<5;++y) {
        for(int x=0;x<5;++x){

        }
    }
}