//Program: automatic coin dispenser
//File: smithHW1.cpp
//Author:David Smith
//Date: jan 26th 2017
//Description: Change calculator for a shop or someone who needs an easy way to know the change due to the customer. Also useful for keeping tack of your total sales and what changeyou have used that day/month/year.


#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
  float totalpurchases = 0;
  float totalcash = 0;
  float purchase;
  float cash;
  int coins = 0;
  
  cout << fixed << setprecision (2);
  cout << setw (15) << "Purchase";
  cout << setw (10) << "Tendered";
  cout << setw (10) << "Change";
  cout << setw (6) << "$0.25";
  cout << setw (6) << "$0.10";
  cout << setw (6) << "$0.05";
  cout << setw (6) << "$0.01" << endl;
  while (cin >> purchase >> cash)
    {
      totalpurchases += purchase;
      totalcash += cash;
      float change = cash - purchase;
//pennie problem! fixed, by making it all inside the int and adding a .05 to the previous float 
      int pennies = int((change - int(change)) * 100 +0.5);//needed to convert from float to int 

      int quarters = pennies / 25;
      coins += quarters * 25;
      pennies %= 25;
      int dimes = pennies / 10;
      coins += dimes * 10;
      pennies %= 10;
      int nickles = pennies / 5;
      coins += nickles * 5;
      pennies %= 5;
    
      coins += pennies;
      cout << setw (15) << purchase;
      cout << setw (10) << cash;
      cout << setw (10) << change;
      cout << setw (6) << quarters;
      cout << setw (6) << dimes;
      cout << setw (6) << nickles;
      cout << setw (6) << pennies << endl;
    }
  cout << "Total purchase: " << totalpurchases;
  cout << "; Total cash: " << totalcash << endl;
  cout << "Changed owed = " << totalcash - totalpurchases
       << "; Change given in coin: " << coins / 100.0
       << endl;
  return 0;
}
