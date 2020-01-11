#include <stdio.h>
#include "libft/libft.h"


int main() {
    char c[] = {1, 5, 3, 3, 8, 2, 4,20,1,9,3};
    int i = 0;
    int j = 0;
    int k;
    int z = 0;
   int size = (int)ft_strlen(c) - 1;

    //сортировка пузырьком
//    while (size--)
//    {
//        j = 0;
//        while (c[j + 1] != '\0')
//        {
//            if (c[j] > c[j + 1])
//            {
//                k = c[j];
//                c[j] = c[j + 1];
//                c[j + 1] = k;
//            }
//            j++;
//        }
//    }
    //сортировка выбором
//    while (c[i] != '\0')
//    {
//        j = i;
//        while(c[j] !='\0')
//        {
//            if (c[j] < c[i])
//            {
//                k = c[i];
//                c[i] = c[j];
//                c[j] = k;
//            }
//            j++;
//        }
//        i++;
//    }
    //сортировка вставками
//    while (i < size)
//    {
//        k = c[i];
//        j = i - 1;
//        while(j >= 0 && c[j] > k)
//        {
//            c[j + 1] = c[j];
//            j--;
//        }
//        c[j + 1] = k;
//        i++;
//    }
    while (z != (int)ft_strlen(c) - 1)
        printf("%d ",(int)c[z++]);
    return (0);
}