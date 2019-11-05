/**
 * A2main.cpp
 * PURPOSE: This program is to simulate the hospital blue code
 */

#include "Hospital.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "A2Const.hpp"

using namespace std;

int main(int argc, char *argv[]){
	/*
	if(argc < 2){
		cout << "Usage: " << argv[0] << " <file name>\n";
		exit(1);
	}
	*/
	int v1 = A2Const::numAssessmentNurses;
	int v2 = A2Const::numBloodTech;
	int v3 = A2Const::numXRayTech;
	int v4 = A2Const::numDoctors;
	int v5 = A2Const::bloodWorkTime;
	int v6 = A2Const::XRayTime;

	Hospital* h = new Hospital(v1, v2, v3, v4, v5, v6);

	cout << "Simulation begins...\n";
	
//	h->simulate(argv[1]);		// <<-- this command should be enabled if using command line prompt

//----HARD CODED DATA TEST----

//	h->simulate("mytest1.txt");
//	h->simulate("mytest2.txt");
//	h->simulate("test1.txt");	
	h->simulate("test10.txt");	
//	h->simulate("test100.txt");		
	
	cout << "\n...Simulation complete.\n\n";
	
	h->statistics();	//prints statistics

	cout << "\nEnd of processing.\n";
	return 0;
}// main
