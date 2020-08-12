#include<iostream>
#include<math.h>

using  namespace std;

int main(int argc, char const *argv[])
{
	//hardcoded

	int n=4;//no.of training sets
	int m=3;//no.of features
	float w[]={0.1,0.1,0.1};
	float lr=0.1;
	int x[n][m]={{1,1,1}, {1,1,-1}, {1,-1,1},{1,-1,-1}};
	int target[]={1,1,1,-1};

	// for(int i=0;i<n;i++)
	// 	{for(int j=0;j<m;j++)
	// 		cout<<x[i][j]<<" ";
	// 		cout<<endl;
	// 	}

	float se[n];//squared error
	for(int i=0;i<n;i++)
	{
		cout<<"\n######### for training set i= "<<i;
		float y_in=0;
		for(int j=0;j<m;j++)
		{
			y_in+=w[j]*x[i][j];
		}
		cout<<"\nY_in = "<<y_in;


		float error= target[i]-y_in;
				cout<<"\nerror = "<<error;

		se[i]=error*error;
				cout<<"\nsquared error= "<<se[i];

		if(se[i]<lr)
		{
			cout<<"weights adjusted..training stopped";
			break;
		}
		else
		{
			for(int j=0;j<m;j++)
		{
				w[j]+=(lr*error*x[i][j]);
				cout<<"\nfor j= "<<j<< "weight is"<<w[j];

						}
		}

	}
float mse=0;
	for(int k=0;k<n;k++)
	{
		mse+=se[k];

	}

	mse/=n;

	cout<<"\n\n************OUTPUT**************rmse = "<<sqrt(mse)<<"\nweights:\n";

			for(int j=0;j<m;j++)
		{
cout<<w[j]<<" ";
						}

	return 0;
}