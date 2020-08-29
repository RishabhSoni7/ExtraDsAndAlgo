#include<iostream>
#include<vector>
#include<stack>  

using namespace std;

void stockSpan(int* arr, int n){
    stack<int> s;
    vector<int> v;

    for(int i=0;i<n;i++){
        if(s.empty()){
            v.push_back(1);
        }else if(arr[s.top()]>arr[i]){
            v.push_back(i-s.top());
        }else{
            while(!s.empty()&&arr[s.top()]<arr[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(i+1);
            }else{
                v.push_back(i-s.top());
            }
        }
        s.push(i);
    }

    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }

}

int main() 
{ 
    int arr[] = { 100, 80, 60, 70, 60, 75, 85 }; 
    int n = 7;
    stockSpan(arr, n);  
}