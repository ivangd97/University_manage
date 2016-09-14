///============================================================================
// Name        : Estudiante.cpp
// Author      : Profesores de la asignatura
// Version     : Curso 15/16
// Copyright   : UEx
// Description : definición de la clase estudiante
//============================================================================


#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

#include <cstring>
#include <iostream>
#include "cola.h"
#include "solicitud.h"

using namespace std;


class Estudiante {
private:
	string ape1;
	string ape2;
	string nombre;
	string dni;
	float nota;
	solicitud *colaSol;

public:

	Estudiante();

	Estudiante(string ape1, string ape2, string nombre, string dni, float nota);

	Estudiante(string ape1, string ape2, string nombre, string dni);

	//PRE:Debe de estar bien creada la clase Estudiante
	//POST:Debe de mostrar todos los atributos del estudiante excepto la cola de solicitudes
	//PARÁMETROS: Ninguno, ya que el método muestra el estudiante y sus datos
	//COMPLEJIDAD:O(1)
	void   mostrar();

	//PRE:Debe de estar bien creada la clase Estudiante
	//POST:Devuelve el primer apellido del estudiante
	//PARÁMETROS:Ninguno, retorna el primer apellido del alumno
	//COMPLEJIDAD:O(1)
    string getape1 ()const;

    //PRE:Debe de estar bien creada la clase Estudiante
    //POST:Devuelve el segundo apellido del estudiante
    //PARÁMETROS: Ninguno, retorna el segundo apellido del alumno
    //COMPLEJIDAD:O(1)
    string getape2 ()const;

    //PRE:Debe de estar bien creada la clase Estudiante
    //POST:Devuelve el DNI del estudiante
    //PARÁMETROS: Ninguno, retorna el dni del estudiante
    //COMPLEJIDAD:O(1)
    string getdni ()const;

    //PRE:Debe de estar creada la cola de solicitudes
    //POST:Encola una solicitud en la cola
    //PARÁMETROS: sol será la nueva solicitud que encolaremos en la cola de solicitudes del estudiante
    //COMPLEJIDAD:O(1)
	void   setSolicitud(string sol);

	//PRE:Debe de estar creada la cola de solicitudes
	//POST:Devuelve la primera solicitud de la cola y esta es desencolada
	//PARÁMETROS: ninguno, retorna la cima de la cola de solicitudes
	//COMPLEJIDAD:O(1)
	string  getSolicitud1();

	//PRE:Debe de estar bien creada la clase Estudiante
	//POST:Devuelve la nota del estudiante
	//PARÁMETROS: Ninguno, retorna la nota del alumno
	//COMPLEJIDAD:O(1)
	float  getNota()const;

	//PRE:Debe de estar bien creada la clase Estudiante
	//POST:Devuelve el nombre del estudiante
	//PARÁMETROS: Ninguno, retorna el nombre del estudiante
	//COMPLEJIDAD:O(1)
	string getNombre()const;

	//PRE:Debe de estar creada la cola de solicitudes
	//POST:Devuelve true si la cola de solicitudes del estudiante esta vacia o false en caso contrario
	//PARÁMETROS: Ninguno, retorna si la cola de solicitudes está vacía o no
	//COMPLEJIDAD:O(1)
	bool estaVacia();

	//PRE:Debe de estar bien creada la clase Estudiante
	//POST:Devuelve si un estudiante es anterior a otro por orden alfabético
	//PARÁMETROS: e será el estudiante con el que comparar
	//COMPLEJIDAD:O(1)
	bool operator < (const Estudiante &e);

	//PRE:Debe de estar bien creada la clase Estudiante
	//POST:Devuelve si dos estudiantes son iguales
	//PARÁMETROS: e será el estudiante con el que comparar
	//COMPLEJIDAD:O(1)
	bool operator == (const Estudiante &e);

	~Estudiante();
};


#endif /* ESTUDIANTE_H_ */
