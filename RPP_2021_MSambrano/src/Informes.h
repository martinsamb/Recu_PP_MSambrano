/*
 * Informes.h
 *
 *  Created on: 21 jun. 2021
 *      Author: martin
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int info_ServiciosPrestados(Trabajo *pArray,int len, Servicio *pArrayS,int lenS);
int info_ordenarTrabajoMarca(Trabajo* pArray,int len, int orden);
int info_serviciosMasTrabajos(Servicio *pArrayS,int lenS,Trabajo *pArray,int len);


#endif /* INFORMES_H_ */
