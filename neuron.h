#ifndef NEURON_H
#define NEURON_H
#include<vector>
#include<cmath>
#include <iostream>
#include <cstdlib>

struct Connection{
    double weight;
    double deltaweight;
};

class NEURON{
    private:
        std::vector<Connection> output_weights;
        double m_output_val;
        size_t my_Index;
        static double getrandomnumbers();
        static double transferFunction(double x);
        static double transferFunctionDerivative(double x);
    public:
        NEURON(unsigned int outs , size_t N_Index);
        void setOutputVal(double val);
        double getOutputVal() const;
        void NEfeedforward(const std::vector<NEURON> &prevlayer);
};

#endif
