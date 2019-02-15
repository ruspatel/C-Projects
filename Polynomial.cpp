//============================================================================
// Name        : Polynomial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Polynomial.h"

/*struct poly_t
{
    double *a_coeffs;       // array of coefficients
    unsigned int degree;    // the degree of the polynomial
};*/


void init_poly(poly_t &p, double const init_coeffs[], unsigned int const init_degree){
	if(p.a_coeffs != nullptr){
		delete[] p.a_coeffs;
		p.a_coeffs = nullptr;
		p.degree = 0;
	}
	p.degree = init_degree;
	p.a_coeffs = new double[p.degree + 1];
	//copying array to new array
	for(std::size_t k{0}; k <= p.degree; ++k){
		p.a_coeffs[k] = init_coeffs[k];
	}

}
void destroy_poly(poly_t &p){
	delete[] p.a_coeffs;
	p.a_coeffs = nullptr;
	p.degree = 0;
}

unsigned int poly_degree(poly_t const &p){//throw statement within
	if(p.a_coeffs == nullptr){
		throw 0;
	}
	return p.degree;
}

double poly_coeff(poly_t const &p, unsigned int n){//throw statement within
	if(p.a_coeffs == nullptr){
		throw 0;
	}
	for(std::size_t k{0}; k <= n&&(p.a_coeffs[n] != 0); ++k){
	if(n > p.degree){
		p.a_coeffs[n] = 0;
	}
	else if(k==n){
		return p.a_coeffs[k];
		}
	}
	return 0;
}
double poly_val(poly_t const &p, double x){
	double result = p.a_coeffs[p.degree];
	    for (int k = p.degree; k > 0; --k){
	        result = result*x + p.a_coeffs[k-1];
	    }
	    return result;
}

void poly_add(poly_t &p, poly_t const &q){
	if((p.a_coeffs == nullptr)||(q.a_coeffs == nullptr)){
		throw 0;
	}
	unsigned int capacity{0};
	unsigned int new_degree{0};
	double *new_p;
	double max{0};
	double min{0};
	if(p.degree > q.degree){
		//new_p = new double[p.degree + 1];
		new_degree = p.degree;
		capacity = p.degree + 1;
		max = p.degree;
		min = q.degree;
	}else if(q.degree > p.degree){
		//new_p = new double[q.degree + 1];
		new_degree = q.degree;
		capacity = q.degree + 1;
		max = q.degree;
		min = p.degree;
	}else{
		//new_p = new double[p.degree + 1];
		new_degree = p.degree;
		capacity = p.degree + 1;
		max = p.degree;
		min = q.degree;
	}

	new_p = new double[capacity];
	for(std::size_t k{0}; k <= new_degree; ++k){
		if(k <= min){
			new_p[k] = p.a_coeffs[k] + q.a_coeffs[k];
		}else if(min == q.degree){
			new_p[k] = p.a_coeffs[k];
		}else{
			new_p[k] = q.a_coeffs[k];
		}
	}
	unsigned int store{new_degree};
	bool test{true};;
	for(std::size_t k{store};((k > 0)&&(test == true)); --k){
		if((p.a_coeffs[k] + q.a_coeffs[k])==0){
			store -= 1;
		}else{
			test = false;
		}
	}

	p.degree = store;
	destroy_poly(p);
	init_poly(p, new_p, store);
	delete[] new_p;
	new_p = nullptr;


	/*for(std::size_t k{0}; k <= p.degree; ++k){
		p.a_coeffs[k] = new_p[k];
	}*/

	//delete[] new_p;
	//new_p = nullptr;

	/*for(std::size_t k{0}; k <= p.degree; ++k){
		std::cout<<p.a_coeffs[k]<<std::endl;
	}*/
}

