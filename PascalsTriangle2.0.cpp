//============================================================================
// Name        : 0.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

#ifndef MARMOSET_TESTING
int main();
#endif

int factorial (int n);
int pascal_triangle(int n);
int fact_recursion(int n);
int pascal_triangle_recursive(int n);

#ifndef MARMOSET_TESTING
int main(){
	std::cout<<pascal_triangle(9);
	std::cout<<endl;
	std::cout<<pascal_triangle_recursive(4);
	return 0;
}
#endif


int factorial(int n ) {
	    int fact{1};
	    int k{2};

	    while ( k <= n ) {
	        fact *= k;
	        ++k;
	    }

	    return fact;
	}

int pascal_triangle(int n){
	int initial{0};
	int r{0};
	while(initial <= n){

		while(r <= initial){
			int term{0};
				term = ((factorial(initial))/((factorial(r))*(factorial(initial - r))));
				std::cout<<term<<" ";
				++r;
		}
		std::cout<<endl;
		r=0;
		++initial;
	}
	int num_iterations{0};
	int total_int{0};
	int s{1};
	while(num_iterations <= n){
		total_int += s;
		++s;
		++num_iterations;
	}
	return total_int;
}


int fact_recursion(int n){
	if (n==0){
		return 1;
	}else{
		return (n * fact_recursion(n-1));
	}
}
int pascal_triangle_recursive(int n){
	int initial{0};
		int r{0};
		while(initial <= n){

			while(r <= initial){
				int term{0};
					term = ((fact_recursion(initial))/((fact_recursion(r))*(fact_recursion(initial - r))));
					std::cout<<term<<" ";
					++r;
			}
			std::cout<<endl;
			r=0;
			++initial;
		}
		int num_iterations{0};
		int total_int{0};
		int s{1};
		while(num_iterations <= n){
			total_int += s;
			++s;
			++num_iterations;
		}
		return total_int;
}


