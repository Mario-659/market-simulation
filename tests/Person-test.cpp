#include "gtest/gtest.h"
#include "Person.h"

TEST(PersonTest, PersonConstructor){
    Position *pos = new Position(12, 15);
    Person a(pos);
    Person *per = &a;
    EXPECT_EQ(a.getID(), 1) << "Wrong ID";
    EXPECT_EQ(a.getPosition()->getY(), pos->getY()) << "Y coordinates don't match";
    EXPECT_EQ(a.getPosition()->getX(), pos->getX()) << "X coordinates don't match";
    EXPECT_EQ(per, pos->getPerson()) << "Position has wrong Person pointer";
    EXPECT_EQ(a.getPosition(), pos) << "Person has wrong Position pointer";
}

/*TEST(PersonTest, move){
    Map map(10);
    Person person(map.getPosition(2,3));

    person.move(&map);
    EXPECT_FALSE(map.getPosition(2,3)->getPerson() == &person) << "Previous Position hasn't changed";

    //Checking nearby position's pointers
    unsigned i = 0;
    if(map.getPosition(3,3)->getPerson()!= nullptr) i++;
    if(map.getPosition(3,4)->getPerson()!= nullptr) i++;
    if(map.getPosition(3,2)->getPerson()!= nullptr) i++;
    if(map.getPosition(2,2)->getPerson()!= nullptr) i++;
    if(map.getPosition(2,4)->getPerson()!= nullptr) i++;
    if(map.getPosition(1,3)->getPerson()!= nullptr) i++;
    if(map.getPosition(1,2)->getPerson()!= nullptr) i++;
    if(map.getPosition(1,4)->getPerson()!= nullptr) i++;
    EXPECT_EQ(i, 1) << i << " Positions are populated (instead of 1)";
}*/
