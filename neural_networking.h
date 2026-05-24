#ifndef NETWORK_H
#define NETWORK_H
#include "neuron.h"

typedef std::vector<NEURON> Layer;

class NETWORK{
    public:
        NETWORK(const std::vector<unsigned int> &t);

        /*
        Performs the forward pass through the network.
        Takes input values and propagates them through all layers to produce output predictions.
        */
       void feedforward(const std::vector<double> &input_vals);
       /*
        Performs backward propagation (training step).
        Takes target/expected values and computes errors to adjust weights and biases.
       */
      void backprop(const std::vector<double> &target_Vals);
      
    // Retrieves the output results from the neural network after a feedforward pass.
    std::vector<double> getresult();
    
    private:
        std::vector<Layer> m_layers;
        const std::vector<unsigned int> topology;
        unsigned int  num_layers;

};

#endif

