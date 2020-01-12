//
// Created by 石成 on 2020/1/3.
//

#ifndef DATASTRUCTURE_ALGORITHM_H
#define DATASTRUCTURE_ALGORITHM_H
#include <vector>

namespace cheng{
    //二分查找
    // 迭代
    int binary_search(std::vector<int>& vec, int lo, int hi, int target)
    {
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (vec[mid] == target)
                return mid;
            else if (vec[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }

    // 递归
    int binary_search_1(std::vector<int>& vec, int lo, int hi, int target)
    {
        if (lo > hi)
            return -1;
        int mid = (lo + hi) / 2;
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] < target)
            return binary_search_1(vec, mid + 1, hi, target);
        else
            return binary_search_1(vec, lo, mid - 1, target);

    }

    // 返回target的第一个位置
    int my_lower_bound(std::vector<int>& vec, int target)
    {
        int lo = 0, hi = vec.size();
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (vec[mid] >= target)
                hi = mid;
            else
                lo = mid+1;
        }
        return hi;

    }

    // 返回第一个大于target的位置
    int my_upper_bound(std::vector<int>& vec, int target)
    {
        int lo = 0, hi = vec.size();
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (vec[mid] > target)
                hi = mid;
            else
                lo = mid+1;
        }
        return hi;
    }

    //排序算法
    
    //冒泡
    void bubble_sort(std::vector<int>& vec)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            for (int j = 0; j < vec.size()-i-1; ++j)
            {
                if (vec[j] > vec[j+1])
                    std::swap(vec[j], vec[j+1]);
            }
        }
    }

    //选择
    void select_sort(std::vector<int>& vec)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            int min_index = i;
            for (int j = i + 1; j < vec.size(); ++j)
            {
                min_index = vec[j] < vec[min_index] ? j : min_index;
            }
            std::swap(vec[i], vec[min_index]);
        }
    }

    //插入
    void insert_sort(std::vector<int>& vec)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            for (int j = i; j >= 1; --j)
            {
                if (vec[j] < vec[j-1])
                    std::swap(vec[j], vec[j-1]);
                // 很重要，这样才能使有序数组排序时间复杂度退化到O(n)
                else
                    break;
            }
        }
    }

    //快排

    //朴素快排
    int partition1(std::vector<int>& vec, int lo, int hi)
    {
        int i = lo, j = hi+1;
        int pivot = vec[lo];
        while (1)
        {
            while(vec[++i] < pivot)
                if (i == hi)
                    break;
            while(vec[--j] > pivot)
                if (j == lo)
                    break;
            if (i >= j)
                break;
            std::swap(vec[i], vec[j]);
        }
        std::swap(vec[lo], vec[j]);
        return j;
    }

    void quick_sort1(std::vector<int>& vec, int lo, int hi)
    {
        if (lo >= hi)
            return;
        int mid = partition1(vec, lo, hi);
        quick_sort1(vec, lo, mid-1);
        quick_sort1(vec, mid+1, hi);
    }

    //三向切分
    std::pair<int, int> partition2(std::vector<int>& vec, int lo, int hi)
    {
        // less从第一个元素开始，省去最后交换pivot的动作
        int less = lo, more = hi;
        int pivot = vec[lo];
        int cur = lo+1;
        // <= 很重要，more代表>区间的左边一格，cur==more时进行最后一个元素的判断，至此遍历所有元素
        while (cur <= more)
        {
            if (vec[cur] < pivot)
            {
                std::swap(vec[less++], vec[cur++]);
            }
            else if (vec[cur] > pivot)
            {
                std::swap(vec[more--], vec[cur]);
            }
            else
            {
                cur++;
            }
        }
        return std::make_pair(less, more);

    }
    void quick_sort2(std::vector<int>& vec, int lo, int hi)
    {
        if (lo >= hi)
            return;
        auto mid = partition2(vec, lo, hi);
        quick_sort1(vec, lo, mid.first-1);
        quick_sort1(vec, mid.second+1, hi);
    }

    //归并
    void merge(std::vector<int>& vec, int lo, int mid, int hi)
    {
        std::vector<int> temp(vec);
       int l1 = lo, l2 = mid+1;
       int cur = lo;
       while (l1 <= mid && l2 <= hi)
       {
           if (temp[l1] < temp[l2])
               vec[cur++] = temp[l1++];
           else
               vec[cur++] = temp[l2++];
       }
       while (l1 <= mid)
           vec[cur++] = temp[l1++];
       while (l2 <= hi)
           vec[cur++] = temp[l2++];

    }

    void merge_sort(std::vector<int>& vec, int lo, int hi)
    {
        if (lo >= hi)
            return;
        int mid = (lo + hi) / 2;
        merge_sort(vec, lo, mid);
        merge_sort(vec, mid+1, hi);
        merge(vec, lo, mid, hi);
    }

    //堆排序

}

#endif //DATASTRUCTURE_ALGORITHM_H
