#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int value;
    int priority;
};

class PriorityQueue{
    private:
        vector<Node*> PQ;
        int N, NumNodes;
    public:
        PriorityQueue(int size){
            N = size;
            vector<Node*> PQ(size);
            NumNodes = -1;
        }
        ~PriorityQueue(){
            for(int i=0; i < PQ.size(); i++){
                delete PQ[i];
            }
            std::cout << "Lista Borrada.\n";
        }
        void Heapify(int);
        void swap(int&, int&);
        void push(int, int);
        void pop();
        int top();
        bool empty();
        int size();
        void display();
};

void PriorityQueue::swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void PriorityQueue::Heapify(int i){
    int size = PQ.size();

    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < size && PQ[l]->value > PQ[largest]->value){
        largest = l;
    }
    if(r < size && PQ[r]->value > PQ[largest]->value){
        largest = r;
    }

    if(largest != i){
        swap(PQ[i]->value, PQ[largest]->value);
        Heapify(largest);
    }
}

void PriorityQueue::push(int value, int prior){
    if (NumNodes == N-1) {
        std::cout << "La lista esta llena\n";
        return;
    }

    NumNodes++;

    PQ[NumNodes]->value = value;
    PQ[NumNodes]->priority = prior;

    Heapify(0);
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
    delete PQ[mayorIndex];
}

int PriorityQueue::top(){
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
    return PQ[mayorIndex]->value;
}

bool PriorityQueue::empty(){
    if (NumNodes == -1){
        std::cout << "La lista esta vacia\n";
        return true;
    }

    else{
        std::cout << "La lista tiene elementos\n";
        return false;
    }
}

int PriorityQueue::size(){
    return NumNodes + 1;
}

void PriorityQueue::display(){
    std::cout << "Elementos: ";
    for(int i=0; i<= NumNodes; i++){
        std::cout << PQ[i]->value << " ";
    }
    std::cout << "\n";
    std::cout << "Prioridad: ";
    for(int i=0; i<= NumNodes; i++){
        std::cout << PQ[i]->priority << " ";
    }
    std::cout << "\n";
}

int main(){
    PriorityQueue PQ(6);

    PQ.push(2, 1);
    PQ.push(9, 3);
    PQ.push(3, 4);
    PQ.push(1, 2);
    PQ.push(5, 1);
    PQ.push(4, 2);

    PQ.display();

    return 0;
}