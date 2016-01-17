//
//  euler.cpp
//  WhoCascade
//
//  Created by Jack Olney on 17/01/2016.
//  Copyright © 2016 Jack Olney. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "euler.h"
#include "parameters.h"
#include "initial.h"

using namespace std;

/* Approximates y(t) in y'(t)=f(t,y) with y(start)=y0 and t=start..stop and the step size 'step'. */

void Euler(initial * i, params * p, double start, double stop, double step)
{
	// Initial values
	//	initial init;
	//	
	//	double y1 = init.y1;
	//	double y2 = init.y2;
	//	double mort = init.mort;
	//	
	//	double N = 0;
	
	// Parameters
	//	Params p;
	
	for (double t = start; t < stop; t += step) {
		
		cout << fixed << setprecision(3) << t << " y1 = " << i->y1 << " y2 = " << i->y2 << " mort = " << i->mort << " N = " << i->N << endl;
		
		// Think of this just like the excel implementation of the model, each row is a different cell f(x)
		
		i->y1 += step * ( - (p->alpha + p->mu) * i->y1);
		
		i->y2 += step * ( + (p->alpha * i->y1) - (p->mu * i->y2) );
		
		i->mort += step * ( + p->mu * (i->y1 + i->y2) );
		
		i->N = i->y1 + i->y2 + i->mort;
		
	}
	cout << "Finished." << endl;
}