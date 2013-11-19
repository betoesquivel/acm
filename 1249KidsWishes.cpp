/*
 * =====================================================================================
 *
 *       Filename:  1249KidsWishes.cpp
 *
 *    Description:  Kids want to sit in a circle and some wish to sit next to maximum
 *    2 other kids. I have to say if, given the number of kids and the wishes, it is
 *    possible to arrange them in a perfect circle.
 *
 *        Version:  1.0
 *        Created:  11/02/2013 03:42:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
int main(int argc, const char *argv[])
{
	int kids, wishes;
	cin>>kids>>wishes;
	int kid, wish; 
	while(kids!=0 && wishes!=0){

		for (int i = 0; i < wishes; i++) {
			cin>>kid>>wish;
			kid--; wish--;
			//introduzco en la matriz el wish
		}

		bool possible = true;

		cout << ((possible) ? "Y":"N") <<endl;

		cin>>kids>>wishes;
	}
	
	
	return 0;
}


