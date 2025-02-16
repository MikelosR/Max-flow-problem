#include "../include/agogos.h"

// Constructor with parameters
agogos::agogos(int in_capacity,int in_name,  int in_from_idragogeio, int in_send_to_idragogeio, int cap_flow)
    :   capacity(in_capacity), name(in_name), from_idragogeio(in_from_idragogeio), send_to_idragogeio(in_send_to_idragogeio), 
        flow(cap_flow) {}

// Default constructor
agogos::agogos() : capacity(0), name(0), from_idragogeio(0), send_to_idragogeio(0), flow(0) {}

//Copy constructor (Deep Copy)
agogos::agogos(const agogos& other) {
    capacity = other.capacity; //Deep copy
    name = other.name;
    from_idragogeio = other.from_idragogeio;
    send_to_idragogeio = other.send_to_idragogeio;
    flow = other.flow;
}

agogos& agogos::operator=(const agogos& other) {
    if (this != &other) { // Prevent self-assignment
        capacity = other.capacity;
        name = other.name;
        from_idragogeio = other.from_idragogeio;
        send_to_idragogeio = other.send_to_idragogeio;
        flow = other.flow;
    }
    return *this;
}

void agogos::set_capacity(int in_capacity) {
    capacity = in_capacity;
}

int agogos::get_capacity() const {
    return capacity;
}

void agogos::set_name(int in_name) {
    name = in_name;
}

int agogos::get_name() const {
    return name;
}

void agogos::set_from_idragogeio(int in_from_idragogeio) {
    from_idragogeio = in_from_idragogeio;
}

int agogos::get_from_idragogeio() const {
    return from_idragogeio;
}

void agogos::set_send_to_idragogeio(int in_send_to_idragogeio) {
    send_to_idragogeio = in_send_to_idragogeio;
}

int agogos::get_send_to_idragogeio() const {
    return send_to_idragogeio;
}

void agogos::set_flow(int in_flow) { 
    flow = in_flow; 
}
    
int agogos::get_flow() const { 
    return flow; 
}


