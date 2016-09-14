/*
 * Pruebas.h
 *
 *  Created on: 16/6/2016
 *      Author: ivangd97
 */

#ifndef PRUEBAS_H_
#define PRUEBAS_H_
using namespace std;
#include "Estudiante.h"
#include "Titulacion.h"
#include "Titulaciones.h"
#include "Universidad.h"

class Pruebas {

	//En las pruebas del Estudiante crearemos un estudiante por parámetros y lo mostraremos
	// en pantalla, modificaremos sus solicitudes y volveremos a mostrar los cambios
	//PRE: Estudiante debe estar bien definido e implementado
	//POST: Muestra una prueba de carga y modificación de una instancia estudiante
	//PARÁMETROS: Ninguno, nos redirecciona a las pruebas del estudiante
	//COMPLEJIDAD: O(1)
	void pruebasEstudiante();

	//En las pruebas de titulacion se creará una titulacion, se insertarán un par de alumnos
	// y se mostrarán por pantalla para demostrar que los módulos funcionan
	//PRE: Titulación debe estar bien definido e implementado
	//POST: Crea una titulación ficticia y le añade algunos estudiantes para su prueba
	//PARÁMETROS: Ninguno, nos redirecciona a las pruebas de la titulacion
	//COMPLEJIDAD: O(n) siendo n el número de estudiantes que mostrará
	void pruebasTitulacion();

	//Las pruebas de titulaciones consistiran en crear varias titulaciones, insertarlas,mostrarlas y buscar alguna
	// ya que este módulo consiste basicamente en la gestión de una lista con punto de interés
	//PRE: Titulaciones debe estar bien definido e implementado
	//POST: Carga varias titulaciones y las muestra para comprobar que se hace correctamente
	//PARÁMETROS: Ninguno, nos redirecciona a la prueba de titulaciones
	//COMPLEJIDAD: O(n) siendo n el número de titulaciones añadidas que serán mostradas posteriormente
	void pruebasTitulaciones();

	//En las pruebas de universidad cargaremos las listas reales y trabajaremos con ellas
	// si la salida coincide con la esperada en el pdf podremos comprobar que esta bien
	//PRE: Universidad debe estar bien definido e implementado
	//POST: Se realiza la carga de estudiantes y titulaciones real para comparar con el archivo .pdf dado
	//PARÁMETROS: Ninguno, nos redirecciona a la prueba de universidad
	//COMPLEJIDAD:
	void pruebasUniversidad();

public:
	Pruebas();

	//PRE: Pruebas debe estar bien definido e implementado
	//POST: Muestra un pequeño menú donde podemos elegir la prueba que deseamos ver por pantalla
	//PARÁMETROS: Ninguno, la selección se hace dentro del método
	//COMPLEJIDAD:
	void elegirPrueba();

	~Pruebas();
};



#endif /* PRUEBAS_H_ */
