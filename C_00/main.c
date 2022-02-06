#include "./ex00/ft_putchar.c"
#include "./ex01/ft_print_alphabet.c"
#include "./ex02/ft_print_reverse_alphabet.c"
#include "./ex03/ft_print_numbers.c"
#include "./ex04/ft_is_negative.c"
#include "./ex05/ft_print_comb.c"
#include "./ex06/ft_print_comb2.c"
#include "./ex07/ft_putnbr.c"
#include "./ex08/ft_print_combn.c"
#include <stdio.h>

int main(){
	printf("----ex00----\n42\n");
	ft_putchar('4');
	ft_putchar('2');
	printf("\n\n");
	printf("----ex01----\n");
	printf("abcdefghijklmnopqrstuvwxyz\n");
	ft_print_alphabet();
	printf("\n\n");
	printf("----ex02----\n");
	printf("zyxwvutsrqponmlkjihgfedcba\n");
	ft_print_reverse_alphabet();
	printf("\n\n");
	printf("----ex03----\n");
	printf("0123456789\n");
	ft_print_numbers();
	printf("\n\n");
	printf("----ex04----\n");
	printf("PPN\n");
	ft_is_negative(1);
	ft_is_negative(0);
	ft_is_negative(-10);
	printf("\n\n");
	printf("----ex05----\n");
	ft_print_comb();
	printf("\n\n");
	printf("----ex06----\n");
	//ft_print_comb2();
	printf("\n\n");
	printf("----ex07----\n");
	printf("12225281\n");
	ft_putnbr(12225281);
	printf("\n2147483647\n");
	ft_putnbr(2147483647);
	printf("\n-47483648\n");
	ft_putnbr(-47483648);
	printf("\n-2147483648\n");
	ft_putnbr(-2147483648);
	printf("\n0\n");
	ft_putnbr(0);
	printf("\n-1\n");
	ft_putnbr(-1);
	printf("\n\n");
	printf("----ex08----\n");
	ft_print_combn(1);
	ft_putchar('\n');
	ft_print_combn(2);
	ft_putchar('\n');
	ft_print_combn(5);
	ft_putchar('\n');
	//ft_print_combn(9);
	ft_putchar('\n');
	return 0;
}