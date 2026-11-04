#include<iostream>
#include<list>
#include<iterator>
using namespace std;
void printList(list<int>ll){
    list<int>::iterator itr;
    for(itr = ll.begin(); itr!=ll.end();itr++){
        cout<<(*itr)<<"->";
    }
    cout<<endl;
}
int main(){
    list<int> ll;//vector<int> arr
    ll.push_front(4);
    ll.push_front(1);//1->4
    ll.push_back(3);//1->4->3
    ll.push_back(5);//1->4->3->5
    printList(ll);
    cout<<ll.size()<<endl;
    cout<<"head="<<ll.front()<<"\n";
        cout<<"head="<<ll.back()<<"\n";
ll.pop_front();
printList(ll);
    return 0;
}