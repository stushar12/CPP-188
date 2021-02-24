#include <bits/stdc++.h>
using namespace std;
#define int long long int

int woodCut(int arr[],int n,int mid)
{
    int sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] > mid)
            sum =sum+arr[i]-mid;
    }
    return sum;
}
int tree_height(int arr[],int n,int required)
{
	sort(arr,arr+n);
    int low = 0 , mid , high =arr[n-1];
    int ans = 0;
    while(low <= high)
    {
        mid = (low + high)/2;
        int wood = woodCut(arr,n,mid);
        if(wood >= required)
        {
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return ans;
}
int32_t main()
{
    int trees,requirement;
    cin>>trees>>requirement;

    int arr[trees];

    for(int i=0;i<trees;i++)
    cin>>arr[i];
    
    cout<<tree_height(arr,trees,requirement);
}