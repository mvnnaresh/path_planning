#include <cmath>

#include "tests/test_utils.hpp"

TEST(PathPlanningTest, EmptyGrid) {
  std::vector<std::vector<int>> grid{
                     { 0 , 0 , 0 },
                     { 0 , 0 , 0 },
                     { 0 , 0 , 0 }
                   };
  ASSERT_EQ(4, run_test(grid, "dijkstra"));
  ASSERT_EQ(4, run_test(grid, "a_star"));
  ASSERT_EQ(4, run_test(grid, "jump_point_search"));
  ASSERT_EQ(4, run_test(grid, "lpa_star"));
  // NOTE: RRT currently does not store cost. Now becomes a TODO.
  ASSERT_LE(floor(sqrt((double)8 )), run_test(grid, "rrt"));
  ASSERT_EQ(std::sqrt((double)(8)), run_test(grid, "rrtstar"));
  ASSERT_EQ(4, run_test(grid, "d_star_lite"));
  ASSERT_GE(5, run_test(grid, "ant_colony"));
  ASSERT_GE(5, run_test(grid, "genetic_algorithm"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
