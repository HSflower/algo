//
//  Day15.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 5. 31..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Day15.hpp"


void day15()
{
    Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }
    mylist.display(head);
    
}
