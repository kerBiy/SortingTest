#include <iostream>

int main()
{
    int arr[]{123, 2412, 3512, 35, 123, 45, 1234, 5, 2, 45, 2, 4, 24252, 467, 46, 4};
    const int n = 16;

    int fr[100000]{};
    int max = 0;

    for (int i = 0; i < n; ++i)
    {
        fr[arr[i]]++;
        if (arr[i] > max)
            max = arr[i];
    }

    int exp = -1;
    for (int i = 0; i <= max; ++i)
    {
        for (int j = 1; j <= fr[i]; ++j)
            arr[++exp] = i;
    }

    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << '\n';
}
