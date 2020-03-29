//NAME: RUTUJA BHANDIGANI
// N QUEENS ALGORITHM

#include<iostream>
#include<cstdlib>
using namespace std;

int count=0,total_o=0,nq_cnt=0;


int place(int k, int i,int x[])
{
	int j;
	count++;
	for(j=1;j<=(k-1);j++)
	{
		if((x[j]==i) || (abs(x[j]-i) == abs(j-k)))
			return false;
		
	}
	return true;
}

void NQueen(int k,int n,int x[])
{
	int i,j;
	int ab[n][n];
	for(i=1;i<=n;i++)
	{
		if(place(k,i,x))
		{
			x[k]=i;
			if(k==n)
			{
			    total_o++;
			    for(int l=1;l<=n;l++)
			        for(int m=1;m<=n;m++)
			            ab[l][m]=0;
			       
			 cout<<"\nColumnwise location: ";           
				for(j=1;j<=n;j++)
				{
					cout<<x[j]<<" ";
					ab[j][x[j]]=1;
				}
				cout<<"\nMatrix location: \n";
				for(int l=1;l<=n;l++)
				{
			        for(int m=1;m<=n;m++)
			        {
			            cout<<ab[l][m]<<" ";
			        }
			        cout<<"\n";
				}
					cout<<"\nNo. of times place function is called: "<<count;
					cout<<"\nNo. of times Nqueen function is called: "<<nq_cnt+1<<endl;
					count=nq_cnt=0;
			}
			else
			{
				nq_cnt++;
				NQueen(k+1,n,x);
				
			}	
		}
	}
	
	
}

int main()
{
	
	int k,n;//,count=0;
	cout<<"Enter the number of queens: ";
	cin>>n;
	int x[n];
	k=1;              
	for(int j=1;j<=n;j++)
	{
		x[j]=0;
	}
	NQueen(k,n,x);
    cout<<"\n\nTotal possible solutions: "<<total_o;
}	