// itinerary list means that the list which shows that from to and again (to form) (form to)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void itinerary(map<string,string> list1){
    // make reverse map to find the starting city...
    map<string,string> reverseList1;
    map<string,string> :: iterator it;

    for(it = list1.begin();it != list1.end();it++){
        reverseList1[it->second] = it->first;
    }

    string start;
    for(it = list1.begin();it != list1.end();it++){
        if(reverseList1.find(it->first) == reverseList1.end()){
            start = it->first;
            break;
        }
    }

    cout<<"this is start:"<<start<<endl;

    //now start is founded lets just print the list
    it = list1.find(start);
    cout<<"FINAL ITINERARY LIST"<<endl;
    while(it != list1.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it = list1.find(it->second);
    }

}
int main(){
    map<string,string> list1 ;
    list1["pune"] = "mumbai";
    list1["mumbai"] = "nashik";
    list1["nashik"] = "kolhapur";
    list1["kolhapur"] = "satara";


    itinerary(list1);
    return 0;
}