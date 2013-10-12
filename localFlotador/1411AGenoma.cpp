/*
 * =====================================================================================
 *
 *       Filename:  1411AGenoma.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/13 17:26:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

int main()
{
	int numberOfProblems, numberOfCreatures;
	cin>>numberOfProblems;
	string alienGeneSet, terrestrialGeneSet;
	int marsNumber;

	int contador = 1;
	while(contador<=numberOfProblems)
	{
		cout<<"Case "<<contador<<endl;


		cin>>alienGeneSet>>numberOfCreatures;
		int terrestrialLength, alienLength;

		while(numberOfCreatures>0)
		{
			cin>>terrestrialGeneSet;
			marsNumber = 0;
			terrestrialLength = terrestrialGeneSet.length();
			alienLength = alienGeneSet.length();
			for(int i = 0; i<(alienLength-terrestrialLength+1); i++)
			{
				if(alienGeneSet.substr(i,terrestrialLength) == terrestrialGeneSet) 
				{
					marsNumber++;
				}

			}
			if(marsNumber!=0)
			{
				cout<<marsNumber<<endl;
			}else
			{
				cout<<"Darwin was right about this creature"<<endl;
			}
			numberOfCreatures--;
		}
		
		contador++;
	}

}


