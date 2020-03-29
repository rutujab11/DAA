#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int capacity,n;
	int i,j;
	float r[50],w[50],v[50],x[50],profit=0,weight=0;
	cout<<"Enter the knapsack capacity:\t";
	cin>>capacity;
	
	cout<<"Enter the number of objects:\t";
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		cout<<"Enter weight of object"<<i<<" :\t";
		cin>>w[i];
		cout<<"Enter profit of object"<<i<<" :\t";
		cin>>v[i];
		x[i]=0;
	}
	
	cout<<"weight:\t[";
	for(i=1;i<=n;i++)
	{
		cout<<w[i]<<",";
	}
	
	cout<<"]";
	cout<<"\n";
	
	cout<<"profit:\t[";
	for(i=1;i<=n;i++)
	{
		cout<<v[i]<<",";
	}
	
	cout<<"]";
	cout<<"\n";
	for(i=1;i<=n;i++)
	{
		r[i]=v[i]/w[i];
		cout<<"profit/unit weight:\t"<<r[i]<<"\n";
	}
	
	for(i=1;i<=(n-1);i++)
	{
		for(j=1;j<=(n-i);j++)
		{
			if(r[j]<r[j+1])
			{
				swap(r[j],r[j+1]);
				swap(v[j],v[j+1]);
				swap(w[j],w[j+1]);
			}
		}
	}
				
	cout<<"decreasing order of profit/unit weight:\t";
	for(i=1;i<=n;i++)
	{
		cout<<r[i]<<"\t";
	}
	cout<<"\n";
	int u=capacity;
	
	for(i=1;i<=n;i++)
	{
		if(w[i]>u)
			break;
		
		x[i]=1;
		u=u-w[i];
	}
	
	if(i<=n)
	{
		x[i]=u/(w[i]);
	}
	
	cout<<"\n";
	
	cout<<"x[i]:\t[";
	for(i=1;i<=n;i++)
	{
		cout<<x[i]<<",";
	}
	cout<<"]";
	cout<<"\n";
		
	for(i=1;i<=n;i++)
	{
		profit=profit + (v[i]*x[i]);
		
	}
	cout<<"p[i]x[i]:\t"<<profit<<"\t";
	cout<<"\n";
	for(i=1;i<=n;i++)
	{
		weight=weight + (w[i]*x[i]);
		
	}
	cout<<"w[i]x[i]:\t"<<weight<<"\t";
	cout<<"\n";
}
