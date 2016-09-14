/*
 * Pruebas.cpp
 *
 *  Created on: 16/6/2016
 *      Author: ivangd97
 */

#include "Pruebas.h"

using namespace std;

Pruebas::Pruebas() {
	// TODO Auto-generated constructor stub

}

void Pruebas::elegirPrueba(){
	int numeroPrueba;
	cout << "Escoge la prueba que deseas hacer" << endl;
	cout << "1 -> pruebas estudiante" << endl;
	cout << "2 -> pruebas titulacion" << endl;
	cout << "3 -> pruebas titulaciones" << endl;
	cout << "4 -> pruebas universidad" << endl;
	cout << "0 -> exit" << endl;
	cin >> numeroPrueba;
	if (numeroPrueba != 0){
		switch(numeroPrueba){
		case 1:
			pruebasEstudiante();
			elegirPrueba();
			break;
		case 2:
			pruebasTitulacion();
			elegirPrueba();
			break;
		case 3:
			pruebasTitulaciones();
			elegirPrueba();
			break;
		case 4:
			pruebasUniversidad();
			elegirPrueba();
			break;
		}
	}
	else
		cout << "Saliendo del módulo de pruebas" << endl;

}

void Pruebas::pruebasEstudiante(){
	cout << "PRINCIPIO DE LAS PRUEBAS DE ESTUDIANTE" << endl;
	// Primero creamos un estudiante a través del constructor parametrizado
	Estudiante *e = new Estudiante("Jorge","Gudiño","Alejandro","1234567A", 9);
	//Procedemos a las pruebas de estudiante, las cuales consistirán en añadirle una cola
	// de solicitudes y volver a mostrarlo
	e->mostrar();
	cout << "Añadiendo solicitudes..." << endl;
	e->setSolicitud("01");
	e->setSolicitud("02");
	e->mostrar();
	cout << e->getSolicitud1() << endl;
	cout << e->getSolicitud1() << endl;
	cout << "FIN DE LAS PRUEBAS DE ESTUDIANTE" << endl;
}

void Pruebas::pruebasTitulacion(){
	cout << "PRINCIPIO DE LAS PRUEBAS DE TITULACION" << endl;
	// Creamos una titulacion y un par de estudiante para poder realizar todas las pruebas correspondientes
	Titulacion *t = new Titulacion("01",1,"Ingeniería informática");
	Estudiante *e1 = new Estudiante("Jorge","Gudiño","Alejandro","1234567A", 9);
	Estudiante *e2 = new Estudiante("Gonzalez","Dominguez","Ivan","1234567B", 6);

	cout << "Añadiendo estudiantes a la titulación..." << endl;
	t->insertarenarbolA(e1);
	t->insertarenarbolE(e2);
	cout << "Mostrando la titulación..." << endl;
	t->mostrarArbol();


	cout << "FIN DE LAS PRUEBAS DE TITULACION" << endl;
}

void Pruebas::pruebasTitulaciones(){
	cout << "PRINCIPIO DE LAS PRUEBAS DE TITULACIONES" << endl;
	Titulaciones *t = new Titulaciones();
	//Creamos dos o tres titulaciones para la prueba
	Titulacion *t1 = new Titulacion("01",20,"Ingeniería informática en Ingenieria del Software");
	Titulacion *t2 = new Titulacion("02",15,"Ingeniería informática de Computadores");
	Titulacion *t3 = new Titulacion("03",30,"Ingeniería en Telecomunicaciones");

	cout << "Insertando titulaciones..." << endl;
	t->insertarTitulacion(t1);
	t->insertarTitulacion(t2);
	t->insertarTitulacion(t3);

	cout << "Mostrando titulaciones..." << endl;
	t->mostrarTitulacion();



	cout << "FIN DE LAS PRUEBAS DE TITULACIONES" << endl;

}

void Pruebas::pruebasUniversidad(){
	cout << "PRINCIPIO DE LAS PRUEBAS DE UNIVERSIDAD" << endl;
	Universidad *uni = new Universidad;

	cout << "Cargando estudiantes y titulaciones..." << endl;
	uni->cargarPilaEstudiantes();
	uni->cargarTitulaciones();
	cout << "Asignando estudiantes a las titulaciones..." << endl;
	uni->asignarTitulaciones();
	cout << "Mostrando titulaciones..." << endl;
	uni->mostrarTitulaciones();

	cout << "FIN DE LAS PRUEBAS DE UNIVERSIDAD" << endl;
}

Pruebas::~Pruebas() {
	// TODO Auto-generated destructor stub
}

