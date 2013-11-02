/*
 * =====================================================================================
 *
 *       Filename:  2552Elections.cpp
 *
 *    Description:  elections
 *
 *        Version:  1.0
 *        Created:  10/25/2013 05:28:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <algorithm>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main(int argc, const char *argv[])
{
	int candidates = 0, totalVotes = 0;
	int arr[10];
	cin>>candidates;
	for (int i = 0; i < candidates; i++) {
		cin>>arr[i];
		totalVotes+=arr[i];
	}
	//sort
   	qsort (arr, candidates, sizeof(int), compare);
	double c1 = .45*totalVotes;
	if(arr[candidates-1]>=c1) cout<<1<<endl;
	else{
		double c2 = .40*totalVotes;
		double c3 = .10*totalVotes;
		if(arr[candidates-1]>=c2 && arr[candidates-1]-arr[candidates-2]>=c3){
			cout<<1<<endl;
		}else{
			cout<<2<<endl;
		}
	}
	return 0;
}
