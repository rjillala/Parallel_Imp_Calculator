#include <iostream>
#include <string>
#include <vector>

using namespace std;

double frequency = 0;
string freq_units = "Hz";
vector<double> real;
vector<double> imag;
double real_sum = 0;
double imag_sum = 0;
int num_values = 0;

void obtain_frequency() {
	cout << "Which unit of frequency will be given?\n'Hz' or 'rad/sec'\nEnter: ";
	cin >> freq_units;
	while (freq_units != "Hz" && freq_units != "rad/sec") {
		cout << "Invalid option\nEnter: ";
		cin >> frequency;
	}
	cout << "\nInput frequency\nEnter: ";
	cin >> frequency;
}

void obtain_values() {
	cout << "\nInput real and imaginary values seperately\n";
	string recur;
	cout << "\nReal Component: ";
	double real_in;
	cin >> real_in;
	real.push_back(real_in);
	real_sum += real_in;
	cout << "Imaginary Component: ";
	double imag_in;
	cin >> imag_in;
	imag.push_back(imag_in);
	imag_sum += imag_in;
	num_values++;
	cout << "\nWould you like to add another value?\nEnter(Y or N): ";
	cin >> recur;
	while (recur == "Y") {
		cout << "Real Component: ";
		cin >> real_in;
		real.push_back(real_in);
		cout << "Imaginary Component: ";
		cin >> imag_in;
		imag.push_back(imag_in);
		num_values++;
		real_sum += real_in;
		imag_sum += imag_in;
		cout << "\nWould you like to add another value?\nEnter(Y or N): ";
		cin >> recur;
	}
	num_values--;
}

void calc() {
	for (int i = 0; i < real.size() - 1; i++) {
		real_sum = real[i] + real[i + 1];
		imag_sum = imag[i] + imag[i + 1];
		
		double temp = real[i] * real[i + 1] - imag[i] * imag[i + 1];
		imag[i + 1] = real[i] * imag[i + 1] + imag[i] * real[i + 1];
		real[i + 1] = temp;
		
		double denom = real_sum * real_sum + imag_sum * imag_sum;
		
		temp = real[i + 1] * real_sum + imag[i + 1] * imag_sum;
		imag[i + 1] = real[i + 1] * imag_sum * -1 + imag[i + 1] * real_sum;
		real[i + 1] = temp;
		
		real[i + 1] /= denom;
		imag[i + 1] /= denom;
	}
	
}


void display_results() {
	cout << "\nReal result: " << real[num_values];
	cout << "\nImaginary result: " << imag[num_values];
}

int main() {
	//obtain_frequency();
	obtain_values();
	calc();
	display_results();
	return 0;
}