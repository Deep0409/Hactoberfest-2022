#include <iostream>

using namespace std;

long long int merge(long long int arr[],long long int l, long long int mid, long long int r)
    {
      long long  inv=0;
      long long int n1=mid-l+1;
      long long  int n2=r-mid;
       long long int a[n1],b[n2];
       
       for(int i=0;i<n1;i++)
       a[i]=arr[l+i];
       
       for(int i=0;i<n2;i++)
       b[i]=arr[mid+i+1];
        
        
    int i=0,k=l,j=0;
    
    while(i<n1&&j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i];
            k++,i++;
        }
        else{
             arr[k]=b[j];
            inv+=n1-i;
           
            k++,j++;
        }
        
    }
    
    while(i<n1)
    {
        arr[k]=a[i];
            k++,i++;
        
    }
    
     while(j<n2)
    {
        arr[k]=b[j];
            k++,j++;
        
    }
        
        
        return inv;
    }
    
    

long long int mergesort(long long int arr[],long long int l,long long int r)
    { 
        long long  inv=0;
        
        if(l<r)
        {
            int mid=(l+r)/2;
            inv+=mergesort(arr,l,mid);
            inv+=mergesort(arr,mid+1,r);
            inv+=merge(arr,l,mid,r);
            
        }
        
        return inv;
        
    }
    


long long int inversionCount(long long int arr[], long long int N)
    {
        // Your Code Here
        return mergesort(arr,0,N-1);
    }
    
    

int main()
{
    long long int  a[100000]={0},n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<inversionCount(a,n);
    

    return 0;
}