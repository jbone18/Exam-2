#pragma once
#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!
// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty

// BirthdayParty is derived from Party
class BirthdayParty : public Party
{
	// Data structure for containing the party goers in this dinner party
	std::list<std::string> bparty;

	// Constructor for creating a DinnerParty
	BirthdayParty() {}

	friend class PartyFactory;

public:

	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	PartyTicket * add(std::string name)
	{
		//Creates an object of PartyTicket
		PartyTicket *partyticket = NULL;
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
		bparty.push_front(name);

		//Iterator is assigned to the front of the room  (pointing to the recently added party goer)
		std::list<std::string> ::iterator IT = bparty.begin();

		//Create a new dinner party ticket
		partyticket = new BirthdayPartyTicket(this, IT);

		return partyticket;
	}

	// List all the persons currently in the party
	void list()
	{
		// iterate through all the persons here.
		for (std::list<std::string> ::iterator i = bparty.begin(); i != bparty.end(); i++)
		{
			//Output each name in bparty
			std::cout << *i << std::endl;
		}
	}

	// Remove the person identified by the iterator from the party
	void remove(std::list<std::string>::iterator it)
	{
		// someone's getting out of hand. Let's ask them to leave.
		bparty.erase(it);
	}
};
#endif