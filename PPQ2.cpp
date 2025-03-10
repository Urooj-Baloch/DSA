#include<iostream>
using namespace std;
class Planet{
    public:
    string name;
    int resources;
    bool hasDebris;
    Planet*next;
    Planet(string name, int resources, bool hasDebris){
        this->name=name;
        this->resources=resources;
        this->hasDebris=hasDebris;
        this->next=NULL;
    }
};
void AddPlanet(Planet* &head, string name,int resources,bool hasDebris){
    Planet* temp=new Planet(name,resources,hasDebris);
    temp->next=head;
    head=temp;
}
void Explore(Planet* head){
    int totalResources=0;
    int health=10;
    Planet* temp=head;
    while(temp!=0){
        cout<<temp->name<<" ";
        totalResources+=temp->resources;
        cout << "Collected " << temp->resources << " resources. Total: " << totalResources << endl;
        if(temp->hasDebris){
            health-=2;
            totalResources/=2;
            cout << "Hit debris! Health: " << health << ", Resources now: " << totalResources << endl;
        }
        if (health <= 0) {
            cout << "Mission failed! Health reached zero.\n";
            return;
        }
        temp=temp->next;

    }
    cout<<endl;

}
int main(){
    Planet* head= nullptr;
    AddPlanet(head,"Earth",5,false);
    AddPlanet(head,"Mars",10,false);
    AddPlanet(head,"Jupiter",15,true);
    AddPlanet(head,"Venus",14,false);
    AddPlanet(head,"Satrun",20,true);
    AddPlanet(head,"Neptune",30,true);
    Explore(head);
}
    
