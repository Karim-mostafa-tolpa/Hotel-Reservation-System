


#include "ApplyTaxOperation.h"
#include <iostream>
using namespace std;

ApplyTaxOperation::ApplyTaxOperation(double& rate) : taxRate(rate) {}

void ApplyTaxOperation::execute() {
    double newRate;
    cout << "Enter new tax rate (e.g., 0.15 for 15%): ";
    cin >> newRate;
    taxRate = newRate;
    cout << "Tax rate set to " << taxRate * 100 << "%\n";
}