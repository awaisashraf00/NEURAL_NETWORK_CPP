#include "neural_networking.h"
#include <cassert>

NETWORK::NETWORK(const std::vector<unsigned int> &t):topology(t){ 
    num_layers = t.size();
    for(unsigned int layer{0};layer<num_layers;layer++){
        m_layers.push_back(Layer());
        unsigned int num_outs = (layer == num_layers-1 ? 0:t[layer+1]);

        for(unsigned int num_neuron{0}; num_neuron<=t[layer] ;++num_neuron){
            m_layers.back().push_back(NEURON(num_outs,num_neuron));
        }
    }  
}

void NETWORK::feedforward(const std::vector<double> &input_vals){
    assert(input_vals.size()==m_layers[0].size()-1);

    for(size_t i{0};i<input_vals.size();++i){
        m_layers[0][i].setOutputVal(input_vals[i]);
    }

    for(size_t lnum{1};lnum< m_layers.size();lnum++){
        Layer &pre_layer = m_layers[lnum-1];
        for(size_t n_num{0} ; n_num < m_layers[lnum].size();n_num++){
            m_layers[lnum][n_num].NEfeedforward(pre_layer);
        }
    }
}

void NETWORK::backprop(const std::vector<double> &target_Vals){
    // TODO: Implement backward propagation
    // Calculate overall net errors
    //calcluate layers form output to first hidden layer
    Layer &outputLayer = m_layers.back();
    double m_error;
    for(size_t i{0};i<outputLayer.size();i++){
        double delta = target_Vals[i] - outputLayer[i].getOutputVal();
        m_error += delta*delta;
    }
    m_error /= outputLayer.size()-1;
    m_error  = sqrt(m_error);
    
}

std::vector<double> NETWORK::getresult(){
    std::vector<double> result_Vals;
    return result_Vals;
}