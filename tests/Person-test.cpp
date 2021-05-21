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

TEST(PersonTest, move){
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
}


//tests for moving when near border and with other Persons

TEST(PersonTest, moveNoFreePos){
    Map map(12);
    Person person(map.getPosition(5,5));

    // populating map in nearby positions
    Person a(map.getPosition(4,4));
    Person b(map.getPosition(4,5));
    Person c(map.getPosition(4,6));
    Person d(map.getPosition(5,4));
    Person e(map.getPosition(5,6));
    Person f(map.getPosition(6,4));
    Person g(map.getPosition(6,5));
    Person h(map.getPosition(6,6));

    person.move(&map);
    EXPECT_EQ(map.getPosition(5,5)->getPerson(), &person) << "Wrong pointer";

    //Checking nearby position's pointers
    unsigned i = 0;
    if(map.getPosition(4,4)->getPerson() == &person) i++;
    if(map.getPosition(4,5)->getPerson() == &person) i++;
    if(map.getPosition(4,6)->getPerson() == &person) i++;
    if(map.getPosition(5,4)->getPerson() == &person) i++;
    if(map.getPosition(5,6)->getPerson() == &person) i++;
    if(map.getPosition(6,4)->getPerson() == &person) i++;
    if(map.getPosition(6,5)->getPerson() == &person) i++;
    if(map.getPosition(6,6)->getPerson() == &person) i++;
    EXPECT_EQ(i, 0) << i << " nearby Positions have wrong pointer";
}

TEST(PersonTest, moveOneFreePos){
    Map map(13);
    Person person(map.getPosition(5,5));

    // populating map in nearby positions
    Person a(map.getPosition(4,4));
    Person b(map.getPosition(4,5));
    Person c(map.getPosition(4,6));
    Person e(map.getPosition(5,6));
    Person f(map.getPosition(6,4));
    Person g(map.getPosition(6,5));
    Person h(map.getPosition(6,6));

    person.move(&map);
    EXPECT_FALSE(map.getPosition(5,5)->getPerson() == &person) << "Previous Position hasn't changed";

    //Checking nearby position's pointers
    unsigned i = 0;
    if(map.getPosition(4,4)->getPerson() == &person) i++;
    if(map.getPosition(4,5)->getPerson() == &person) i++;
    if(map.getPosition(4,6)->getPerson() == &person) i++;
    if(map.getPosition(5,6)->getPerson() == &person) i++;
    if(map.getPosition(6,4)->getPerson() == &person) i++;
    if(map.getPosition(6,5)->getPerson() == &person) i++;
    if(map.getPosition(6,6)->getPerson() == &person) i++;
    EXPECT_EQ(i, 0) << i << " nearby Positions have wrong pointer";

    EXPECT_EQ(map.getPosition(5,4)->getPerson(), &person) << "Person hasn't settled in only available Position";
}

TEST(PersonTest, moveNearBorder){
    Map map(14);
    Person person(map.getPosition(0,0));

    person.move(&map);
    EXPECT_FALSE(map.getPosition(0,0)->getPerson() == &person) << "Previous Position hasn't changed";

    //Checking nearby position's pointers
    unsigned i = 0;
    if(map.getPosition(0,1)->getPerson()!= nullptr) i++;
    if(map.getPosition(1,0)->getPerson()!= nullptr) i++;
    if(map.getPosition(1,1)->getPerson()!= nullptr) i++;

    EXPECT_EQ(i, 1) << i << " Positions are populated (instead of 1)";

}
