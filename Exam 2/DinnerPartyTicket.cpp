#include "DinnerPartyTicket.h"
#include "DinnerParty.h"

// Implements the leave method
void DinnerPartyTicket::leave() 
{
	// down-cast base class to derived class
	DinnerParty * actual_party = dynamic_cast<DinnerParty *>(the_party); 

	// call remove DinnerParty remove method to erase party goes identified by "me"
	actual_party->remove(me); 
}