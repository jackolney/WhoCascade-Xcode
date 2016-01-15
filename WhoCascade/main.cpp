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

/* Approximates y(t) in y'(t)=f(t,y) with y(a)=y0 and t=a..b and the step size h. */

void Euler(theFunc f, double y0, double start, double stop, double step)
{
	double y = y0;
	for (double t = start; t < stop; t += step) {
		cout << fixed << setprecision(3) << t << " " << y << endl;
		y += step * f(t, y);
	}
	cout << "Finished." << endl;
}

// Example: Newton's cooling law
double NewtonCoolingLaw(double t, double y) // The second arguement here is the THING was are monitoring.
{
	return -0.07 * y;
}

int main() {
	Euler(NewtonCoolingLaw, 1000, 0, 20,  1);
	return 0;
}