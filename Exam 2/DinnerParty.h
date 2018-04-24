#pragma once
#ifndef _DINNER_PARTY_H_
#define _DINNER_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "DinnerPartyTicket.h"

//DinnerParty is derived from Party
class DinnerParty : public Party
{
private:
	// Data structure for containing the party goers in this dinner party
	std::list<std::string> room; 

	// Constructor for creating a DinnerParty
	DinnerParty() {}

	friend class PartyFactory;

public:

	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	PartyTicket * add(std::string name) 
	{
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
		room.push_front(name);
		
		//Iterator is assigned to the front of the room  (pointing to the recently added party goer)
		std::list<std::string> ::iterator IT = room.begin();

		//Create a new dinner party ticket
		partyticket = new DinnerPartyTicket(this, IT);

		return partyticket;
	}

	// List all the persons currently in the party
	void list() 
	{
		// iterate through all the persons here.
		for (std::list<std::string> ::iterator i = room.begin(); i != room.end(); i++)
		{
			// Output the names in the room
			std::cout << *i << std::endl;
		}
	}

	// Remove the person identified by the iterator from the party
	void remove(std::list<std::string>::iterator it) 
	{
		// someone's getting out of hand. Let's ask them to leave.
		room.erase(it);
	}
};
#endif