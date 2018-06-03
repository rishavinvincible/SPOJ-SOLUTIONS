#include <bits/stdc++.h>
using namespace std;

int isvalid(int arr[], int x, int n, int c)
{
	int start=arr[0],cows=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]-start>=x)
		{
			cows++;
			start = arr[i];
		}
		if(cows==c)
			return 1;
	}
	return 0;
}

int fun(int arr[], int n, int c)
{
	int l=0, h=arr[n-1],mid, max=-1;
	while(h-l>1)
	{
		int mid=(l+h)/2;
		//cout<<mid<<endl;
		if(isvalid(arr,mid,n,c))
		{
			//cout<<mid<<endl;
			if(mid>max)
			{
				max=mid;
			}
			l=mid;
		}
		else
			h=mid;
	}
	return max;
}

int main() {
	int t,n,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&c);
		int arr[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr, arr+n);
		int res = fun(arr,n,c);
		printf("%d\n",res);
	}
	return 0;
}
