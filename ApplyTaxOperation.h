


#ifndef APPLYTAXOPERATION_H
#define APPLYTAXOPERATION_H

class ApplyTaxOperation {
    double& taxRate;
public:
    ApplyTaxOperation(double& rate);
    void execute();
};

#endif