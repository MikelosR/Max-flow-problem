#include "include/libraries.h"
#include "include/agogos.h"
#include "include/idragogeio.h"
#include "include/my_max_flow.h"
using namespace std;


int main() {
	ifstream file("tests/input.txt"); // Open the file
    if (!file.is_open()) {
        cerr<<"Error: Could not open the file."<<endl;
        return 1;
    }
    //Variables to hold the three numbers
    int a, b;
    unsigned long c; 
    int num_of_idragogeia = 500, agogoi = 1000;
    
    vector<tuple<int, int, int>> all_edges_vector;
    string line;
    unsigned long upper_bound = 1000000000;
    while (getline(file, line)) { // Read each line from the file
        istringstream iss(line); // Create a string stream from the line
        if (iss>>a>>b>>c) { // Extract the three numbers from the line
            all_edges_vector.emplace_back(a, b, c); // Store the numbers in a vector as a tuple
            //Restriction a,b,c
            if(a < 1 || a > num_of_idragogeia) cout<<"wrong a index!"<<endl;
            if(b < 1 || b > num_of_idragogeia) cout<<"wrong b index!"<<endl;
            if(c < 1 || c > upper_bound) cout<<"wrong c index!"<<endl;
            
        }
        else{
            iss.clear(); //Clear the stream's fail state
            iss.str(line); //Reset the stream with the current line
            if (iss >> num_of_idragogeia >> agogoi) {
                //Restriction num_of_idragogeia, agogoi
                if(num_of_idragogeia < 1 || num_of_idragogeia > 500) cout<<"polla idragogeia!"<<endl;
                if(agogoi < 1 || agogoi > 1000) cout<<"polloi agogoi!"<<endl;
            } 
            else {
                cerr << "Error: Invalid line format." << endl;
            }
        }
    }

    file.close(); //Close the file

    vector<ydragogeio> graph(num_of_idragogeia+1);
    agogos first_index;
    graph[0].add_edge(first_index);
    for (int i =  1; i <= num_of_idragogeia; i++){
        graph[i].set_name(i);
    }

    agogos temp_edge;
    for (const auto& tpl : all_edges_vector) {
        int a, b, c;
        tie(a, b, c) = tpl; //Extract values from the tuple
        temp_edge.set_capacity(c);
        temp_edge.set_flow(0);
        temp_edge.set_from_idragogeio(a);
        temp_edge.set_send_to_idragogeio(b);
        graph[a].add_edge(temp_edge);
    }

    int max_flow = ford_fulkerson(graph, 1, graph.size()-1);
    cout<<"Maximum Flow: "<<max_flow<<endl;
	return 0;
}

