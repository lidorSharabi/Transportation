#include "Road.h"
#include "Search.h"

/**
 * this is a constructor of Road.
 * @param map - a Map object
 * @param start - the starting point of the road
 * @param end - the ending point of the road.
 */
Road::Road(Map* map, Point start, Point end) {
    this->map = map;
    this->start = map->getPointByCoordinates(start);
    this->end = map->getPointByCoordinates(end);
    this->currentLocation = NULL;
    this->calculateRoad(this->start, this->end);
}

/**
 * this function is a default constructor.
 */
Road::Road() {
    this->map = NULL;
    this->start = NULL;
    this->end = NULL;
    this->currentLocation = NULL;
}

/**
 * this function is a destructor.
 */
Road::~Road() {
    /* delete(this->start);
     delete(this->end);
     for(int i = 0; i < this->road.size(); i++)
         delete(this->road[i]);*/
}

/**
 * this function returns the current location of the road.
 * @return
 */
Location* Road::getCurrentLocation() {
    return this->currentLocation;
}

/**
 * this fuction returns the road.
 * @return
 */
std::vector<Point*> Road::getRoad() {
    return this->road;
}

/**
 * this function takes the road one step ahead.
 */
void Road::moveOneStep() {
    int i;
    //finding the index of the current location in the vector
    /*for(i = 0; i < this->road.size(); i++) {
        if (*(this->road) == *(this->currentLocation->getPosition()))
            break;
    }*/

    //setting the current location point to be the next
    this->currentLocation->updateLocation(this->road[i+1]);
}

/**
 * this function calculates the road using the bfs algorithm.
 * @param start - the starting point of the road.
 * @param end - the ending point of the road.
 */
void Road::calculateRoad(Point* start, Point* end) {
    road = Search<Point>::bfsTraversal(*start, *end);
    //clear changes in points that search algorithm made.
    map->clearSearch();
}

/**
 * this function sets the currentLocation and changes it's value to the startingPoint.
 * @param location- the location to set.
 */
void Road::setLocation(Location* location) {
    this->currentLocation = location;
    this->currentLocation->updateLocation(this->start);
}