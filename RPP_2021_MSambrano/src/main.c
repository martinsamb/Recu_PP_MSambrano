/*
 ============================================================================
 Name        : RPP_2021_MSambrano.c
 Author      : martin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"
#include "Trabajo.h"
#include "Informes.h"
#include "utn.h"

#define QTY_SERVICIO 4
#define QTY_TRABAJO 50
#define ORDEN_ASC 1
#define ORDEN_DES 0

int main(void)
{
	setbuf(stdout,NULL);
	int option;
	//int auxAsc=0;
	//int auxDes=0;

	Trabajo arrayTrabajo[QTY_TRABAJO];

	//Inicializacion
	trabajo_inicializarArray(arrayTrabajo, QTY_TRABAJO);

	//harcodear
	Servicio arrayServicio[]={ { 20000, "Limpieza", 250 , 0 }, { 20001, "Parche", 300 , 0 }, { 20002, "Centrado", 400 , 0 }, { 20003, "Cadena", 350 , 0 } };
	/*Trabajo arrayTrabajo[]={{1,"Trek",26,20000,{4,4,2020},0},{2,"Specialized",26,20001,{5,5,2020},0},{3,"Giant",26,20002,{2,9,2020},0},
							{4,"Cannondale",26,20003,{6,2,2021},0}};*/
	do
	{
		menuPrincipal();
		if(!utn_getNumero(&option,"\nElija una Opcion del Menu[1-9]:","\nError",1,9,2))
		{
			switch(option)
			{
			case 1://Alta trabajo
				trabajo_altaArray(arrayTrabajo,QTY_TRABAJO,arrayServicio,QTY_SERVICIO);

				break;

			case 2://Modificar trabajo
				if (trabajo_arrayVacio(arrayTrabajo, QTY_TRABAJO))
				{
					printf("\nAun no se cargo ningun trabajo.\n\n");
				}
				else
				{
					trabajo_modificarArray(arrayTrabajo, QTY_TRABAJO,arrayServicio, QTY_SERVICIO);
				}
				break;

			case 3://baja trabajo
				if (trabajo_arrayVacio(arrayTrabajo, QTY_TRABAJO))
				{
					printf("\nAun no se cargo ningun trabajo.\n\n");
				}
				else
				{
					trabajo_bajaArray(arrayTrabajo, QTY_TRABAJO, arrayServicio, QTY_SERVICIO);
				}
				break;

			case 4://Listar trabajo
				if(trabajo_arrayVacio(arrayTrabajo, QTY_TRABAJO))
				{
					printf("Aun no tiene trabajo dados de alta\n");
				}
				else
				{
					trabajo_ordenarTrabajoAnio(arrayTrabajo, QTY_TRABAJO,ORDEN_ASC);
				}
				trabajo_imprimirArray(arrayTrabajo, QTY_TRABAJO, arrayServicio, QTY_SERVICIO);
				break;

			case 5://Lista servicio
				if(servicio_arrayVacio(arrayServicio, QTY_SERVICIO))
				{
					printf("\nNo se cargo ningun servicio");
				}
				else
				{
					servicio_imprimirArray(arrayServicio, QTY_SERVICIO);
				}
				break;

			case 6://Total servicios
				info_ServiciosPrestados(arrayTrabajo, QTY_TRABAJO,arrayServicio, QTY_SERVICIO);
				break;

			case 7://Total servicios
				if(trabajo_arrayVacio(arrayTrabajo, QTY_TRABAJO))
				{
					printf("Aun no tiene trabajo dados de alta\n");
				}
				else
				{
					info_ordenarTrabajoMarca(arrayTrabajo, QTY_TRABAJO, ORDEN_ASC);
				}
				trabajo_imprimirArray(arrayTrabajo, QTY_TRABAJO, arrayServicio, QTY_SERVICIO);
				break;

			case 8://Total servicios
				info_serviciosMasTrabajos(arrayServicio, QTY_SERVICIO,arrayTrabajo, QTY_TRABAJO);
				break;

			case 9: //Salir
				break;
			default:
				printf("\nOpcion no valida");
			}
		}
	}while(option != 9);


	return EXIT_SUCCESS;
}
