/*
 * solicitud.h
 *
 *  Created on: 12/04/2016
 *      Author: alejandro
 */

#ifndef SOLICITUD_H_
#define SOLICITUD_H_
#include "cola.h"
using namespace std;

class solicitud {
	Cola<string> *codigoTitulacion;
public:
	solicitud();

	//PRE:La cola debe de estar creada
	//POST:Devuelve la primera solicitud de la cola
	//PARÁMETROS: Ninguno, devuelve una solicitud de la cola
	//COMPLEJIDAD:O(1)
	string getSolicitud ()const;

	//PRE:La cola debe de estar creada
	//POST:Encola una solicitud a la cola
	//PARÁMETROS: codigo será el codigo de la titulacion que queremos solicitar
	//COMPLEJIDAD:O(1)
	void setSolicitud(string codigo);

	//PRE:La cola debe de estar creada
	//POST:Devuelve true si la cola esta vacia y si no false
	//PARÁMETROS: Ninguno, retorna si la cola está vacía o no
	//COMPLEJIDAD:O(1)
	bool estaColaVacia();

	~solicitud();
};


#endif /* SOLICITUD_H_ */
