/*
 * Titulacion.h
 *
 *  Created on: 12/04/2016
 *      Author: alejandro
 */

#ifndef TITULACION_H_
#define TITULACION_H_

#include <cstring>
#include "listapi.h"
#include "pila.h"
#include "Estudiante.h"
#include "conjuntoEstudiantes.h"
#include "arbol.h"
#include "comparaestudiante.h"
#include "ArbolEstudiantes.h"
using namespace std;

class Titulacion {
private:

	string codigoTitulacion;
	int plazas;
	string carrera;
	conjuntoEstudiantes *ListaEspera;
	conjuntoEstudiantes *ListaAdmitidos;
	int NotaCorte;//la vamos a necesitar para el punto 8 del menú

public:

	Titulacion();
	Titulacion(string codigoTitulacion,int plazas,string carrera);

	//PRE:La clase Titulacion debe de estar bien creada
	//POST:Devuelve el número de plazas
	//PARÁMETROS: Ninguno, devuelve el número de plazas de la titulación
	//COMPLEJIDAD:O(1)
    int	   getplazas			();

    //PRE:La clase Titulacion debe de estar bien creada
    //POST:Devuelve el nombre de la carrera
    //PARÁMETROS: Ninguno, retorna el nombre de la carrera
    //COMPLEJIDAD:O(1)
    string getcarrera			();

    //PRE:La clase Titulacion debe de estar bien creada
    //POST:Devuelve el código de la titulación
    //PARÁMETROS: Ninguno, retorna el codigo de la carrera
    //COMPLEJIDAD:O(1)
    string    getcodigoTitulacion	();

	//PRE:La lista de admitidos y la de espera debe de estar creada
	//POST:Muestra todas las características de la titulación
    //PARÁMETROS: Ninguno, muestra la titulación
	//COMPLEJIDAD:O(1)
	void   mostrarTitulacion 	();

	//PRE:La lista de admitidos y la de espera debe de estar creada
	//POST:ELimina el de menor nota de la lista de admitidos
	//PARÁMETROS: Ninguno, elimina el estudiante de menor nota en la lista de admitidos
	//COMPLEJIDAD:O(1)
	void eliminarMenorNotaLA 	();

	//PRE:La lista de admitidos y la de espera debe de estar creada
	//POST:Devuelve el estudiante  de mayor nota de la lista de espera
	//PARÁMETROS: Almacenaremos en e los datos del estudiante con mayor nota de la lista de espera
	//COMPLEJIDAD:O(1)
	void buscarMayorNotaLE   	(Estudiante *&e);

	//PRE:La lista de admitidos y la de espera debe de estar creada
	//POST:Devuelve el estudiante  de menor nota de la lista de admitidos
	//PARÁMETROS: Almacenaremos en e los datos del estudiante con menor nota de la lista de admitidos
	//COMPLEJIDAD:O(1)
	void buscarMenorNotaLA   	(Estudiante *&e);

	//PRE:La lista de admitidos y la de espera debe de estar creada
	//POST:Muestra toda la titulacion
	//PARÁMETROS: Ninguno, muestra los estudiantes almacenados en el árbol
	//COMPLEJIDAD:O(1)
	void mostrarArbol		  	    ();

	//PRE: La lista de admitidos debe estar bien definida e implementada
	//POST: Inserta en orden un estudiante en la lista de admitidos
	//PARÁMETROS: e será el estudiante que queremos insertar en la lista de admitidos
	//COMPLEJIDAD: O(n)
	void insertarLA(Estudiante *e);

	//PRE: La lista de espera debe estar bien definida e implementada
	//POST: Inserta en orden un estudiante en la lista de espera
	//PARÁMETROS: e será el estudiante que queremos insertar en la lista de espera
	//COMPLEJIDAD: O(n)
	void insertarLE(Estudiante *e);

	//PRE: La lista de admitidos debe estar bien definida e implementada
	//POST: Devuelve true si la lista de admitidos está llena
	//PARÁMETROS: Ninguno, retorna si la lista de admitidos está llena
	//COMPLEJIDAD: O(1)
	bool LAllena();

	//PRE: La lista de admitidos y arbol deben estar bien definidos e implementados
	//POST: Vuelca la informacion de la lista de admitidos a un arbol binario
	//PARÁMETROS: Ninguno, vuelca la lista de admitidos en el árbol
	//COMPLEJIDAD: O(n)
	void volcarabbadmitidos ();

