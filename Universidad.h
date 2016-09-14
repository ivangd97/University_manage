/*
 * Universidad.h
 *
 *  Created on: 12/04/2016
 *      Author: alejandro
 */

#ifndef UNIVERSIDAD_H_
#define UNIVERSIDAD_H_

#include "Estudiante.h"
#include "Titulacion.h"
#include "Titulaciones.h"
#include "Preinscripciones.h"
#include "pila.h"
#include "listapi.h"
#include "conjuntoEstudiantes.h"
using namespace std;

class Universidad {
private:
	Preinscripciones *totalEstudiantes;
	Titulaciones *totalTitulaciones;

public:

	Universidad();

	//PRE:Debe de existir el fichero de carga
	//POST:Mete los estudiantes del fichero en el totalEstudiantes
	//PARÁMETROS: Ninguno, realiza la carga del archivo estudiantes
	//COMPLEJIDAD:O(n²)
	void cargarPilaEstudiantes 		();

	//PRE:Debe de existir el fichero de carga
	//POST:Mete las titulaciones del fichero en el totalTitulaciones
	//PARÁMETROS: Ninguno, carga los datos del archivo de titulaciones
	//COMPLEJIDAD:O(n²)
	void cargarTitulaciones    		();

	//PRE: Debe existir el fichero de carga
	//POST: Realiza el proceso de matriculas y renuncias
	//PARÁMETROS: Ninguno, matricula los estudiantes
	//COMPLEJIDAD: O(n²)
	void cargaMatriculadosB();

	//PRE:La carga de los ficheros debe de ser correcta
	//POST:Coge los estudiantes de la pila
	//PARÁMETROS:Ninguno, asigna los estudiantes a las titulaciones
	//COMPLEJIDAD:O(n)
	void asignarTitulaciones  	    ();

	//PRE:La clase Estudiante debe de estar bien creada
	//POST:Muestra los estudiantes por consola
	//PARÁMETROS: Ninguno, muestra los estudiantes
	//COMPLEJIDAD:O(n²)
	void mostrarEstudiante     		();

	//PRE:La carga de los ficheros debe de ser correcta
	//POST:Muestra a los estudiantes de la carga
	//PARÁMETROS: Ninguno, muestra la carga de los estudiantes
	//COMPLEJIDAD:O(n)
    void mostrarCargaEstudiantes 	();

    //PRE:La carga de los ficheros debe de ser correcta
    //POST:Mete a los estudiantes en las diferentes titulaciones
	//PARÁMETROS: e será el estudiante que deseamos procesar
    //COMPLEJIDAD:O(n)
    void procesarEstudiante 		(Estudiante *&e);

	//PRE: Titulacion debe estar bien definida e implementada
	//POST: Muestra todas las titulaciones de la universidad
	//PARÁMETROS: Ninguno, muestra las titulaciones
	//COMPLEJIDAD:O(n)
    void mostrarTitulaciones        ();

	//PRE: Titulacion debe estar bien definida e implementada
	//POST: Muestra la nota de corte de las titulaciones de la universidad
	//PARÁMETROS: Ninguno, muestra las notas de corte
	//COMPLEJIDAD: O(n)
    void mostrarNotaCorteTit        ();

	//PRE: Pruebas debe estar bien definida e implementada
	//POST: Nos lleva al menú de pruebas del programa
	//PARÁMETROS: Ninguno, redirecciona al menú de pruebas
	//COMPLEJIDAD:O(1)
    void pruebas                    ();

    //PRE: Arbol debe estar bien definido e implementado
    //POST: Vuelca las listas a árboles
	//PARÁMETROS: Ninguno, vuelca las listas en árboles
    //COMPLEJIDAD:O(n)
    void Matricula ();

    //PRE: Árbol debe estar bien definido e implementado
    //POST: Muestra una titulación del árbol
	//PARÁMETROS: i será la posición de la titulación que deseamos ver
    //COMPLEJIDAD: O(n)
    void mostrarTitulacionArbol(int i);

    //PRE: Árbol debe estar bien definido e implementado
    //POST: Busca un estudiante por dni
	//PARÁMETROS: newDNI será el parámetro por el cuál buscaremos al individuo
    //COMPLEJIDAD: O(n)
    void buscarPorDNI(string newDNI);

    //PRE: ListaTitulaciones debe estar bien definido e implementado
    //POST: Muestra una titulación
	//PARÁMETROS: i será la posición de la titulación que deseamos ver
    //COMPLEJIDAD: O(n)
    void mostrarunaTitulacion(int i);

    //PRE: Árbol debe estar bien definido e implementado
    //POST: Muestra los estudiantes que coincidan con una raiz de apellido
	//PARÁMETROS: i será la posición de la titulación que deseamos ver y apel la raíz con la que compararemos
    //COMPLEJIDAD: O(n)
    void mostrararbolraiz (string apel,int i);

	~Universidad();
};



#endif /* UNIVERSIDAD_H_ */
