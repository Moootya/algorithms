#include <iostream> 


int main(void)
{
    int nums[8] = {
        1, 2, 3, 4, 5, 6, 7, 8
    };

    int min_ = 0;
    int max_ = 0;
    int num_first;
    int num_second;

    for (int i = 0; i <= 7; i = i + 2)
    {
        num_first = nums[i];
        num_second = nums[i+1];

        if (num_first > num_second)
        {
            if (num_first > max_)
            {
                max_ = num_first;
            }
            if (num_second < min_)
            {
                min_ = num_second;
            }
        } 
        else {
            if (num_second > max_)
            {
                max_ = num_second;
            }
            if (num_first < min_)
            {
                min_ = num_first;
            }
        }
    }
    std::cout << "Min: " << min_ << "; Max: " << max_ << std::endl;


    return 0;    
}




