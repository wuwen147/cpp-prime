#include"stlalgo.h"
#include<iostream>
#include<string>

bool compare(int32_t i)
{
    //bool ret = (i >= 2);
    if(i > 2)
    {
        std::cout << 1;
    }
    else
    {
        std::cout << 0;
    }
    return true;
}

int addtocompare(int32_t i)
{
    int32_t a = i+1;
    if(a != 2)
    {
        std::cout << true;
    }
    else
    {
        std::cout << false;
    }
    return 0;
}
int main()
{
    int arr1[] = {1, 3, 5, 7, 9};
    stlalgo::all_of(arr1, arr1+5, compare);
    int arr2[] = {1, 3, 5, 7, 9};
    stlalgo::any_of(arr2, arr2+5, compare);
    stlalgo::none_of(arr2, arr2+5, compare);
    int ret = stlalgo::count(arr2, arr2+5, 3);
    std::cout<<ret<<std::endl;
    stlalgo::count_if(arr2, arr2+5, addtocompare);
    auto result = stlalgo::find(arr2, arr2+5, 3);
    std::cout << result << std::endl;
    return 0;
}
