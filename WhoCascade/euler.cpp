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
	for (double t = start; t < stop; t += step) {
		
//		cout << fixed << setprecision(3) << t << " y1 = " << i->y1 << " y2 = " << i->y2 << " mort = " << i->mort << " N = " << i->N << endl;
		
		// Think of this just like the excel implementation of the model, each row is a different cell f(x)
		
		i->Dx_500 += step * (+ p->rho * i->UnDx_500 - (p->nu_1 + p->epsilon + (p->art_all * p->s_1 * p->p * p->theta) + (p->art_all * p->s_1 * (1-p->p) * p->theta) + p->alpha_1 + p->mu) * i->Dx_500);
		
//		i->y1 += step * ( - (p->alpha_1 + p->mu) * i->y1);
//		
//		i->y2 += step * ( + (p->alpha_1 * i->y1) - (p->mu * i->y2) );
//		
//		i->mort += step * ( + p->mu * (i->y1 + i->y2) );
//		
//		i->N = i->y1 + i->y2 + i->mort;
		
	}
	cout << "Finished." << endl;
}