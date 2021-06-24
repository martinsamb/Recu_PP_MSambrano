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
		printf("El total de dinero por los servicios prestados es: %.2f",acumuladorTotal);
	}

	return retorno;
}

