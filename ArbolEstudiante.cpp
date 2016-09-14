/*
 * ArbolEstudiante.cpp
 *
 *  Created on: 14/06/2016
 *      Author: alejandro
 */

#include "ArbolEstudiantes.h"
#include "arbol.h"
#include "comparaestudiante.h"
#include "Estudiante.h"
using namespace std;

ArbolEstudiantes::ArbolEstudiantes() {
	abb = new Arbol<Estudiante *, ComparaPtrEstudiante>;
}

void ArbolEstudiantes::borrarP(Estudiante *e) {
	abb->borrar(e);
}

void ArbolEstudiantes::mayornota(Arbol<Estudiante *, ComparaPtrEstudiante> *abb,Estudiante *&e, float &nota) {
	Arbol<Estudiante *, ComparaPtrEstudiante> *aux;
	if(!abb->vacio()){
		aux=abb->hijoIzq();
		if (aux != NULL) {
			mayornota(abb->hijoIzq(),e,nota);
		}
		if(abb->raiz()->getNota()>nota){
			e=abb->raiz();
			nota=e->getNota();
		}
		aux=abb->hijoDer();
		if(aux!=NULL){
		mayornota(abb->hijoDer(),e,nota);
		}
	}
}

void ArbolEstudiantes::menornota(Arbol<Estudiante *, ComparaPtrEstudiante> *abb,Estudiante *&e, float &nota) {
	Arbol<Estudiante *, ComparaPtrEstudiante> *aux;
	if(!abb->vacio()){
			aux=abb->hijoIzq();
			if (aux != NULL) {
				menornota(abb->hijoIzq(),e,nota);
			}
			if(abb->raiz()->getNota()<nota){
				e=abb->raiz();
				nota=e->getNota();
			}
			aux=abb->hijoDer();
			if(aux!=NULL){
			menornota(abb->hijoDer(),e,nota);
			}
		}
	}

void ArbolEstudiantes::mostrar(Arbol<Estudiante *, ComparaPtrEstudiante> *abb) {
	if (abb != NULL) {
		mostrar(abb->hijoIzq());
		abb->raiz()->mostrar();
		mostrar(abb->hijoDer());
	}
}

void ArbolEstudiantes::mostrarP() {
	mostrar(abb);
}

bool ArbolEstudiantes::perteneceEstudiante (Estudiante *e){
	return abb->pertenece(e);
}

bool ArbolEstudiantes::buscar(Arbol<Estudiante *, ComparaPtrEstudiante> *abb,string ape1,string ape2,string nombre,string dni,Estudiante *&e) {
	bool encontrado = false;
	Arbol<Estudiante *, ComparaPtrEstudiante> *aux;

	if (abb != NULL) {
		if(abb->raiz()->getape1() > ape1){
			aux=abb->hijoIzq();
			if(aux!=NULL){
				encontrado = buscar(aux,ape1,ape2,nombre,dni,e);
			}
		}
		if(abb->raiz()->getape1()==ape1){
			if(abb->raiz()->getape2()>ape2){
				aux=abb->hijoIzq();
				if(aux!=NULL){
					encontrado = buscar(aux,ape1,ape2,nombre,dni,e);
				}
			}
			if(abb->raiz()->getape2()==ape2){
				if(abb->raiz()->getNombre() > nombre){
					aux=abb->hijoIzq();
					if(aux!=NULL){
						encontrado = buscar(aux,ape1,ape2,nombre,dni,e);
					}
				}
				if(abb->raiz()->getNombre()==nombre){

					if(abb->raiz()->getdni()>dni){
						aux=abb->hijoIzq();
						if(aux!=NULL){
							encontrado = buscar(aux,ape1,ape2,nombre,dni,e);
						}
					}
					if(abb->raiz()->getdni()==dni){
						encontrado = true;
						e=abb->raiz();
					}
					if(abb->raiz()->getdni()<dni){
						aux=abb->hijoDer();
						if(aux!=NULL){
							encontrado = buscar(aux,ape1,ape2,nombre,dni,e);
						}
					}
				}
				if(abb->raiz()->getNombre() < nombre){
					aux=abb->hijoDer();
					if(aux!=NULL){
						encontrado = buscar(aux,ape1,ape2,nombre,dni,e);
					}
				}
			}
			if(abb->raiz()->getape2()<ape2){
				aux=abb->hijoDer();
				if(aux!=NULL){
					encontrado = buscar(aux,ape1,ape2,nombre,dni,e);
				}
			}
		}
		if(abb->raiz()->getape1() < ape1){
			aux=abb->hijoDer();
			if(aux!=NULL){
				encontrado = buscar(aux,ape1,ape2,nombre,dni,e);
			}
		}
	}
	return encontrado;
}

