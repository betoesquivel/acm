#include <iostream>
#include <list>

using namespace std; 

void printList(list<int> &l, list<int> &l2)
{

	list<int>::iterator l_it;
	list<int>::iterator l2_it;
	l_it = l.begin();
	l2_it = l2.begin();
	while(l_it!=l.end())
	{
		cout<<*l_it<<' ';
		cout<<*l2_it<<endl;
		l_it++;
		l2_it++;
	}
	
}


int main()
{
	list<int> idList, solvedList;
	list<int>::iterator idList_it, solvedList_it;

	int numberOfTeams, teamID, solvedProblems;
	
	cin>>numberOfTeams;
    cin>>teamID>>solvedProblems;
	idList.push_back(teamID);
	solvedList.push_back(solvedProblems);
    
	for(int i = 1; i<numberOfTeams; i++)
	{
		cin>>teamID>>solvedProblems;
		solvedList_it = solvedList.begin();
		idList_it = idList.begin();
		
		while(solvedList_it != solvedList.end() && *solvedList_it>=solvedProblems)
		{
			solvedList_it++;
			idList_it++;
		}	
		
		
		if(solvedList_it == solvedList.end())
		{
			idList.push_back(teamID);
			solvedList.push_back(solvedProblems);
		}		
		else
		{
			idList.insert(idList_it,teamID);
			solvedList.insert(solvedList_it,solvedProblems);
		}
		
	}

	printList(idList,solvedList);
}
