#include <stdio.h>

void insert(int H[], int n)
{
    int i = n, temp;
    temp = H[i];

    while (i > 1 && temp > H[i/2])
    {
        H[i] = H[i / 2];
        i = i / 2;
    }
    H[i] = temp;
}

int delete(int H[], int n)
{
    int i, j, x, temp, val = H[i];
    x = H[n];
    H[1] = H[n];
    
    H[n] = val;
    
    i = 1;
    j = i * 2;

    while (j < n - 1)
    {
        if (H[j+1] > H[j])
            j++;
        if (H[i] < H[j])
        {
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}

void create_heap()
{

}

int main(void)
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};

    for (int i = 2; i <= 7; i++)
        insert(H, i);

    delete (H, 7);
    delete (H, 6);
    delete (H, 5);
    delete (H, 4);  
    delete (H, 3);
    delete (H, 2);

    for (int i = 1; i <= 7; i++)
        printf("%d ", H[i]);

    return 0;
}