void ArbolEstudiantes::buscarporraizP(Arbol<Estudiante *, ComparaPtrEstudiante> *abb,string &nombre){
	Estudiante *e;
	Arbol<Estudiante*, ComparaPtrEstudiante> *aux;
	string raiz;

	if (!abb->vacio()) {
		aux = abb->hijoIzq();
		if (aux != NULL) {
			buscarporraizP(aux, nombre);
		}
		e = abb->raiz();
		raiz = e->getNombre();
		if (raiz.find(nombre)==0 ) {
			e->mostrar();
		}
		aux = abb->hijoDer();
		if (aux != NULL) {
			buscarporraizP(aux, nombre);
		}
	}
}

void ArbolEstudiantes::buscarporraiz(string nombre){
	 buscarporraizP(abb,nombre);
}

void ArbolEstudiantes::insertarP(Estudiante* e) {
	abb->insertar(e);
}

bool ArbolEstudiantes::buscarP(string ape1,string ape2,string nombre,string dni,Estudiante *&e) {
	return(buscar(abb,ape1,ape2,nombre,dni,e));
}

Estudiante* ArbolEstudiantes::mayornotaP() {
	Estudiante *aux;
	float nota = 0;
	mayornota(abb, aux, nota);
	return aux;
}

Estudiante* ArbolEstudiantes::menornotaP() {
	Estudiante *aux;
	float nota = 11;
	menornota(abb, aux, nota);
	return aux;
}

Arbol<Estudiante *, ComparaPtrEstudiante>* ArbolEstudiantes::similares(
		Arbol<Estudiante *, ComparaPtrEstudiante> *abb, const string &apel) {

	Estudiante *e;
	Arbol<Estudiante *, ComparaPtrEstudiante> *izq;
	Arbol<Estudiante *, ComparaPtrEstudiante> *der;
	Arbol<Estudiante *, ComparaPtrEstudiante> *aux = NULL;
	string raiz;

	if (!abb->vacio()) {
		e=abb->raiz();
		raiz = e->getape1();
		if(raiz.find(apel)==0){
			aux=abb;
		}
		else{
			if(raiz<apel){
				der=abb->hijoDer();
				if(der!=NULL){
					aux=similares(der,apel);
				}
			}
			else{
				izq=abb->hijoIzq();
				if(izq!=NULL){
					aux=similares(izq,apel);
				}
			}
		}
	}
	return aux;
}

void ArbolEstudiantes::filtroInOrden(Arbol<Estudiante*,ComparaPtrEstudiante>*abb,const string &ape1){
	Arbol<Estudiante*,ComparaPtrEstudiante> *aux;
	string raiz;

	if(!abb->vacio()){
		aux=abb->hijoIzq();
		if(aux!=NULL){
			filtroInOrden(aux,ape1);
		}
		if(abb->raiz()->getape1().find(ape1)==0){
			abb->raiz()->mostrar();
		}
		aux=abb->hijoDer();
		if(aux!=NULL){
			filtroInOrden(aux,ape1);
		}
	}
}

void ArbolEstudiantes::mostrarSimilares(const string &ape1){
	Arbol<Estudiante*,ComparaPtrEstudiante> *aux;

	if(!abb->vacio()){
		aux=similares(abb,ape1);
		if(aux!=NULL){
			cout<<"Mostrando: "<<ape1<<endl;
			filtroInOrden(aux,ape1);
		}
		else
			cout<<"No existe nadie que empiece por :"<<ape1<<endl;
	}

}

bool ArbolEstudiantes::existeabbP(Arbol<Estudiante*,ComparaPtrEstudiante>*abb){
	return abb->vacio();
}

bool ArbolEstudiantes::existeabb(){
	return existeabbP(abb);
}

ArbolEstudiantes::~ArbolEstudiantes() {
	Estudiante *aux;
	while (!abb->vacio()) {
	aux = abb->raiz();
	borrarP(aux);
	delete aux;
	}
	delete abb;
}
