/*
 * =====================================================================================
 *
 *       Filename:  2123GameOfTiles.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/13 20:00:16
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
char tablero[50][50];

int main()
{
	string filaTablero;
	int filas, columnas;
	while(cin>>filas>>columnas)
	{
		for(int f = 0; f<filas; f++)
		{
			cin>>filaTablero;
			for(int c = 0; c<columnas; c++)
			{
				tablero[f][c] = filaTablero.c_str()[c];
			}
		}

		int blancos = 0, negros = 0;
		bool unoGanador = false;

		int c = 0, f;
		while(c<columnas)
		{
			f=0;
			while(f<filas)
			{
				if(tablero[f][c]=='.')
				{
					if(f>0 && f<filas && c>0 && c<columnas)
					{
						if(tablero[f-1][c]=='.' ||
						   tablero[f+1][c]=='.' ||
						   tablero[f][c+1]=='.' ||
						   tablero[f][c-1]=='.' )
							blancos++;
					}

					if(f==0 && c==0 )
					{
						if(
						   tablero[f+1][c]=='.' ||
						   tablero[f][c+1]=='.' 
						   )
							blancos++;
					}

					if(f==filas-1 && c==0)
					{
						if(tablero[f-1][c]=='.' ||
						   
						   tablero[f][c+1]=='.' 
						   )
							blancos++;
					}

					if(f==filas-1 && c==columnas-1)
					{
						if(tablero[f-1][c]=='.' ||
						   
						   
						   tablero[f][c-1]=='.' )
							blancos++;
					}

					if(f==0 && c==columnas-1)
					{
						if(tablero[f+1][c]=='.' ||
						   
						   
						   tablero[f][c-1]=='.' )
							blancos++;
					}

					if(f==0 && c>0 && c<columnas-1)
					{
						if(
						   tablero[f+1][c]=='.' ||
						   tablero[f][c+1]=='.' ||
						   tablero[f][c-1]=='.' )
							blancos++;
					}

					if(f==filas-1 && c>0 && c<columnas-1)
					{
						if(tablero[f-1][c]=='.' ||
						   
						   tablero[f][c+1]=='.' ||
						   tablero[f][c-1]=='.' )
							blancos++;
					}

					if(f>0 && f<filas-1 && c==0)
					{
						if(tablero[f-1][c]=='.' ||
						   tablero[f+1][c]=='.' ||
						   tablero[f][c+1]=='.' 
						   )
							blancos++;
					}

					if(f>0 && f<filas-1 && c==columnas-1)
					{
						if(tablero[f-1][c]=='.' ||
						   tablero[f+1][c]=='.' ||
						   tablero[f][c-1]=='.' 
						   )
							blancos++;
					}
				}else
				{
					negros++;
				}
			
				f++;
			}
			c++;

			if(blancos%2==0)
			{
				unoGanador = false;
			}
			else
			{
				unoGanador = true;
			}
		
		}
		

		if(unoGanador)
			cout<<'1'<<endl;
		else
			cout<<'2'<<endl;
	}
}
