#include <iostream>
#include <cmath>
#include <string>
#include "Distance.h"

using namespace std;

Distance::Distance()
{
  feet = 0;
  inches = 0.0;
  
  return;
}

Distance::Distance(unsigned ft, double in)
{
  feet = ft;
  inches = in;

  init();
  
  return;
}

Distance::Distance(double in)
{
  feet = 0;
  inches = in;
  
  init();
  
  return;
}

void Distance::init()
{
  if (feet < 0)
  {
    feet = -feet;
  }
  
  if (inches < 0.0)
  {
    inches = -inches;
  }
  
  while (inches >= 12.0)
  {
    ++feet;
    inches = inches - 12.0;
  }
  
  return;
}

unsigned Distance::getFeet() const
{
  return feet;
}

double Distance::getInches() const
{
  return inches;
}

double Distance::distanceInInches() const
{
  return (inches + (feet * 12.0));
}

double Distance::distanceInFeet() const
{
  return (feet + (inches / 12.0));
}

double Distance::distanceInMeters() const
{
  return (feet*12 + inches)*0.0254;
}

const Distance Distance::operator+(const Distance &rhs) const
{
  return Distance(this->distanceInInches()+rhs.distanceInInches());
}

const Distance Distance::operator-(const Distance &rhs) const
{
  return Distance(this->distanceInInches()-rhs.distanceInInches());
}

ostream & operator<<(ostream &out, const Distance &rhs) 
{
  out << rhs.feet << "' " << rhs.inches << "\"";

  return out;
}