^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package apriltag
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.0.4 (2016-10-14)
------------------
* Merge pull request `#1 <https://github.com/clearpathrobotics/apriltag/issues/1>`_ from clearpathrobotics/fix_crash_singular_homography
  Fix crash when homography is singular
* Add unit test for singular homography
* Check if inverse homography Hinv is NULL
  This happens when the homography H is singular.
* Set special compile flags per target
* Contributors: Enrique Fernandez, afakihcpr

0.0.3 (2016-07-11)
------------------
* Install header on global include destination
* Contributors: Enrique Fernandez

0.0.2 (2016-07-07)
------------------
* Fix header install rules
* Contributors: Enrique Fernandez

0.0.1 (2016-07-05)
------------------
* Use __attribute_\_((__unused_\_)) for unused vars, used on asserts
* Catkinize
* Original code from apriltag-2015-03-18
  Downloaded and decompressed here from:
  https://april.eecs.umich.edu/media/media/apriltag/apriltag-2015-03-18.tgz
* Contributors: Enrique Fernandez
