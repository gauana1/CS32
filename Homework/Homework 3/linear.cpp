
//
//  main.cpp
//  PRob2
//
//  Created by Gautam Anand on 5/6/23.
//
// Return false if the somePredicate function returns false for at
          // least one of the array elements; return true otherwise.



bool allTrue(const string a[], int n)
{
    if(n <= 0)
    {
        return true; // if n less than zero return true
    }
    if(n==1)
    {
        return somePredicate(a[0]); //check if  the 0th element returns true of false
    }
    bool s1= allTrue(a, 1); //split the array in two and recursively call allTrue on each part
    bool s2 =allTrue(a+1, n-1);
    return (s1&s2);
}
int countTrue(const string a[], int n)
{
    int count = 0;
    if(n <= 0)
    {
        return 0; //if n less than zero return 0
    }
    if(n==1)
    {
        if(somePredicate(a[0])) //if true return 1, else return 0
        {
            return 1;
        }
        return 0;
    }
    count+=countTrue(a, 1); //split the array and recursively call countTrue on each part
    count+=countTrue(a+1, n-1);
    return (count);
}
int firstTrue(const string a[], int n)
{
    if(n < 1)
    {
        return -1;
    }
    if(somePredicate(a[0])) //check if returns true, if it does, return 0
    {
        return 0;
    }
    else
    {
        int position = firstTrue(a+1, n-1); //else shrink the arary by shifting the pointer up, until it matches/returns true
        if(position == -1)
        {
            return position;
        }
        else
        {
            position++; //incremeent position counter
            return position;
        }
    }
    
}
int positionOfMax(const string a[], int n)
{
    if(n<1)
    {
        return  -1; //base case
    }
    if(n==1)
    {
        return 0; //base case
    }
    int ret = positionOfMax(a+1,n-1)+1; //add 1 to account for change in the frame of reference
    if(a[0] >= a[ret])
    {
        return 0;
    }
    return ret;
}
bool contains(const string a1[], int n1, const string a2[], int n2)
{
    if(n2 == 0) //base case
    {
        return true;
    }
    if(n2 >n1) //base case
    {
        return false;
    }
    if(a1[0] == a2[0])
    {
        return(contains(a1+1, n1-1,a2+1, n2-1));//shrink both arrays if the first element in the 2nd array is contained in teh first
    }
    else
    {
        return(contains(a1+1, n1-1,a2, n2)); //else  only shrink the first array
    }
}


