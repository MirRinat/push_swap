#include <stdio.h>
#include "libft/libft.h"


void qs(int *s_arr,int first,int last)
{
	if (first < last)
	{
		int left = first, right = last;
		int middle = s_arr[(int)(left + right) / 2];
		do
		{
			while (s_arr[left] < middle) left++;
			while (s_arr[right] > middle) right--;
			if (left <= right)
			{
				int tmp = s_arr[left];
				s_arr[left] = s_arr[right];
				s_arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qs(s_arr, first, right);
		qs(s_arr, left, last);
	}
}

int main() {
    int c[] = {1, 5, 3,6,2,4,8,10,23,13};
    int i = 0;
    int j = 0;
    int k;
    int z = 0;
   int size = sizeof(c)/ sizeof(c[0]);
//   int middle;
//   middle = c[0]

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
//    сортировка вставками
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
//	быстрая сортировка
	qs(c,-1,size);

    while (z != (size))
        printf("%d ",(int)c[z++]);
    return (0);
}