/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Value-oriented List: objects stored in this List are kept in 
 *                     ascending sort order of search key.
 *
 * Last modified on: January 2019
 * Author: AL
 */

#include <iostream>
#include <cctype>
#include "List.h"  // Header file
#include "Patient.h"

// Default constructor.
List::List() : elementCount(0), capacity(MAX_ELEMENTS) {
	
   cout << "List::default constructor" << endl;   // For testing purposes ... and curiosity
   
}  // end default constructor

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const {

   return elementCount;
}

// Description: Insert an element.  *** With DEBUG statements ***
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement) 
{
	bool ableToInsert = false;
	int where = elementCount;
	bool done = false;
	
	cout << " elementCount is : " << elementCount << " capacity is : " << capacity << endl;

	// If newElement not already in List and there is still some space in the List (or List empty)
	if ( elementCount < capacity ) {
	    if ( search(newElement) == NULL ) { // newElement not already in List
			for (int index = 0; index < elementCount && !done; index++) { // Shifting to make some space for newElement
				if ( elements[index] > newElement ) {
					cout << elements[index] << " > " << newElement << "at index " << index << endl;
					for (int shift = elementCount; shift > index; shift--) {
						// shift elements right
						cout << elements[shift-1] << " copied to " << shift << endl;
						elements[shift] = elements[shift-1];
					}
					done = true;
					where = index;
				}					
			}
			// Insert newElement
			cout << "Insert newElement at : " << where << endl;
			elements[where] = newElement;
			ableToInsert = true;
			elementCount++;
			
		}
		else  // For debug purposes
			cout << "newElement already in List!" << endl;
	}
	else  // For debug purposes
		cout << "List FULL!" << endl;

	return ableToInsert;
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved ) {
	bool ableToRemove = false;

    for (int index = 0; index < elementCount; index++) {
    	if ( elements[index] == toBeRemoved ) {
    		for (int shift = index+1; shift < elementCount; shift++) {
    			// shift elements <-
    			elements[index] = elements[shift];
    			index = shift;
    		}
    		ableToRemove = true;
    		elementCount--;
		}
	}
	return ableToRemove;
}

// Description: Remove all elements.
void List::removeAll() {
   
   elementCount = 0;   

}  // end removeAll
   
// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target) {   // Linear or binary search
    Patient* result = NULL;
    bool found = false;

    for (int index = 0; index < elementCount && !found; index++) {
    	if ( elements[index] == target ) {
    		result = &elements[index];
    		found = true;
		}
	}
    return result; 
}  // end of search


// Description: Prints all elements stored in List.
void List::printList() {

   for (int index = 0; index < elementCount; index++) {
   	  cout << elements[index] << endl;
   }   
   return;
}

//  End of implementation file