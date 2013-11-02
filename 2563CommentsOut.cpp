/*
 * =====================================================================================
 *
 *       Filename:  2563CommentsOut.cpp
 *
 *    Description:  Tengo que hacer un programa que remueva comentarios
 *    +Los comentarios son abiertos con #@ y cerrados con #@
 *    +Pueden nestearse los comentarios (como parentesis)
 *    +Un comentario no esta balanceado cuando el numero de ocurrencias de 
 *    #@ es distinto al numero de ocurrencias de @#.
 *    +Cada linea tiene igual o menos de 1000 caracteres.
 *
 *        Version:  1.0
 *        Created:  10/25/2013 05:18:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std; 

string extraer_comentarios_linea(string lineaCC)
{
	string lineaSC = "";
	stack<string> mistack; 
	queue<string> miqueue;
	int contador = 0;
	int tam = lineaCC.length();	
	while(contador<tam)
	{
		char c = lineaCC.c_str()[contador];
		switch(c)
		{
			case '#':
				if(lineaCC.c_str()[contador+1] == '@')
				{
					mistack.push("#@");
					contador++;
				}
				break;
			case '@':
				if(lineaCC.c_str()[contador+1] == '#')
				{
					mistack.pop();
					contador++;
				}
				break;
			default:
				if(mistack.empty())
					lineaSC+=c;
				break;
		}
		contador++;
	}
	
	return lineaSC;
}

int main()
{
	string codigo;
	while(getline(cin,codigo))	
		cout<<extraer_comentarios_linea(codigo)<<endl;	
	return 0;
}
