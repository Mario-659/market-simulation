#include <gtest/gtest.h>
#include <fstream>

#include "Simulation.h"

TEST(SimulationTest, savesData){
    Simulation simulation(8, 35, 20, 5, 3);
    simulation.runSimulation(10);

    std::string data;
    std::fstream fs;
    fs.open("Events.csv", std::ios::in);
    ASSERT_TRUE(fs.is_open());

    getline(fs, data);
    EXPECT_EQ(data, "turn,typeOfAction,firstID,firstType,secondID,secondType,numberOfExchangedItems,exchangedMoney");

    fs.close();
    data.clear();

    fs.open("Species.txt", std::ios::in);
    ASSERT_TRUE(fs.is_open());

    getline(fs, data);
    EXPECT_EQ(data, "________________________________________________________________________________");
    fs.close();
}

TEST(SimulationTest, throwsException){
    EXPECT_ANY_THROW(Simulation simulation(5, 20, 15, 5, 5));
}
