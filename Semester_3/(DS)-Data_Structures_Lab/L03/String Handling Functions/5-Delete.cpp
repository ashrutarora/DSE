#include <iostream>
#include <cstdio>
using namespace std;

int main(){

    char str[100], substr[100];
    
    cout << "Enter the string: " << endl;
    gets(str);
    
    //cin.getline(str,100);
    cout << "Enter the sub string to be deleted: " << endl;
    gets(substr);
    
    int i=0, j=0, flag, pos, strlen=0, sublen=0;
    
    for(int i=0 ; str[i]!='\0' ; i++)
	{
        strlen++;
    }
    
    for(int i=0 ; substr[i]!='\0' ; i++)
	{
        sublen++;
    }
    
    while(str[i] != '\0')
	{
        if(str[i] == substr[0])
		{
            flag = 1;
            
            while(substr[j] != '\0')
			{
                if(str[i+j] != substr[j])
				{
                    flag = 0;
                    break;
                }
                j++;
            }
            if(flag ==1)
			{
                pos=i;
            }
        }
        i++;
    }
    for(int i = pos ; i <= strlen-sublen ; i++)
	{
        str[i] = str[i+sublen];
    }
    cout << "The string after substring deletion: " << str;

    return 0;
}
