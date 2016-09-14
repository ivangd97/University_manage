/*
 * Titulaciones.h
 *
 *  Created on: 27/04/2016
 *      Author: alejandro
 */

#ifndef TITULACIONES_H_
#define TITULACIONES_H_
#include "Titulacion.h"
#include "listapi.h"

using namespace std;

class Titulaciones {
private:
	ListaPI <Titulacion*> *listaTitulaciones;

public:
	Titulaciones();

	//PRE: Titulacion debe estar bien definida e implementada
	//POST: Inserta en la lista una titulación pasada por parametro
	//PARÁMETROS: t es la titulación que deseamos insertar en la lista
	//COMPLEJIDAD: O(1)
	void insertarTitulacion(Titulacion *t);

	//PRE: Titulacion debe estar bien definida e implementada
	//POST: Muestra las titulaciones contenidas en la lista
	//PARÁMETROS: NInguno, muestra las titulaciones
	//COMPLEJIDAD: O(n)
    void mostrarTitulacion ();

	//PRE: Titulacion debe estar bien definida e implementada
	//POST: Busca una titulacion en la lista a traves de su codigo de titulacion
    //PARÁMETROS: code será el parámetro a partir del cual buscaremos la titulacion y t donde la almacenaremos si la
    // encontramos
	//COMPLEJIDAD: O(n)
    bool buscarTitulacion (string code,Titulacion *&t);

	//PRE: Titulacion y arbol deben estar bien definidos e implementados
	//POST: Vuelca la información de la lista en un arbol binario
    //PARÁMETROS: Ninguno, vuelca las titulaciones
	//COMPLEJIDAD: O(n)
    void volcartitulaciones ();

	//PRE: Titulacion debe estar bien definida e implementada
	//POST: Nos devuelve la titulacion que esté en la posición i de la lista
    //PARÁMETROS: i será la posición de la lista de titulaciones y t donde almacenaremos la titulación una vez encontrada
	//COMPLEJIDAD: O(n)
    void conseguirTitulacion(int i,Titulacion *&t);

	//PRE: Titulacion debe estar bien definida e implementada
	//POST: Muestra la nota de corte de las titulaciones
    //PARÁMETROS: Ninguno, sólo muestra las notas de corte
	//COMPLEJIDAD: O(n)
    void mostrarNotaCorte();

    //PRE: Arbol debe estar bien definido e implementado
    //POST: Muestra la titulación de la posición i
    //PARÁMETROS: i es la posición de la titulación
    //COMPLEJIDAD: O(n)
    void mostrararbolTitulaciones(int i);

    //PRE: Arbol debe estar bien definido e implementado
    //POST: Muestra la titulación de la posición i
    //PARÁMETROS: i es la posición de la titulación
    //COMPLEJIDAD: O(n)
    void  mostrarTitulacionconcreta(int i) ;

    //PRE: Arbol debe estar bien definido e implementado
    //POST: Muestra un estudiante del árbol
    //PARÁMETROS: nombre será el parámetro a partir del cuál buscaremos en el árbol, i la titulación donde lo buscaremos
    //COMPLEJIDAD:O(n)
    void mostrarestudiantearbol (string nombre,int i);

    //PRE: Arbol debe estar bien definido e implementado
    //POST: Borra el estudiante de los árboles de espera de todas las titulaciones
    //PARÁMETROS: e será el estudiante que deseamos borrar
    //COMPLEJIDAD:O(n)
    void borrardearbolesE(Estudiante *e);

    //PRE: Arbol debe estar bien definido e implementado
    //POST: Busca por DNI
    //PARÁMETROS: dni es el dato por el cual buscaremos al estudiante
    //COMPLEJIDAD: O(n)
    void buscarporDNI(string dni);

	~Titulaciones();
};

#endif /* TITULACIONES_H_ */
