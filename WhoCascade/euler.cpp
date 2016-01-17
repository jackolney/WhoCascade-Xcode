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

void Euler(params * p, double start, double stop, double step)
{
	// Initial values
	initial init;
	
	double y1 = init.y1;
	double y2 = init.y2;
	double mort = init.mort;
	
	double N = 0;
	
	// Parameters
	//	Params p;
	
	for (double t = start; t < stop; t += step) {
		
		cout << fixed << setprecision(3) << t << " y1 = " << y1 << " y2 = " << y2 << " mort = " << mort << " N = " << N << endl;
		
		// Think of this just like the excel implementation of the model, each row is a different cell f(x)
		
		y1 += step * ( - (p->alpha + p->mu) * y1);
		
		y2 += step * ( + (p->alpha * y1) - (p->mu * y2) );
		
		mort += step * ( + p->mu * (y1 + y2) );
		
		N = y1 + y2 + mort;

		
	}
	cout << "Finished." << endl;
}