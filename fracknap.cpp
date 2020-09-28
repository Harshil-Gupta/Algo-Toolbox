#include<bits/stdc++.h>
using namespace std;

class Items{
    public:
    int weight;
    int value;
};

bool comp(Items i1, Items i2) { 
    double ratio1 = (double)i1.value / i1.weight; 
    double ratio2 = (double)i2.value / i2.weight; 
    return ratio1>ratio2;
} 

int main() {
    int n;
    int capacity;
    cin >> n >> capacity;
    Items* items = new Items[n];
    for(int i=0;i<n;i++) {
        cin >> items[i].value;
        cin >> items[i].weight;
    }
    sort(items,items+n,comp); // Descending
    /*for(int i=0;i<n;i++){
        cout << items[i].value << " " << items[i].weight << "\n";
    }*/
    int curWeight = 0;  
    double finalvalue = 0.0; 
    for (int i = 0; i < n; i++) 
    { 
        if (curWeight + items[i].weight <= capacity) 
        { 
            curWeight += items[i].weight; 
            finalvalue += items[i].value; 
        } 
  
        else
        { 
            int remain = capacity - curWeight; 
            finalvalue += items[i].value * ((double) remain / items[i].weight); 
            break; 
        } 
    } 
    cout.precision(10);
    cout << double(finalvalue) << "\n";
    return 0 ;
}