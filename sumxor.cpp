/*
 * =====================================================================================
 *
 *       Filename:  sumxor.cpp
 *
 *    Description:  receiving just the xor and the sum of two numbers X and Y
 *    obtain the numbers X and Y, in which X is always the smallest.
 *
 *        Version:  1.0
 *        Created:  10/03/2013 03:27:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;



//extracted from cplusplus.com/forum/general/10898
string int_to_binary(int x){
    const int size=sizeof(x)*8;
    string res;
    bool s=0;
    for (int a=0;a<size;a++){
        bool bit=x>>(size-1);
        if (bit)
            s=1;
        if (s)
            res.push_back(bit+'0');
        x<<=1;
    }
    if (!res.size())
        res.push_back('0');
    return res;
}

string addBits(int numBits, string s)
{
	for(int i = s.length(); i<numBits; i++)
		s="0"+s;
	return s;
}


int calculate_x_and_y(int xysum, int xyxor, string &y)
{
	string x;


}

int main()
{
	int xy_sum, xy_xor, bits;
	string xysum, xyxor;
	while(cin>>xy_sum>>xy_xor)
	{
		xysum = int_to_binary(xy_sum);
		xyxor = int_to_binary(xy_xor);
		cout<<"This are my numbers converted: "<<xysum<<' '<<xyxor<<endl;
		bits = (xysum.length()>=xyxor.length()) ? xysum.length():xyxor.length();
		xysum = addBits(bits,xysum);
		xyxor = addBits(bits,xyxor);
		cout<<"This are my numbers with "<<bits<<" bits: "<<xysum<<' '<<xyxor<<endl;
	}

}
