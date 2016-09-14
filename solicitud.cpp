/*
 * solicitud.cpp
 *
 *  Created on: 12/04/2016
 *      Author: alejandro
 */

#include "solicitud.h"

using namespace std;

solicitud::solicitud() {
	codigoTitulacion = new Cola <string>;
}

void solicitud::setSolicitud(string s){
	codigoTitulacion->encolar(s);
}
string solicitud::getSolicitud()const{
	string s;
	codigoTitulacion->primero(s);
	codigoTitulacion->desencolar();
	return s;
}

bool solicitud::estaColaVacia(){
	bool esta = false;
	if (codigoTitulacion->vacia()){
		esta = true;
	}
	return esta;
}

solicitud::~solicitud() {
	while(!codigoTitulacion->vacia()){
		codigoTitulacion->desencolar();
	}
	delete codigoTitulacion;
}