void poly_subtract(poly_t &p, poly_t const &q){
	if((p.a_coeffs == nullptr)||(q.a_coeffs == nullptr)){
		throw 0;
	}
	unsigned int capacity{0};
	unsigned int new_degree{0};
	double *new_p;
	double max{0};
	double min{0};
	if(p.degree > q.degree){
		//new_p.a_coeffs = new double[p.degree + 1];
		new_degree = p.degree;
		capacity = new_degree + 1;
		max = p.degree;
		min = q.degree;
	}else if(q.degree > p.degree){
		//new_p.a_coeffs = new double[q.degree +1];
		new_degree = q.degree;
		capacity = new_degree + 1;
		max = q.degree;
		min = p.degree;
	}else{
		//new_p.a_coeffs = new double[p.degree + 1];
		new_degree = p.degree;
		capacity = new_degree + 1;
		max = p.degree;
		min = q.degree;
	}
	new_p = new double[capacity];
	for(std::size_t k{0}; k <= new_degree; ++k){
		if(k <= min){
			new_p[k] = p.a_coeffs[k] - q.a_coeffs[k];
		}else if(min == q.degree){
			new_p[k] = p.a_coeffs[k];
		}else{
			new_p[k] = -(q.a_coeffs[k]);
		}
	}
	unsigned int store{new_degree};
	bool test{true};;
	for(std::size_t k{store}; ((k > 0)&&(test == true)); --k){
		if((p.a_coeffs[k] - q.a_coeffs[k])==0){
			store -= 1;
		}else{
			test = false;
		}
	}


	p.degree = store;
	destroy_poly(p);
	init_poly(p, new_p, store);
	delete[] new_p;
	new_p = nullptr;

	/*for(std::size_t k{0}; k <= p.degree; ++k){
		p.a_coeffs[k] = new_p.a_coeffs[k];
	}*/

	/*delete[] new_p.a_coeffs;
	new_p.a_coeffs = nullptr;*/

	/*for(std::size_t k{0}; k <= p.degree; ++k){
		std::cout<<p.a_coeffs[k]<<std::endl;
	}*/
}
void poly_multiply(poly_t &p, poly_t const &q){
	if((p.a_coeffs == nullptr)||(q.a_coeffs == nullptr)){
			throw 0;
		}
		double *new_p;
		unsigned int new_degree{0};
		new_degree = p.degree + q.degree;
		new_p = new double[new_degree + 1];

	for(std::size_t k{0}; k < (new_degree + 1); ++k){
		new_p[k] = 0.0;
	}

	for(std::size_t r{0}; r <= p.degree; ++r){

		for(std::size_t k{0}; k <= q.degree; ++k){
			new_p[k+r] += (p.a_coeffs[r] * q.a_coeffs[k]);
		}
	}
	unsigned int store{new_degree};
	bool test{true};;
	for(std::size_t k{store};((k > 0)&&(test == true)); --k){
		if(new_p[k]==0){
			store -= 1;
		}else{
			test = false;
		}
	}
	p.degree = store;
	destroy_poly(p);
	init_poly(p, new_p, store);
	delete[] new_p;
	new_p = nullptr;


	/*for(std::size_t k{0}; k <= p.degree; ++k){
			p.a_coeffs[k] = new_p.a_coeffs[k];
		}*/

		/*delete[] new_p.a_coeffs;
		new_p.a_coeffs = nullptr;*/

		/*for(std::size_t k{0}; k <= p.degree; ++k){
			std::cout<<p.a_coeffs[k]<<std::endl;

		}*/
}

double poly_divide(poly_t &p, double r){
	if(p.a_coeffs == nullptr){
		throw 0;
	}
	double remainder{0};
	unsigned int capacity{p.degree - 1};
	double *new_p{new double[capacity]{0}};

	for(std::size_t k{0}; k < capacity; ++k){
			new_p[k] = 0.0;
		}

	if(p.degree == 0){
		remainder = p.a_coeffs[0];
		new_p[0]= p.a_coeffs[0];
		destroy_poly(p);
		init_poly(p, new_p, 0);

		delete[] new_p;
		new_p = nullptr;

		return remainder;
	}
	else{
	for(unsigned int k{p.degree}; k > 0; --k){
		if(k == p.degree){
			new_p[k-1] = p.a_coeffs[k];
		}else{
			new_p[k-1] = p.a_coeffs[k] + ((new_p[k])*r);
		}
	}
	remainder = (new_p[0]*r) + p.a_coeffs[0];

	destroy_poly(p);
	init_poly(p, new_p, capacity);

	delete[] new_p;
	new_p = nullptr;

	return remainder;
	}
}



void poly_diff(poly_t &p){
	if(p.a_coeffs == nullptr){
		throw 0;
	}
	double *new_p;
	new_p = new double[p.degree];
	double count_degree = p.degree;
	double new_degree = p.degree - 1;

	for(unsigned int k{p.degree}; k > 0;--count_degree, --k){
		new_p[k-1] = count_degree*p.a_coeffs[k];
	}
	destroy_poly(p);
	init_poly(p, new_p, new_degree);

	delete[] new_p;
	new_p = nullptr;

	/*for(unsigned int k{0}; k <=new_degree; ++k){
		std::cout<<p.a_coeffs[k]<<std::endl;
	}*/

}
double poly_approx_int(poly_t const &p, double a, double b, unsigned int n){
	if(p.a_coeffs == 0){
		throw 0;
	}
	double h = ((b - a)/n);

	double sum{(poly_val(p, a)) + (poly_val(p, b))};

	for(unsigned int k{1}; k < n; ++k){
		sum += (2 * poly_val(p, (a + (k*h))));

	}
	return ((h/2) * sum);
}


#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main(){
	poly_t p;
	poly_t q;

	p.degree = 0;
	p.a_coeffs = nullptr;
	q.degree = 0;
	q.a_coeffs = nullptr;

	double a[4]{1, 0, -1};
	double b[3]{1, 1, 1};
	init_poly(p, a, 2);
	init_poly(q, b, 2);
	std::cout<<poly_divide(p, -1)<<std::endl;
	std::cout<<p.degree;
	return 0;
}
#endif








