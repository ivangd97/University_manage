/*
 * Preinscripciones.h
 *
 *  Created on: 27/04/2016
 *      Author: alejandro
 */

#ifndef PREINSCRIPCIONES_H_
#define PREINSCRIPCIONES_H_
#include "pila.h"
#include "Estudiante.h"
#include "conjuntoEstudiantes.h"
using namespace std;

class Preinscripciones {

private:
	Pila <Estudiante*> *pilaEstudiantes;

public:

	Preinscripciones();

	//PRE:La pila de estudiantes debe de estar bien creada
	//POST:Devuelve true si está la pila vacía o false en caso contrario
	//PARÁMETROS: Ninguno, retorna si la pila esta vacia o no
	//COMPLEJIDAD:O(1)
	bool estaPilaVacia	 	    ();

	//PRE:La pila de estudiantes debe de estar bien creada
	//POST:Apila un estudiante
	//PARÁMETROS: e será el estudiante que queremos añadir a la pila
	//COMPLEJIDAD:O(1)
	void meterEstudiante  		(Estudiante *e);

	//PRE:La pila de estudiantes debe de estar bien creada
	//POST:Desapila un estudiante
	//PARÁMETROS: Ninguno, elimina un estudiante de la pila
	//COMPLEJIDAD:O(1)
	void quitarEstudiante 		();

	//PRE:La pila de estudiantes debe de estar bien creada
	//POST:Se coge al primer estudiante de la pila y se guarda en una variable y se devuelve el puntero que apunta a ese estudiante
	//PARÁMETROS: e será el parámetro de entrada/salida donde almacenaremos el estudiante consultado
	//COMPLEJIDAD:O(1)
	void consultarEstudiante    (Estudiante *&e);

	~Preinscripciones();
};


#endif /* PREINSCRIPCIONES_H_ */
