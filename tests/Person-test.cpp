#include "gtest/gtest.h"
#include "Person.h"

TEST(PersonTest, Person1Constructor){
    int id = Person::getCounter() + 1;

    auto pos = new Position(12, 15);
    Person a(pos);
    Person *per = &a;
    EXPECT_EQ(a.getID(), id) << "Wrong ID";
    EXPECT_EQ(a.getPosition()->getY(), pos->getY()) << "Y coordinates don't match";
    EXPECT_EQ(a.getPosition()->getX(), pos->getX()) << "X coordinates don't match";
    EXPECT_EQ(per, pos->getPerson()) << "Position has wrong Person pointer";
    EXPECT_EQ(a.getPosition(), pos) << "Person has wrong Position pointer";

    EXPECT_EQ(a.getInventory()->getMoney(), 0) << "Inventory has wrong money value with Person(Position*) constructor";
}

TEST(PersonTest, Person2Constructor){
    int id = Person::getCounter() + 1;

    auto pos = new Position(13, 16);
    Person a(pos, 100);
    Person *per = &a;
    EXPECT_EQ(a.getID(), id) << "Wrong ID";
    EXPECT_EQ(a.getPosition()->getY(), pos->getY()) << "Y coordinates don't match";
    EXPECT_EQ(a.getPosition()->getX(), pos->getX()) << "X coordinates don't match";
    EXPECT_EQ(per, pos->getPerson()) << "Position has wrong Person pointer";
    EXPECT_EQ(a.getPosition(), pos) << "Person has wrong Position pointer";

    EXPECT_EQ(a.getInventory()->getMoney(), 100) << "Inventory has wrong money value with Person(Position*) constructor";
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


//Testing if Person is killed when moves out of border
TEST(PersonTest, moveOutOfBorder){
    Map map(1);
    auto person = new Person(map.getPosition(0, 0));

    EXPECT_EQ(map.getPosition(0)->getPerson(), person);

    person->move(&map);

    EXPECT_EQ( map.getPosition(0)->getPerson(), nullptr);
    EXPECT_TRUE(person->isKilled());
}