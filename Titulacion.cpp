/*
x * Titulacion.cpp
 *
 *  Created on: 12/04/2016
 *      Author: alejandro
 */

#include "Titulacion.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <ostream>

using namespace std;

Titulacion::Titulacion() {
	plazas = 00;
	codigoTitulacion = " ";
	carrera = " ";
	ListaAdmitidos = new conjuntoEstudiantes;
	ListaEspera = new conjuntoEstudiantes;
	NotaCorte = 00;
}

Titulacion::Titulacion(string codigoTitulacion,int plazas,string carrera){
	this->codigoTitulacion = codigoTitulacion;
	this->plazas = plazas;
	this->carrera = carrera;
	ListaAdmitidos = new conjuntoEstudiantes;
	ListaEspera = new conjuntoEstudiantes;
	this->NotaCorte = 00;
}
int Titulacion::getplazas(){
	return plazas;
}

string Titulacion::getcarrera(){
	return carrera;
}

string Titulacion::getcodigoTitulacion(){
	return codigoTitulacion;
}

void Titulacion::insertarLA(Estudiante *e){

	ListaAdmitidos->insertarOrdenNota(e);
}

void Titulacion::insertarLE(Estudiante *e){

	ListaEspera->insertarOrdenNota(e);
}

bool Titulacion::LAllena(){

	bool esta = false;
	if(ListaAdmitidos->cuantos() == plazas){
		esta = true;
	}
	return esta;
}


void Titulacion::mostrarTitulacion(){
	cout<<codigoTitulacion<<" "<<carrera<<" "<<plazas << endl;
	cout<<"Lista de admitidos"<<endl;
	ListaAdmitidos->mostrar();
	cout<<"Lista de espera"<<endl;
	ListaEspera->mostrar();

}

void Titulacion::eliminarMenorNotaLA (){
	ListaAdmitidos->eliminarMenorNota();
}

void Titulacion::buscarMayorNotaLE   (Estudiante *&e){
	ListaEspera->buscarMayorNota(e);
}

void Titulacion::buscarMenorNotaLA   (Estudiante *&e){
	ListaAdmitidos->buscarMenorNota(e);
}
void Titulacion::mostrarArbol(){
	cout << "Lista de admitidos: " << endl;
	ListaAdmitidos->mostrararbol();
	cout << "Lista de espera: " << endl;
	ListaEspera->mostrararbol();
}

void Titulacion::volcarabbadmitidos(){
	ListaAdmitidos->volcarArbol();
}

void Titulacion::volcarabbespera(){
	ListaEspera->volcarArbol();
}

void Titulacion::volcaraarboles(){
	ListaAdmitidos->volcarArbol();
	ListaEspera->volcarArbol();
}

void Titulacion::insertarenarbolA(Estudiante *&e) {
	ListaAdmitidos->insertarenarbol(e);
}

bool Titulacion::buscarenarbolA(string ape1,string ape2,string nombre,string dni,Estudiante *&e) {
	return(ListaAdmitidos->buscarenarbol(ape1,ape2,nombre,dni,e));
}

bool Titulacion::buscarenarbolE(string ape1,string ape2,string nombre,string dni,Estudiante *&e) {
	return(ListaEspera->buscarenarbol(ape1,ape2,nombre,dni,e));
}

void Titulacion::insertarenarbolE(Estudiante*& e) {
	ListaEspera->insertarenarbol(e);
}

void Titulacion::borrarenarbolA(Estudiante*e) {
	ListaAdmitidos->borrarenarbol(e);
}

void Titulacion::borrarenarbolE(Estudiante*e) {
	ListaEspera->borrarenarbol(e);
}

void Titulacion::mayornotaarbolE(Estudiante *&e) {
	ListaEspera->mayornotaarbol(e);
}

void Titulacion::menornotaarbolA(Estudiante *&e) {
	ListaAdmitidos->menornotaarbol(e);
}

void Titulacion::mostrararbolA() {
	ListaAdmitidos->mostrararbol();
}

void Titulacion::mostrararbolE() {
	ListaEspera->mostrararbol();
}

bool Titulacion::pertenecearbolA(Estudiante *e){
	return ListaAdmitidos->pertenecearbol(e);
}

bool Titulacion::pertenecearbolE(Estudiante *e){
	return ListaEspera->pertenecearbol(e);
}

bool Titulacion::buscarDNIA(string DNI, Estudiante *&e){
	return ListaAdmitidos->buscarDNI(DNI, e);
}

bool Titulacion::buscarDNIE(string DNI, Estudiante *&e){
	return ListaEspera->buscarDNI(DNI, e);
}


bool Titulacion::existearbolE(){
	return ListaEspera->existearbol();
}
void Titulacion::mostrarSimilaresarbol(string apel){
	cout<<"EN LA LISTA DE ADMITIDOS DE : "<<getcarrera()<<endl;
	ListaAdmitidos->similaresarbol(apel);
	cout<<"EN LA LISTA DE ESPERA DE : "<<getcarrera()<<endl;
	ListaEspera->similaresarbol(apel);
}

void Titulacion::buscarestudiante(string nombre) {
	ListaAdmitidos->buscarestudiante(nombre);
	ListaEspera->buscarestudiante(nombre);
}


Titulacion::~Titulacion() {
	delete ListaAdmitidos;
	delete ListaEspera;
}
