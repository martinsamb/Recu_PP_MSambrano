/*
 * Servicio.c
 *
 *  Created on: 22 jun. 2021
 *      Author: marti
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"
#include "Trabajo.h"
#include "utn.h"


/**
 * \brief Imprime los datos de un Servicio
 * \param pArray Puntero al producto que se busca imprimir
 */
void servicio_imprimir(Servicio pArray)
{
	printf("\nID:%d - Descripcion:%s - Precio:%.2f",pArray.id,pArray.descripcion,pArray.precio);
}

/**
 * \brief Imprime el array de Servicio
 * \param pArray Array de Sericio a ser actualizado
 * \param len Limite del array de Servicio
 */
void servicio_imprimirArray(Servicio* pArray,int len)
{
	int i;
	if(pArray != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty == 0)
			{
				servicio_imprimir(pArray[i]);
			}
		}
	}
}


/**
 * \brief Inicializa el array Trabajo
 * \param pArray Array de Contribuyente a ser actualizado
 * \param len Limite del array de Trabajo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int servicio_inicializarArray(Servicio* pArray,int len)
{
	int ret = -1;
	int i;
	if(pArray != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			pArray[i].isEmpty =1;
		}
		ret = 0;
	}
	return ret;
}

/*
 * brief Recibe el numero de id del servicio y devuelve su descripcion
 * param idServicio Numero de id de la servicio
 * param array Array de Servicio
 * param len Tamaño del array de Servicio
 * param descripcion Puntero al espacio de memoria donde se va a guardar la descripcion del servicio
 * return Retorna 0 si se cargo la descripcion y -1 si no
 */

int servicio_cargarDescripcionPorId(int idServicio, Servicio *pArray, int len,char *descripcion)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && len > 0 && descripcion != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if (pArray[i].id == idServicio)
			{
				strncpy(descripcion, pArray[i].descripcion, 20);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int servicio_harcodear(Servicio *pArray, int len, int limite)
{
	int retorno =-1;
	int i;
	if (pArray != NULL && len >= limite)
	{
		Servicio listaAux[] = { { 1, "LIMPIEZA", 250 }, { 2, "PARCHE", 300 }, { 3,
				"CENTRADO", 400 }, { 4, "CADENA", 350 }, };
		if (limite <= len)
		{
			for (i = 0; i < limite; i++)
			{
				pArray[i].id = listaAux[i].id;
				strncpy(pArray[i].descripcion, listaAux[i].descripcion, sizeof(pArray[i].descripcion));
				pArray[i].precio = listaAux[i].precio;
				pArray[i].isEmpty = listaAux[i].isEmpty;
			}
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Ordenar el array de Servicio por ID ascendente
 * \param pArray Array de Servicio
 * \param len Limite del array de Servicio
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int servicio_ordenarID(Servicio* pArray,int len)
{
	int ret = -1;
	int flagSwap;
	int i;
	Servicio buffer;
	if(pArray != NULL && len > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(pArray[i].isEmpty || pArray[i+1].isEmpty)
				{
					continue;
				}
				if(pArray[i].id > pArray[i+1].id)
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1]=buffer;
				}
			}
			len--;
		}while(flagSwap);
	}
	return ret;
}

/*
 * brief Recibe un array de estructuras y la recorre para fijarse si tiene al menos un dato cargado
 * param list Array de Servicio
 * param len Longitud del array
 * return Retorna 1 si esta completamente vacio y 0 si tiene al menos una marca guardada
 */

int servicio_arrayVacio(Servicio *pArray, int len)
{
	int retorno = 1;
	int i;

	if (pArray != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0)//Esta lleno
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


