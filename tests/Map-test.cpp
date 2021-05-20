#include "gtest/gtest.h"
#include "Map.h"

TEST(MapTest, PositionConstructor) {
    Position a(14, 20);

    EXPECT_EQ (a.getX(),  14);
    EXPECT_EQ (a.getY(),  20);
    EXPECT_EQ (a.getPerson(), nullptr);
}

TEST(MapTest, MapConstructor){
    Map a(20);
    Position *ptr = a.getPosition(14, 19);
    EXPECT_EQ(ptr->getX(),14) << "Incorrect x coordinate with getPosition";
    EXPECT_EQ(ptr->getY(),19) << "Incorrect y coordinate with getPosition";
    EXPECT_EQ(ptr->getPerson(), nullptr) << "Position's pointer different than nullptr";
}

TEST(MapTest, PositionsInMap){
    Map a(15);
    Position *ptr = a.getPosition(0, 0);
    EXPECT_EQ(ptr->getX(),0) << "Incorrect x coordinate with getPosition";
    EXPECT_EQ(ptr->getY(),0) << "Incorrect y coordinate with getPosition";
    EXPECT_EQ(ptr->getPerson(), nullptr) << "Position's pointer different than nullptr";

    ptr = a.getPosition(14, 14);
    EXPECT_EQ(ptr->getX(),14) << "Incorrect x coordinate with getPosition";
    EXPECT_EQ(ptr->getY(),14) << "Incorrect y coordinate with getPosition";
    EXPECT_EQ(ptr->getPerson(), nullptr) << "Position's pointer different than nullptr";

    ptr = a.getPosition(0, 14);
    EXPECT_EQ(ptr->getX(),0) << "Incorrect x coordinate with getPosition";
    EXPECT_EQ(ptr->getY(),14) << "Incorrect y coordinate with getPosition";
    EXPECT_EQ(ptr->getPerson(), nullptr) << "Position's pointer different than nullptr";
}