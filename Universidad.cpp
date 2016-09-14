/*
 * Universidad.cpp
 *
 *  Created on: 12/04/2016
 *      Author: alejandro
 */

#include "Universidad.h"
#include "Estudiante.h"
#include "Titulacion.h"
#include "cola.h"
#include "pila.h"
#include "solicitud.h"
#include "Preinscripciones.h"
#include "Titulaciones.h"
#include "Pruebas.h"
using namespace std;
#include <fstream>
#include <sstream>
#include <cstring>
#include <ostream>

Universidad::Universidad() {
	Estudiante();
	Titulacion();
	totalEstudiantes = new Preinscripciones;
	totalTitulaciones = new Titulaciones;
}

void Universidad::cargarPilaEstudiantes (){
	ifstream fent;
	Estudiante *e;
	string ape1,ape2,nombre,dni,nota,limite,cod;
	float newNota;
	int lim;
	string sol;
	fent.open ("estudiantes.txt");
	if(fent.is_open()){
		while(!fent.eof()){
			getline(fent,ape1,'#');
			if(!fent.eof()){
				getline(fent,ape2,'#');
				getline(fent,nombre,'#');
				getline(fent,dni,'#');
				getline(fent,nota,'#');
				getline(fent,limite);
				newNota = atof(nota.c_str());
				lim = atoi(limite.c_str());
				e= new Estudiante(ape1,ape2,nombre,dni,newNota);
				for(int i=0;i<lim;i++){
					getline(fent,cod);
					e->setSolicitud(cod);
				}
				totalEstudiantes->meterEstudiante(e);
			}
		}
	}
	fent.close();
}

void Universidad::cargarTitulaciones (){
	ifstream fent;
	ofstream fsal;
	string codigo,nombreTitulacion,plazasTotales;
	int plazas;
	fent.open("titulaciones.txt");
	if(fent.is_open()){
		while(!fent.eof()){
			getline(fent,codigo,'#');
			getline(fent,nombreTitulacion,'#');
			getline(fent,plazasTotales);
			plazas = atoi(plazasTotales.c_str());
			Titulacion *t = new Titulacion(codigo,plazas,nombreTitulacion);
			totalTitulaciones->insertarTitulacion(t);

			string nombreT= codigo +".txt";
			fsal.open (nombreT.c_str());

			fsal<<codigo<<" "<<nombreTitulacion<<" "<<" "<<plazasTotales<<endl;

			fsal.close();
		}
	}
	fent.close();
}

void Universidad::cargaMatriculadosB() {
	ifstream fent;
	ofstream fsal;
	Estudiante *e1, *e2;
	string ape1,ape2,nombre,dni,titulacion;
	string estado;
	string nombreF;
	Titulacion *t;
	fent.open ("matyrenuncias.txt");
	while(!fent.eof()){
		if(fent.is_open()){
			getline(fent,estado,'#');
			if(!fent.eof()){
				getline(fent,titulacion,'#');
				getline(fent,ape1,'#');
				getline(fent,ape2,'#');
				getline(fent,nombre,'#');
				getline(fent,dni);
				if(estado == "MAT"){
					if(totalTitulaciones->buscarTitulacion(titulacion,t)){
						if(t->buscarenarbolA(ape1,ape2,nombre,dni,e1)){
							t->borrarenarbolA(e1);
							totalTitulaciones->borrardearbolesE(e1);
							nombreF=titulacion + ".txt";
							fsal.open(nombreF.c_str(),ios::app);
							if(fsal.is_open()){
								fsal<<e1->getape1()<<" "<<e1->getape2()<<" "<<e1->getNombre()<<" "<<e1->getdni()<<" "<<e1->getNota()<<endl;
							}
							fsal.close();
						}
					}
				}
				else {
					if(totalTitulaciones->buscarTitulacion(titulacion,t)){
						if(t->buscarenarbolA(ape1,ape2,nombre,dni,e1)){
							t->borrarenarbolA(e1);
							totalTitulaciones->borrardearbolesE(e1);
							if(!t->existearbolE()){
								t->mayornotaarbolE(e2);
								t->insertarenarbolA(e2);
								t->borrarenarbolE(e2);
							}
						}
					}
				}
			}
		}
	}
	fent.close();
}

void Universidad::procesarEstudiante(Estudiante *&e){
	Estudiante *est;
	Titulacion *t;
	if(!e->estaVacia()) {
		if	(totalTitulaciones->buscarTitulacion(e->getSolicitud1(),t)){
			if(!t->LAllena()){
				t->insertarLA(e);
			}
			else{
				t->buscarMenorNotaLA(est);
				if(est->getNota() < e->getNota()){
					t->eliminarMenorNotaLA();
					t->insertarLE(est);
					t->insertarLA(e);
					procesarEstudiante(est);
				}
				else{
					t->insertarLE(e);
					procesarEstudiante (e);
				}
			}
		}
	}
}

void Universidad::asignarTitulaciones(){
	Estudiante *e;
	while(!totalEstudiantes->estaPilaVacia()){
		totalEstudiantes->consultarEstudiante(e);
		procesarEstudiante(e);
		totalEstudiantes->quitarEstudiante();
	}
}

void Universidad::mostrarCargaEstudiantes() {
	Estudiante *e;
	while(!totalEstudiantes->estaPilaVacia()){
		totalEstudiantes->consultarEstudiante(e);
		e->mostrar();
		totalEstudiantes->quitarEstudiante();
	}
}

void Universidad::mostrarEstudiante(){
	Estudiante *e = new Estudiante ();
	Pila <Estudiante*> *pAux = new Pila<Estudiante*> ;
	while(!totalEstudiantes->estaPilaVacia()){
		totalEstudiantes->consultarEstudiante(e);
		e->mostrar();
		pAux->apilar(e);
		totalEstudiantes->quitarEstudiante();
	}
	while(!pAux->vacia()){
		pAux->cima(e);
		totalEstudiantes->meterEstudiante(e);
		pAux->desapilar();
	}
}

void Universidad::pruebas(){
	Pruebas p;
	p.elegirPrueba();
}

void Universidad::mostrarTitulaciones(){
	totalTitulaciones->mostrarTitulacion();
}

void Universidad::mostrarNotaCorteTit(){
	totalTitulaciones->mostrarNotaCorte();
}

void Universidad::Matricula (){
	totalTitulaciones->volcartitulaciones();
}

void Universidad::mostrarTitulacionArbol(int i){
	totalTitulaciones->mostrararbolTitulaciones(i);
}

void Universidad::buscarPorDNI(string newDNI){
	totalTitulaciones->buscarporDNI(newDNI);
}
void Universidad::mostrarunaTitulacion(int i){
	totalTitulaciones->mostrarTitulacionconcreta(i);
}

void Universidad::mostrararbolraiz(string nombre,int i){
	totalTitulaciones->mostrarestudiantearbol(nombre,i);
}

Universidad::~Universidad() {
	delete totalEstudiantes;
	delete totalTitulaciones;
}
