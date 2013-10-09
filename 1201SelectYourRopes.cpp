/*
 * =====================================================================================
 *
 *       Filename:  1201SelectYourRopes.cpp
 *
 *    Description:  Problema para el coj.uci.cu en Mindpushups 2013.
 *
 *        Version:  1.0
 *        Created:  10/08/2013 06:12:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Jose Alberto Esquivel Patino
 *   Organization: ITESM 
 *
 * =====================================================================================
 */
#include <iostream>
#include <list>

using namespace std;

int main()
{
	int casos;
	cin>>casos;
	while(casos>0)
	{
		int numeroDeCuerdas, resistencia_temp, contadorDeCuerdas;
		cin>>numeroDeCuerdas;
		list<int> resistencias;

		list<int>::iterator iterador_resistencias;
		for(contadorDeCuerdas = 0; contadorDeCuerdas<numeroDeCuerdas; contadorDeCuerdas++)
		{
			cin>>resistencia_temp;
			iterador_resistencias = resistencias.begin();
			while(resistencia_temp<*iterador_resistencias && iterador_resistencias!=resistencias.end())
			{
				iterador_resistencias++;
			}
			if(iterador_resistencias>resistencias.end())
				resistencias.insert(resistencia_temp);
			else
				resistencias.push_back(resistencia_temp);
		}	

		iterador_resistencias = resistencias.begin();
		int pesoMaximo = *iterador_resistencias;
		while(resistencia_temp<*iterador_resistencias && iterador_resistencias!=resistencias.end())
		{
			

			iterador_resistencias++;
		}

		casos--;
	}
}

