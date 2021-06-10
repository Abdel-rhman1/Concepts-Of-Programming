#include<iostream>
#include<stack>
using namespace std;
//// Calling Class
class GenerateSubsets{
public:
  int* a,  k, n, start, remain;
  int cur_ind;
  int *cur_subset;
  // Calling Class Constructor
  GenerateSubsets(int* a, int k, int n, int cur_ind, int *cur_set , int start,int remain){
      this-> a = a;
      this->k = k;
      this->cur_ind = cur_ind;
      this->cur_subset = cur_set;
      this->n = n;
      this->start = start;
      this->remain = remain;
  }
};
// Generate All SubSets Main function
void GenerateSubsetsCall(int* a, int k, int n){
    int cur_subset[100];
    // First Initial Calling
    GenerateSubsets FirstCall(a , k , n , 0 , cur_subset, 0 , k);
    // Stack react as Recursion Memory
    stack<GenerateSubsets> s;
    // push it into the stack
    s.push(FirstCall);
    // loop until the stack is empty
    while(!s.empty()){
        // get the calling of the top of the stack
        GenerateSubsets callig = s.top();
        // remove it from the stack
        s.pop();
        // Base Case
        if(callig.start==n){
            for(int i=0;i<3;i++)  cout<<callig.cur_subset[i]<<"     "; cout<<endl;
            //callig.cur_ind -=1;
        }

        // ingore This element in the Array
        if(n - callig.start>callig.remain){
            GenerateSubsets ob2(a, k, n, callig.cur_ind, callig.cur_subset,callig.start+1, callig.remain );
             s.push(ob2);
        }
        // use the current Item
        if(callig.remain > 0)
        {
            callig.cur_subset[callig.cur_ind++]=a[callig.start];
            //cout<<cur_subset[cur_ind-1]<<"   ";
            GenerateSubsets ob1(a, k, n ,callig.cur_ind, callig.cur_subset, callig.start+1, callig.remain-1);
            //cout<<"Welcome2 To You"<<endl;
            s.push(ob1);
        }
    }
}

int main(){
  int a[]={1,3,5,8,10}; int n=sizeof(a)/sizeof(a[0]), k=3;
    GenerateSubsetsCall(a, k, n);
  return 0;
}
/*
int cur_ind;
int cur_subset[100];
void GenerateSubsets(int* a, int k, int n, int start, int remain)
{
    // Base case
    if(start==n)
    {
        //cout<<"Hello"<<endl;
        if(cur_ind==k){int i; for(i=0;i<k;i++) cout<<cur_subset[i]<<" "; cout<<endl;}
        return;
    }
    // Use the current item
    if(remain > 0)
    {
        //cout<<"First Cond"<<endl;
        cur_subset[cur_ind++]=a[start];
        //cout<<"cur_ind Before"<<endl;
        //cout<<cur_ind<<endl;
        GenerateSubsets(a, k, n, start+1, remain-1);
        cur_ind--;
        //cout<<"cur_ind After"<<endl;
        //cout<<cur_ind<<endl;
    }
    if(n-start>remain)
    {
        //cout<<"Second Condition"<<endl;
        GenerateSubsets(a, k, n, start+1, remain);
    } // Ignore the current item

}
void GenerateSubsets(int* a, int k, int n)
{
    cur_ind=0;
    GenerateSubsets(a, k, n, 0, k);
}
int main()
{
    int a[]={1,3,5,8,10}; int n=sizeof(a)/sizeof(a[0]), k=3;
    GenerateSubsets(a, k, n);
    return 0;
}

*/
