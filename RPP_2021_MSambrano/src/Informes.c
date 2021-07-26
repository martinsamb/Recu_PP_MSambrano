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
/*
int info_serviciosMasTrabajos(Trabajo *pArray,int len, Servicio *pArrayS,int lenS)
{
	int retorno = -1;
	int i;
	int j;
	int max;
	if(pArray != NULL && len > 0 && pArrayS != NULL && lenS > 0)
	{
		for(j=0;j<lenS; j++)//Servicio
		{
			if(pArrayS[i].isEmpty == 0)
			{
				for(i=0; i<len; i++)//Trabajo
				{
					if(pArray[i].idServicio == pArrayS[j].id && pArrayS[j].isEmpty == 0)
					{
						if(pArray[i].idServicio>max)
						{
							max = pArray[i].idServicio;
						}
					}
				}
			}
		}
		printf("El servicio de mas trabajos es: %d",max);
	}

	return retorno;
}*/

//8.2. El o los servicios con más trabajos realizados
//Servicio={20000,"Limpieza",250}, {20001,"Parche",300}, {20002,"Centrado",400}, {20003,"Centrado",350}

int info_serviciosMasTrabajos(Servicio *pArrayS,int lenS,Trabajo *pArray,int len)
{
	int retorno = -1;
	int i;
	int contador0 = 0;
	int contador1 = 0;
	int contador2 = 0;
	int contador3 = 0;
	char maximo[LEN_MAXIMO];


	if(pArray != NULL && len > 0 && pArrayS != NULL && lenS > 0)
	{
		for(i=0;i<lenS; i++)//Servicio
		{
			if(pArrayS[i].id == 20000 && pArrayS[i].isEmpty == 0)
			{
				contador0++;//limpieza | 250
			}
			else if(pArrayS[i].id == 20001 && pArrayS[i].isEmpty == 0)
			{
				contador1++;//Parche | 300
			}
			else if(pArrayS[i].id == 20002 && pArrayS[i].isEmpty == 0)
			{
				contador2++;//Centrado | 400
			}
			else if(pArrayS[i].id == 20003 && pArrayS[i].isEmpty == 0)
			{
				contador3++;//Cadena | 350
			}
		}
		strcpy(maximo, "Limpieza");//250
		if (contador1 > contador0 && contador1 > contador2 && contador1 > contador3)
		{
			strcpy(maximo,"Parche");//300
		}
		else if (contador2 > contador0 && contador2 > contador1 && contador2 > contador3)
		{
			strcpy(maximo,"Centrado");//400
		}
		else if (contador3 > contador0 && contador3 > contador1 && contador3 > contador2)
		{
			strcpy(maximo,"Cadena");//350
		}
		printf("\nEl servicio mas pedido es: %s", maximo);
	}
	return retorno;
}


