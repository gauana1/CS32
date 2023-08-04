//
//  p1. cpp
//  HW3
//
//  Created by Gautam Anand on 5/10/23.
//

//


//Your declarations and implementations would go here
class Event
{
public:
    Event(string s)
    {
        m_name = s; //constructor for event
    }
    string name() const
    {
        return this->m_name; //return m_name
    }
    virtual bool isSport() const //returns true by default, and is virtual because some functions aren't sports
    {
        return true;
    }
    virtual string need() const = 0; //pure virutal, every funciton has a diff implmenetion and don't want event to be created as an object
    
    virtual ~Event() //destructor for event virtual since each dervied class has its own destructor
    {

    }
private:
    string m_name;
};
class BasketballGame : public Event
{
public:
    BasketballGame(string s):Event(s)
    {
    
    }
    virtual string need() const //define need
    {
        return "hoops";
    }
    virtual ~BasketballGame()
    {
        cout << "Destroying the " << name() << " basketball game "  << endl; //cout appropriate statement in destructor
    }
};
class Concert : public Event
{
public:
    Concert(string s, string genre):Event(s) //concatenate string and use initializer list
    {
        m_genre = genre;
    }
    virtual bool isSport() const //not a sport so change implementation of is sport
    {
        return false;
    }
    virtual string need() const //need a stage for a concert
    {
        return "a stage";
    }
    virtual ~Concert()
    {
        cout << "Destroying the " << name() << " " << this-> m_genre<< " concert " << endl; //cout appropriate statement in destructor
    }
private:
    string m_genre;
};
class HockeyGame : public Event
{
public:
    HockeyGame(string s):Event(s)
    {
    
    }
    virtual string need() const //cout ice for need
    {
        return "ice";
    }
    virtual ~HockeyGame()
    {
        cout << "Destroying the " << name() << " hockey game " << endl; //cout approproate statement for destructor
    }
};


