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
#define LEN_MAXIMO 21


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

//7.2. Listado de todos los trabajos ordenados por marca de la bicicleta.


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


//8.2. El o los servicios con más trabajos realizados
//Servicio={20000,"Limpieza",250}, {20001,"Parche",300}, {20002,"Centrado",400}, {20003,"Centrado",350}

int info_serviciosMasTrabajos(Servicio *pArrayS,int lenS,Trabajo *pArray,int len)
{
	int retorno = -1;
	int contadorMax;//contadorDelServicioMasUsado
	int contador = 0;
	int flag = 0;//flagPrimerComparacion

	if(pArray != NULL && len > 0 && pArrayS != NULL && lenS > 0)
	{
		for(int i = 0; i < lenS; i++ )//Servicio
		{
			contador = 0;
			for(int j = 0; j < len; j++)//Trabajo
			{
				if(pArrayS[i].id == pArray[j].idServicio)//igualdad de campos
				{
					contador++;//voy sumando cada iteración
				}
			}
			if(flag==0 || (contadorMax < contador))//Maximo ||if(aux>max)
			{
				contadorMax = contador;
				retorno = 0;

				flag = 1;
			}
		}
		printf("El Servicio Mas usado es: \n\n");
		servicio_imprimirTitulo();
		for(int i = 0; i <lenS; i++ )//Servicio
		{
			contador = 0;
			for(int j = 0; j < len; j++)//Trabajo
			{
				if(pArrayS[i].id == pArray[j].idServicio)
				{
					contador++;
				}
			}
			if(contador == contadorMax)//Comparo con el maximo
			{
				servicio_imprimirContenido(pArrayS, i);
			}
		}
		retorno = 0;
	}
	return retorno;
}


