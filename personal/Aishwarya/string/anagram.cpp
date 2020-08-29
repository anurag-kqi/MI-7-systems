#include <iostream> 
#include<string.h>
using namespace std; 

bool anagram(string, string);

bool anagram(string str1, string str2) 
{ 
    int len,len1,len2,i,j,found=0,not_found=0;
    len1 = str1.size();
	len2 = str2.size();
	if(len1==len2)
	{
		len=len1;
		for(i=0;i<len;i++)
		{
			found=0;
			for(j=0;j<len;j++)
			{
				if(str1[i]==str2[j])
				{
					found=1;
					break;
				}
			}
			if(found==0)
			{
				not_found=1;
				break;
			}
		}
		if(not_found==1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		cout<<"Two string must have same number of character to be Anagram\n";
	}
} 
   
int main() 
{ 
    string str1, str2;
    int ch,res;
    cout<<"Enter two strings: ";
    cin>>str1>>str2; 
    res = anagram(str1, str2);
    if (res == true) 
        cout << "The two strings are anagram of each other\n"; 
    else
        cout << "The two strings are not anagram of each other\n"; 
  
    return 0; 
} 