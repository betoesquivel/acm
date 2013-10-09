/*
 * =====================================================================================
 *
 *       Filename:  1959Gifts.cpp
 *
 *    Description:  Problema de la acm, mindpushups 2013. Segunda semana virtual.
 *
 *        Version:  1.0
 *        Created:  10/08/2013 07:05:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jose Alberto Esquivel Patino
 *   Organization:  Itesm 
 *
 * =====================================================================================
 */
#include <iostream>
#include <list>

using namespace std; 

template <class T>
void printList(const list<T> &l)
{

	list<int>::iterator l_it;
	cout<<"Printing the list."<<endl;
	for(l_it = l.begin(); l_it!=l.end(); l++)
	{
		cout<<*l_it<<endl;
	}
	cout<<endl;
	
}
int main()
{
	int numberOfCows, budget;
	cin>>numberOfCows>>budget;
	
	list<int> giftCosts, shippingCosts, totalCosts;
	list<int>::iterator giftCosts_it, shippingCosts_it, totalCosts_it;
	for(int cow_it = 0; cow_it<numberOfCows; cow_it++)
	{
		int cowGiftCost, cowShippingCost, cowGiftTotalCost;
		cin>>cowGiftCost>>cowShippingCost;
		cowGiftTotalCost = cowGiftCost+cowShippingCost;

		giftCosts_it = giftCosts.begin();
		shippingCosts_it = shippingCosts.begin();
		totalCosts_it = totalCosts.begin();
		while(totalCosts_it != totalCosts.end() && cowGiftTotalCost > *totalCosts_it)
		{
			giftCosts_it++;
			shippingCosts_it++;
			totalCosts_it++;
		}
		
		if(totalCosts_it != totalCosts.end())
		{
			giftCosts.insert(giftCosts_it, cowGiftCost);
			shippingCosts.insert(shippingCosts_it, cowShippingCost);
			totalCosts.insert(totalCosts_it, cowGiftTotalCost);
		}
		else
		{
			giftCosts.push_back(cowGiftCost);
			shippingCosts.push_back(cowShippingCost);
			totalCosts.push_back(cowShippingCost);
		}
	}
	printList(giftCosts);

	int subTotal = 0, giftsAfforded = 0;
        int mostExpensiveGift, tentativeDiscount;
	//int discount;

	giftCosts_it = giftCosts.begin();
	totalCosts_it = totalCosts.begin();
	while(totalCosts_it != totalCosts.end() && subTotal <= budget)
	{
		subTotal += *totalCosts_it;
		mostExpensiveGift = (*giftCosts_it > mostExpensiveGift) ? *giftCosts_it:mostExpensiveGift;
		//discount = tentativeDiscount;
		tentativeDiscount = mostExpensiveGift/2;

		if(subTotal<=budget)
		{
			giftsAfforded++;
			totalCosts_it++;
			giftCosts_it++;
		}
	}

	if((subTotal-tentativeDiscount)<=budget)
	{
		giftsAfforded++;
		totalCosts_it++;
		giftCosts_it++;
	}
	cout<<giftsAfforded<<endl;
}



