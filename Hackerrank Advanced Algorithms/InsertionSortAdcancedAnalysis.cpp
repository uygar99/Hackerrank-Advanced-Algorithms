#include <iostream>
using namespace std;
int temp[100000];
long long int shft(long long int s[],long long int left,long long int mid,long long int right)
{
    long long int shift=0;
    long long int i=left, j=mid, k=left;
    while(i<mid && j<=right)
    {
        if(s[i] <= s[j])
		{
            temp[k]=s[i];
            k++, i++;
        }
        else
		{
            temp[k]=s[j];
            k++, j++;
            shift += mid-i;
        }
    }
    while(i<mid)
	{
        temp[k] = s[i];
        k++, i++;
    }
    
    while(j<=right)
	{
        temp[k] = s[j];
        k++, j++;
    }
    
    while(left<=right)
	{
        s[left] = temp[left];
        left++;
    }
    return shift;
}
long long int mergeSort(long long int s[],long long int left,long long int right)
{
    long long int shift = 0;
    if(left < right)
    {
        long long int mid = left + (right-left)/2;
        shift += mergeSort(s, left, mid);
        shift += mergeSort(s, mid+1, right);
        shift += shft(s, left, mid+1, right);
    }
    return shift;
}
int main()
{
    long long int n, t;
    cin >> t;
    for(long long int i=0;i<t;i++)
    {
        cin >> n;
        long long int s[n];
        for(long long int i=0; i<n; i++)
            cin >> s[i];
        long long int shift = mergeSort(s, 0, n-1);
        cout << shift <<endl;
    }
    return 0;
}
