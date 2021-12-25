/**
 * @file OOPS Practice
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
All OOPS in a single shot.
Object-Oriented Programming involves the usage of Classes and Objects that are 
designed to replicate the real-life scenario. 
Classes and Objects:
Classes are the basic concept of OOP. Classes are the user-defined data types 
that help us encapsulate different data members and member functions into one 
single entity that acts as a blueprint to create Objects which in turn help us 
replicate a real-life analogy. Class is not visible to the world but an objects is.
*/
#include<bits/stdc++.h>

using namespace std;

class Mobile{
    public:     // normally displayed to all the people to help them make decision to buy the phone.
    string company;
    string name;
    string sceen_dimensions;
    string body_color;
    int RAM;
    int Storage;
    string processor;
    int Battery; // in mAh
    float price;
    string anroid_version;

    private:    // hidden from the people and are accessible to the owner of the phone only.
    string IMEI1;
    string IMEI2;
    string serial_num;
    string IPAddress;
    string WIFIMAC;

    protected:  // similarly some of the details that are to be hidden from the people are kept in this.
}

class 