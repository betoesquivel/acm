/*
 * =====================================================================================
 *
 *       Filename:  1285FinalStandings.cpp
 *
 *    Description:  Using bubble sort or priority queue or quicksort
 *
 *        Version:  1.0
 *        Created:  11/10/13 17:00:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>

using namespace std;

int arreglo_id[100000];
int arreglo_insert[100000];

void imprimirArreglos(int length)
{
	for(int i = 0; i<length; i++){
		cout<<arreglo_id[i]<<' ';
		cout<<arreglo_insert[i]<<endl;
	}
}

void insercionDirecta (int cantidad)
{
	for ( int i = 1; i < cantidad; i++ ){ 
		int aux = arreglo_insert[i];
		int auxId = arreglo_id[i]; 
		int j = i - 1;
		while ( j >= 0 && aux > arreglo_insert[j] ) {
			arreglo_insert[j + 1] = arreglo_insert[j]; 
			arreglo_id[j + 1] = arreglo_id[j]; 
			j--;
			
		}

			arreglo_insert[j + 1] = aux;
			arreglo_id[j + 1] = auxId;
	}
}

int main()
{
	int numberOfTeams, teamID, solvedProblems;
	cin>>numberOfTeams;
    
	for(int i = 0; i<numberOfTeams; i++)
	{
		cin>>teamID>>solvedProblems;
		arreglo_id[i] = teamID;
		arreglo_insert[i] = solvedProblems;
	}
	insercionDirecta(numberOfTeams);
	imprimirArreglos(numberOfTeams);
}
