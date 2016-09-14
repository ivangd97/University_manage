/*
 * comparausuario.h
 *
 *  Created on: 20 de abr. de 2016
 *      Author: jarico
 */

#ifndef COMPARAESTUDIANTE_H_
#define COMPARAESTUDIANTE_H_

#include "Estudiante.h"
#include <string>
using namespace std;

class ComparaPtrEstudiante {
public:

	int operator()(const Estudiante *e1, const Estudiante *e2) const {
		int flag = 1;
		if (e1->getdni() == e2->getdni())
			flag = 0;
		else {
			if (e1->getape1() < e2->getape1())
				flag = -1;
			else {
				if (e1->getape1() == e2->getape1()) {
					if (e1->getape2() < e2->getape2())
						flag = -1;
					else
						if (e1->getape2() == e2->getape2())
							if (e1->getNombre() < e2->getNombre())
								flag = -1;
				}
			}
		}
		return flag;
	}

};
#endif /* COMPARAESTUDIANTE_H_ */
