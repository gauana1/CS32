void removeBad(list<Restaurant*>& li)
{
    list<Restaurant*>::iterator it;
        for(it = li.begin(); it!= li.end(); it++)
        {
            if((*it) -> stars() <= 2)
            {
                delete *it;
                it = li.erase(it);
                it --;

            }
        }
}




