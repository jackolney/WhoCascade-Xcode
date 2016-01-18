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
		
		/* UNDIAGNOSED */
		i->UnDx_500 += step * (0.5251 * (0.02466 * (((i->UnDx_500 + i->Dx_500 + i->Care_500 + i->PreLtfu_500 + i->Tx_Na_500 + i->Ltfu_500) * 1.35)
			+ ((i->UnDx_350500 + i->Dx_350500 + i->Care_350500 + i->PreLtfu_350500 + i->Tx_Na_350500 + i->Ltfu_350500) * 1)
			+ ((i->UnDx_250350 + i->Dx_250350 + i->Care_250350 + i->PreLtfu_250350 + i->Tx_Na_250350 + i->Ltfu_250350 + i->UnDx_200250 + i->Dx_200250 + i->Care_200250 + i->PreLtfu_200250 + i->Tx_Na_200250 + i->Ltfu_200250) * 1.64)
			+ ((i->UnDx_100200 + i->Dx_100200 + i->Care_100200 + i->PreLtfu_100200 + i->Tx_Na_100200 + i->Ltfu_100200 + i->UnDx_50100 + i->Dx_50100 + i->Care_50100 + i->PreLtfu_50100 + i->Tx_Na_50100 + i->Ltfu_50100 + i->UnDx_50 + i->Dx_50 + i->Care_50 + i->PreLtfu_50 + i->Tx_Na_50 + i->Ltfu_50) * 5.17)
			+ ((i->Tx_A_500 + i->Tx_A_350500 + i->Tx_A_250350 + i->Tx_A_200250 + i->Tx_A_100200 + i->Tx_A_50100 + i->Tx_A_50) * 0.1)))
		   - (p->nu_1 + p->rho + (p->art_all * p->s_1 * p->p * p->theta) + (p->art_all * p->s_1 * (1-p->p) * p->theta) + p->alpha_1 + p->mu) * i->UnDx_500);
		
		i->UnDx_350500 += step * (0.2315 * (0.02466 * (((i->UnDx_500 + i->Dx_500 + i->Care_500 + i->PreLtfu_500 + i->Tx_Na_500 + i->Ltfu_500) * 1.35)
			+ ((i->UnDx_350500 + i->Dx_350500 + i->Care_350500 + i->PreLtfu_350500 + i->Tx_Na_350500 + i->Ltfu_350500) * 1)
			+ ((i->UnDx_250350 + i->Dx_250350 + i->Care_250350 + i->PreLtfu_250350 + i->Tx_Na_250350 + i->Ltfu_250350 + i->UnDx_200250 + i->Dx_200250 + i->Care_200250 + i->PreLtfu_200250 + i->Tx_Na_200250 + i->Ltfu_200250) * 1.64)
			+ ((i->UnDx_100200 + i->Dx_100200 + i->Care_100200 + i->PreLtfu_100200 + i->Tx_Na_100200 + i->Ltfu_100200 + i->UnDx_50100 + i->Dx_50100 + i->Care_50100 + i->PreLtfu_50100 + i->Tx_Na_50100 + i->Ltfu_50100 + i->UnDx_50 + i->Dx_50 + i->Care_50 + i->PreLtfu_50 + i->Tx_Na_50 + i->Ltfu_50) * 5.17)
			+ ((i->Tx_A_500 + i->Tx_A_350500 + i->Tx_A_250350 + i->Tx_A_200250 + i->Tx_A_100200 + i->Tx_A_50100 + i->Tx_A_50) * 0.1)))
			+ p->nu_1 * i->UnDx_500 - (p->nu_2 + p->rho + (p->art_500 * p->s_2 * p->p * p->theta) + (p->art_500 * p->s_2 * (1-p->p) * p->theta) + p->alpha_2 + p->mu) * i->UnDx_350500);
		
		i->UnDx_250350 += step * (0.1787 * (0.02466 * (((i->UnDx_500 + i->Dx_500 + i->Care_500 + i->PreLtfu_500 + i->Tx_Na_500 + i->Ltfu_500) * 1.35)
			+ ((i->UnDx_350500 + i->Dx_350500 + i->Care_350500 + i->PreLtfu_350500 + i->Tx_Na_350500 + i->Ltfu_350500) * 1)
			+ ((i->UnDx_250350 + i->Dx_250350 + i->Care_250350 + i->PreLtfu_250350 + i->Tx_Na_250350 + i->Ltfu_250350 + i->UnDx_200250 + i->Dx_200250 + i->Care_200250 + i->PreLtfu_200250 + i->Tx_Na_200250 + i->Ltfu_200250) * 1.64)
			+ ((i->UnDx_100200 + i->Dx_100200 + i->Care_100200 + i->PreLtfu_100200 + i->Tx_Na_100200 + i->Ltfu_100200 + i->UnDx_50100 + i->Dx_50100 + i->Care_50100 + i->PreLtfu_50100 + i->Tx_Na_50100 + i->Ltfu_50100 + i->UnDx_50 + i->Dx_50 + i->Care_50 + i->PreLtfu_50 + i->Tx_Na_50 + i->Ltfu_50) * 5.17)
			+ ((i->Tx_A_500 + i->Tx_A_350500 + i->Tx_A_250350 + i->Tx_A_200250 + i->Tx_A_100200 + i->Tx_A_50100 + i->Tx_A_50) * 0.1)))
			+ p->nu_2 * i->UnDx_350500 - (p->nu_3 + p->rho + (p->art_350 * p->s_3 * p->p * p->theta) + (p->art_350 * p->s_3 * (1-p->p) * p->theta) + p->alpha_3 + p->mu) * i->UnDx_250350);
		
		i->UnDx_200250 += step * (0.0615 * (0.02466 * (((i->UnDx_500 + i->Dx_500 + i->Care_500 + i->PreLtfu_500 + i->Tx_Na_500 + i->Ltfu_500) * 1.35)
			+ ((i->UnDx_350500 + i->Dx_350500 + i->Care_350500 + i->PreLtfu_350500 + i->Tx_Na_350500 + i->Ltfu_350500) * 1)
			+ ((i->UnDx_250350 + i->Dx_250350 + i->Care_250350 + i->PreLtfu_250350 + i->Tx_Na_250350 + i->Ltfu_250350 + i->UnDx_200250 + i->Dx_200250 + i->Care_200250 + i->PreLtfu_200250 + i->Tx_Na_200250 + i->Ltfu_200250) * 1.64)
			+ ((i->UnDx_100200 + i->Dx_100200 + i->Care_100200 + i->PreLtfu_100200 + i->Tx_Na_100200 + i->Ltfu_100200 + i->UnDx_50100 + i->Dx_50100 + i->Care_50100 + i->PreLtfu_50100 + i->Tx_Na_50100 + i->Ltfu_50100 + i->UnDx_50 + i->Dx_50 + i->Care_50 + i->PreLtfu_50 + i->Tx_Na_50 + i->Ltfu_50) * 5.17)
			+ ((i->Tx_A_500 + i->Tx_A_350500 + i->Tx_A_250350 + i->Tx_A_200250 + i->Tx_A_100200 + i->Tx_A_50100 + i->Tx_A_50) * 0.1)))
			+ p->nu_3 * i->UnDx_250350 - (p->nu_4 + p->rho + (p->art_350 * p->s_4 * p->p * p->theta) + (p->art_350 * p->s_4 * (1-p->p) * p->theta) + p->alpha_4 + p->mu) * i->UnDx_200250);
		
		i->UnDx_100200 += step * (0.0011 * (0.02466 * (((i->UnDx_500 + i->Dx_500 + i->Care_500 + i->PreLtfu_500 + i->Tx_Na_500 + i->Ltfu_500) * 1.35)
			+ ((i->UnDx_350500 + i->Dx_350500 + i->Care_350500 + i->PreLtfu_350500 + i->Tx_Na_350500 + i->Ltfu_350500) * 1)
			+ ((i->UnDx_250350 + i->Dx_250350 + i->Care_250350 + i->PreLtfu_250350 + i->Tx_Na_250350 + i->Ltfu_250350 + i->UnDx_200250 + i->Dx_200250 + i->Care_200250 + i->PreLtfu_200250 + i->Tx_Na_200250 + i->Ltfu_200250) * 1.64)
			+ ((i->UnDx_100200 + i->Dx_100200 + i->Care_100200 + i->PreLtfu_100200 + i->Tx_Na_100200 + i->Ltfu_100200 + i->UnDx_50100 + i->Dx_50100 + i->Care_50100 + i->PreLtfu_50100 + i->Tx_Na_50100 + i->Ltfu_50100 + i->UnDx_50 + i->Dx_50 + i->Care_50 + i->PreLtfu_50 + i->Tx_Na_50 + i->Ltfu_50) * 5.17)
			+ ((i->Tx_A_500 + i->Tx_A_350500 + i->Tx_A_250350 + i->Tx_A_200250 + i->Tx_A_100200 + i->Tx_A_50100 + i->Tx_A_50) * 0.1)))
			+ p->nu_4 * i->UnDx_200250 - (p->nu_5 + p->rho + (p->art_200 * p->s_5 * p->p * p->theta) + (p->art_200 * p->s_5 * (1-p->p) * p->theta) + p->alpha_5 + p->mu) * i->UnDx_100200);
		
		i->UnDx_50100 += step * (0.0008 * (0.02466 * (((i->UnDx_500 + i->Dx_500 + i->Care_500 + i->PreLtfu_500 + i->Tx_Na_500 + i->Ltfu_500) * 1.35)
			+ ((i->UnDx_350500 + i->Dx_350500 + i->Care_350500 + i->PreLtfu_350500 + i->Tx_Na_350500 + i->Ltfu_350500) * 1)
			+ ((i->UnDx_250350 + i->Dx_250350 + i->Care_250350 + i->PreLtfu_250350 + i->Tx_Na_250350 + i->Ltfu_250350 + i->UnDx_200250 + i->Dx_200250 + i->Care_200250 + i->PreLtfu_200250 + i->Tx_Na_200250 + i->Ltfu_200250) * 1.64)
			+ ((i->UnDx_100200 + i->Dx_100200 + i->Care_100200 + i->PreLtfu_100200 + i->Tx_Na_100200 + i->Ltfu_100200 + i->UnDx_50100 + i->Dx_50100 + i->Care_50100 + i->PreLtfu_50100 + i->Tx_Na_50100 + i->Ltfu_50100 + i->UnDx_50 + i->Dx_50 + i->Care_50 + i->PreLtfu_50 + i->Tx_Na_50 + i->Ltfu_50) * 5.17)
			+ ((i->Tx_A_500 + i->Tx_A_350500 + i->Tx_A_250350 + i->Tx_A_200250 + i->Tx_A_100200 + i->Tx_A_50100 + i->Tx_A_50) * 0.1)))
			+ p->nu_5 * i->UnDx_100200 - (p->nu_6 + p->rho + (p->art_200 * p->s_6 * p->p * p->theta) + (p->art_200 * p->s_6 * (1-p->p) * p->theta) + p->alpha_6 + p->mu) * i->UnDx_50100);
		
		i->UnDx_50 += step * (0.0014 * (0.02466 * (((i->UnDx_500 + i->Dx_500 + i->Care_500 + i->PreLtfu_500 + i->Tx_Na_500 + i->Ltfu_500) * 1.35)
			+ ((i->UnDx_350500 + i->Dx_350500 + i->Care_350500 + i->PreLtfu_350500 + i->Tx_Na_350500 + i->Ltfu_350500) * 1)
			+ ((i->UnDx_250350 + i->Dx_250350 + i->Care_250350 + i->PreLtfu_250350 + i->Tx_Na_250350 + i->Ltfu_250350 + i->UnDx_200250 + i->Dx_200250 + i->Care_200250 + i->PreLtfu_200250 + i->Tx_Na_200250 + i->Ltfu_200250) * 1.64)
			+ ((i->UnDx_100200 + i->Dx_100200 + i->Care_100200 + i->PreLtfu_100200 + i->Tx_Na_100200 + i->Ltfu_100200 + i->UnDx_50100 + i->Dx_50100 + i->Care_50100 + i->PreLtfu_50100 + i->Tx_Na_50100 + i->Ltfu_50100 + i->UnDx_50 + i->Dx_50 + i->Care_50 + i->PreLtfu_50 + i->Tx_Na_50 + i->Ltfu_50) * 5.17)
			+ ((i->Tx_A_500 + i->Tx_A_350500 + i->Tx_A_250350 + i->Tx_A_200250 + i->Tx_A_100200 + i->Tx_A_50100 + i->Tx_A_50) * 0.1)))
			+ p->nu_6 * i->UnDx_50100 - (p->rho + (p->art_200 * p->s_7 * p->p * p->theta) + (p->art_200 * p->s_7 * (1-p->p) * p->theta) + p->alpha_7 + p->mu) * i->UnDx_50);
		
		/* DIAGNOSED */
		i->Dx_500 += step * (+ p->rho * i->UnDx_500 - (p->nu_1 + p->epsilon + (p->art_all * p->s_1 * p->p * p->theta) + (p->art_all * p->s_1 * (1-p->p) * p->theta) + p->alpha_1 + p->mu) * i->Dx_500);
		i->Dx_350500 += step * (+ p->rho * i->UnDx_350500 + p->nu_1 * i->Dx_500 - (p->nu_2 + p->epsilon + (p->art_500 * p->s_2 * p->p * p->theta) + (p->art_500 * p->s_2 * (1-p->p) * p->theta) + p->alpha_2 + p->mu) * i->Dx_350500);
		i->Dx_250350 += step * (+ p->rho * i->UnDx_250350 + p->nu_2 * i->Dx_350500 - (p->nu_3 + p->epsilon + (p->art_350 * p->s_3 * p->p * p->theta) + (p->art_350 * p->s_3 * (1-p->p) * p->theta) + p->alpha_3 + p->mu) * i->Dx_250350);
		i->Dx_200250 += step * (+ p->rho * i->UnDx_200250 + p->nu_3 * i->Dx_250350 - (p->nu_4 + p->epsilon + (p->art_350 * p->s_4 * p->p * p->theta) + (p->art_350 * p->s_4 * (1-p->p) * p->theta) + p->alpha_4 + p->mu) * i->Dx_200250);
		i->Dx_100200 += step * (+ p->rho * i->UnDx_100200 + p->nu_4 * i->Dx_200250 - (p->nu_5 + p->epsilon + (p->art_200 * p->s_5 * p->p * p->theta) + (p->art_200 * p->s_5 * (1-p->p) * p->theta) + p->alpha_5 + p->mu) * i->Dx_100200);
		i->Dx_50100 += step * (+ p->rho * i->UnDx_50100 + p->nu_5 * i->Dx_100200 - (p->nu_6 + p->epsilon + (p->art_200 * p->s_6 * p->p * p->theta) + (p->art_200 * p->s_6 * (1-p->p) * p->theta) + p->alpha_6 + p->mu) * i->Dx_50100);
		i->Dx_50 += step * (+ p->rho * i->UnDx_50 + p->nu_6 * i->Dx_50100 - (p->epsilon + (p->art_200 * p->s_7 * p->p * p->theta) + (p->art_200 * p->s_7 * (1-p->p) * p->theta) + p->alpha_7 + p->mu) * i->Dx_50);
		
		/* CARE */
		i->Care_500 += step * (+ p->epsilon * i->Dx_500 - (p->nu_1 + p->kappa + (p->art_all * p->p * p->gamma) + (p->art_all * p->s_1 * p->p * p->theta) + (p->art_500 * (1-p->p) * p->gamma) + (p->art_500 * p->s_1 * (1-p->p) * p->theta) + p->alpha_1 + p->mu) * i->Care_500);
		i->Care_350500 += step * (+ p->epsilon * i->Dx_350500 + p->nu_1 * i->Care_500 - (p->nu_2 + p->kappa + (p->art_500 * p->p * p->gamma) + (p->art_500 * p->s_2 * p->p * p->theta) + (p->art_500 * (1-p->p) * p->gamma) + (p->art_500 * p->s_2 * (1-p->p) * p->theta) + p->alpha_2 + p->mu) * i->Care_350500);
		i->Care_250350 += step * (+ p->epsilon * i->Dx_250350 + p->nu_2 * i->Care_350500 - (p->nu_3 + p->kappa + (p->art_350 * p->p * p->gamma) + (p->art_350 * p->s_3 * p->p * p->theta) + (p->art_350 * (1-p->p) * p->gamma) + (p->art_350 * p->s_3 * (1-p->p) * p->theta) + p->alpha_3 + p->mu) * i->Care_250350);
		i->Care_200250 += step * (+ p->epsilon * i->Dx_200250 + p->nu_3 * i->Care_250350 - (p->nu_4 + p->kappa + (p->art_350 * p->p * p->gamma) + (p->art_350 * p->s_4 * p->p * p->theta) + (p->art_350 * (1-p->p) * p->gamma) + (p->art_350 * p->s_4 * (1-p->p) * p->theta) + p->alpha_4 + p->mu) * i->Care_200250);
		i->Care_100200 += step * (+ p->epsilon * i->Dx_100200 + p->nu_4 * i->Care_200250 - (p->nu_5 + p->kappa + (p->art_200 * p->p * p->gamma) + (p->art_200 * p->s_5 * p->p * p->theta) + (p->art_200 * (1-p->p) * p->gamma) + (p->art_200 * p->s_5 * (1-p->p) * p->theta) + p->alpha_5 + p->mu) * i->Care_100200);
		i->Care_50100 += step * (+ p->epsilon * i->Dx_50100 + p->nu_5 * i->Care_100200 - (p->nu_6 + p->kappa + (p->art_200 * p->p * p->gamma) + (p->art_200 * p->s_6 * p->p * p->theta) + (p->art_200 * (1-p->p) * p->gamma) + (p->art_200 * p->s_6 * (1-p->p) * p->theta) + p->alpha_6 + p->mu) * i->Care_50100);
		i->Care_50 += step * (+ p->epsilon * i->Dx_50 + p->nu_6 * i->Care_50100 - (p->kappa + (p->art_200 * p->p * p->gamma) + (p->art_200 * p->s_7 * p->p * p->theta) + (p->art_200 * (1-p->p) * p->gamma) + (p->art_200 * p->s_7 * (1-p->p) * p->theta) + p->alpha_7 + p->mu) * i->Care_50);
		
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