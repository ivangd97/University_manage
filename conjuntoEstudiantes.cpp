/*
 * conjuntoEstdiantes.cpp
 *
 *  Created on: 13/04/2016
 *      Author: alejandro
 */

#include "conjuntoEstudiantes.h"

using namespace std;

conjuntoEstudiantes::conjuntoEstudiantes() {
	montonEstudiantes = new ListaPI <Estudiante*>;
	ace = new ArbolEstudiantes;
}

int conjuntoEstudiantes::cuantos(){
	int cont=0;
	if(!montonEstudiantes->estaVacia()){
		montonEstudiantes->moverInicio();
		while(!montonEstudiantes->finLista()){
			cont++;
			montonEstudiantes->avanzar();
		}
	}
	return cont;
}

void conjuntoEstudiantes::insertarOrdenNota(Estudiante *est){
	Estudiante *e;
	bool insertado = false;
	montonEstudiantes->moverInicio();
	if(montonEstudiantes->estaVacia()){
		montonEstudiantes->insertar(est);
	}
	else{
		while (!montonEstudiantes->finLista() && !insertado) {
			montonEstudiantes->consultar(e);
			if(e->getNota()>est->getNota()){
				montonEstudiantes->avanzar();
			}
			else{
				insertado = true;
			}
		}
		montonEstudiantes->insertar(est);
	}
}

void conjuntoEstudiantes::eliminarMenorNota(){
	if(!montonEstudiantes->estaVacia()){
		montonEstudiantes->moverFinal();
		montonEstudiantes->borrar();
	}
}

void conjuntoEstudiantes::buscarMenorNota (Estudiante *&e){
	if(!montonEstudiantes->estaVacia()){
		montonEstudiantes->moverFinal();
		montonEstudiantes->consultar(e);
	}
}

bool conjuntoEstudiantes::buscarDNI(string nuevodni, Estudiante *&est){
	bool encontrado = false;
	Estudiante *e;
	montonEstudiantes->moverInicio();
	if(!montonEstudiantes->estaVacia()){
		while(!montonEstudiantes->finLista() && !encontrado){
			montonEstudiantes->consultar(e);
			if(e->getdni()== nuevodni){
				est = e;
				encontrado = true;
			}
			else{
				montonEstudiantes->avanzar();
			}
		}
	}
	return encontrado;
}

void conjuntoEstudiantes::buscarMayorNota (Estudiante *&e){
	if(!montonEstudiantes->estaVacia()){
		montonEstudiantes->moverInicio();
		montonEstudiantes->consultar(e);
	}
}

void conjuntoEstudiantes::mostrar(){
	Estudiante *e;
	montonEstudiantes->moverInicio();
	while(!montonEstudiantes->finLista()){
		montonEstudiantes->consultar(e);
		e->mostrar();
		montonEstudiantes->avanzar();
	}
}

void conjuntoEstudiantes::volcarArbol() {
	Estudiante *e;
	if(!montonEstudiantes->estaVacia()){
		montonEstudiantes->moverInicio();
		while(!montonEstudiantes->finLista()){
			montonEstudiantes->consultar(e);
			montonEstudiantes->borrar();
			ace->insertarP(e);
		}
	}
}

bool conjuntoEstudiantes::buscarenarbol(string ape1,string ape2,string nombre,string dni,Estudiante *&e) {
	return(ace->buscarP(ape1,ape2,nombre,dni,e));
}

void conjuntoEstudiantes::insertarenarbol(Estudiante *e) {
	ace->insertarP(e);
}

void conjuntoEstudiantes::borrarenarbol(Estudiante *e) {
	ace->borrarP(e);
}

void conjuntoEstudiantes::mayornotaarbol(Estudiante *&e) {
	e = ace->mayornotaP();
}

void conjuntoEstudiantes::menornotaarbol(Estudiante *&e) {
	e = ace->menornotaP();
}

void conjuntoEstudiantes::mostrararbol() {
	ace->mostrarP();
}

bool conjuntoEstudiantes::pertenecearbol(Estudiante *e){
	return ace->perteneceEstudiante(e);
}

void conjuntoEstudiantes::similaresarbol(string apel){
	ace->mostrarSimilares(apel);
}

bool conjuntoEstudiantes::existearbol(){
	return ace->existeabb();
}

void conjuntoEstudiantes::buscarestudiante(string nombre) {
	ace->buscarporraiz(nombre);
}

conjuntoEstudiantes::~conjuntoEstudiantes() {
	Estudiante *e;
	montonEstudiantes->moverInicio();
	while(!montonEstudiantes->estaVacia()){
		montonEstudiantes->consultar(e);
		montonEstudiantes->borrar();
		delete e;
	}
	delete montonEstudiantes;
	delete ace;
}
