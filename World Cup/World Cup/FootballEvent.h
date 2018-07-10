#ifndef _FOOTBALL_EVENT_H_
#define _FOOTBALL_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "FootballTicket.h"

// FIXME 2: Create BaseballEvent and BaseballTicket to for good baseball games!
// FIXME 2a: Create a function stretch so that the attendees can stand up an stretch for the 7th inning
// FIXME 3: Update EventFactory::factory() to allow it to be the ONLY method for creating a BaseballEvent
/**
* BaseballEvent is derived from Event
*/
class FootballEvent : public Event
{
	// Data structure for containing the party goers in this dinner party
	std::list<std::string> fevent;

	// Constructor for creating a DinnerParty
	FootballEvent() {}

	friend class EventFactory;
public:

	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	EventTicket * add(std::string name)
	{
		//Creates an object of PartyTicket
		EventTicket *eventticket = NULL;
		/**
		* FIXME 1a:
		*   Pseudo-code
		*    1. add name to the front of room
		*    2. get iterator to the front of the room (this points to the recently added party goer)
		*    3. create a new dinner party ticket (DinnerPartyTicket) with its constructor
		*            Pass to the constructor "this" party, and the iterator from step 2
		*    4. return this new party ticket
		*/

		//Add name to the front of room
		fevent.push_front(name);

		//Iterator is assigned to the front of the room  (pointing to the recently added party goer)
		std::list<std::string> ::iterator IT = fevent.begin();

		//Create a new dinner party ticket
		eventticket = new footballTicket(this, IT);

		return eventticket;
	}

	// List all the persons currently in the party
	void list()
	{
		// iterate through all the persons here.
		for (std::list<std::string> ::iterator i = fevent.begin(); i != fevent.end(); i++)
		{
			//Output each name in bparty
			std::cout << *i << std::endl;
		}
	}

	// Remove the person identified by the iterator from the party
	void remove(std::list<std::string>::iterator it)
	{
		// someone's getting out of hand. Let's ask them to leave.
		fevent.erase(it);
	}
	void stretch() {
		for (std::list<std::string>::iterator i = fevent.begin(); i != fevent.end(); i++) {
			std::cout << '\t' << *i << " says 'boom boom clap!'" << std::endl;
		}
	};

#endif