

void listAll(const MenuItem* m, string path) // two-parameter overload
{
    if(m == nullptr)
    {
        return;
    }
    if(m->name()!="")
    {
        cout << path << m->name() << endl;
    }
    if(m-> menuItems() == nullptr)
    {
        return;
    }
    else
    {
        if(m-> name() != "")
        {
            path += m->name();
            path += "/";
        }
        
    }
    
    for(vector<MenuItem*>::const_iterator it = m -> menuItems() -> begin(); it != m -> menuItems() -> end(); it++)
    {
        listAll(*(it), path);
    }



}


