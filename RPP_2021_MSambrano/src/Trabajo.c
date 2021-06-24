/*
 * Trabajo.c
 *
 *  Created on: 21 jun. 2021
 *      Author: marti
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"
#include "Trabajo.h"
#include "utn.h"

/*
 * brief Recorre el array y encuentra la primera posicion libre
 * param array Array de trabajo
 * param len Tamaño del array de trabajo
 * param posicion Puntero al espacio de memoria donde se va a guardar la posicion libre encontrada
 * return Retorna 0 si encontro una posicion libre y -1 si no
 */

int trabajo_buscarLibre(Trabajo *pArray, int len, int *posicion)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 1)//Esta vacio
			{
				*posicion = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/**
 * \brief Imprime los datos de un Trabajo
 * \param pArray Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

void trabajo_imprimir(Trabajo array,Servicio* pArray, int len)
{
	char descripcionServicio[LEN_DESCRIPCION];

	if(pArray != NULL && len > 0 && (servicio_cargarDescripcionPorId(array.idServicio, pArray, len, descripcionServicio)==0))
	{

		printf("\n%d\t\t%s\t\t%d\t\t%d\t\t%d\t%d\t%d", array.id,
															array.marcaBicicleta,
															array.rodadoBicicleta,
														    array.idServicio,
															array.fecha.dia,
										                    array.fecha.mes,
										                    array.fecha.anio);
	}
}


/**
 * \brief Imprime el array de Trabajo
 * \param pArray Array de Contribuyente a ser actualizado
 * \param len Limite del array de Pantallaes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

void trabajo_imprimirArray(Trabajo *pArray, int len,Servicio* pArrayS, int lenS)
{
	int i;

	if (pArray != NULL && len > 0)
	{
		printf("\nId\tMarca Bicicleta\tRodado Bicicleta\tIdServicio\tDia\tMes\tAnio");
		for (i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0)
			{

				trabajo_imprimir(pArray[i], pArrayS, lenS);
			}
		}
		printf("\n");
	}
}

/**
 * \brief Inicializa el array Trabajo
 * \param pArray Array de Contribuyente a ser actualizado
 * \param len Limite del array de Trabajo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int trabajo_inicializarArray(Trabajo* pArray,int len)
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

/**
 * \brief Da de alta un Trabajo en una posicion del array
 * \param pArray Array de Trabajo a ser actualizado
 * \param len Limite del array de Contribuyente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */



int trabajo_altaArray(Trabajo *pArray, int len,Servicio *pArrayS, int lenS)
{
	int retorno = -1;
	int posicion;

	if (pArray != NULL && len > 0 && pArrayS != NULL && lenS > 0)
	{
		if(trabajo_buscarLibre(pArray, len, &posicion) == -1)
		{
			printf("\nNo hay lugares vacios.");
		}
		else
		{
			utn_getNumero(&pArray[posicion].id, "\nIngrese id:","\nError", 1, 10000, 2);
			utn_getNombre(pArray[posicion].marcaBicicleta,LEN_MARCA,"\nIngrese marca bicicleta: ","\nERROR, nombre invalido.\n",2);
			utn_getNumero(&pArray[posicion].rodadoBicicleta,"\n Ingrese rodado de bicicleta","\n Error", 1,100,2);
			servicio_imprimirArray(pArrayS, lenS);
			utn_getNumero(&pArray[posicion].idServicio,"\n Ingrese id Servicio","\nError", 1,30000,2);
			utn_getNumero(&pArray[posicion].fecha.dia, "\nIngrese el día","\nError", 1,31,2);
			utn_getNumero(&pArray[posicion].fecha.mes, "\nIngrese el mes","\nError", 1,12,2);
			utn_getNumero(&pArray[posicion].fecha.anio, "\nIngrese el anio","\nError", 1,3000,2);
			pArray[posicion].isEmpty = 0;
			printf("\nPosicion: %d\nId: %d\nMarca Bicicleta: %s\nRodado Bicicleta: %d\nIdServicio: %d\nDia: %d\nMes: %d\nAnio: %d ",posicion,
																																pArray[posicion].id,
																																pArray[posicion].marcaBicicleta,
																																pArray[posicion].rodadoBicicleta,
																																pArray[posicion].idServicio,
																																pArray[posicion].fecha.dia,
																																pArray[posicion].fecha.mes,
																																pArray[posicion].fecha.anio);
		    retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Actualiza los datos de un Trabajo en una posicion del array
 * \param array Array de Contribuyente a ser actualizado
 * \param limite Limite del array de Trabajo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int trabajo_modificarArray(Trabajo *pArray, int len, Servicio *pArrayS,int lenS)
{
	int retorno = -1;
	int posicion;
	int id;
	int opcion;

	if (pArray != NULL && len > 0)
	{
		trabajo_imprimirArray(pArray, len, pArrayS, lenS);
		utn_getNumero(&id,"\nId a modificar:","\nError",1,1000,2);
		if(trabajo_encontrarById(pArray, len, id, &posicion)==-1)
		{
			printf("\nEl id ingresado no existe.");
		}
		else
		{
			do
			{
				printf("\nPosicion: %d\nId: %d\nMarca Bicicleta: %s\nRodado Bicicleta: %d\nIdServicio: %d\nDia: %d\nMes: %d\nAnio: %d ",posicion,
						pArray[posicion].id,pArray[posicion].marcaBicicleta,pArray[posicion].rodadoBicicleta,pArray[posicion].idServicio,pArray[posicion].fecha.dia,
						pArray[posicion].fecha.mes,pArray[posicion].fecha.anio);
				utn_getNumero(&opcion,"\nModificar: \n\n1-Marca de Bicicleta \n2-Servicio \n3-Salir\n","\nError",1,3,2);
				switch (opcion)
				{
					case 1:
						utn_getNombre(pArray[posicion].marcaBicicleta, LEN_MARCA, "\nIngrese Marca Bicicleta","\nError",2);
						break;
					case 2:
						utn_getNumero(&pArray[posicion].idServicio,"\n Id a  Modificar[20000-Limpieza -20001-Parche - 20002-Centrado - 20003-Cadena]","\nError",20000,20003,2);
						break;
					case 3:
						break;
					default:
						printf("\nOpcion invalida");
				}
			} while (opcion != 3);
			retorno = 0;
		}
	}
	return retorno;
}


/**
 * \brief Actualiza una posicion del array
 * \param pArray Array de Trabajo a ser actualizado
 * \param len Limite del array de Trabajo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */


int trabajo_bajaArray(Trabajo *pArray, int len, Servicio *pArrayS,int lenS)
{
	int retorno = -1;
	int posicion;
	int id;

	if (pArray != NULL && len > 0)
	{
		trabajo_imprimirArray(pArray, len, pArrayS, lenS);
		utn_getNumero(&id,"\nId a eliminar: ", "\nError",1,30000, 2);
		if(trabajo_encontrarById(pArray,len,id,&posicion)==-1)
		{
			printf("\nEl id ingresado no existe.");
		}
		else
		{
			pArray[posicion].isEmpty = 1;
			retorno = 0;
		}
	}

	return retorno;
}

/**
* \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param pArray Trabajp Array de Trabajo
* \param len int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*/
int trabajo_buscarId(Trabajo* pArray, int len, int valorBuscado)
{
	int ret = -1;
	int i;
	if(pArray != NULL && len > 0 && valorBuscado >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty==0 && pArray[i].id == valorBuscado)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

/**
 * \brief Buscar primer posicion vacia
 * \param pArray Array de Trabajo
 * \param len Limite del array de Trabajo
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int trabajo_getEmptyIndex(Trabajo* pArray,int len)
{
	int ret = -1;
	int i;
	if(pArray != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(pArray[i].isEmpty == 1)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}


/********************************************************************************************************/

/*brief Ordena por Año y si son iguales ordena por marca, segun el orden (ascendente/descendente)
 * param1 pArray *trabajo, array con los elementos a ordenar.
 * param2 int len, cantidad de elementos del array.
 * param3 int orden,[1] para que sea ascendente [0] para que sea descendente.
 * return retorna 0 si funciona correctamente o -1 si hubo algun error.
 * */

int trabajo_ordenarTrabajoAnio(Trabajo* pArray,int len, int orden)
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
				if(pArray[i].isEmpty == 0 && pArray[j].isEmpty == 0)
				{
					if((orden && pArray[i].fecha.anio > pArray[j].fecha.anio) || (!orden && pArray[i].fecha.anio < pArray[j].fecha.anio))
					{
						Aux = pArray[i];
						pArray[i] = pArray[j];
						pArray[j] = Aux;
						retorno = 0;
					}
					else
					{
						if(pArray[i].fecha.anio == pArray[j].fecha.anio)
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

			}
		}
	}

	return retorno;
}


/********************************************************************************************************/

/*
 * brief Recibe el id de un Trabajo y devuelve su posicion en el array
 * param list Array de Trabajo
 * param len Tamaño del array de Trabajo
 * param id Numero de id delTrabajo para saber su posicion en el array
 * param posicion Puntero al espacio de memoria donde se va a guardar la posicion del electrodomestico en el array
 * return Retorna 0 si salio OK y -1 si no
 */

int trabajo_encontrarById(Trabajo* pArray, int len, int id,int *posicion)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 1)
			{
				continue;
			}
			else if (pArray[i].id == id)
			{
				*posicion = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Ordenar el array de Trabajo por ID ascendente
 * \param pArray Array de Trabajo
 * \param len Limite del array de Trabajo
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int trabajo_ordenarID(Trabajo* pArray,int len)
{
	int ret = -1;
	int flagSwap;
	int i;
	Trabajo buffer;
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
 * param list Array de trabajo
 * param len Longitud del array
 * return Retorna 1 si esta completamente vacio y 0 si tiene al menos un trabajo guardado
 */

int trabajo_arrayVacio(Trabajo *pArray, int len)
{
	int retorno = 1;
	int i;

	if (pArray != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



/*********************************************************************************************************/

void menuPrincipal()
{
    printf("\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - Alta de trabajo\n");
    printf("2 - Modificar trabajo\n");
    printf("3 - Baja trabajo\n");
    printf("4 - Lista trabajo \n");
    printf("5 - Lista servicio \n");
    printf("6 - Total servicios\n");
    printf("7 - Salir\n");

}

