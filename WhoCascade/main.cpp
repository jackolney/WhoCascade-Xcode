//
//  main.cpp
//  WhoCascade
//
//  Created by Jack Olney on 15/01/2016.
//  Copyright © 2016 Jack Olney. All rights reserved.
//

#include <iomanip>
#include <iostream>
#include "euler.h"
#include "parameters.h"
#include "initial.h"

using namespace std;


int main() {
	
	params * p = new params;
	
	initial * i = new initial();
	
	Euler(i, p, 0, 10,  0.02);
	
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
// 3) Needs to take some inputs...
// 4) Respond by returning a whole heap of vectors to R.
// 5) EXPAND
// 4) R .Call()