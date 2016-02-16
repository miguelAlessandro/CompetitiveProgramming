#include <iostream>

using namespace::std;

int n, a, c25 = 0, c50 = 0;
bool b = true;

int main( void ){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        if(b)
        {
            if(a == 25) 
                c25++;
            else if(a == 50)
            {
                if(c25 > 0)
                    c25--;
                else{
                    b = false;
        			break;
        		}
                c50++;
            }
            else
            {
                if(c50 > 0 && c25 > 0){
                
                    c50--; c25--;
                    
                }
                else if(c25 >= 3)
                    c25 -= 3;
                else{
					                
                    b = false;
            		break;
            	}
            }
        }
    }

    if(b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