	//PRE: La lista de espera y arbol deben estar bien definidos e implementados
	//POST: Vuelca la informacion de la lista de espera a un arbol binario
	//PARÁMETROS: Ninguno, vuelca la lista de espera en el árbol
	//COMPLEJIDAD: O(n)
	void volcarabbespera	();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve true si el estudiante con DNI pasado por parametro se encuentra en el arbol de admitidos
	//PARÁMETROS: ape1,ape2,nombre y dni serán los parámetros a parti de los cuales buscaremos al estudiante
	// dentro del árbol y e será el parámetro e/s donde lo almacenaremos
	//COMPLEJIDAD:O(n)
	bool buscarenarbolA   (string ape1,string ape2,string nombre,string dni,Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve true si el estudiante con DNI pasado por parametro se encuentra en el arbol de espera
	//PARÁMETROS:ape1,ape2,nombre y dni serán los datos a partir de los cuales buscaremos al estudiante en el
	// árbol y e el dato de e/s donde lo guardaremos
	//COMPLEJIDAD:O(n)
	bool buscarenarbolE   (string ape1,string ape2,string nombre,string dni,Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Inserta un estudiante en el arbol de admitidos
	//PARÁMETROS: e será el estudiante que queremos insertar en el árbol de admitidos
	//COMPLEJIDAD:O(1)
	void insertarenarbolA (Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Inserta un estudiante en el arbol de espera
	//PARÁMETROS: e será el estudiante que queremos insertar en el árbol de espera
	//COMPLEJIDAD:O(1)
	void insertarenarbolE (Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Borra un estudiante pasado por parametro del arbol de admitidos
	//PARÁMETROS: e será el estudiante que queremos borrar del árbol de admitidos
	//COMPLEJIDAD:O(1)
	void borrarenarbolA  (Estudiante *e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Borra un estudiante pasado por parametro del arbol de espera
	//PARÁMETROS: e será el estudiante que queremos borrar de la lista de espera
	//COMPLEJIDAD:O(1)
	void borrarenarbolE  (Estudiante *e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve la mayor nota que hay en el arbol de espera
	//PARÁMETROS: e será el parámetro de e/s donde almacenaremos el estudiante de mayor nota de la lista de espera
	//COMPLEJIDAD:O(n)
	void mayornotaarbolE  (Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve la menor nota que exite en el arbol de admitidos
	//PARÁMETROS: e será el parámetro de e/s donde almacenaremos el estudiante de menor nota de la lista de admitidos
	//COMPLEJIDAD:O(n)
	void menornotaarbolA  (Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Muestra el arbol de admitidos
	//PARÁMETROS: Ninguno, ya que muestra los estudiantes del árbol de admitidos
	//COMPLEJIDAD: O(n)
	void mostrararbolA    ();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Muestra el arbol de espera
	//PARÁMETROS: Ninguno, muestra los estudiantes del árbol de espera
	//COMPLEJIDAD:O(n)
	void mostrararbolE   ();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Nos dice si un estudiante pertenece al árbol de admitidos
	//PARÁMETROS: e será el estudiante que buscaremos en el árbol de admitidos
	//COMPLEJIDAD:O(1)
	bool pertenecearbolA(Estudiante *e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Nos dice si un estudiante pertenece al árbol de espera
	//PARÁMETROS: e será el estudiante que buscaremos en el árbol de espera
	//COMPLEJIDAD:O(1)
	bool pertenecearbolE(Estudiante *e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Muestra los similares a una raíz en el árbol
	//PARÁMETROS: apel será el parámetro a partir del cual comprobaremos y mostraremossi fuera necesario
	//COMPLEJIDAD: O(n)
	void mostrarSimilaresarbol(string apel);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Busca por DNI un estudiante en el árbol de admitidos
	//PARÁMETROS: DNI será el parámetro por el cuál buscaremos y e donde almacenaremos el estudiante si lo encontramos
	//COMPLEJIDAD: O(n)
	bool buscarDNIA(string DNI, Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Busca por DNI un estudiante en el árbol de espera
	//PARÁMETROS: DNI será el parámetro por el cuál buscaremos y e donde almacenaremos el estudiante si lo encontramos
	//COMPLEJIDAD: O(n)
	bool buscarDNIE(string DNI, Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Vuelca las listas a árboles
	//PARÁMETROS: Ninguno, el método transforma las listas en árboles
	//COMPLEJIDAD: O(n)
	void volcaraarboles();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Comprobará si el árbol de espera está vacío o no
	//PARÁMETROS: Ninguno, retorna si el árbol de espera existe o no
	//COMPLEJIDAD: O(1)
	bool existearbolE();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Busca por nombre un estudiante en el árbol de admitidos
	//PARÁMETROS: nombre será el parámetro por el cuál buscaremoss
	//COMPLEJIDAD: O(n)
	void buscarestudiante(string nombre);

	~Titulacion();
};


#endif /* TITULACION_H_ */
