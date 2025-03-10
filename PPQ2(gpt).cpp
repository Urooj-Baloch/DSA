#include <iostream>
using namespace std;

// Node structure for linked list
struct Planet {
    string name;
    int resources; // Resources available on the planet
    bool hasDebris; // True if there is debris
    Planet* next; // Pointer to the next planet

    Planet(string n, int r, bool d) {
        name = n;
        resources = r;
        hasDebris = d;
        next = nullptr;
    }
};

// Function to traverse planets and collect resources
void explorePlanets(Planet* head) {
    int totalResources = 0;
    int health = 10; // Initial health

    Planet* current = head;
    while (current != nullptr) {
        cout << "Arrived at: " << current->name << endl;
        
        // Collect resources
        totalResources += current->resources;
        cout << "Collected " << current->resources << " resources. Total: " << totalResources << endl;

        // Check for debris
        if (current->hasDebris) {
            health -= 2; // Health decreases by 2 if debris is present
            totalResources /= 2; // Lose half of collected resources
            cout << "Hit debris! Health: " << health << ", Resources now: " << totalResources << endl;
        }

        // Check if mission fails
        if (health <= 0) {
            cout << "Mission failed! Health reached zero.\n";
            return;
        }

        // Move to the next planet
        current = current->next;
    }

    cout << "Mission successful! Final resources: " << totalResources << ", Health: " << health << endl;
}

// Helper function to add a planet to the linked list
void addPlanet(Planet*& head, string name, int resources, bool debris) {
    if (head == nullptr) {
        head = new Planet(name, resources, debris);
    } else {
        Planet* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Planet(name, resources, debris);
    }
}

int main() {
    Planet* head = nullptr;

    // Creating planets (name, resources, debris)
    addPlanet(head, "Earth", 5, false);
    addPlanet(head, "Mars", 10, false);
    addPlanet(head, "Jupiter", 8, true);
    addPlanet(head, "Saturn", 12, false);
    addPlanet(head, "Neptune", 6, true);

    // Start exploration
    explorePlanets(head);

    return 0;
}
