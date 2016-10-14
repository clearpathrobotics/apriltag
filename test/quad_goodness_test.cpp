
#include <gtest/gtest.h>

#include <apriltag.h>
#include <common/matd.h>

#include <cfloat>

TEST(TestSuite, testSingularHomagraphy)
{
  // Singular homography matrix H, that would make quad_goodness crash in
  // apriltag.c:451 with version 0.0.3:
  double data[] = {
      16.842470612365709   , -21.25926568714921   , -38.101414660361321,
      19.352180267131565   , -26.072801836536478  , -45.424602052297601,
       0.044929071016859341, -0.056935972637537219,  -0.10186418817681848};

  matd_t* H = matd_create_data(3, 3, data);

  // Compute inverse, which should fail and return NULL:
  matd_t* Hinv = matd_inverse(H);

  EXPECT_EQ(NULL, Hinv);

  // Compute LU decomposition, to check that H is singular:
  // Note that this function is used internally by matd_inverse to check if the
  // matrix is singular (see common/matd.c:526).
  matd_plu_t* plu = matd_plu(H);

  EXPECT_TRUE(plu->singular);

  // Call quad_goodness, which after version 0.0.3 (not included) shoud NOT
  // crash and should return a score equal to -DBL_MAX.
  // Note that the family and image (im) are NOT needed, so we pass NULL.
  // Note that quad_goodness is NOT exported on the apriltag.h header, so we
  // CANNOT test it.
#if QUAD_GOODNESS_BECOMES_PUBLIC
  struct quad q;
  q.Hinv = Hinv;

  const double score = quad_goodness(NULL, NULL, &q);

  EXPECT_EQ(-DBL_MAX, score);
#endif
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
