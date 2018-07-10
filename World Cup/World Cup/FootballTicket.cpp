#include "FootballTicket.h"
#include "FootballEvent.h"

/**
* Implements the leave method
*/
void FootballTicket::leave() {
	// down-cast base class to derived class
	FootballEvent * actual_party = dynamic_cast<FootballEvent *>(the_event);

	// call remove DinnerParty remove method to erase party goes identified by "me"
	actual_party->remove(me);
	// FIXME 4: Implement leave for baseball games
}
