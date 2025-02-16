#ifndef YDRAGOGEIO_H
#define YDRAGOGEIO_H

#include "agogos.h" // Include agogos class header
using namespace std;
#include <vector>

class ydragogeio {
private:
    int name;
    vector<agogos> edge;

public:
    //Constructor with parameter
    ydragogeio(int in_name);
    
    //Default constructor
    ydragogeio();
    
    //Getter and Setter functions
    void set_name(int in_name);
    int get_name() const;

    //Add an agogos object to the edge vector
    void add_edge(const agogos a);
    vector<agogos>& get_edges();

    //Print edges
    void print_edges() const;

    //Update a specific edge in the vector
    void update_edge(unsigned long index, int new_name, int new_capacity);    
};

#endif
