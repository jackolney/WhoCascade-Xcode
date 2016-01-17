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

void Euler(double start, double stop, double step)
{
	// Initial values
	initial init;
	
	double y1 = init.y1;
	double y2 = init.y2;
	
	// Parameters
	Params p;
	
	for (double t = start; t < stop; t += step) {
		
		cout << fixed << setprecision(3) << t << " y1 = " << y1 << " y2 = " << y2 << endl;
		
		// Think of this just like the excel implementation of the model, each row is a different cell f(x)
		
		y1 += step * -p.mu * y1;
		
		y2 += step * +p.mu * y1;
		
	}
	cout << "Finished." << endl;
}