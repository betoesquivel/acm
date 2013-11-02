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
int arreglo_quick[100000];
int arreglo_pos[100000];
int aux[100000];
int aux_id[100000];
int aux_pos[100000];

void Particion (int inicio, int fin, int &pivote)
{
    int elempivote=arreglo_quick[inicio], pospivote=arreglo_pos[inicio], j=inicio, aux;

    for (int i=inicio+1; i<=fin; i++) {
        if (arreglo_quick[i]>elempivote || (arreglo_quick[i]==elempivote && arreglo_pos[i]<=pospivote)) {
            j++;
            aux=arreglo_quick[i];
            arreglo_quick[i]=arreglo_quick[j];
            arreglo_quick[j]=aux;
            
            aux = arreglo_id[i];
            arreglo_id[i] = arreglo_id[j];
            arreglo_id[j] = aux;
            
            aux = arreglo_pos[i];
            arreglo_pos[i] = arreglo_pos[j];
            arreglo_pos[j] = aux;
        }
    }
    pivote=j;
    aux=arreglo_quick[inicio];
    arreglo_quick[inicio]=arreglo_quick[pivote];
    arreglo_quick[pivote]=aux;
    
    aux=arreglo_id[inicio];
    arreglo_id[inicio]=arreglo_id[pivote];
    arreglo_id[pivote]=aux;
    
    aux=arreglo_pos[inicio];
    arreglo_pos[inicio]=arreglo_pos[pivote];
    arreglo_pos[pivote]=aux;
}

void QuickSort(int inicio, int fin)
{
    int pivote;
    if (inicio < fin) {
        Particion(inicio, fin, pivote);
        QuickSort(inicio, pivote-1);
        QuickSort(pivote+1, fin);
    }
}

void imprimirArreglos(int length)
{
	for(int i = 0; i<length; i++){
		cout<<arreglo_id[i]<<' ';
		cout<<arreglo_quick[i]<<endl;
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
		arreglo_quick[i] = solvedProblems;
		arreglo_pos[i] = i;
	}
	QuickSort(0, numberOfTeams-1);
	imprimirArreglos(numberOfTeams);
}
