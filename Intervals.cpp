//============================================================================
// Name        : Intervals.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++,  Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

//Function Declarations
int main();
void interval_calculator();


//Function Definitions
void interval_calculator(){
	std::string input{};
	double a{0};
	double b{0};
	double c{0};
	double d{0};
	double im_interval[2]{1,  0};
	double mm_interval[2]{1,  0};
	while(input!= "exit"){
		std::cout<<"input :> ";
		std::cin>> input;
		if(input == "exit"){
			std::cout<<"Bye bye: Terminating interval calculator program.";
		}
		else if(input=="enter"){
			std::cin>>a;
			std::cin>>b;
			if(a > b){
					std::cout<<"Error: invalid interval as "<<a<<" > "<<b<<std::endl;
					if(im_interval[0] < im_interval[1]){
						std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
					}else{
						std::cout<<"--";
					}
				}else{
					im_interval[0] = a;
					im_interval[1] = b;
					//std::cout<<"input:> enter "<<im_interval[0]<<" "<<im_interval[1]<<std::endl;
					std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
				}
		}
		else if(input=="negate"){
			if(im_interval[0] < im_interval[1]){
				double tmp{im_interval[0]};
				im_interval[0] = -im_interval[1];
				im_interval[1] = -tmp;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";

			}else{
				std::cout<<"--";
			}


		}
		else if(input == "invert"){
			if (im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}else if(((im_interval[0] < 0) && (im_interval[1] > 0))||((im_interval[0] == 0)&&(im_interval[1] == 0))){
				std::cout<<"Error: division by zero";
				std::cout<<std::endl;
				std::cout<<"--";
				im_interval[0] = 0;
				im_interval[1] = 0;
			}else{
				double tmp{im_interval[1]};
				im_interval[1] = (1/ (im_interval[0]));
				im_interval[0] = (1/tmp);
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}
		}
		else if(input=="ms"){
			if(im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}else{
				//Immediate interval assigned to memory stored interval
				mm_interval[0] = im_interval[0];
				mm_interval[1] = im_interval[1];
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}
		}
		else if(input == "mr"){
			if((im_interval[0] > im_interval[1])){
			std::cout<<"--";
			}
				else if(mm_interval[0] > mm_interval[1]){
						std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
							}else{//mm_interval[0] < mm_interval[1]
								im_interval[0] = mm_interval[0];
								im_interval[1] = mm_interval[1];
								std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}
		}
		//is not outputting properly
		else if(input == "mc"){
			if(im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}
			else{//if(mm_interval[0] < mm_interval[1]){
				mm_interval[0] = 1;
				mm_interval[1] = 0;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
		}

		}
		else if(input == "m+"){
			if (im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}else if((im_interval[0] < im_interval[1])&&(mm_interval[0] < mm_interval[1])){
				mm_interval[0] = im_interval[0] + mm_interval[0];
				mm_interval[1] = im_interval[1] + mm_interval[1];
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}
		}

		else if(input == "m-"){
			if (im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}else if((mm_interval[0] <= mm_interval[1])){
				mm_interval[0] = mm_interval[0] - im_interval[0];
				mm_interval[1] = mm_interval[1] - im_interval[1];
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
				if(mm_interval[0] > mm_interval[1]){
					double tmp{mm_interval[0]};
					mm_interval[0] = mm_interval[1];
					mm_interval[1] = tmp;
				}
			}
		}
		else if(input == ("scalar_add")){
			std::cin>> c;
			if (im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}else{
				im_interval[0] += c;
				im_interval[1] += c;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}
		}
		else if(input == "scalar_subtract"){
			std::cin>>c;
			if (im_interval[0] >= im_interval[1]){
				std::cout<<"--";
			}else{
				im_interval[0] -= c;
				im_interval[1] -= c;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}
			}
		else if(input == "scalar_multiply"){
			std::cin>>c;
			if (im_interval[0] > im_interval[1]){
					std::cout<<"--";
			}else if(c > 0){
				im_interval[0] = im_interval[0]*c;
				im_interval[1] = im_interval[1]*c;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else if(c < 0){
				double tmp{im_interval[0]};
				im_interval[0] = im_interval[1] * c;
				im_interval[1] = tmp * c;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else{
				im_interval[0] = 0;
				im_interval[1] = 0;
			}

			}
		else if(input == "scalar_divide"){
			std::cin>>c;
			if (im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}else if(c > 0 ){
				im_interval[0] = im_interval[0] / c;
				im_interval[1] = im_interval[1] / c;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else if(c < 0){
				double tmp{im_interval[0]};
				im_interval[0] = im_interval[1] / c;
				im_interval[1] = tmp / c;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else{
				std::cout<<"Error: division by zero"<<std::endl;
				std::cout<<"--";
				im_interval[0] = 1;
				im_interval[1] = 0;
			}
		}
		else if(input == "scalar_divided_by"){
			std::cin>>c;
			if((a < 0) && (b > 0)){
				std::cout<<"Error: division by zero."<<std::endl;
				std::cout<<"--";
			}
			else if (im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}else if(c > 0){
				double tmp{im_interval[0]};
				im_interval[0] = c/im_interval[1];
				im_interval[1] = c/tmp;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else{
				//double tmp{im_interval[0]};
				im_interval[0] = c/im_interval[0];
				im_interval[1] = c/im_interval[1];
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
		}
		}
		else if(input == "interval_add"){
			std::cin>>c;
			std::cin>>d;
			if((c > d)&&(im_interval[0] > im_interval[1])){
				std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
				std::cout<<"--";
			}else if((c > d)&&(im_interval[0] < im_interval[1])){
				std::cout<<"Error: invalid interval as "<<c<<" > "<<d;
				std::cout<<std::endl;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else if(im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}
			else if((c < d)&&(im_interval[0] < im_interval[1])){
				im_interval[0] += c;
				im_interval[1] += d;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}
		}
		else if(input == "interval_subtract"){
			std::cin>>c;
			std::cin>>d;
			if((c > d)&&(im_interval[0] > im_interval[1])){
				std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
				std::cout<<"--";
			}else if((c > d)&&(im_interval[0] < im_interval[1])){
				std::cout<<"Error: invalid interval as "<<c<<" > "<<d;
				std::cout<<std::endl;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else if(im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}
			else if((c < d)&&(im_interval[0] < im_interval[1])){
				im_interval[0] -= d;
				im_interval[1] -= c;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
				}
			}
		else if(input == "interval_multiply"){
		    std::cin>>c;
			std::cin>>d;
			if((c > d)&&(im_interval[0] > im_interval[1])){
				std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
				std::cout<<"--";
			}else if((c > d)&&(im_interval[0] < im_interval[1])){
				std::cout<<"Error: invalid interval as "<<c<<" > "<<d;
				std::cout<<std::endl;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]"<<std::endl;
			}else if(im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}
			else if((c < d)&&(im_interval[0] < im_interval[1])){
			    //find min and max

				double min_array[4]{(im_interval[0]*c), (im_interval[0]*d), (im_interval[1]*c), (im_interval[1]*d)};
				double min{min_array[0]};
				for(std::size_t k{1}; k < 4; ++k){
					if(min_array[k] < min){
						min = min_array[k];
					}
				}
				double max_array[4]{(im_interval[0]*c), (im_interval[0]*d), (im_interval[1]*c), (im_interval[1]*d)};
				double max{max_array[0]};
				for(std::size_t k{1}; k < 4; ++k){
					if(max_array[k] > max){
						max = max_array[k];
					}
				}
				im_interval[1] = max;
				im_interval[0] = min;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}
		}
		else if(input == "interval_divide"){
			std::cin>>c;
			std::cin>>d;
			if((c < 0)&&(d > 0)){//&&((im_interval[0] > im_interval[1]))){
				std::cout<<"Error: division by zero"<<std::endl;
				std::cout<<"--";
				im_interval[0] = 1;
				im_interval[1] = 0;
			/*}else if(((c < 0)&&(d > 0))&&((im_interval[0] < im_interval[1]))){
				std::cout<<"Error: division by zero"<<std::endl;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]"<<std::endl;
			*/
			}else if((c > d)&&(im_interval[0] > im_interval[1])){
				std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
				std::cout<<"--";
			}else if((c > d)&&(im_interval[0] < im_interval[1])){
				std::cout<<"Error: invalid interval as "<<c<<" > "<<d;
				std::cout<<std::endl;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else if(im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}
			else if((c < d)&&(im_interval[0] < im_interval[1])){
				//find min and max

				double min_array[4]{(im_interval[0]/c), (im_interval[0]/d), (im_interval[1]/c), (im_interval[1]/d)};
				double min{min_array[0]};
				for(std::size_t k{1}; k < 4; ++k){
					if(min_array[k] < min){
						min = min_array[k];
					}
				}
				double max_array[4]{(im_interval[0]/c), (im_interval[0]/d), (im_interval[1]/c), (im_interval[1]/d)};
				double max{max_array[0]};
				for(std::size_t k{1}; k < 4; ++k){
					if(max_array[k] > max){
						max = max_array[k];
					}
				}
				im_interval[1] = max;
				im_interval[0] = min;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";

		}
		}
		else if(input == "intersect"){
			std::cin>>c;
			std::cin>>d;
			if(c > d ){
				std::cout<<"Error: invalid interval as"<<c<<" > "<<d<<std::endl;
					if(im_interval[0] < im_interval[1]){
						std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
					}else{
						std::cout<<"--";
					}
			/*if((c > d)&&(im_interval[0] > im_interval[1])){
				std::cout<<"Error: invalid interval as 2 > 1"<<std::endl;
				std::cout<<"--";
			}else if ((c > d)&&(im_interval[0] < im_interval[1])){
				std::cout<<"Error: invalid interval as 2 > 1"<<std::endl;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]"<<std::endl;
			*/
			}else if((c < d )&& (im_interval[0] > im_interval[1])){
				std::cout<<"--";

				//determing intersections
			}else if ((im_interval[0] < c)&&(d < im_interval[1])&&(d > im_interval[0])){
				im_interval[0] = c;
				im_interval[1] = d;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else if((c < im_interval[0])&&(d < im_interval[1])&&(im_interval[0] < d)){
				//im_interval[0];
				im_interval[1] = d;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else if((im_interval[0] < c)&&((im_interval[1] < d)&&( im_interval[1] > c))){
				im_interval[0] = c;
				//im_interval[1];
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else if((c < im_interval[0])&&(im_interval[1] < d)&&(d > im_interval[0])){
				//do nothing
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}else{
				im_interval[0] = 1;
				im_interval[1] = 0;
				std::cout<<"--";
			}
		}
		else if(input=="integers"){
			if(im_interval[0] > im_interval[1]){
				std::cout<<"--";
			}else{
				int tmp_0{im_interval[0] / 1};
				int tmp_1{im_interval[1] / 1};
				if(im_interval[0] > tmp_0){
					tmp_0 += 1;
				}
				for(int k{tmp_0}; k <= tmp_1; ++k){
					if(k < tmp_1){
						std::cout<<k<<", ";
					}else if(k == tmp_1){
							std::cout<<k<<std::endl;
					}

				}

			std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";

			}

		}else if(input == "cartesian_integers"){
				std::cin>>c;
				std::cin>>d;
				double tmp_0 = ceil(im_interval[0]);
				double tmp_1 = floor(im_interval[1]);
				double tmp_c = ceil(c);
				double tmp_d = floor(d);
				if(c > d){
					std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
						if(im_interval[0] > im_interval[1]){
						std::cout<<"--";
							}else{
								std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
							}
			}else if((c < d)&&(im_interval[0] > im_interval[1])){
				std::cout<<"--";
			}else if(int(c)==int(d)){
				std::cout<<"["<<tmp_c<<", "<<tmp_d<<"]"<<std::endl;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}
			else if(tmp_c == tmp_d){
				if(tmp_0 == tmp_1){
					std::cout<<"("<<tmp_0<<", "<<tmp_c<<")"<<std::endl;
					std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
				}else{
				std::cout<<"("<<tmp_0<<", "<<tmp_c<<"), ("<<tmp_1<<", "<<tmp_d<<")"<<std::endl;
				std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
				}
			}else{
			while(tmp_0 <= tmp_1){
				while(tmp_c <= tmp_d){
					if((tmp_0 == tmp_1)&&(tmp_c == tmp_d)){
						std::cout<<"("<<tmp_0<<","<<tmp_c<<")";
						tmp_c += 1;
					}else{
					std::cout<<"("<<tmp_0<<","<<tmp_c<<"), ";
					tmp_c += 1;
					}
				}
				tmp_0 += 1;
				tmp_c = ceil(c);
				}
			std::cout<<std::endl;
			std::cout<<"["<<im_interval[0]<<", "<<im_interval[1]<<"]";
			}
		}

			else{
				std::cout<<"Error: illegal command";
			}

		std::cout<<std::endl;
	}
}


int main(){
	interval_calculator();
	return 0;
}
