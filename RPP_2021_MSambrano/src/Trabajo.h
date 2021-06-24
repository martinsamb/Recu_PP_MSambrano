/*
 * Trabajo.h
 *
 *  Created on: 22 jun. 2021
 *      Author: marti
 */

#define LEN_MARCA 30

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct
{
	int dia;
	int mes;
	int anio;

}Fecha;


typedef struct
{
	int id;
	char marcaBicicleta[LEN_MARCA];
	int rodadoBicicleta;
	int idServicio;
	Fecha fecha;
	int isEmpty;

}Trabajo;


#endif /* TRABAJO_H_ */

int trabajo_buscarLibre(Trabajo *pArray, int len,int *posicion);

void trabajo_imprimir(Trabajo array,Servicio* pArray, int len);

void trabajo_imprimirArray(Trabajo *pArray, int len,Servicio* pArrayS, int lenS);

int trabajo_inicializarArray(Trabajo* pArray,int len);

int trabajo_altaArray(Trabajo* pArray, int len,Servicio *pArrayS, int lenS);

int trabajo_modificarArray(Trabajo* pArray,int len, Servicio* pArrayS, int lenS);

int trabajo_bajaArray(Trabajo *pArray, int len, Servicio *pArrayS,int lenS);

int trabajo_buscarId(Trabajo* pArray, int len, int valorBuscado);

int trabajo_getEmptyIndex(Trabajo* pArray,int len);

int trabajo_ordenarTrabajoAnio(Trabajo* pArray,int len, int orden);

/********************************************************************************************************/

int trabajo_encontrarById(Trabajo* pArray, int len, int id,int *posicion);

int trabajo_ordenarID(Trabajo* pArray,int len);

int trabajo_arrayVacio(Trabajo *pArray, int len);

/*********************************************************************************************************/

void menuPrincipal();

