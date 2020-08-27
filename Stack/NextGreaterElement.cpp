#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> nextGreaterElement(int* arr, int n){
    vector<int> v;
    for(int i=0;i<n;i++){
        int k=0;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                v.push_back(arr[j]);
                k=1;
                break;
            }
        }
        if(k==0){
        v.push_back(-1);
        }
    }
    return v;
}

vector<int> nextGreaterElementUsingStack(int* arr, int n){
    vector<int> v;
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            v.push_back(-1);
        }else if(s.top()>arr[i]){
            v.push_back(s.top());
        }else{
            while(!s.empty()&&s.top()<arr[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}



int main() 
{ 
    int arr[] = {11, 13, 21, 3}; 
    int n = 4;
    //vector<int> v = nextGreaterElement(arr, n);
    vector<int> v = nextGreaterElementUsingStack(arr, n);
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
} 