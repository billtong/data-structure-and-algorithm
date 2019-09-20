#include<iostream>
#include<fstream>

#include"Flight.h"
#include"FlightOptions.h"
#include"FlightMatrix.h"

using std::ifstream;
using std::string;
using std::cout;
using std::endl;

void readFlightMatrixFromTxt(FlightMatrix *&, string);

int main(int argc, char* argv[])
{
	string testFilepath = "./assets/2019_Lab_2_flights_test_data.txt";
	string realFilepath = "./assets/2019_Lab_2_flights_real_data.txt";
	FlightMatrix *testFm;
	readFlightMatrixFromTxt(testFm, realFilepath);
	testFm->dijkstra(98, 36);
	system("pause");
	return 0;
}

void readFlightMatrixFromTxt(FlightMatrix *&fmPtr, string filePath)
{
	ifstream file(filePath);
	if (!file) {
		cout << "ERROR: cannot open file" << endl;
		exit(-1);
	}
	int length;
	file >> length;
	fmPtr = new FlightMatrix(length, 0);
	while (file.peek() != EOF)
	{
		int i, j, dt, at;
		file >> i;
		file >> j;
		file >> dt;
		file >> at;
		fmPtr->matrix[i][j].append(dt, at);
	}
	file.close();
}