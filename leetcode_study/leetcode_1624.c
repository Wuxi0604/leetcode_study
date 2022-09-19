#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int 
maxLengthBetweenEqualCharacters(
    char*       s
) 
{
    int     sign[26];
    int     int_size = sizeof(int);
    memset(sign, -1, int_size * 26);
    int     len = strlen(s);
    char*   front = s;
    char*   end = s + len - 1;
    bool    is_find = false;
    int     index = -1;
    int     cur = 0;
    int     result = -1;
    int     temp_result;

    if(len == 2 && *front == *end)
    {
        return 0;
    }
    //需要两趟遍历
    for(cur = 0; cur < len; cur++)
    {
        index = ctoi(*front);
        if(sign[index] == -1)
        {
            sign[index] = cur;
        }
        if(cur == len)
        {
            continue;
        }
        front++;
    }

    //需要两趟遍历
    for(cur = 0; cur < len; cur++)
    {
        index = ctoi(*end);
        if(sign[index] != -1 && sign[index] != len - cur - 1)
        {
            temp_result = len - sign[index] - 2;
            if(result == -1)
            {
                result = temp_result;
            }
            else
            {
                result = result < temp_result ? temp_result : result;
            }
        }
        if(cur == len)
        {
            continue;
        }
        end--;
    }

    return result;
}

int
ctoi(
    char  a
)
{
    return a - 'a';
}

//int
//main()
//{
//    char* test = "scayofdzca";
//    int result = maxLengthBetweenEqualCharacters(test);
//    printf("结果是：%d", result);
//}