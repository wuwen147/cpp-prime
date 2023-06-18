#ifndef STLALGO_H_
#define STLALGO_H_

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4244)
#endif // !STLALGO_H_
#include <cstddef>
#include <ctime>
#include "memory.h"
namespace stlalgo
{
    //算法1：检查左闭右开区间是否全部元素满足某一条件。
    template <class InputItem, class condition>
    bool all_of(InputItem first, InputItem last, condition con)
    {
        for(; first != last; ++first)
        {
            if(!con(*first))
            {
                return false;
            }
        }
        return true;
    }
    //算法2：检查左闭右开区间是否存在某一元素元素满足某一条件。
    template <class InputItem, class condition>
    bool any_of(InputItem first, InputItem last, condition con)
    {
        for(; first != last; ++first)
        {
            if(con(*first))
            {
                return true;
            }
        }
        return false;
    }
    //算法3：检查[first, last)内是否全部元素都不满足一元操作 unary_pred 为 true 的情况，满足则返回 true
    template <class InputItem, class condition>
    bool none_of(InputItem first, InputItem last, condition con)
    {
        for(; first != last; ++first)
        {
            if(con(*first))
            {
                return false;
            }
        }
        return true;
    }
    //算法4：// count
    // 对[first, last)区间内的元素与给定值进行比较，缺省使用 operator==，返回元素相等的个数
    template <class InputItem, class T>
    size_t count(InputItem input, InputItem last, const T& value)
    {
        int count = 0;
        for(; input != last; ++input)
        {
            if(*input == value)
            {
                count++;
            }
        }
        return count;
    }
    // 算法5 count_if
    // 对[first, last)区间内的每个元素都进行一元 unary_pred 操作，返回结果为 true 的个数
    template <class InputItem, class T>
    size_t count_if(InputItem input, InputItem last, T oper)
    {
        int count = 0;
        for(; input != last; ++input)
        {

            if(oper(*input))
            {
                count++;
            }
        }
        return count;
    }
    // 算法6 find
    // 在[first, last)区间内找到等于 value 的元素，返回指向该元素的迭代器
    template <class InputItem, class T>
    InputItem find(InputItem input, InputItem last, const T& oper)
    {
        while(input != last && *input != oper)
        {
            input++;
        }
        return input;
        //这里用for循环好像不太好
        // for(; input != last; ++input)
        // {

        //     if(*input == oper)
        //     {
        //         return input;
        //     }
        // }
        // return ;
    }
    // find_if
    // 在[first, last)区间内找到第一个令一元操作 unary_pred 为 true 的元素并返回指向该元素的迭代器
    template <class InputItem, class T>
    InputItem find_if(InputItem input, InputItem last,  T oper)
    {
        while(input != last && !oper(*input))
        {
            input++;
        }
        return input;
    }
    // find_if_not
    // 在[first, last)区间内找到第一个令一元操作 unary_pred 为 false 的元素并返回指向该元素的迭代器
    template <class InputItem, class T>
    InputItem find_if_not(InputItem input, InputItem last, T oper)
    {
        while(input != last && oper(*input))
        {
            input++;
        }
        return input;
    }
    //com 重载版本
    template <class ForwardIter1, class ForwardIter2, class Compared>
    ForwardIter1 search(ForwardIter1 first1, ForwardIter1 last1, ForwardIter2 first2,ForwardIter2 last2,Compared com)
    {
        int count1 = 0;
        int count2 = 0;
        while(first1 != last1)
        {
            count1++;
        }
        while(first2 != last2)
        {
            count2++;
        }
        if(count1 < count2)
        {
            return last1;
        }
        //其余两种情况，count1>=count2
        auto current1 = first1;
        auto current2 = first2;
        //以较短的那个字符串长度为准
        while(current2 != last2)
        {
            if(com(*current1, *current2))
            {
                //相等就两个指针都++
                ++current1;
                ++current2;
            }
            else
            {
                //如果不等，就分情况讨论
                //如果两个要比较的所占空间大小相等
                if(count1 == count2)
                {
                    return last1;
                }
                else
                {
                    current1 = ++last1;
                    current2 = last2;
                }
            }
        }

    }
    //search_n,用于在指定区域内查找第一个符合要求的子序列,查找的只能是包含多个相同元素的子序列。
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif