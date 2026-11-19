#include "bidder.hpp"
#include "auctioneer.hpp"
#include <cstdlib>

void Bidder::update(Auctioneer *auctioneer)
{
    if (auctioneer->getHighestBidder() == this)
    {
        return;
    }

    double new_bid = auctioneer->getHighestBid() * bid_increase_perc;
    if (new_bid > budget)
    {
        return;
    }

    double roll = (double)rand() / RAND_MAX * 100;

    if (roll < bid_probability)
    {
        double previous_bid = auctioneer->getHighestBid();
        Bidder *prev_bidder = auctioneer->getHighestBidder();

        cout << name << " bidded $"
             << new_bid << " in response to ";
        if (prev_bidder == nullptr)
        {
            cout << "Starting bid";
        }
        else
        {
            cout << prev_bidder->getName();
        }

        cout << "'s bid of $" << previous_bid << endl;

        highest_bid = new_bid;
        auctioneer->accept_bid(new_bid, this);
    }
}

double Bidder::getHighestBid()
{
    return highest_bid;
}

string Bidder::getName()
{
    return name;
}
