#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void readData(const string& filename, vector<double>& anglePopulate, vector<double>& coefficientPopulate);

double interpolation(double userAngle, const vector<double>& angle, const vector<double>& coefficient);

bool isOrdered(const vector<double>& angleCheck);

void reorder(vector<double>& orderAngle, vector<double>& orderCoefficient);


int main()
{
    string file;
    vector<double> angles;
    vector<double> coefficients;
    double angleUser;
    char userChar;
    
    cout << "Enter name of input data file:" << endl;
    cin >> file;
    cout << endl;
    
    readData(file, angles, coefficients);
    
    if(!isOrdered(angles))
    {
        reorder(angles, coefficients);
    }
    
    cout << "Enter an angle:" << endl;
    cin >> angleUser;
    cout << endl;

    cout << "Your coefficient of lift is: " << interpolation(angleUser, angles, coefficients) << endl;
    cout << "Would you like to enter another value? (y/n)" << endl;
    cin >> userChar;
    cout << endl;
        
    if (userChar == 'n')
    {
        return 0;
    }
        
    while (userChar == 'y')
    {
        cout << "Enter an angle:" << endl;
        cin >> angleUser;
        cout << "Your coefficient of lift is: " << interpolation(angleUser, angles, coefficients) << endl;
        cout << "Would you like to enter another value? (y/n)" << endl;
        cin >> userChar;
        cout << endl;
        
        if (userChar == 'n')
        {
            return 0;
        } 
    }
        
    return 0;
}

void readData(const string& filename, vector<double>& anglePopulate, vector<double>& coefficientPopulate)
{
    ifstream inFS;
    double filenum1 = 0.0;
    double filenum2 = 0.0;
    
    inFS.open(filename.c_str());
    
    if (!inFS.is_open())
    {
        cout << "Error opening " << filename << endl;
        
        exit(1);
    }
    
    while (inFS >> filenum1 >> filenum2)
    {
        anglePopulate.push_back(filenum1);
        coefficientPopulate.push_back(filenum2);
    }

    return;
}

double interpolation(double userAngle, const vector<double>& angle, const vector<double>& coefficient)
{
    unsigned i = 0;
    double liftCoef = 0.0;
    
    for (i = 0; i < angle.size(); ++i)
    {
        if (userAngle > angle.at(i) && userAngle < angle.at(i+1))
        {
            liftCoef = coefficient.at(i) + (coefficient.at(i+1) - coefficient.at(i))*((userAngle - angle.at(i))/(angle.at(i+1)-angle.at(i)));
        }
        else if (userAngle == angle.at(i))
        {
            //f(b) = f(a) + ( f(c) - f(a) ) * ( (b - a)/(c - a) )
            return coefficient.at(i);
        }
    }
    
    return liftCoef;
}


bool isOrdered(const vector<double>& angleCheck)
{
    if (angleCheck.size() == 0)
    {
        return true;
    }
    
    if (angleCheck.size() == 1)
    {
        return true;
    }
    
    for (unsigned int i = 0; i + 1 < angleCheck.size(); ++i)
    {
        if (angleCheck.at(i) > angleCheck.at(i+1))
        {
            return false;
        }
    }
    
    return true;
}


void reorder(vector<double>& orderAngle, vector<double>& orderCoefficient)
{
    double min = 0.0;
    double min2 = 0.0;
    unsigned i = 0;
    unsigned j = 0;
    for (i = 0; i < orderAngle.size(); ++i)
    {
        for (j = i + 1; j < orderAngle.size(); ++j)
        {
            if (orderAngle.at(j) < orderAngle.at(i))
            {
                min = orderAngle.at(j);
                min2 = orderCoefficient.at(j);
            }
        }
        
        swap(orderAngle.at(i), min);
        swap (orderCoefficient.at(i), min2);
    }
    
    //sort(orderAngle.begin(), orderAngle.end());
    //sort(orderCoefficient.begin(), orderCoefficient.end());
    
    return;
}
