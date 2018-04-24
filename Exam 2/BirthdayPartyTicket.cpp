#include "BirthdayPartyTicket.h"
#include "BirthdayParty.h"

// Implements the leave method
void BirthdayPartyTicket::leave() 
{
	// FIXME 4: Implement leave for birthday parties
	// down-cast base class to derived class
	BirthdayParty * actual_party = dynamic_cast<BirthdayParty *>(the_party);

	// call remove DinnerParty remove method to erase party goes identified by "me"
	actual_party->remove(me);
}