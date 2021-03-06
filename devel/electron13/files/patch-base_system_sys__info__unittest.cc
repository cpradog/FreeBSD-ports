--- base/system/sys_info_unittest.cc.orig	2021-07-15 19:13:29 UTC
+++ base/system/sys_info_unittest.cc
@@ -63,13 +63,13 @@ TEST_F(SysInfoTest, AmountOfMem) {
   EXPECT_GE(SysInfo::AmountOfVirtualMemory(), 0);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #define MAYBE_AmountOfAvailablePhysicalMemory \
   DISABLED_AmountOfAvailablePhysicalMemory
 #else
 #define MAYBE_AmountOfAvailablePhysicalMemory AmountOfAvailablePhysicalMemory
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 TEST_F(SysInfoTest, MAYBE_AmountOfAvailablePhysicalMemory) {
   // Note: info is in _K_bytes.
   SystemMemoryInfoKB info;
@@ -100,7 +100,7 @@ TEST_F(SysInfoTest, MAYBE_AmountOfAvailablePhysicalMem
   EXPECT_GT(amount, static_cast<int64_t>(info.free) * 1024);
   EXPECT_LT(amount / 1024, info.total);
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 TEST_F(SysInfoTest, AmountOfFreeDiskSpace) {
   // We aren't actually testing that it's correct, just that it's sane.
@@ -150,7 +150,7 @@ TEST_F(SysInfoTest, NestedVolumesAmountOfTotalDiskSpac
 }
 #endif  // defined(OS_FUCHSIA)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 TEST_F(SysInfoTest, OperatingSystemVersionNumbers) {
   int32_t os_major_version = -1;
@@ -236,7 +236,7 @@ TEST_F(SysInfoTest, GetHardwareInfo) {
   EXPECT_TRUE(IsStringUTF8(hardware_info->model));
   bool empty_result_expected =
 #if defined(OS_ANDROID) || defined(OS_APPLE) || defined(OS_WIN) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       false;
 #else
       true;
