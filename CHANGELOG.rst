^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package apriltag
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.6.7 (2017-05-02)
------------------
* Depend on opencv3
* Contributors: Enrique Fernandez

0.6.6 (2016-12-02)
------------------
* Merge pull request `#3 <https://github.com/clearpathrobotics/apriltag/issues/3>`_ from clearpathrobotics/CORE-5975_upgrade_to_2016-12-01_version
  Upgrade to 2016-12-01 version
* Silence unused variable (used on assert)
* Use unsigned int for matd len
* Upgrade to 2016-12-01 version
  fixes CORE-5975
* Keep the webcam from locking up on Ctrl+C
* Contributors: Enrique Fernandez, Enrique Fernández Perdomo

0.6.5 (2016-11-04)
------------------
* Updagre to 2016-10-21 version
  See https://april.eecs.umich.edu/media/apriltag/apriltag-2016-10-21.tgz
  (https://april.eecs.umich.edu/software/apriltag.html)
* Manually bump version to 0.6.4
* Merge pull request `#2 <https://github.com/clearpathrobotics/apriltag/issues/2>`_ from clearpathrobotics/CORE-4601_fix_stride
  Fix stride
* Fix stride
  fixes CORE-4601
  See:
  https://april.eecs.umich.edu/pipermail/apriltag-devel/2016-April/000051.html
* Contributors: Enrique Fernandez, Enrique Fernández Perdomo

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
