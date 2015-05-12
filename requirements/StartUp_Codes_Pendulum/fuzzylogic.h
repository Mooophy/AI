#ifndef __FUZZYLOGIC_H__
#define __FUZZYLOGIC_H__

#include <math.h>
#include <set>
#include <stack>
#include <ctime>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

/////////////////////////////////////////////////////

#define MAX_NO_OF_INPUTS 5
#define MAX_NO_OF_INP_REGIONS 5
#define MAX_NO_OF_OUTPUT_VALUES 8

#define TOO_SMALL 1e-6

//Trapezoidal membership function types
typedef enum {regular_trapezoid, left_trapezoid, right_trapezoid} trapz_type;

//Input parameters
enum {in_theta,in_theta_dot,in_x,in_x_dot};

//Fuzzy sets
enum {in_nl,in_ns,in_ze,in_ps, in_pl};

//Fuzzy output terms
enum {out_nvl,out_nl,out_nm, out_ns, out_ze,out_ps, out_pm,out_pl, out_pvl};

typedef struct {
   trapz_type tp;
   float a,b,c,d,l_slope,r_slope;
}trapezoid;

typedef struct {
   short inp_index[MAX_NO_OF_INPUTS],
	 inp_fuzzy_set[MAX_NO_OF_INPUTS],
	 out_fuzzy_set;
}  rule;

typedef struct {
   bool allocated;
   trapezoid inp_mem_fns [MAX_NO_OF_INPUTS] [MAX_NO_OF_INP_REGIONS];
   rule *rules;
   int no_of_inputs,no_of_inp_regions,no_of_rules,no_of_outputs;
   float output_values[MAX_NO_OF_OUTPUT_VALUES];
} fuzzy_system_rec;

extern fuzzy_system_rec g_fuzzy_system;

//---------------------------------------------------------------------------

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ);
float fuzzy_system (float inputs[],fuzzy_system_rec fl);
void free_fuzzy_rules (fuzzy_system_rec *fz);

//-------------------------------------------------------------------------
void initFuzzyRules(fuzzy_system_rec *fl);
void initMembershipFunctions(fuzzy_system_rec *fl); 
void initFuzzySystem (fuzzy_system_rec *fl);

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ);
float trapz (float x, trapezoid trz);
float min_of (float values[],int no_of_inps);
float fuzzy_system (float inputs[],fuzzy_system_rec fz);
void free_fuzzy_rules (fuzzy_system_rec *fz);

#endif
