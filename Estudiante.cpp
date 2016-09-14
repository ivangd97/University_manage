///============================================================================
// Name        : Estudiante.cpp
// Author      : Profesores de la asignatura
// Version     : Curso 15/16
// Copyright   : UEx
// Description : implementación de la clase estudiante
//============================================================================


#include "Estudiante.h"
#include "cola.h"

Estudiante::Estudiante() {
	ape1   = "";
	ape2   = "";
	nombre = "";
	dni    = "";
	nota   = 0.0;
	colaSol = new solicitud;
}

Estudiante::Estudiante(string ape1, string ape2, string nombre, string dni, float nota){
	this->ape1   = ape1;
	this->ape2   = ape2;
	this->nombre = nombre;
	this->dni    = dni;
	this->nota   = nota;
	colaSol = new solicitud;
}

Estudiante::Estudiante(string ape1, string ape2, string nombre, string dni) {
	this->ape1   = ape1;
	this->ape2   = ape2;
	this->nombre = nombre;
	this->dni    = dni;
	this->nota   = 0.0;
	colaSol      = new solicitud;
}

void Estudiante::mostrar(){
	cout <<ape1 <<" "<<ape2<<" "<<nombre<<" "<<dni<<" \t\t"<<nota <<endl;
}

void Estudiante::setSolicitud(string sol){
	colaSol->setSolicitud(sol);
}

float Estudiante:: getNota()const{
	return nota;
}

string Estudiante::getNombre()const{
	return nombre;
}

string Estudiante::getape1 ()const{
	return ape1;
}

string Estudiante::getape2 ()const{
	return ape2;
}

string Estudiante::getdni ()const{
	return dni;
}

string Estudiante::getSolicitud1(){
	return	colaSol->getSolicitud();
}

bool Estudiante::estaVacia(){
	return	colaSol->estaColaVacia();
}

bool Estudiante::operator <(const Estudiante &e){
	return (nota<e.nota);
}

bool Estudiante::operator ==(const Estudiante &e){
	string nombre1, nombre2;
	nombre1 = getape1()+getape2()+getNombre();
	nombre2 = e.ape1+e.ape2+e.nombre;
	return (nombre1==nombre2);
}

Estudiante::~Estudiante() {
	delete colaSol;
}


