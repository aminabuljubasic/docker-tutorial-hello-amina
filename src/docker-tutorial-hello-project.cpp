//============================================================================
// Name        : docker-tutorial-hello-project.cpp
// Author      : Amy Tabb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv) {
	ifstream in;
	ofstream out;
	string directory, str;
	string filename_in, filename_out;
	if (argc >= 2){
			directory = argv[1];
			cout << "Directory is : " << directory << endl;

			filename_in = directory + "/read.txt";

			in.open(filename_in.c_str());

			if (!in.good()){
				cout << "You forgot the read.txt file in the bindmount directory, quitting." << endl;
				exit(1);
			}


			filename_out = directory + "/write.txt";
			out.open(filename_out.c_str());


			while(getline(in, str)) {
				out << str << endl;
			}

			out << endl << " Hello world from the final program!  Here were the arguments!" << endl;
			cout << endl << " Hello world from the final program!  Here were the arguments!" << endl;
		for (int i = 2; i < argc; i++){
			cout << "Argument " << i << " " << argv[i] << endl;
			out << "Argument " << i << " " << argv[i] << endl;
		}
		out.close();
	} else
		return 0;
}
