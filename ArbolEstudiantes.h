/*
 * ArbolEstudiantes.h
 *
 *  Created on: 14/06/2016
 *      Author: alejandro
 */

#ifndef ARBOLESTUDIANTES_H_
#define ARBOLESTUDIANTES_H_
#include "arbol.h"
#include "Estudiante.h"
#include "comparaestudiante.h"
using namespace std;

class ArbolEstudiantes {

private:

	Arbol<Estudiante *, ComparaPtrEstudiante> *abb;

	//Busca un estudiante dentro del arbol
	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve true si encuentra el estudiante que se busca
	//PARÁMETROS: abb será el árbol donde buscaremos al estudiante, Estudiante será el parámetro de e/s que almacenará
	// el estudiante y el resto son los datos del estudiante en sí
	//COMPLEJIDAD:O(log(n))
	bool buscar(Arbol<Estudiante *, ComparaPtrEstudiante> *abb,string ape1,string ape2,string nombre, string dni,Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve el estudiante con mayor nota del arbol
	//PARÁMETROS: abb es el árbol dónde buscaremos el dato, e es el estudiante de e/s donde almacenaremos el dato y nota
	// almacenará la nota de este estudiante
	//COMPLEJIDAD:O(n)
	void mayornota(Arbol<Estudiante *, ComparaPtrEstudiante> *abb,Estudiante *&e, float &nota);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve el estudiante de menor nota contenido en el arbol
	//PARÁMETROS: abb será el árbol donde buscaremos el dato, e y nota serán los parámetros que almacenarán la información
	//del estudiante
	//COMPLEJIDAD:O(n)
	void menornota(Arbol<Estudiante *, ComparaPtrEstudiante> *abb,Estudiante *&e, float &nota);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Muestra los estudiantes contenidos en el arbol
	//PARÁMETROS: abb será el árbol que vamos a mostrar
	//COMPLEJIDAD:O(n)
	void mostrar(Arbol<Estudiante *, ComparaPtrEstudiante> *abb);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Filtro para la ordenación del árbol
	//PARÁMETROS: abb será el árbol dónde almacenaremos los estudiantes y ape1 el dato por el cual se ordenarán
	//COMPLEJIDAD:O(n)
	void filtroInOrden(Arbol<Estudiante*,ComparaPtrEstudiante>*abb,const string &ape1);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Muestra los estudiantes similares a una raíz dada
	//PARÁMETROS: abb será el árbol donde buscaremos y apel la raíz a partir de la cual buscaremos y mostraremos los
	// similares
	//COMPLEJIDAD:O(n)
	Arbol<Estudiante *, ComparaPtrEstudiante> * similares(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, const string &apel);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve si el árbol está vacío
	//PARÁMETROS: abb será el árbol que vamos a consultar
	//COMPLEJIDAD:O(1)
	bool existeabbP(Arbol<Estudiante*,ComparaPtrEstudiante>*abb);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Muestra los estudiantes contenidos en el arbol
	//PARÁMETROS: abb será el árbol en el que vamos a buscar y nombre la raíz por la que buscaremos
	//COMPLEJIDAD:O(log(n))
	void buscarporraizP(Arbol<Estudiante *, ComparaPtrEstudiante> *abb,string &nombre);

public:
	ArbolEstudiantes();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Inserta un estudiante dentro del árbol
	//PARÁMETROS: e será el estudiante que insertaremos en el árbol
	//COMPLEJIDAD:O(1)
	void insertarP	(Estudiante *e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Busca a traves del DNI un estudiante en el arbol, devuelve true si lo encuentra
	//PARÁMETROS: ape1,ape2,nombre,dni serán los datos del estudiante que buscamos y el parámetro e de e/s será
	// dónde guardaremos el dato si es encontrado para poder tratarlo después
	//COMPLEJIDAD:O(log(n))
	bool buscarP	(string ape1,string ape2,string nombre,string dni,Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Muestra el contenido del árbol
	//PARÁMETROS: Ninguno, ya que solamente mostrará uno a uno los componentes del árbol
	//COMPLEJIDAD:O(n)
	void mostrarP	();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Busca y borra un estudiante pasado por parámetro
	//PARÁMETROS: e será el estudiante que deseamos borrar
	//COMPLEJIDAD:O(1)
	void borrarP	(Estudiante *e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve el estudiante con mayor nota
	//PARÁMETROS: Ninguno, ya que la clase devolverá una instancia Estudiante que contendrá los datos del alumno con
	//mayor nota del árbol
	//COMPLEJIDAD:O(n)
	Estudiante* mayornotaP	();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve el estudiante con menor nota
	//PARÁMETROS: NInguno, ya que devuelve una instancia Estudiante que contiene los datos del alumno con menor nota
	// del árbol
	//COMPLEJIDAD:O(n)
	Estudiante* menornotaP	();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Nos dice si un estudiante pertenece al árbol
	//PARÁMETROS: e será el estudiante que buscaremos en el árbol y devolveremos un booleano de si pertenece o no
	//COMPLEJIDAD:O(1)
	bool perteneceEstudiante (Estudiante *e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: muestra los similares
	//PARÁMETROS: ape1 será la raíz a partir de la que mostraremos alumnos similares
	//COMPLEJIDAD:O(n)
	void mostrarSimilares(const string &ape1);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve si existe el árbol que estamos consultando
	//PARÁMETROS: NInguno, sólo devolvemos un booleano true si existe y false si está vacío
	//COMPLEJIDAD:O(1)
	bool existeabb();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve los estudiantes que se parezcan a la raíz
	//PARÁMETROS: nombre será la raíz a partir de la cual se buscarán los nombres
	//COMPLEJIDAD:O(log(n))
	void buscarporraiz(string nombre);

	~ArbolEstudiantes();

};

#endif /* ARBOLESTUDIANTES_H_ */
