//
//  main.cpp
//  WhoCascade
//
//  Created by Jack Olney on 15/01/2016.
//  Copyright © 2016 Jack Olney. All rights reserved.
//

#include <iomanip>
#include <iostream>

using namespace std;

typedef double theFunc(double, double); // This a type called 'F' - which is a function taking two doubles

/* Approximates y(t) in y'(t)=f(t,y) with y(start)=y0 and t=start..stop and the step size 'step'. */

void Euler(theFunc f1, theFunc f2, double start, double stop, double step)
{
	// Initial values
	double y1 = 100;
	double y2 = 0;
	
	for (double t = start; t < stop; t += step) {
		
		cout << fixed << setprecision(3) << t << " y1 = " << y1 << " y2 = " << y2 << endl;
		
		// Think of this just like the excel implementation of the model, each row is a different cell f(x)

		y1 += step * -0.01 * y1;
		
		y2 += step * +0.01 * y1;
		
		
//		y1 += step * f1(t, y1);
		
//		y2 += step * f2(t, y2);
	}
	cout << "Finished." << endl;
}

// Two State Model Test
double StateOne(double t, double y)
{
	return -0.01 * y;
}

double StateTwo(double t, double y)
{
	return +0.01 * y;
}

int main() {
	Euler(StateOne, StateTwo, 0, 20,  0.02);
	return 0;
}

// Need to implement a two-state model

// A = 100
// B = 0

// Need an efficient structure that allows me to create a starting size, for all...
// Classes
// Class of 'ODE_FUNCTION' then create instance of them for use in the model with specific functions attached.
// How will these interface with Euler() then?


// IDEAL SITUATION
// Euler(start, stop, step)
// Then inside Euler, is the functions that are called to run the model? (a different function for each ODE?)
// Maintain 'pure' functional programming ethos?

// For this initial test, then just create two separate functions.


// Steps:
// 1) Can we put everything into functions? (keeps it neat)
// 2) Sanity check to R output / Berkeley Madonna output
// 3) EXPAND
