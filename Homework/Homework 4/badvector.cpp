void removeBad(vector<Restaurant*>& v)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i]->stars()<=2)
        {
            delete v[i];
            v.erase(v.begin()+i);
            i--;
        }
    }
}


