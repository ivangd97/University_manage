/*
 * conjuntoEstdiantes.h
 *
 *  Created on: 13/04/2016
 *      Author: alejandro
 */

#ifndef CONJUNTOESTUDIANTES_H_
#define CONJUNTOESTUDIANTES_H_
#include "listapi.h"
#include "Estudiante.h"
#include "ArbolEstudiantes.h"

using namespace std ;

class conjuntoEstudiantes {
private:

	ListaPI <Estudiante*> *montonEstudiantes;
	ArbolEstudiantes *ace;

public:

	conjuntoEstudiantes();

	//PRE:La lista de estudiantes debe de estar bien creada
	//POST:Devuelve cuantos estudiantes hay en la lista
	//PARÁMETROS: Ninguno ya que retorna el int con el número de alumnos que hay dentro de la estructura
	//COMPLEJIDAD:O(N)
	int  cuantos		   ();

	//PRE:La lista de estudiantes debe de estar bien creada
	//POST:Inserta a los estudiantes en la lista por orden de nota
	//PARÁMETROS: Estudiante será el parámetro que queremos insertar en la Lista
	//COMPLEJIDAD:O(N)
	void insertarOrdenNota (Estudiante *e);

	//PRE:La lista de estudiantes debe de estar bien creada
	//POST:Elimina el que tenga menor nota de la lista (será el ultimo)
	//PARÁMETROS: Ninguno, ya que elimina el estudiante que esté el último
	//COMPLEJIDAD:O(1)
	void eliminarMenorNota ();

	//PRE:La lista de estudiantes debe de estar bien creada
	//POST:Devuelve true si un estudiante determinado se encuentra en la lista y false en caso contrario
	//PARÁMETROS: nuevodni será el parámetro por el que comprobaremos y buscaremos al estudiante que será almacenado
	// en una variable de e/s que es est
	//COMPLEJIDAD:O(N)
	bool buscarDNI		   (string nuevodni, Estudiante *&est);

	//PRE:La lista de estudiantes debe de estar bien creada
	//POST:Devuelve el estudiante con mayor nota (será el primero de la lista)
	//PARÁMETROS: e es un parámetro de e/s donde almacenaremos el estudiante de mayor nota
	//COMPLEJIDAD:O(1)
	void buscarMayorNota   (Estudiante *&e);

	//PRE:La lista de estudiantes debe de estar bien creada
	//POST:Devuelve el estudiante con menor nota (será el último de la lista)
	//PARÁMETROS: e será el parámetrodonde almacenaremos el estudiante de menor nota
	//COMPLEJIDAD:O(1)
	void buscarMenorNota   (Estudiante *&e);

	//PRE:La lista de estudiantes debe de estar bien creada
	//POST:Muestra todos los estudiantes de la lista
	//PARÁMETROS: Ninguno ya que sólo muestra la información de la estructura de datos
	//COMPLEJIDAD:O(N)
	void mostrar 		   ();

	//PRE: Arbol y lista deben estar bien definidos e implementados
	//POST: Vuelca la lista en el arbol binario
	//PARÁMETROS: Ninguno, vuelca la lista al árbol
	//COMPLEJIDAD: O(n)
	void volcarArbol	   ();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Busca a través del DNI un estudiante dentro del árbol
	//PARÁMETROS:ape1,ape2,nombre y dni serán los datos del estudiante y e será donde almacenemos dicho estudiante
	//COMPLEJIDAD:O(log n)
	bool buscarenarbol(string ape1,string ape2,string nombre,string dni,Estudiante *&e) ;

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Inserta un estudiante dentro del arbol
	//PARÁMETROS: e será el estudiante que queremos insertar en nuestro árbol
	//COMPLEJIDAD: O(log n)
	void insertarenarbol(Estudiante *e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Borra un estudiante dentro del arbol
	//PARÁMETROS: e es el Estudiante que queremos borrar del árbol
	//COMPLEJIDAD: O(n)
	void borrarenarbol(Estudiante *e) ;

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve el estudiante con mayor nota del árbol
	//PARÁMETROS: e es la instancia dónde almacenaremos el estudiante con mayor nota del árbol
	//COMPLEJIDAD: O(1)
	void mayornotaarbol(Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve el estudiante con menor nota del árbol
	//PARÁMETROS: Guardaremos en e el Estudiante con la menor nota del árbol
	//COMPLEJIDAD: O(1)
	void menornotaarbol(Estudiante *&e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Muestra el árbol
	//PARÁMETROS: Ninguno, ya que este método muestra los componentes del árbol
	//COMPLEJIDAD: O(n)
	void mostrararbol() ;

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve si un estudiante pertenece al árbol
	//PARÁMETROS: e será el estudiante que buscaremos en el árbol
	//COMPLEJIDAD: O(n)
	bool pertenecearbol(Estudiante *e);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Muestra los estudiantes similares a una raíz contenidos en el árbol
	//PARÁMETROS: apel será la raíz a partir de la cual buscaremos y mostraremos estudiantes similares
	//COMPLEJIDAD: O(n)
	void similaresarbol(string apel);

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Devuelve si el árbol está vacío o no
	//PARÁMETROS: Ninguno, ya que este método comprueba si el árbol está vacío o no
	//COMPLEJIDAD: O(1)
	bool existearbol();

	//PRE: Arbol debe estar bien definido e implementado
	//POST: Busca un estudiante en el árbol
	//PARÁMETROS: Nombre será el parámetro a través del cuál buscaremos los Estudiantes que queremos
	//COMPLEJIDAD: O(n)
	void buscarestudiante(string nombre);

	~conjuntoEstudiantes();
};

#endif
