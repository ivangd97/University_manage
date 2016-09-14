/*
 * Titulaciones.cpp
 *
 *  Created on: 27/04/2016
 *      Author: alejandro
 */

#include "Titulaciones.h"
#include "iostream"
using namespace std;

Titulaciones::Titulaciones() {
	listaTitulaciones = new ListaPI<Titulacion*>;
}

void Titulaciones::insertarTitulacion(Titulacion *t){
	listaTitulaciones->insertar(t);
	listaTitulaciones->moverFinal();
	listaTitulaciones->avanzar();
}

bool Titulaciones::buscarTitulacion (string code,Titulacion *&t){
	bool encontrado = false;
	listaTitulaciones->moverInicio();
	while(!listaTitulaciones->finLista() && !encontrado){
		listaTitulaciones->consultar(t);
		if(t->getcodigoTitulacion()==code){
			encontrado=true;
		}
		else
			listaTitulaciones->avanzar();
	}
	return encontrado;
}

void Titulaciones::volcartitulaciones() {
	Titulacion *t;
	if(!listaTitulaciones->estaVacia()){
		listaTitulaciones->moverInicio();
		while(!listaTitulaciones->finLista()){
			listaTitulaciones->consultar(t);
			t->volcaraarboles();
			listaTitulaciones->avanzar();
		}
	}
}

void Titulaciones::mostrarTitulacion() {
	Titulacion *t;
	listaTitulaciones->moverInicio();
	while(!listaTitulaciones->finLista()){
		listaTitulaciones->consultar(t);
		t->mostrarTitulacion();
		listaTitulaciones->avanzar();
	}
}

void Titulaciones::conseguirTitulacion(int i,Titulacion *&t){
	listaTitulaciones->moverInicio();
	while(i!=1 && !listaTitulaciones->finLista())	{
		listaTitulaciones->avanzar();
		i--;
	}
	listaTitulaciones->consultar(t);
}

void Titulaciones::borrardearbolesE(Estudiante *e){
	Titulacion *t;
	if(!listaTitulaciones->estaVacia()){
		listaTitulaciones->moverInicio();
		while(!listaTitulaciones->finLista()){
			listaTitulaciones->consultar(t);
			if(t->pertenecearbolE(e)){
				t->borrarenarbolE(e);
			}
			listaTitulaciones->avanzar();
		}
	}
}

void Titulaciones::mostrarNotaCorte(){
Titulacion *t;
Estudiante *e;
	listaTitulaciones->moverInicio();
	while(!listaTitulaciones->finLista()){
		listaTitulaciones->consultar(t);
		cout << t->getcarrera() << endl;
		cout << "Con nota de corte: " << endl;
		t->menornotaarbolA(e);
		cout << e->getNota() << endl;
		listaTitulaciones->avanzar();
	}
}

void Titulaciones::mostrararbolTitulaciones(int i){
	Titulacion *t;
	conseguirTitulacion(i,t);
	cout<<"Admitidos:"<<endl;
	t->mostrararbolA();
	cout<<"Espera:"<<endl;
	t->mostrararbolE();
}

void Titulaciones::mostrarTitulacionconcreta(int i) {
	Titulacion *t = NULL;
	listaTitulaciones->moverInicio();
	while(i<=7 && i>1){
		listaTitulaciones->avanzar();
		i--;
	}
	listaTitulaciones->consultar(t);
	t->mostrarTitulacion();
}

void Titulaciones::mostrarestudiantearbol(string nombre,int i){
	Titulacion *t = NULL;
	listaTitulaciones->moverInicio();
	while(i!=1){
		listaTitulaciones->avanzar();
		i--;
	}
	listaTitulaciones->consultar(t);
	t->buscarestudiante(nombre);
}
void Titulaciones::buscarporDNI(string dni){
	Estudiante *e;
	Titulacion *t;
	bool salir = false;
	listaTitulaciones->moverInicio();
	while(!salir && !listaTitulaciones->finLista()){
		listaTitulaciones->consultar(t);
		if(t->buscarDNIA(dni,e) == true){
			cout<<"Se encuentra en la lista de admtidos de  "<<t->getcarrera()<<endl;
			e->mostrar();
			salir = true;
		}
		if(t->buscarDNIE(dni,e) == true){
			cout<<"Se encuentra en la lista de espera de  "<<t->getcarrera()<<endl;
			e->mostrar();
		 	salir = true;
		}
		else{
			listaTitulaciones->avanzar();
		}
	}
	if(!salir){
		cout<<"El estudiante no existe"<<endl;
	}
}

Titulaciones::~Titulaciones() {
	Titulacion *t;
	listaTitulaciones->moverInicio();
	while(!listaTitulaciones->estaVacia()){
		listaTitulaciones->consultar(t);
		delete t;
		listaTitulaciones->borrar();
	}
	delete listaTitulaciones;
}

