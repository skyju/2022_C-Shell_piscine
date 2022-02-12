#include <stdio.h>
#include "./ex00/ft_strcmp.c"
#include "./ex01/ft_strncmp.c"
#include "./ex02/ft_strcat.c"
#include "./ex03/ft_strncat.c"
#include "./ex04/ft_strstr.c"
#include "./ex05/ft_strlcat.c"
#include <string.h>

int	main(void)
{
	{
		char str1[500] = "Hello Wiorld!";
		char str2[500] = "Hello Wáell?!";
		char str3[500] = "abc";
		char str4[500] = "ab";

		printf("----ex00----\n");
		printf("%s\n%s\n",str1, str2);
		printf("[ Compare ]\n");
		printf("원본함수\n%d\n구현함수\n%d\n", strcmp(str1, str2), ft_strcmp(str1, str2));
		printf("\n");
		printf("원본함수\n%d\n구현함수\n%d\n", strcmp(str3, str4), ft_strcmp(str3, str4));
	}
	printf("\n");

	{
		char str1[500] = "Hello World!";
		char str2[500] = "Hello Worl";

		printf("----ex01----\n");
		printf("%s\n%s\n",str1, str2);
		printf("[ Compare ]\n");
		printf("원본함수\n%d\n구현함수\n%d\n", strncmp(str1, str2, 5), ft_strncmp(str1, str2, 5));
		printf("\n");
		printf("원본함수\n%d\n구현함수\n%d\n", strncmp(str1, str2, 0), ft_strncmp(str1, str2, 0));
		printf("\n");
		printf("원본함수\n%d\n구현함수\n%d\n", strncmp(str1, str2, 30), ft_strncmp(str1, str2, 30));
		printf("\n");
		printf("원본함수\n%d\n구현함수\n%d\n", strncmp(str1, str2, -1), ft_strncmp(str1, str2, -1));
	}

	printf("\n");
	{
		char str1[500] = "Hello World! ";
		char str2[500] = "It is nice to see ya";

		printf("----ex02----\n");
		printf("문자열 1: %s\n문자열 2: %s\n",str1, str2);
		printf("dest: 문자열 1\nsrc : 문자열 2\n");
		printf("------------------------\n");
		printf("---------[ 원본함수 ]-------\n");
		printf("%s\n", strcat(str1, str2));
		printf("\n");
		printf("--After cat--\n");
		printf("문자열 1: %s\n문자열 2: %s\n",str1, str2);
	}

	printf("\n");
	{
		char str1[500] = "Hello World! ";
		char str2[500] = "It is nice to see ya";
		printf("---------[ 구현함수 ]---------\n");
		printf("\n%s\n", ft_strcat(str1, str2));
		printf("\n");
		printf("--After cat--\n");
		printf("문자열 1: %s\n문자열 2: %s\n",str1, str2);

	}
	printf("\n");

	{
		char str1[500] = "Hello World! ";
		char str2[500] = "It is nice to see ya";

		printf("----ex03----\n");
		printf("%s\n%s\n",str1, str2);
		printf("5 Cat\n");
		printf("cated srt : %s\n", strncat(str1, str2, 5) );
		printf("After 5 cat\n");
		printf("%s\n%s\n", str1, str2);	
	}
	printf("\n");
	{
		char str1[500] = "Hello World! ";
		char str2[500] = "It is nice to see ya";

		printf("test\n");
		printf("%s\n%s\n",str1, str2);
		printf("5 Cat\n");
		printf("cated str : %s\n", ft_strncat(str1, str2, 5) );
		printf("After 5 cat\n");
		printf("%s\n%s\n", str1, str2);
	}
	printf("\n");
	{
		char str1[500] = "Hello My name is sryou and sryou is my name.. Nice to meet you ";
		char str2[500] = "sryou";
		char str3[500] = "My name is happy";

		printf("----ex04----\n");
		printf("%s\n%s\n", str1, str2);
		printf("Find str : %s\n", strstr(str1, str2));
		printf("Find str : %s\n", strstr(str1, str3));
		printf("Find str : %s\n", strstr(str2, str3));
		printf("After find\n%s\n%s\n%s\n", str1, str2, str3);	
	}
	printf("\n");
	{
		char str1[500] = "Hello My name is sryou and sryou is my name.. Nice to meet you ";
		char str2[500] = "sryou";
		char str3[500] = "My name is happy";

		printf("test\n");
		printf("%s\n%s\n", str1, str2);
		printf("Find str : %s\n", ft_strstr(str1, str2));
		printf("Find str : %s\n", ft_strstr(str1, str3));
		printf("Find str : %s\n", ft_strstr(str2, str3));
		printf("After find\n%s\n%s\n%s\n", str1, str2, str3);	
	}
	printf("\n");
	{
		char str1[500] = "strlcat! ";
		char str2[500] = "But I don't like cat...";

		printf("----ex05----\n");
		printf("원래 문자열 \n%s\n%s\n",str1, str2);
		printf("--------------\n");

		printf("5 Cat\n");
		printf("cated val : %lu\n", strlcat(str1, str2, 5) );
		printf("After 5 cat\n");
		printf("%s\n%s\n", str1, str2);	

		printf("\n");

		printf("30 Cat\n");
		printf("cated val : %lu\n", strlcat(str1, str2, 30) );
		printf("After 30 cat\n");
		printf("%s\n%s\n", str1, str2);

		printf("\n");

		printf("15 Cat\n");
		printf("cated val : %lu\n", strlcat(str1, str2, 15) );
		printf("After 15 cat\n");
		printf("%s\n%s\n", str1, str2);

		printf("\n");

		printf("0 Cat\n");
		printf("cated val : %lu\n", strlcat(str1, str2, 0) );
		printf("After 0 cat\n");
		printf("%s\n%s\n", str1, str2);	
	}
	printf("\n");
	{
		char str1[500] = "strlcat! ";
		char str2[500] = "But I don't like cat...";

		printf("----구현함수----\n");
		printf("원래 문자열 \n%s\n%s\n",str1, str2);
		printf("--------------\n");

		printf("5 Cat\n");
		printf("cated val : %u\n", ft_strlcat(str1, str2, 5) );
		printf("After 5 cat\n");
		printf("%s\n%s\n", str1, str2);

		printf("\n");

		printf("30 Cat\n");
		printf("cated val : %u\n", ft_strlcat(str1, str2, 30) );
		printf("After 30 cat\n");
		printf("%s\n%s\n", str1, str2);

		printf("\n");

		printf("15 Cat\n");
		printf("cated val : %u\n", ft_strlcat(str1, str2, 15) );
		printf("After 15 cat\n");
		printf("%s\n%s\n", str1, str2);

		printf("\n");

		printf("0 Cat\n");
		printf("cated val : %u\n", ft_strlcat(str1, str2, 0) );
		printf("After 0 cat\n");
		printf("%s\n%s\n", str1, str2);	
	}
	printf("\n");

	return 0;
}