// NAME: RUTUJA BHANDIGANI
//RANDOMIZED QUICKSORT

#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int x=0;
int partition(int A[],int n,int high,int low)   //Partition Function
{
    int i,j,pivot;
    i=low+1;
    j=high;
    pivot=A[low];  //First element for pivot
    while(i<=j)
    {
        while(i<high && A[i]<=pivot)
        {
            i++;
        }
        while(j>low && A[j]>=pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(A[i],A[j]);
        }
        else
        {
            swap(A[low],A[j]);
            return j;
        }
    }
    return j;
}

void quick_sort(int A[],int n,int high,int low)
{
	//first iteration is display
	//last is output
	cout<<"Iteration count "<<x++<<" : ";
    for(int i=0;i<n;i++)
    {

        cout<<A[i]<<" ";
    }
    cout<<endl;
    if(low<high)
    {
        int p=partition(A,n,high,low);
        quick_sort(A,n,p-1,low);
        quick_sort(A,n,high,p+1);
    }
}

int part_ran(int A[],int n,int high,int low)    //radomize partition
{
	srand(time(NULL));
	int random = low + rand() % (high - low); //generate random no. B/W low and high
	swap(A[random], A[high]);
	int p=partition(A,n,high,low);
	cout<<"Pivot element: "<<A[p]<<endl;
	return p;
	//return partition(A,n,high,low);
}

void quick_sort_rand(int A[],int n,int high,int low) //randomize quick sort
{
	//first iteration is display
	//last is output
	cout<<"Iteration count "<<x++<<" : ";
    for(int i=0;i<n;i++)
    {

        cout<<A[i]<<" ";
    }
    cout<<endl;
    if(low<high)
    {
        int p=part_ran(A,n,high,low);
        quick_sort(A,n,p-1,low);
        quick_sort(A,n,high,p+1);
    }
}

int main()    //main program
{
    int i,n,high,low,high1,low1;
    cout<<"Enter no. of elements in array: ";
    cin>>n;
    cout<<"\nEnter elements: ";
    int A[n],A1[n];
    low=low1=0;
    high=high1=n-1;
    for(i=0;i<n;i++)
    {
    	//cin>>A[i];
    	int random =(rand()%1000) +1;         //storing any random no. B/W 1 & 1000
    	A[i]=random;
    	A1[i]=random;
    }
    cout<<"\n";
    quick_sort(A,n,high,low);  //calling normal quick sort
    x=0;
    cout<<"\n\nRandom sorting:\n";
    quick_sort_rand(A1,n,high1,low1); //calling random quick sort
}
