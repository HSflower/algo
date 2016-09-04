/*
 * studyInheritance.cpp
 *
 *  Created on: 2016. 8. 30.
 *      Author: hanseul
 */




class Animal
{
  public:
  int legs;
  int arms;
  int age;
  Animal();
  ~Animal();
  void eat();
  void sleep();
  void drink();
}
;//The class Animal contains information and functions
//related to all animals (at least, all animals this lesson uses)
class Cat : public Animal
{
  public:
  int fur_color;
  void Purr();
  void fish();
  void Mark_territory();
};
//For those of you familiar with cats
//eat of the above operations is unique
//to your friendly furry friends
//(or enemies, as the case may be)

//public, protected, private
