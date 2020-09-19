// cpp program to print * between two identical number
#include <iostream>
using namespace std;

//Function To find length
int length(char arr[])
{
	int len = 0;
	for(int i =0;arr[i]!='\0';i++){
		len++;
	}
	return len;
}

//Recursive Function
void pairStar(char arr[],int start)
{
	 if(arr[start]=='\0'){
		   return;
	 }
  	//Recursive Call
  	pairStar(arr,start+1);

  	if (arr[start] == arr[start+1]) {
    		int l = length(arr);

    		arr[l+1] = '\0';    //Extending the string

    		//To shift the letters by 1
    		for(int i = l-1;i>=start +1;i--){
    			arr[i+1] = arr [i];
  	     }

  		   arr[start+1] = '*';    //Entering * in between
  	}
}

int main(){
	char input[50];
	cout<<"Enter Input"<<endl;
	cin>> input;

	pairStar(input,0);  //Calling the function

	cout<<"Modified Output"<<endl;
	cout<<input<<endl;

	return 0;
}
