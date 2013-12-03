#include<iostream>
using namespace std;
void merge(int a[],int p,int q,int r)
{
    int left[q-p+2],right[r-q+1];
    for(int i=0;i<(q-p+1);i++)
    {
        left[i]=a[i+p];
    }
        for(int i=0;i<(r-q);i++)
    {
        right[i]=a[i+q+1];
    }
    left[q-p+1]=1000000;right[r-q]=1000000;
    int i=0,j=0;
    for(int k=p;k<r+1;k++)
    {
        if(left[i]<=right[j]){a[k]=left[i];i++;}
        else
        {
            a[k]=right[j];
            j++;
        }
    }
}
void merge_sort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=(r+p)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
    return ;
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        merge_sort(a,0,n-1);
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
    }
}

