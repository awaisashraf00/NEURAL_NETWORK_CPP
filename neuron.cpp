#include "neuron.h"

void NEURON::setOutputVal(double val) { m_output_val = val; }
double NEURON::getOutputVal() const {return m_output_val;}
double NEURON::getrandomnumbers() { return (rand() / double(RAND_MAX)); }
double NEURON::transferFunction(double x){return tanh(x);}
double NEURON::transferFunctionDerivative(double tangent){return 1-(tangent*tangent);}


NEURON::NEURON(unsigned int outs,size_t N_Index):my_Index(N_Index){ 
    for(unsigned int i{0};i<outs;++i){
        output_weights.push_back(Connection({}));
        output_weights.back().weight = getrandomnumbers();
    }
}

void NEURON::NEfeedforward(const std::vector<NEURON> &prevlayer)
{
    double sum{0};
    
    for(size_t layer_sum{0};layer_sum<prevlayer.size();layer_sum++){
        sum += prevlayer[layer_sum].getOutputVal() * prevlayer[layer_sum].output_weights[my_Index].weight;
    }

    m_output_val = NEURON::transferFunction(sum);
}


