
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "bidder.hpp"
#include "auction.hpp"

using namespace std;

const double MIN_PROBABILITY = 0;
const double MAX_PROBABILITY = 100;

/*
Returns a random double in [min, max). See Lab-08.pptx for why rand()/RAND_MAX
is used here instead of hardcoding a probability.
*/
double generateRandom(double min, double max)
{
  double f = (double)rand() / RAND_MAX;
  return min + f * (max - min);
}

int main()
{
  srand(time(0));

  vector<Bidder *> bidders;

  // Preloaded test bidders.
  bidders.push_back(new Bidder("Jojo", 3000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.2));
  bidders.push_back(new Bidder("Melissa", 7000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.5));
  bidders.push_back(new Bidder("Priya", 15000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.1));
  bidders.push_back(new Bidder("Kewei", 800, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.9));
  bidders.push_back(new Bidder("Scott", 4000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 2));

  // TODO: prompt the user for the item name and starting price.
  string item;
  double start_price;

  cout << "Enter the item name: ";
  getline(cin, item);

  cout << "Enter the starting price";
  cin >> start_price;
  // TODO: give the user the option to either start the auction with just
  // the preloaded bidders above, or add more bidders first (prompting for
  // each new bidder's name, budget, bid_probability, and bid_increase_perc).
char choice;

cout << "Do you want to add more bidders? (y/n)";
cin >> choice;


while (choice == 'y' || choice == 'Y')
{
  string name;
  double budget;
  double probability;
  double increase;

  cout <<"Enter bidder name: ";
  cin >> name;

  cout << "Enter budget: ";
  cin >> budget;

  cout << "Enter bid probability (0-100): ";
  cin >> probability;

  cout << "Enter bid increase multiplier";
  cin >> increase;

  bidders.push_back(new Bidder(name, budget, probability, increase));

  cout << "Add another bidder? (y/n): ";
  cin >> choice;
}


  cout << "Starting Auction!!" << endl;
  cout << "------------------" << endl;
  Auction my_auction(bidders);
  my_auction.simulate_auction(item, start_price);

  for (Bidder *bidder : bidders)
  {
    delete bidder;
  }
  return 0;
}
