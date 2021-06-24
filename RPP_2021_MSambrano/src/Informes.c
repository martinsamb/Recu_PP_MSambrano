/*
 * Informes.c
 *
 *  Created on: 21 jun. 2021
 *      Author: martin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"
#include "Trabajo.h"
#include "Informes.h"
#include "utn.h"

int info_ServiciosPrestados(Trabajo *pArray,int len, Servicio *pArrayS,int lenS)
{
	int retorno = -1;
	int i;
	int j;
	float acumuladorTotal = 0;

	if(pArray != NULL && len > 0 && pArrayS != NULL && lenS > 0)
	{	//Recorro trabajo
		for(i=0; i<len; i++)
		{
			if(pArray[i].isEmpty == 0)
			{	//recorro servicios
				for(j=0;j<lenS; j++)
				{	//array trabajo.idservicio = array Servicio.Id Servicios y servicios lleo
					if(pArray[i].idServicio == pArrayS[j].id && pArrayS[j].isEmpty == 0)
					{
						acumuladorTotal += pArrayS[j].precio;
						retorno = 0;
					}
				}
			}
		}
		printf("El total de pesos por los servicios prestados es: %.2f",acumuladorTotal);
	}

	return retorno;
}

//1. Listado de todos los trabajos ordenados por marca de la bicicleta.

/*brief Ordena por Año y si son iguales ordena por marca, segun el orden (ascendente/descendente)
 * param1 pArray *trabajo, array con los elementos a ordenar.
 * param2 int len, cantidad de elementos del array.
 * param3 int orden,[1] para que sea ascendente [0] para que sea descendente.
 * return retorna 0 si funciona correctamente o -1 si hubo algun error.
 * */

int info_ordenarTrabajoMarca(Trabajo* pArray,int len, int orden)
{
	int retorno = -1;
	Trabajo Aux;
	int i,j;

	if(pArray != NULL && len > 0 && (orden == 0 || orden == 1))
	{
		for(i=0;i<len-1;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if((orden && strcmp(pArray[i].marcaBicicleta,pArray[j].marcaBicicleta) == 1 ) || (!orden && strcmp(pArray[i].marcaBicicleta,pArray[j].marcaBicicleta) == -1))
				{
					Aux = pArray[i];
					pArray[i] = pArray[j];
					pArray[j] = Aux;
					retorno = 0;
				}

			}

		}
	}

	return retorno;
}


//2. El o los servicios con más trabajos realizados.
int info_mayorServicios(Trabajo* pArray,int len,Servicio* pArrayS, int lenS)
{
	int retorno = -1;
	int id;
	int j;
	int flag=0;
	int contador = 0;
	int ServicioConMayorTra;

	if(pArrayS!=NULL && len>0)
	{//recorro el array servicio
		for(int i=0;i<lenS;i++)
		{
			if(pArrayS[i].isEmpty==0)//esta lleno
			{
				id = pArrayS[i].id;//asigno el id
				//recorro array Trabajo
				for(j=0; j<len; j++)
				{
					if(pArray[j].isEmpty==0 && pArray[j].id == id && pArray[j].id == id)
					{
						contador++;
					}
				}

				if(contador>flag)// maximo
				{
					ServicioConMayorTra = id;
				}
			}
		}

		printf("El Servicio con mayor trabajo es:  %d\n", ServicioConMayorTra);

	}

	return retorno;
}
