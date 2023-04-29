#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    int sum = 0;
    int min_num = -1;
    int min_num_index = -1;

    for (int i = 0;i < n;i++)
    {
        int num;
        std::cin >> num;

        if (num % 10 != 1)
        {
            sum += num;

            if (min_num == -1 || num < min_num)
            {
                min_num = num;
                min_num_index = i + 1;
            }
        }
    }

    std::cout << "Sum of numbers not ending with 1: " << sum << std::endl;
    std::cout << "Smallest number not ending with 1: " << min_num << std::endl;
    std::cout << "Index of smallest number not ending with 1: " << min_num_index << std::endl;

    return 0;
}