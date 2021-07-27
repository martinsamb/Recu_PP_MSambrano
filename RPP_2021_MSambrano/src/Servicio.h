/*
 * Servicio.h
 *
 *  Created on: 19 jun. 2021
 *      Author: martin
 */



#ifndef SERVICIO_H_
#define SERVICIO_H_


#define LEN_DESCRIPCION 21

typedef struct
{
	int id;
	char descripcion[LEN_DESCRIPCION];
	float precio;
	int isEmpty;

}Servicio;

#endif /* SERVICIO_H_ */

void servicio_imprimir(Servicio pArray);

void servicio_imprimirArray(Servicio* pArray,int len);

int servicio_inicializarArray(Servicio* pArray,int len);

int servicio_cargarDescripcionPorId(int idServicio, Servicio *pArray, int len,char *descripcion);

int servicio_harcodear(Servicio *pArray, int len, int limite);

int servicio_ordenarID(Servicio* pArray,int len);

int servicio_arrayVacio(Servicio *pArray, int len);

int servicio_descripcionPorId(int idBuscado, Servicio *pArrayS, int lenS,char *descripcion);

void servicio_imprimirTitulo();

int servicio_imprimirContenido(Servicio *pArrayS, int posicion);

