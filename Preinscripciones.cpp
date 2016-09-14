/*
 * Preinscripciones.cpp
 *
 *  Created on: 27/04/2016
 *      Author: alejandro
 */

#include "Preinscripciones.h"

using namespace std;

Preinscripciones::Preinscripciones() {
	pilaEstudiantes = new Pila <Estudiante*> ;
}

bool Preinscripciones::estaPilaVacia (){
	bool estavacia = true;
		if(!pilaEstudiantes->vacia()){
			estavacia=false;
		}
	return estavacia;
}

void Preinscripciones::consultarEstudiante(Estudiante *&e){

	pilaEstudiantes->cima(e);

}

void Preinscripciones::meterEstudiante(Estudiante *e){
	pilaEstudiantes->apilar(e);
}

void Preinscripciones::quitarEstudiante(){
	pilaEstudiantes->desapilar();
}

Preinscripciones::~Preinscripciones() {
	while(!pilaEstudiantes->vacia()){
		pilaEstudiantes->desapilar();
	}
 delete pilaEstudiantes;
}


