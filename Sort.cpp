#include<vector>
#include<iostream>
using namespace std;


// 归并排序：性质：1、时间复杂度：O(nlogn)  2、空间复杂度：O(n)     3、稳定排序     4、非原地排序
// 基数排序：性质：1、时间复杂度：O(kn)     2、空间复杂度：O(n+k)   3、稳定排序     4、非原地排序
// 计数排序：性质：1、时间复杂度：O(n+k)    2、空间复杂度：O(k)     3、稳定排序     4、非原地排序
// 桶排序：  性质：1、时间复杂度：O(nlogn)  2、空间复杂度：O(1)     3、非稳定排序   4、原地排序

// 选择排序
// 选择排序：性质：1、时间复杂度：O(n2)     2、空间复杂度：O(1)     3、非稳定排序   4、原地排序
// 堆排序：  性质：1、时间复杂度：O(nlogn)  2、空间复杂度：O(1)     3、非稳定排序   4、原地排序

// 插入排序
// 插入排序：性质：1、时间复杂度：O(n2)     2、空间复杂度：O(1)     3、稳定排序     4、原地排序
// 希尔排序：性质：1、时间复杂度：O(nlogn)  2、空间复杂度：O(1)     3、非稳定排序   4、原地排序

// 交换排序
// 冒泡排序：性质：1、时间复杂度：O(n2)     2、空间复杂度：O(1)     3、稳定排序     4、原地排序
// 快速排序：性质：1、时间复杂度：O(nlogn)  2、空间复杂度：O(logn)  3、非稳定排序   4、原地排序

template <typename T> void bubbleSort(vector<T> &data)
{
    for(int i=0;i<data.size()-1;i++){
        for(int j=0;j<data.size()-i-1;j++){
            if(data[j]>data[j+1]){
                // T temp=data[j];
                // data[j]=data[j+1];
                // data[j+1]=temp;
                swap(data[j],data[j+1]);
            }
        }
    }
}

template <typename T> void quickSort(vector<T> &data,int low,int high)
{
    if(low>=high)
        return;
    T key=data[low];
    int left = low, right = high;
    while(left < right)
    {
        while(left<right && data[right]>=key) --right;
        data[left] = data[right];
        while(left<right && data[left]<=key) ++left;
        data[right] = data[left];
    }
    data[left]=key;
    quickSort(data,low,left-1);
    quickSort(data,left+1,high);

}
template <typename T> void quickSort(vector<T> &data)
{
    quickSort(data,0,data.size()-1);
}

int main()
{
    vector<double> a={2,3,4,6223,657322,1,3213,1,1,2,3123,4563,3213};
    for(auto v:a)
        cout<<v<<" ";
    cout<<endl;
    quickSort(a);
    for(auto v:a)
        cout<<v<<" ";
    cout<<endl;
}


