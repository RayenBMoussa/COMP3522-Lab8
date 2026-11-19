#include "auctioneer.hpp"

void Auctioneer::register_bidder(Bidder *bidder)
{

    // adds another bidder to the bidders vector
    bidders.push_back(bidder);
}

void Auctioneer::reset_auctioneer()
{
    // TODO: clear the bidders vector and reset highest_bid/highest_bidder.
    bidders.clear();
    highest_bid = 0;
    highest_bidder = nullptr;
}

void Auctioneer::notify_bidders()
{
    // TODO: call update(this) on every registered bidder except
    // highest_bidder (a bidder cannot retaliate to their own bid).
    for (Bidder *bidder : bidders)
    {
        if (bidder != highest_bidder)
        {
            bidder->update(this);
        }
    }
}

void Auctioneer::accept_bid(double bid, Bidder *bidder)
{
    // TODO: if bid > highest_bid, record the new highest_bid/highest_bidder
    // and call notify_bidders().
    if (bid > highest_bid)
    {
        highest_bid = bid;
        highest_bidder = bidder;
        notify_bidders();
    }
}

double Auctioneer::getHighestBid()
{
    return highest_bid;
}

Bidder *Auctioneer::getHighestBidder()
{
    return highest_bidder;
}
