void removeEven(list<int>& li)
{
list<int>::iterator it;
    for(it = li.begin(); it!= li.end(); it++)
    {
        if((*it)%2==0)
        {
            it = li.erase(it);
            it --;

        }
    }
}


