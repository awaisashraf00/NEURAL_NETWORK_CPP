
#include "neural_networking.h"

int main(){
    std::vector<unsigned int> topology;
    topology.push_back(3);
    topology.push_back(3);
    topology.push_back(2);
    NETWORK neural = NETWORK(topology);
    
    
    std::vector<double> targets;
    neural.backdrop(targets);
    std::vector<double> inputs;
    neural.feedforward(inputs);
    
    return 0;
}