//8.2. El o los servicios con más trabajos realizados
//Servicio={20000,"Limpieza",250}, {20001,"Parche",300}, {20002,"Centrado",400}, {20003,"Cadena",350}
/*
int info_serviciosMasTrabajos(Trabajo *pArray, int len,Servicio *pArrayS, int lenS)
{
	int retorno = -1;
	int i;
	int contador0 = 0;
	int contador1 = 0;
	int contador2 = 0;
	int contador3 = 0;
	char maximo[21];

	if ( pArray!= NULL && len > 0 && pArrayS != NULL && lenS > 0 )
	{

		for (i = 0; i < lenS; i++)
		{
			if (pArrayS[i].id == 20000 && pArrayS[i].isEmpty == 0)
			{
				contador0++;//Limpieza: $250
			}
			else if (pArrayS[i].id == 20001 && pArrayS[i].isEmpty == 0)
			{
				contador1++;//Parche: $300
			}
			else if (pArrayS[i].id == 20002 && pArrayS[i].isEmpty == 0)
			{
				contador2++;//Centrado: $400
			}
			else if (pArrayS[i].id == 20003 && pArrayS[i].isEmpty == 0)
			{
				contador3++;//Cadena: $350
			}
		}
		printf("\n%d - %d - %d - %d",contador0,contador1,contador2,contador3);
		strcpy(maximo, "Limpieza");//250
		if (contador1 > contador0 && contador1 > contador2 && contador1 > contador3)
		{
			strcpy(maximo, "Parche");//300
		}
		else if (contador2 > contador0 && contador2 > contador1 && contador2 > contador3)
		{
			strcpy(maximo, "Centrado");//400
		}
		else if (contador3 > contador0 && contador3 > contador1 && contador3 > contador2)
		{
			strcpy(maximo, "Cadena");//350
		}
		printf("\nEl servicio mas pedido es: %s", maximo);
	}

	return retorno;
}
*/
//void servicio_mas_realizado(trabajo* trabajos,int len,servicio* servicios,int len_s)
/*
void info_serviciosMasTrabajos(Trabajo* pArray,int len,Servicio* pArrayS,int lenS)
{
    int servicio1=pArrayS[0].id;
    int servicio2=pArrayS[1].id;
    int servicio3=pArrayS[2].id;
    int servicio4=pArrayS[3].id;
    int count1=0;
    int count2=0;
    int count3=0;
    int count4=0;
    int max_id;
    char descripcion[50];
    for(int i=0;i<len;i++)
    {
	if(pArray[i].idServicio== servicio1)
	    count1++;
	else if (pArray[i].idServicio== servicio2)
	    count2++;
	else if (pArray[i].idServicio== servicio3)
	    count3++;
	else
	    count4++;
    }
    if(count1>count2 && count1>count3 && count1>count4)
	max_id = servicio1;
    else if(count2>count1 && count2>count3 && count2>count4)
	max_id = servicio2;
    else if(count3>count1 && count3>count2 && count3>count4)
    	max_id = servicio3;
    else
    	max_id = servicio4;

    servicio_descripcionPorId(max_id, pArrayS, lenS, descripcion);
    printf("\n El servicio mas prestado es : %s",descripcion);
}

int info_serviciosMasTrabajos(Trabajo* pArray,int len,Servicio* pArrayS,int lenS)
{
	int retorno = -1;
	int i;
	int j;
	int contador0=0;
	int contador1=0;
	int contador2=0;
	int contador3=0;
	char maximo[21];

	if(pArray != NULL && len > 0 && pArrayS != NULL && lenS > 0)
	{
		for(i=0; i<len; i++)//Trabajo
		{
			if(pArray[i].isEmpty == 0)
			{
				for(j=0;j<lenS; j++)//Servicio
				{
					if(pArrayS[i].id == pArrayS[j].id && pArrayS[j].isEmpty == 0)
					{
						if (pArrayS[i].id == 20000 && pArrayS[i].isEmpty == 0)
						{
							contador0++;//Limpieza: $250
						}
						else if (pArrayS[i].id == 20001 && pArrayS[i].isEmpty == 0)
						{
							contador1++;//Parche: $300
						}
						else if (pArrayS[i].id == 20002 && pArrayS[i].isEmpty == 0)
						{
							contador2++;//Centrado: $400
						}
						else if (pArrayS[i].id == 20003 && pArrayS[i].isEmpty == 0)
						{
							contador3++;//Cadena: $350
						}
					}
				}
			}
		}
		strcpy(maximo, "Limpieza");//250
		if (contador1 > contador0 && contador1 > contador2 && contador1 > contador3)
		{
			strcpy(maximo, "Parche");//300
		}
		else if (contador2 > contador0 && contador2 > contador1 && contador2 > contador3)
		{
			strcpy(maximo, "Centrado");//400
		}
		else if (contador3 > contador0 && contador3 > contador1 && contador3 > contador2)
		{
			strcpy(maximo, "Cadena");//350
		}
		printf("\nEl servicio mas pedido es: %s", maximo);
	}

	return retorno;
}
*/
//**********************************************************************************************


