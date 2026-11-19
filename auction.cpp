#include "auction.hpp"
#include <iostream>

using namespace std;

Auction::Auction(vector<Bidder *> bidders)
{
    this->bidders = bidders;
    // TODO: register every bidder with this auction's auctioneer.
    for (Bidder *bidder : bidders)
    {
        auctioneer.register_bidder(bidder);
    }
}

void Auction::simulate_auction(string item, double start_price)
{
    cout << "Auctionning " << item
         << " at starting price $" << start_price << endl;

    auctioneer.accept_bid(start_price);

    Bidder *winner = auctioneer.getHighestBidder();
    if (winner != nullptr)
    {
        cout << "The " << item << " goes to " << winner->getName()
             << " for $" << auctioneer.getHighestBid() << endl;
    }
    else
    {
        cout << "No winning bidder." << endl;
    }

    cout << endl;

    for (Bidder *bidder : bidders)
    {
        cout << "Bidder: " << bidder->getName()
             << " , Highest bid: $" << bidder->getHighestBid()
             << endl;
    }
}
