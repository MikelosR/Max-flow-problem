#include "../include/idragogeio.h"
#include <iostream>
using namespace std;

ydragogeio::ydragogeio(int in_name) : name(in_name) {}

ydragogeio::ydragogeio() : name(0) {}

void ydragogeio::set_name(int in_name) {
    name = in_name;
}

int ydragogeio::get_name() const {
    return name;
}

void ydragogeio::add_edge(const agogos a) {
    edge.push_back(a);
}

vector<agogos>& ydragogeio::get_edges() { 
    return edge;
}

void ydragogeio::print_edges() const {
    for (const auto& e : edge) {
        cout<<"Capacity: "<<e.get_capacity()<<", From: "<<e.get_from_idragogeio()
            <<", To: "<<e.get_send_to_idragogeio()<<", Flow: "<<e.get_flow()<<endl;
    }
    cout<<endl;
}

void ydragogeio::update_edge(unsigned long index, int new_name, int new_capacity) {
    if (index < edge.size()) {
        edge[index].set_name(new_name);
        edge[index].set_capacity(new_capacity);
    } else {
        cout<<"Invalid index!"<<endl;
    }
}