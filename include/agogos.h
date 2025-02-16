#ifndef AGOGOS_H
#define AGOGOS_H

class agogos {
private:
    int capacity;
    int name;
    int from_idragogeio;
    int send_to_idragogeio;
    int flow;

public:
    // Constructor with parameters
    agogos(int in_capacity, int in_name,  int in_from_idragogeio, int in_send_to_idragogeio, int cap_flow);
    
    // Default constructor
    agogos();
    //Copy constructor
    agogos(const agogos& other);
    agogos& operator=(const agogos& other);


    //Getter and Setter functions
    void set_capacity(int in_capacity);
    int get_capacity() const;

    
    void set_name(int in_name);
    int get_name() const;
    
   
    void set_from_idragogeio(int in_from_idragogeio);
    int get_from_idragogeio() const;
    
    void set_send_to_idragogeio(int in_send_to_idragogeio);
    int get_send_to_idragogeio() const;

    void set_flow(int in_flow);
    int get_flow() const;
};

#endif
