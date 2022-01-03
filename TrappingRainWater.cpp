#include <iostream>
#include <vector>
#include <string>

using namespace std;

int trap(vector<int>& height);


int main ()
{       
    // vector<int> height = {4,2,0,3,2,5};
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // vector<int> height = {4,2,3};

    int result = trap(height);
    cout<< "water |=> " << result<< "\n\r";

}
int trap(vector<int>& height) 
{
       int sum =0;
    bool finish =false;

    for(int i=0; i< height.size(); )        
    {
        if(finish) return sum;

        int base = height[i];
        int secSum=0;
        int counter =0;
        bool found= false;
        int min =0;
        for(int j=i+1; j< height.size(); j++)
        {
            if( height[j]<base)
            {
                secSum += base - height[j];
                counter ++;
                // if(height[j]> min)
                // {
                //     secSum -= counter * (base - height[j]);
                //     found = true;
                //     i =j;
                //     break;
                // }
            }
            else if(height[j]>=base)
            {
                found = true;
                i =j;
                break;
            }
            else if(height[j]>height[j-1] && j-1 !=i)
            {
                secSum -= counter * (base - height[j]);
                found = true;
                i =j;
                break;
            }

            // if(j+1 == height.size() || (j+1 < height.size() && height[j+1]<height[j]))
            // {
            //     secSum -= counter * (base - height[j]);
            //     found = true;
            //     i =j;
            //     break;
            // }   
           
        }
        if (found)
        {
            sum += secSum;
        }
        else
        {
            i++;
        }
    }
    return sum;
}