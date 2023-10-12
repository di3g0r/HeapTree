#include <iostream>
#include <vector>

using namespace std;

//Creamos el nodo
struct Node{
    int value;
    int priority;
};

class PriorityQueue{
    private:
        int NumNodes;
        vector<Node*> PQ;
    public:
        PriorityQueue(){
            vector<Node*> PQ;
            NumNodes = -1;
        }
        ~PriorityQueue(){
            for(int i=0; i < PQ.size(); i++){
                delete PQ[i];
            }
            std::cout << "Lista Borrada.\n";
        }
       void Heapify(vector<Node*> &v,int index);
       void MaxHeap();

       void push(int data, int prior);
       void pop();

       void swap(Node *&a, Node *&b);

       int peek();
       bool empty();
       int size();
       void deleteAll();
       void display();
};

void PriorityQueue::swap(Node *&a, Node *&b){
    Node* temp;
    temp = a;
    a = b;
    b = temp;
}

void PriorityQueue::Heapify(vector<Node*> &v,int index){
    int size = v.size();

    int largest = PQ[index]->priority;
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    if(l < size && v[l]->priority > v[largest]->priority){
        largest = l;
    }
    if(r < size && v[r]->priority > v[largest]->priority){
        largest = r;
    }

    if(largest != index){
        swap(v[index], v[largest]);
        Heapify(v, largest);
    }
}

void PriorityQueue::MaxHeap(){
    int size = PQ.size();

    for(int i = size / 2 - 1;i >= 0; i--){
        Heapify(PQ, i);
    }
}

void PriorityQueue::push(int data, int prior){

    NumNodes++;

    PQ[NumNodes]->value = data;
    PQ[NumNodes]->priority = prior;

    MaxHeap();
}

void PriorityQueue::pop(){
    if (NumNodes == -1){
        std::cout << "La lista esta vacia\n";
        return;
    }

    int mayorIndex = 0;
    int numV = PQ[0]->value;
    int numP = PQ[0]->priority;

    for(int i=0; i < PQ.size();i++){
        if(PQ[i]->priority > numP){
            numP = PQ[i]->priority;
            numV = PQ[i]->value;
            mayorIndex = i;
        }
        else if(PQ[i]->priority == numP){
            if(PQ[i]->value > numV){
                numV = PQ[i]->value;
                mayorIndex = i;
            }
        }
    }
    NumNodes--;
    delete PQ[mayorIndex];
    MaxHeap();
}

int PriorityQueue::peek(){
    if (NumNodes == -1){
        std::cout << "La lista esta vacia\n";
        return;
    }

    return PQ[0]->priority;
}

bool PriorityQueue::empty(){
    if (NumNodes == -1){
        std::cout << "La lista esta vacia\n";
        return true;
    }

    std::cout << "La lista tiene elementos\n";
    return false;
}

int PriorityQueue::size(){
    return PQ.size();
}

void PriorityQueue::deleteAll(){
    for(int i=0; i < PQ.size(); i++){
            delete PQ[i];
        }
    std::cout << "Lista Borrada.\n";
}

void PriorityQueue::display(){
    std::cout << "Elementos: ";
    for(int i=0; i<= PQ.size(); i++){
        std::cout << PQ[i]->value << " ";
    }
    std::cout << "\n";
    std::cout << "Prioridad: ";
    for(int j=0; j<= PQ.size(); j++){
        std::cout << PQ[j]->priority << " ";
    }
    std::cout << "\n";
}



int main(){

    PriorityQueue cola;

    cola.push(2,3);
    cola.push(4,1);
    cola.push(5,6);

    cola.display();
    return 0;
}