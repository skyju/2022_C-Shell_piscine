#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_printer(int *arr, int n)
{
    int i;

    i = 0;
    while (i < n-1)
    {
        if (arr[i] >= arr[i+1])
            return ;
        ++i;
    }
    i = 0;
    while (i < n)
        ft_putchar(arr[i++] + '0'); 
    if (arr[0] != 10-n)
        write(1, ", ", 2);
}

void ft_print_combn(int n)
{
    int arr[n];
    int i;

    if (n <= 0 || n >= 10)
        return ;
    i = 0;
    while (i < n)
        arr[i] = i++;
    while (arr[0] != 10-n)
    {   
        ft_printer(arr, n);
        arr[n - 1]++; //맨 끝자리 증가시킴(~9)
        i = n - 1;
        while (i) // arr[0] 이전에서 멈춤,, arr[0]은 다음자리가 없으므로
        {
            if(arr[i] > 9) // 이전 자리가 9보다 커지면
            {
                arr[i - 1]++; // 그 다음자리를 증가시키고
                arr[i] = 0; // 해당 자리는 0으로 초기화
            }
            --i;
        }
    }
}

int main(void)
{
    ft_print_combn(6);
}
